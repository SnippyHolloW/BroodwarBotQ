#include "MutaliskUnit.h"

std::set<BWAPI::UnitType> MutaliskUnit::setPrio;

MutaliskUnit::MutaliskUnit(BWAPI::Unit* u, UnitsGroup* ug)
: FlyingUnit(u, ug)
{
    if (setPrio.empty())
    {
        setPrio.insert(BWAPI::UnitTypes::Protoss_High_Templar);
    }
}

MutaliskUnit::~MutaliskUnit()
{
}

void MutaliskUnit::micro()
{
#ifdef __NON_IMPLEMENTE__
    BWAPI::Broodwar->printf("MutaliskUnit::micro non impl�ment� !");
#endif
}

void MutaliskUnit::check()
{
}

bool MutaliskUnit::canHit(BWAPI::Unit* enemy)
{
#ifdef __NON_IMPLEMENTE__
    BWAPI::Broodwar->printf("MutaliskUnit::canHit non impl�ment� !");
#endif
    return false;
}

int MutaliskUnit::getTimeToAttack()
{
#ifdef __NON_IMPLEMENTE__
    BWAPI::Broodwar->printf("MutaliskUnit::getTimeToAttack non impl�ment� !");
#endif
    return 0;
}

std::set<BWAPI::UnitType> MutaliskUnit::getSetPrio()
{
    return MutaliskUnit::setPrio;
}