#include "DarkTemplarUnit.h"

BWAPI::UnitType DarkTemplarUnit::listPriorite[NUMBER_OF_PRIORITY] = {BWAPI::UnitTypes::Protoss_High_Templar,
                                                                BWAPI::UnitTypes::Protoss_Dragoon,
                                                                BWAPI::UnitTypes::Protoss_Reaver,
                                                                BWAPI::UnitTypes::Protoss_Zealot,
                                                                BWAPI::UnitTypes::Protoss_Probe};

DarkTemplarUnit::DarkTemplarUnit(BWAPI::Unit* u, UnitsGroup* ug):GroundUnit(u, ug)
{
}

DarkTemplarUnit::~DarkTemplarUnit()
{
}

void DarkTemplarUnit::micro()
{
    BWAPI::Broodwar->printf("DarkTemplarUnit::micro non impl�ment� !");
}

bool DarkTemplarUnit::canHit(BWAPI::Unit* enemy)
{
    BWAPI::Broodwar->printf("DarkTemplarUnit::canHit non impl�ment� !");
    return false;
}

int DarkTemplarUnit::getTimeToAttack()
{
    BWAPI::Broodwar->printf("DarkTemplarUnit::getTimeToAttack non impl�ment� !");
    return 0;
}

BWAPI::UnitType* DarkTemplarUnit::getListPriorite()
{
    return DarkTemplarUnit::listPriorite;
}