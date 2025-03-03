#pragma once
#include <BWAPI.h>
#include <BWTA.h>
#include <windows.h>
#include "Defines.h"
#include "Micro/Formations.h"
#include "Intelligence/EUnitsFilter.h"
#include "Regions/MapManager.h"
#include "Regions/Regions.h"
#include "Micro/UnitsGroup.h"
#include "Micro/Goals/GoalManager.h"
#include "Macro/UnitGroupManager.h"
#include "Macro/Arbitrator.h"

static bool analyzed;
static bool analysis_just_finished;
static BWTA::Region* home;
static BWTA::Region* enemy_base;
DWORD WINAPI AnalyzeThread();

class MicroAIModule : public BWAPI::AIModule
{
public:	    
    EUnitsFilter* eUnitsFilter;
    MapManager* mapManager;
    Regions* regions;
    UnitGroupManager * unitGroupManager;
    Arbitrator::Arbitrator<BWAPI::Unit*,double> arbitrator;
    GoalManager* goalManager;
    bool enemiesFound;
    BWAPI::TilePosition eStartLocation;
    MicroAIModule();
    ~MicroAIModule();
	virtual void onStart();
	virtual void onEnd(bool isWinner);
	virtual void onFrame();
	//virtual void onRemove(BWAPI::Unit* unit);
	virtual void onSendText(std::string text);
    virtual void onUnitCreate(Unit* unit);
    virtual void onUnitDestroy(Unit* unit);
    virtual void onUnitShow(BWAPI::Unit* unit);
	virtual void onUnitHide(BWAPI::Unit* unit);
	void showStats(); //not part of BWAPI::AIModule
	void showPlayers();
	void showForces();
	std::map<BWAPI::Unit*,BWAPI::UnitType> buildings;
};