#include <PrecompiledHeader.h>
#include "Micro/Units/ProtossFlying/ObserverUnit.h"
#include "Intelligence/EUnitsFilter.h"
#include "Micro/UnitsGroup.h"

using namespace BWAPI;

ObserverUnit::ObserverUnit(BWAPI::Unit* u)
: FlyingUnit(u)
{
    _eUnitsFilter = & EUnitsFilter::Instance();
}

ObserverUnit::~ObserverUnit()
{
}

void ObserverUnit::micro()
{
	if (dodgeStorm())
		return;
    if (Broodwar->getFrameCount() - _lastClickFrame <= Broodwar->getLatencyFrames())
        return;
    Position invisPos = Positions::None;
    double minDist = 100000.0;
    for (std::map<Unit*, Position>::const_iterator it = _unitsGroup->enemies.begin();
        it != _unitsGroup->enemies.end(); ++it)
    {
        double enemyDist = it->second.getApproxDistance(_unitPos);
		//if (_eUnitsFilter->getInvisibleUnits().count(it->first) && enemyDist < minDist)
		if (!it->first->isDetected() && enemyDist < minDist)
        {
            minDist = enemyDist;
            invisPos = it->second;
        }
    }
    if (invisPos != Positions::None)
    {
        unit->move(invisPos);
        _lastClickFrame = Broodwar->getFrameCount();
        _lastMoveFrame = Broodwar->getFrameCount();
    } 
    else
	{
		_mode = MODE_SCOUT;
		updateDir();
		clickDir();
		_mode = MODE_FIGHT_A;
	}
}

void ObserverUnit::check()
{
}

int ObserverUnit::getAttackDuration()
{
    return 0;
}

std::set<BWAPI::UnitType> ObserverUnit::getSetPrio()
{
    return std::set<BWAPI::UnitType>();
}