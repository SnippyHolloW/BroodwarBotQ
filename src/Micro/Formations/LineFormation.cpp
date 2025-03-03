#include <PrecompiledHeader.h>
#include "LineFormation.h"
#include "Regions/MapManager.h"

using namespace BWAPI;

LineFormation::LineFormation(const LineFormation& f)
: Formation(f)
, _lines(1)
{ }

LineFormation::LineFormation(const Vec& center, const Vec& direction, int nonFlyers)
: Formation(center, nonFlyers, direction)
, _lines(1)
{ }

LineFormation::LineFormation(const Position& p, const Vec& direction, int nonFlyers)
: Formation(p, nonFlyers, direction)
, _lines(1)
{ }

void LineFormation::computeToPositions(const std::vector<pBayesianUnit>& vUnits)
{
    if (end_positions.size() == vUnits.size())
        return;
    if (!vUnits.size())
        return;
    //BWTA::Chokepoint* nearestChoke = BWTA::getNearestChokepoint(center);
    //BWTA::Region* region = BWTA::getRegion(TilePosition(center));	
    end_positions.clear();
    if (vUnits.size() == 1)
    {
        end_positions.push_back(Position((int)center.x, (int)center.y));
        return;
    }
    int maxLength = 0;
	for(std::vector<pBayesianUnit>::const_iterator it = vUnits.begin(); it != vUnits.end(); it++)
	{
		BayesianUnit* bayesianUnit = it->get();
		int length = (abs(direction.x) > abs(direction.y)) ? bayesianUnit->unit->getType().tileHeight() : bayesianUnit->unit->getType().tileWidth();
		if (  length > maxLength)
			maxLength = length;
		//lineLength += (abs(direction.x) > abs(direction.y)) ? (*it)->getType().tileHeight() : (*it)->getType().tileWidth();
	}
	maxLength *= TILE_SIZE + 8;
	int lineLength = maxLength * vUnits.size();
	//Vec dir(direction.x, direction.y); // rotation of 90� of the normal to obtain director vector.
    Vec dir;
    if (!direction.x)
    {
        dir = Vec(1.0, 0.0);
    } 
    else
        dir = Vec(- direction.y / direction.x, 1.0);
    dir.normalize();
	Vec begin = center - (dir * lineLength / 2); // Compute the first coord on the line.

    for(unsigned int i = 0; i < vUnits.size();++i)
    {
        Position topos = (begin + (dir * i * 1.2 * maxLength)).toPosition();
        if (!vUnits[i]->unit->getType().isFlyer() && !Broodwar->isWalkable(topos.x()/8, topos.y()/8))
        {
            Position tmp = MapManager::Instance().closestWalkableSameRegionOrConnected(topos);
            if (tmp != Positions::None)
                topos = tmp;
        }
        if (topos.isValid())
            end_positions.push_back(topos);
        else
        {
            topos.makeValid();
            end_positions.push_back(topos);
        }
    }

    computeMean();
}
