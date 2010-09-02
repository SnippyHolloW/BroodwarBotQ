#include "CarrierUnit.h"

BWAPI::UnitType CarrierUnit::listPriorite[NUMBER_OF_PRIORITY] = {BWAPI::UnitTypes::Protoss_High_Templar,
                                                                BWAPI::UnitTypes::Protoss_Dragoon,
                                                                BWAPI::UnitTypes::Protoss_Reaver,
                                                                BWAPI::UnitTypes::Protoss_Zealot,
                                                                BWAPI::UnitTypes::Protoss_Probe};

CarrierUnit::CarrierUnit(BWAPI::Unit* u, UnitsGroup* ug):FlyingUnit(u, ug)
{
}

CarrierUnit::~CarrierUnit()
{
}

void CarrierUnit::micro()
{
#ifdef __NON_IMPLEMENTE__
    BWAPI::Broodwar->printf("CarrierUnit::micro non impl�ment� !");
#endif
}

void CarrierUnit::check()
{
}

bool CarrierUnit::canHit(BWAPI::Unit* enemy)
{
#ifdef __NON_IMPLEMENTE__
    BWAPI::Broodwar->printf("CarrierUnit::canHit non impl�ment� !");
#endif
    return false;
}

int CarrierUnit::getTimeToAttack()
{
#ifdef __NON_IMPLEMENTE__
    BWAPI::Broodwar->printf("CarrierUnit::getTimeToAttack non impl�ment� !");
#endif
    return 0;
}

BWAPI::UnitType* CarrierUnit::getListPriorite()
{
    return CarrierUnit::listPriorite;
}