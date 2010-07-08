#include "ArbiterUnit.h"

ArbiterUnit::ArbiterUnit(BWAPI::Unit* u, UnitsGroup* ug):SpecialUnit(u, ug)
{
}

ArbiterUnit::~ArbiterUnit()
{
}

void ArbiterUnit::micro()
{
    BWAPI::Broodwar->printf("ArbiterUnit::micro non impl�ment� !");
}

bool ArbiterUnit::canHit(BWAPI::Unit* enemy)
{
    BWAPI::Broodwar->printf("ArbiterUnit::canHit non impl�ment� !");
    return false;
}

int ArbiterUnit::getTimeToAttack()
{
    BWAPI::Broodwar->printf("ArbiterUnit::getTimeToAttack non impl�ment� !");
    return 0;
}