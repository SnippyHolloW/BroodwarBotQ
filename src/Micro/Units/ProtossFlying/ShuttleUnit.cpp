#include "ShuttleUnit.h"

ShuttleUnit::ShuttleUnit(BWAPI::Unit* u, UnitsGroup* ug)
: FlyingUnit(u, ug)
{
}

ShuttleUnit::~ShuttleUnit()
{
}

void ShuttleUnit::micro()
{
#ifdef __NON_IMPLEMENTE__
    BWAPI::Broodwar->printf("ShuttleUnit::micro non impl�ment� !");
#endif
}

void ShuttleUnit::check()
{
}

bool ShuttleUnit::canHit(BWAPI::Unit* enemy)
{
    return false;
}

int ShuttleUnit::getTimeToAttack()
{
#ifdef __NON_IMPLEMENTE__
    BWAPI::Broodwar->printf("ShuttleUnit::getTimeToAttack non impl�ment� !");
#endif
    return 0;
}

BWAPI::UnitType* ShuttleUnit::getListPriorite()
{
    return ShuttleUnit::listPriorite;
}

std::set<BWAPI::UnitType> ShuttleUnit::getUnitsPrio()
{
    return std::set<BWAPI::UnitType>();
}