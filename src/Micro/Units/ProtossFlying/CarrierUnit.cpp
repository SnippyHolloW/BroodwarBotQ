#include "CarrierUnit.h"

CarrierUnit::CarrierUnit(BWAPI::Unit* u, UnitsGroup* ug):FlyingUnit(u, ug)
{
}

CarrierUnit::~CarrierUnit()
{
}

void CarrierUnit::micro()
{
    BWAPI::Broodwar->printf("CarrierUnit::micro non impl�ment� !");
}

bool CarrierUnit::canHit(BWAPI::Unit* enemy)
{
    BWAPI::Broodwar->printf("CarrierUnit::canHit non impl�ment� !");
    return false;
}

int CarrierUnit::getTimeToAttack()
{
    BWAPI::Broodwar->printf("CarrierUnit::getTimeToAttack non impl�ment� !");
    return 0;
}