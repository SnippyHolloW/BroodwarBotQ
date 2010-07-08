#include "ReaverUnit.h"

ReaverUnit::ReaverUnit(BWAPI::Unit* u, UnitsGroup* ug):GroundUnit(u, ug)
{
}

ReaverUnit::~ReaverUnit()
{
}

void ReaverUnit::micro()
{
    BWAPI::Broodwar->printf("ReaverUnit::micro non impl�ment� !");
}

bool ReaverUnit::canHit(BWAPI::Unit* enemy)
{
    BWAPI::Broodwar->printf("ReaverUnit::canHit non impl�ment� !");
    return false;
}

int ReaverUnit::getTimeToAttack()
{
    BWAPI::Broodwar->printf("ReaverUnit::getTimeToAttack non impl�ment� !");
    return 0;
}