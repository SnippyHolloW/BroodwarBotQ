#include "ScoutObjectives.h"
#include <iostream>
using namespace BWAPI;


ScoutObjectives::ScoutObjectives():bEnnemy_found(false)
{

}

ScoutObjectives::~ScoutObjectives(){

}

bool ScoutObjectives::ennemy_found() const{
 return bEnnemy_found;
}

void ScoutObjectives::set_ennemy_found(bool b){
	bEnnemy_found=b;
}

std::list<Position> ScoutObjectives::get_Objectives(){
std::list<Position> temp;
	for each (Position pos in objectives){
		temp.push_back(pos);
		assigned_objectives.push_back(pos);
	}
	objectives.clear();
return temp;
}





void ScoutObjectives::onUnitShow(BWAPI::Unit* unit){

	if(unit->getType().isResourceDepot() && ! this->ennemy_found()){
		this->set_ennemy_found(true);
		//Find the right base location
		std::set<BWTA::BaseLocation*> res = BWTA::getStartLocations();
		for(std::set<BWTA::BaseLocation* >::iterator b = res.begin(); b!= res.end(); ++b){
			if( (*b)->getTilePosition() == unit->getTilePosition() ){
				eStartLocation = (*b);
				break;
			}
		}
		
		if(eStartLocation == NULL)
			Broodwar -> printf("eStartLocation is NULL, problem...");
		Broodwar->printf("Ennemy main base found, waiting for objectives");
		BWTA::Region* region = eStartLocation->getRegion();

		explore_region(region);
		
	}
		//We assume that if the ennemy was not spotted and we find a ResourceDepot, then it is the main base : requires fast scout
}


bool ScoutObjectives::got_objectives(){

	return objectives.size() > 0;
}

void ScoutObjectives::explore_region(BWTA::Region* region){
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
}


void ScoutObjectives::accomplished(BWAPI::Position p){


this->assigned_objectives.remove(p);
}

void ScoutObjectives::add(Position p){
	to_display.push_back(p);
}

void ScoutObjectives::show(){
	for each (Position pos in to_display){
		Broodwar->drawCircleMap(pos.x(),pos.y(),20,Colors::Blue);
	}
}