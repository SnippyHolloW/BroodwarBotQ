#include "ObserverUnit.h"

ObserverUnit::ObserverUnit(BWAPI::Unit* u, UnitsGroup* ug):FlyingUnit(u, ug)
{
}

ObserverUnit::~ObserverUnit()
{
}

void ObserverUnit::micro()
{
    BWAPI::Broodwar->printf("ObserverUnit::micro non impl�ment� !");
}

bool ObserverUnit::canHit(BWAPI::Unit* enemy)
{
    BWAPI::Broodwar->printf("ObserverUnit::canHit non impl�ment� !");
    return false;
}

int ObserverUnit::getTimeToAttack()
{
    return 0;
}