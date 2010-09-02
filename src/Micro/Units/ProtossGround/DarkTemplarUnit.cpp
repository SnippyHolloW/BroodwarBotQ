#include "DarkTemplarUnit.h"

std::set<BWAPI::UnitType> DarkTemplarUnit::setUnitsPrio;

DarkTemplarUnit::DarkTemplarUnit(BWAPI::Unit* u, UnitsGroup* ug)
: GroundUnit(u, ug)
{
    if (setUnitsPrio.empty())
    {
    }
}

DarkTemplarUnit::~DarkTemplarUnit()
{
}

void DarkTemplarUnit::micro()
{
#ifdef __NON_IMPLEMENTE__
    BWAPI::Broodwar->printf("DarkTemplarUnit::micro non impl�ment� !");
#endif
}

void DarkTemplarUnit::check()
{
}

bool DarkTemplarUnit::canHit(BWAPI::Unit* enemy)
{
#ifdef __NON_IMPLEMENTE__
    BWAPI::Broodwar->printf("DarkTemplarUnit::canHit non impl�ment� !");
#endif
    return false;
}

int DarkTemplarUnit::getTimeToAttack()
{
#ifdef __NON_IMPLEMENTE__
    BWAPI::Broodwar->printf("DarkTemplarUnit::getTimeToAttack non impl�ment� !");
#endif
    return 0;
}

BWAPI::UnitType* DarkTemplarUnit::getListPriorite()
{
    return DarkTemplarUnit::listPriorite;
}

std::set<BWAPI::UnitType> DarkTemplarUnit::getUnitsPrio()
{
    return DarkTemplarUnit::setUnitsPrio;
}