#include "ReaverUnit.h"

BWAPI::UnitType ReaverUnit::listPriorite[NUMBER_OF_PRIORITY] = {BWAPI::UnitTypes::Protoss_High_Templar,
                                                                BWAPI::UnitTypes::Protoss_Dragoon,
                                                                BWAPI::UnitTypes::Protoss_Reaver,
                                                                BWAPI::UnitTypes::Protoss_Zealot,
                                                                BWAPI::UnitTypes::Protoss_Probe};

ReaverUnit::ReaverUnit(BWAPI::Unit* u, UnitsGroup* ug):GroundUnit(u, ug)
{
}

ReaverUnit::~ReaverUnit()
{
}

void ReaverUnit::micro()
{
#ifdef __NON_IMPLEMENTE__
    BWAPI::Broodwar->printf("ReaverUnit::micro non impl�ment� !");
#endif
}

void ReaverUnit::check()
{
}

bool ReaverUnit::canHit(BWAPI::Unit* enemy)
{
#ifdef __NON_IMPLEMENTE__
    BWAPI::Broodwar->printf("ReaverUnit::canHit non impl�ment� !");
#endif
    return false;
}

int ReaverUnit::getTimeToAttack()
{
#ifdef __NON_IMPLEMENTE__
    BWAPI::Broodwar->printf("ReaverUnit::getTimeToAttack non impl�ment� !");
#endif
    return 0;
}

BWAPI::UnitType* ReaverUnit::getListPriorite()
{
    return ReaverUnit::listPriorite;
}