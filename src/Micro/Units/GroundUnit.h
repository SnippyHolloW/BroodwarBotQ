#pragma once

#include "BayesianUnit.h"

class GroundUnit : public BayesianUnit
{
    public:
        GroundUnit(BWAPI::Unit* u, UnitsGroup* ug);
        ~GroundUnit();
        virtual void micro() = 0;
        virtual const std::list<BWAPI::UnitType> getListePrio() const = 0;
        virtual bool canHit(BWAPI::Unit* enemy) = 0;
        virtual int damagesOn(BWAPI::Unit* enemy);
};