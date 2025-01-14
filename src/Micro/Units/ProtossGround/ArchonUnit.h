#pragma once

#include "Micro/Units/GroundUnit.h"
#include <BWAPI.h>

class ArchonUnit : public GroundUnit
{
protected:
    static std::set<BWAPI::UnitType> setPrio;
    virtual bool decideToFlee();
public:
    ArchonUnit(BWAPI::Unit* u);
    virtual ~ArchonUnit();
    virtual void micro();
    virtual void check();
    virtual int getAttackDuration();
    virtual std::set<BWAPI::UnitType> getSetPrio();
};