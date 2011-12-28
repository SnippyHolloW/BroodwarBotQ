#pragma once
#include "BWAPI.h"
#include "Utils/CSingleton.h"
#include "serialized_tables.h"
#include <vector>
#include <set>
#include <string>
#include "Defines.h"

/***
    ***********************
    *openingsProba content*
    ***********************
		|=============|
		|Ben's labels:| (extracted with rules)
		|=============|

Terran openings, in order (in the vector):
 - Bio
 - TwoFactory
 - VultureHarass
 - SiegeExpand
 - Standard
 - FastDropship
 - Unknown

Protoss openings, in order (in the vector):
 - FastLegs
 - FastDT
 - FastObs
 - ReaverDrop
 - Carrier
 - FastExpand
 - Unknown

Zerg openings, in order (in the vector):
 - TwoHatchMuta
 - ThreeHatchMuta
 - HydraRush
 - Standard
 - HydraMass
 - Lurker
 - Unknown

		|==========|
		|My labels:| (extracted by clustering)
		|==========|

Terran openings, in order (in the vector):
 - bio
 - rax_fe
 - two_facto
 - vultures
 - drop
 - unknown

Protoss openings, in order (in the vector):
 - two_gates
 - fast_dt
 - templar
 - speedzeal
 - corsair
 - nony
 - reaver_drop
 - unknown

Zerg openings, in order (in the vector):
 - fast_mutas
 - mutas
 - lurkers
 - hydras
 - unknown
*/

class ETechEstimator : public CSingleton<ETechEstimator>
{
    friend class CSingleton<ETechEstimator>;
    ETechEstimator();
    ~ETechEstimator();
	serialized_tables st;
	serialized_tables TvP; // tmp table to handle random
	serialized_tables ZvP; // tmp table to handle random
	bool tableLoaded;
	void loadTable(const char* tname);
	std::vector<long double> openingsProbas; // see the big fat comment above
	std::set<BWAPI::Unit*> buildingsSeen; 
	std::set<int> buildingsTypesSeen;
	bool notFirstOverlord;
	std::set<BWAPI::UnitType> _alreadySawUnitTypes;
	inline bool alreadySaw(BWAPI::UnitType ut);
	bool insertBuilding(BWAPI::Unit* u);
	bool insertBuilding(BWAPI::UnitType ut);
    void computeDistribOpenings(int time);
	inline void useDistribOpenings();
	inline bool testBuildTreePossible(int indBuildTree,
		const std::set<int>& setObs);
public:
	const std::vector<long double>& getOpeningsProbas() const;
	bool hasInfered;
	void onUnitDestroy(BWAPI::Unit* u);
	void onUnitShow(BWAPI::Unit* u);
	void onUnitHide(BWAPI::Unit* u);
#ifdef __DEBUG__
	void onFrame();
#endif
};