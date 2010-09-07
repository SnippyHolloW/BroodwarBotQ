#include "FormationSubgoal.h"	
using namespace BWAPI;
using namespace std;

#define _OK_DISTANCE_ 4.0 // should perhaps be (WALTILE/2)^2 = 16.0

FormationSubgoal::FormationSubgoal(SubgoalLogic l, pFormation f)
: Subgoal(l)
, formation(f)
{ 
}

FormationSubgoal::FormationSubgoal(const FormationSubgoal& fsg)
: Subgoal(fsg.logic)
, formation(fsg.formation)
{
}

bool FormationSubgoal::isRealized()
{
    return check();
}

void FormationSubgoal::tryToRealize()
{
    unitsGroup->formation(formation);
}

double FormationSubgoal::distanceToRealize()
{
    Position p = Position((int)formation->mean.x, (int)formation->mean.y);
    Broodwar->printf("distance to realize %f", p.getDistance(unitsGroup->center));
    return p.getDistance(unitsGroup->center);
}

bool FormationSubgoal::check()
{
    if (distanceToRealize() <= sqrt(unitsGroup->size()*unitsGroup->size()*_OK_DISTANCE_)) 
        return true;
    //Broodwar->printf("dist: %f", distanceToRealize());
    return false;
}
