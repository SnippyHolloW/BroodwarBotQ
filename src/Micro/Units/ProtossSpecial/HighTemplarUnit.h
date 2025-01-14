#pragma once

#include "Micro/Units/SpecialUnit.h"
#include <BWAPI.h>
#include "Regions/MapManager.h"

class HighTemplarUnit : public SpecialUnit
{
protected:
    MapManager* _mapManager;
    int _lastStormFrame;
    BWAPI::Position _lastStormPos;
    static int lastStormableUnitsUpdateFrame;
    int _mergingFrame;
	BWAPI::Position _bestStormPos;
	BWAPI::Position _bestFartherStormPos;
public:
    HighTemplarUnit(BWAPI::Unit* u);
    virtual ~HighTemplarUnit();
    std::pair<BWAPI::Position, int> bestStormPos();
    virtual void micro();
    virtual void check();
    virtual std::set<BWAPI::UnitType> getSetPrio();
    static std::map<BWAPI::Unit*, BWAPI::Position> stormableUnits;
};