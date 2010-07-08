#include "DarkTemplarUnit.h"

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