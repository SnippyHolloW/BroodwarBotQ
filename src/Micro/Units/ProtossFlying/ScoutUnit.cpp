#include "ScoutUnit.h"

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