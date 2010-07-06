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

bool CorsairUnit::canHit(BWAPI::Unit* enemy)
{
    BWAPI::Broodwar->printf("CorsairUnit::canHit non impl�ment� !");
    return false;
}