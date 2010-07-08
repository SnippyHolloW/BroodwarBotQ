#include "SeeSubgoal.h"
	
SeeSubgoal::SeeSubgoal(SubgoalLogic l, BWAPI::Position pos) :
Subgoal(l),
achieved(false),
pos(pos)
{
}


bool SeeSubgoal::isRealized(){
	if(achieved)
		return true;
	else
		achieved=check();
		return achieved;
}

bool SeeSubgoal::check(){
	return BWAPI::Broodwar->isVisible(pos.x()/32, pos.y()/32);
}

void SeeSubgoal::tryToRealize(UnitsGroup * ug){
	ug->move(pos);
}
double SeeSubgoal::distanceToRealize(UnitsGroup *ug){
	return ug->getCenter().getDistance(pos); 
}