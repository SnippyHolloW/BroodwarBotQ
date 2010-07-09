#include "ArchonUnit.h"

BWAPI::UnitType ArchonUnit::listPriorite[NUMBER_OF_PRIORITY] = {BWAPI::UnitTypes::Protoss_High_Templar,
                                                                BWAPI::UnitTypes::Protoss_Dragoon,
                                                                BWAPI::UnitTypes::Protoss_Reaver,
                                                                BWAPI::UnitTypes::Protoss_Zealot,
                                                                BWAPI::UnitTypes::Protoss_Probe};

ArchonUnit::ArchonUnit(BWAPI::Unit* u, UnitsGroup* ug):GroundUnit(u, ug)
{
}

ArchonUnit::~ArchonUnit()
{
}

void ArchonUnit::micro()
{
    BWAPI::Broodwar->printf("ArchonUnit::micro non impl�ment� !");
}

bool ArchonUnit::canHit(BWAPI::Unit* enemy)
{
    BWAPI::Broodwar->printf("ArchonUnit::canHit non impl�ment� !");
    return false;
}

int ArchonUnit::getTimeToAttack()
{
    BWAPI::Broodwar->printf("ArchonUnit::getTimeToAttack non impl�ment� !");
    return 0;
}

BWAPI::UnitType* ArchonUnit::getListPriorite()
{
    return ArchonUnit::listPriorite;
}