#pragma once
#include <BWAPI.h>
#include <BWTA.h>
#include <windows.h>
#include <algorithm>
#include "WalkTilePosition.h"

#define BU_EVAL_FREQ 6
#define UNIT_DEBUG 1

class BattleUnit
{
    friend void baseMicro();
    friend void zealotMicro();
protected:
#ifdef UNIT_DEBUG
    std::string _unitType;
#endif
    void drawVelocityArrow();
    void drawPath();
    void drawWalkability();
    void drawEnclosingBox();
    void drawTarget();
    std::vector<WalkTilePosition> _path;
    std::vector<BWAPI::Position> _ppath;
    static void pathFind(std::vector<WalkTilePosition>& path, const BWAPI::Position& p_start, const BWAPI::Position& p_end);
    unsigned int _tick;
    bool inline tick();

public:
	BWAPI::Unit* unit;
    BWAPI::Unit* targetEnemy;
	BWAPI::Position target; // display debug purpose
	int timeIdle; // hack to remove soon... evite le conflit avec la reussite d'objectif dans le test UnitsGroup::keepDistance().
	              // Cette variable sera inutile avec le flocking.
	              // Ou avec un Timer (TimeManager soon ready !)

	BattleUnit(BWAPI::Unit* unit);
    ~BattleUnit();
    void attackMove(const BWAPI::Position& p);
    bool operator == (const BattleUnit& bu) const;
    void update();
    virtual void onUnitDestroy(BWAPI::Unit* u);
    virtual void onUnitShow(BWAPI::Unit* u);
    virtual void onUnitHide(BWAPI::Unit* u);

    BWAPI::Unit* findClosestEnemy(std::set<BWAPI::Unit*> &enemies); // Function to remove ?
    virtual int damagesOn(BWAPI::Unit* enemy) = 0;
};
