#include "HighTemplarUnit.h"

HighTemplarUnit::HighTemplarUnit(BWAPI::Unit* u, UnitsGroup* ug):SpecialUnit(u, ug)
{
}

HighTemplarUnit::~HighTemplarUnit()
{
}

void HighTemplarUnit::micro()
{
    BWAPI::Broodwar->printf("HighTemplarUnit::micro non impl�ment� !");
}

bool HighTemplarUnit::canHit(BWAPI::Unit* enemy)
{
    BWAPI::Broodwar->printf("HighTemplarUnit::canHit non impl�ment� !");
    return false;
}