#include "CorsairUnit.h"

CorsairUnit::CorsairUnit(BWAPI::Unit* u, UnitsGroup* ug):FlyingUnit(u, ug)
{
}

CorsairUnit::~CorsairUnit()
{
}

void CorsairUnit::micro()
{
    BWAPI::Broodwar->printf("CorsairUnit::micro non impl�ment� !");
}

const std::list<BWAPI::UnitType> CorsairUnit::getListePrio() const
{
    return listPriorite;
}

bool CorsairUnit::canHit(BWAPI::Unit* enemy)
{
    BWAPI::Broodwar->printf("CorsairUnit::canHit non impl�ment� !");
    return false;
}