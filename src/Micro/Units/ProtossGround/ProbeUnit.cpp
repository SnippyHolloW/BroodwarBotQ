#include "ProbeUnit.h"

ProbeUnit::ProbeUnit(BWAPI::Unit* u, UnitsGroup* ug):GroundUnit(u, ug)
{
}

ProbeUnit::~ProbeUnit()
{
}

void ProbeUnit::micro()
{
#ifdef __NON_IMPLEMENTE__
    BWAPI::Broodwar->printf("ProbeUnit::micro non impl�ment� !");
#endif
}

void ProbeUnit::check()
{
}

bool ProbeUnit::canHit(BWAPI::Unit* enemy)
{
#ifdef __NON_IMPLEMENTE__
    BWAPI::Broodwar->printf("ProbeUnit::canHit non impl�ment� !");
#endif
    return false;
}

int ProbeUnit::getTimeToAttack()
{
#ifdef __NON_IMPLEMENTE__
    BWAPI::Broodwar->printf("ProbeUnit::getTimeToAttack non impl�ment� !");
#endif
    return 0;
}

std::set<BWAPI::UnitType> ProbeUnit::getSetPrio()
{
    return std::set<BWAPI::UnitType>();
}
