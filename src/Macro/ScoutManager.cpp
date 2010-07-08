#include <BWTA.h>
#include <ScoutManager.h>


using namespace BWAPI;
ScoutManager::ScoutManager( )
{
	regions = & Regions::Instance();
	microManager = & MicroManager::Instance();
	to_remove = false;
}

ScoutManager::~ScoutManager( )
{
}

void ScoutManager::update()
{
}

std::string ScoutManager::getName() const
{
	return "Scout Manager";
}

void ScoutManager::scoutAllEnemies()
{
	// TODO
}

void ScoutManager::counterWall()
{
	// TODO
	// se placer ou construire a l'endroit du wall
	// pour photon ensuite ?
}

void ScoutManager::counterBuild()
{
	// TODO
	// En placant le drone aux endroits de construction.
	// Si terran, attaquer le scv qui construit
}

void ScoutManager::harassWorkers()
{
	// TODO
	// hit and run dans les drones aux min
}

void ScoutManager::checkEmptyXP()
{
	//TODO
}



////////////////////////////NEW SECTION

void ScoutManager::onUnitCreate(BWAPI::Unit* unit){
	if(BWAPI::Broodwar->self()->supplyUsed() == 18 && unit->getType().isWorker() && !regions->EnemyFound()){
#ifdef __DEBUG__LOUIS
		BWAPI::Broodwar->printf("gotta find the enemy, ScoutManager created the objective");
#endif
		findEnemy();
	}
}


void ScoutManager::findEnemy(){
	//Create a new scoutGoal 
	pGoal goal = pGoal(new ScoutGoal());
	pSubgoal sb;

	//Scout the different possible bases
	BWTA::BaseLocation * myStartLocation = BWTA::getStartLocation(BWAPI::Broodwar->self());
	std::set<BWTA::BaseLocation*> path = BWTA::getStartLocations();
		
	for(std::set<BWTA::BaseLocation*>::iterator p=path.begin();p!=path.end();p++){
		if( (*p) != myStartLocation){
		sb=pSubgoal(new SeeSubgoal(SL_AND, (*p)->getPosition()));
		goal->addSubgoal(sb);
		}
	}
	sb=pSubgoal(new FindSubgoal(SL_OR));
	goal->addSubgoal(sb);

	//Find the appropriate UnitsGroup
	
	//Select a worker
	UnitsGroup* ug;	
	double minDist=999999;
	double curDist=0;
	
		//Check over all the already created unitsGroup which one is near the first subgoal to accomplish
		//TODO

		
	//NO unitsgroup already found, must create a new one
	ug = new UnitsGroup();	
	for each(Unit* u in Broodwar->getAllUnits()){
		if (u->getPlayer()==Broodwar->self()&&u->getType().isWorker()&& !(u->isConstructing())){
			ug->takeControl(u);
			break;
		}
	}

	//Check if the unitsGroup is not empty else Segfault ?
	if (ug->getUnits()->size() != 0) {
	//TOCHECK
		ug->addGoal(goal);
		microManager->unitsgroups.push_back(ug);
		//	Broodwar->printf("Unit found, goal attributed");
	}else{
		Broodwar->printf("Could not find an appropriate unit for this scout goal");
		Broodwar->printf("Problem...");
	}

}

void ScoutManager::exploreRegion(BWTA::Region* region){
}
/*
	BWTA::Polygon polygon = region->getPolygon();
	std::list<Position> to_see;
	bool insert=true;
	for(std::vector<Position>::iterator it = polygon.begin(); it != polygon.end(); ++it){
		for(std::list<Position>::iterator it_to_see = to_see.begin(); it_to_see != to_see.end(); ++it_to_see){
			if((*it_to_see).getDistance( (*it) ) <= BWAPI::UnitTypes::Protoss_Probe.sightRange())
				insert=false;
		}
		if (insert) {
			to_see.push_back(*it);
		}
		insert=true;
	}

	if(to_see.size() > 0){
		//Create the goal !
		pGoal goal = pGoal(new ScoutGoal(SP_EXPLOREREGION));
		double curDist;
		double maxDist=0;
		BWAPI::Position precPos=to_see.front();
		BWAPI::Position chosePos;
		goal->addSubgoal(pSubgoal(new Subgoal(ST_VIEW,SC_ONCE, SL_AND, to_see.front())));
		to_see.pop_front();
		int size = to_see.size();
		while(size > 0){
			
			for(std::list<Position>::iterator it = to_see.begin(); it != to_see.end(); ++it){
				curDist = it->getDistance(precPos);
				if(curDist > maxDist){
					maxDist=curDist;
					chosePos = (*it);
				}
			}
		precPos = chosePos;
		goal->addSubgoal(pSubgoal(new Subgoal(ST_VIEW,SC_ONCE, SL_AND, chosePos)));
		to_see.remove(chosePos);
		size --;
		maxDist=0;
		}
		
		this->scoutGoals.push_back(goal);
		BWAPI::Broodwar->printf("Goal to explore the base created");
	}
	

}
*/
				//TOCHECK : I use a protoss_probe vision to explore the region
	

/*	
	std::list<Position>::iterator pos;
	BWTA::Polygon polygon = (*region).getPolygon();
	std::list<Position> to_see;
	for(std::vector<Position>::iterator it = polygon.begin(); it != polygon.end(); ++it)
		to_see.push_back((*it));
	
	//Select a first position added to the objectives
	//TODO select a not yet seen position
	Position current_pos= polygon.getNearestPoint(eStartLocation->getPosition());
	objectives.push_back(current_pos);
	to_see.remove(current_pos);

	double max_dist=0;
	double test_dist=0;
	Position current_target;
	int size=to_see.size();
	while(size >0){
		max_dist=0;
		current_target=current_pos;
		//Find the farthest point of current_pos
		for(pos = to_see.begin(); pos != to_see.end(); ++pos){
			test_dist=(*pos).getApproxDistance(current_pos);
			if(test_dist > max_dist){
				max_dist=test_dist;
				current_target = (*pos);
			}
		}
		Broodwar->printf("ou ? x %d  y %d", current_target.x(), current_target.y());
		add(current_target);
		Broodwar->drawCircleMap(current_target.x(),current_target.y(),200,Colors::Blue);
		Broodwar->drawCircle(CoordinateType::Screen,current_target.x(), current_target.y(),200,Colors::Yellow, true);
	//	void drawCircleMap(int x, int y, int radius, Color color = Color(BWAPI::Colors::Green), bool isSolid = false); 
		objectives.push_back(current_target);
		current_pos=current_target;
		to_see.remove(current_pos);
		size--;
	}
	Broodwar->printf("Nombre d'objectifs : %d", objectives.size());
	*/

void ScoutManager::onUnitShow(BWAPI::Unit* unit){
	if(unit->getPlayer()->isEnemy(BWAPI::Broodwar->self()) && to_remove == false){
		to_remove = true;
		//enemy found, must explore his base
		this->exploreRegion(BWTA::getRegion(unit->getTilePosition()));
	}
}