#include "ShuttleUnit.h"

ShuttleUnit::ShuttleUnit(BWAPI::Unit* u, UnitsGroup* ug):FlyingUnit(u, ug)
{
}

ShuttleUnit::~ShuttleUnit()
{
}

void ShuttleUnit::micro()
{
    BWAPI::Broodwar->printf("ShuttleUnit::micro non impl�ment� !");
}

bool ShuttleUnit::canHit(BWAPI::Unit* enemy)
{
    return false;
}

int ShuttleUnit::getTimeToAttack()
{
    BWAPI::Broodwar->printf("ShuttleUnit::getTimeToAttack non impl�ment� !");
    return 0;
}