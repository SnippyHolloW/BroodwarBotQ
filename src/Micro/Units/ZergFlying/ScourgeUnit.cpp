#include "ScourgeUnit.h"

ScourgeUnit::ScourgeUnit(BWAPI::Unit* u, UnitsGroup* ug):FlyingUnit(u, ug)
{
}

ScourgeUnit::~ScourgeUnit()
{
}

void ScourgeUnit::micro()
{
    BWAPI::Broodwar->printf("ScourgeUnit::micro non impl�ment� !");
}

bool ScourgeUnit::canHit(BWAPI::Unit* enemy)
{
    BWAPI::Broodwar->printf("ScourgeUnit::canHit non impl�ment� !");
    return false;
}

int ScourgeUnit::getTimeToAttack()
{
    return 0;
}