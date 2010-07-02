#include "ArchonUnit.h"

ArchonUnit::ArchonUnit(BWAPI::Unit* u, UnitsGroup* ug):GroundUnit(u, ug)
{
}

ArchonUnit::~ArchonUnit()
{
}

void ArchonUnit::micro()
{
    BWAPI::Broodwar->printf("ArchonUnit::micro non impl�ment� !");
}

const std::list<BWAPI::UnitType> ArchonUnit::getListePrio() const
{
    return listPriorite;
}


bool ArchonUnit::canHit(BWAPI::Unit* enemy)
{
    BWAPI::Broodwar->printf("ArchonUnit::canHit non impl�ment� !");
    return false;
}