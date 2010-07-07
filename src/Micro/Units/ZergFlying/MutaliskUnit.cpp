#include "MutaliskUnit.h"

MutaliskUnit::MutaliskUnit(BWAPI::Unit* u, UnitsGroup* ug):FlyingUnit(u, ug)
{
}

MutaliskUnit::~MutaliskUnit()
{
}

void MutaliskUnit::micro()
{
    BWAPI::Broodwar->printf("MutaliskUnit::micro non impl�ment� !");
}

bool MutaliskUnit::canHit(BWAPI::Unit* enemy)
{
    BWAPI::Broodwar->printf("MutaliskUnit::canHit non impl�ment� !");
    return false;
}