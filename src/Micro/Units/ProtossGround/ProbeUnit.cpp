#include "ProbeUnit.h"

ProbeUnit::ProbeUnit(BWAPI::Unit* u, UnitsGroup* ug):GroundUnit(u, ug)
{
}

ProbeUnit::~ProbeUnit()
{
}

void ProbeUnit::micro()
{
    BWAPI::Broodwar->printf("ProbeUnit::micro non impl�ment� !");
}

bool ProbeUnit::canHit(BWAPI::Unit* enemy)
{
    //BWAPI::Broodwar->printf("ProbeUnit::canHit non impl�ment� !");
    return false;
}

int ProbeUnit::getTimeToAttack()
{
    //BWAPI::Broodwar->printf("ProbeUnit::getTimeToAttack non impl�ment� !");
    return 0;
}