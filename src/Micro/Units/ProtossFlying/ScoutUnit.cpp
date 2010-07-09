#include "ScoutUnit.h"

BWAPI::UnitType ScoutUnit::listPriorite[NUMBER_OF_PRIORITY] = {BWAPI::UnitTypes::Protoss_High_Templar,
                                                                BWAPI::UnitTypes::Protoss_Dragoon,
                                                                BWAPI::UnitTypes::Protoss_Reaver,
                                                                BWAPI::UnitTypes::Protoss_Zealot,
                                                                BWAPI::UnitTypes::Protoss_Probe};

ScoutUnit::ScoutUnit(BWAPI::Unit* u, UnitsGroup* ug):FlyingUnit(u, ug)
{
}

ScoutUnit::~ScoutUnit()
{
}

void ScoutUnit::micro()
{
    BWAPI::Broodwar->printf("ScoutUnit::micro non impl�ment� !");
}

bool ScoutUnit::canHit(BWAPI::Unit* enemy)
{
    BWAPI::Broodwar->printf("ScoutUnit::canHit non impl�ment� !");
    return false;
}

int ScoutUnit::getTimeToAttack()
{
    BWAPI::Broodwar->printf("ScoutUnit::getTimeToAttack non impl�ment� !");
    return 0;
}

BWAPI::UnitType* ScoutUnit::getListPriorite()
{
    return ScoutUnit::listPriorite;
}