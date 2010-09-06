#include <DefenseManager.h>
#include <BorderManager.h>
#include "BaseManager.h"
#include "Base.h"
#include "DefendBaseGroundGoal.h"
#include <map>
#include "WarManager.h"


using namespace BWTA;
DefenseManager::DefenseManager()
{
  this->arbitrator = NULL;
}
void DefenseManager::setDependencies()
{
  this->arbitrator= & Arbitrator::Arbitrator<BWAPI::Unit*,double>::Instance();
  this->borderManager = & BorderManager::Instance();
  this->warManager = & WarManager::Instance();
}

void DefenseManager::checkDefenses(){
	//Check on all bases that if we need to defend it, then it is defended
	std::set<Base*> myBases =  BaseManager::Instance().getAllBases();
	for(std::set<Base*>::iterator it = myBases.begin(); it != myBases.end(); ++it){
		bool toDef=true;
		
		
		if((*it)->chokeToDef != NULL ) {
			//Should the chokepoint of this base be defended ?

			//Check if the next region contains a base of ours or not
			BWTA::Region* nextRegion;
			std::pair<Region*,Region*> regions = (*it)->chokeToDef->getRegions();
			if(regions.first == (*it)->getBaseLocation()->getRegion()){
				nextRegion = regions.second;
			} else {
				nextRegion = regions.first;
			}
			
			//Search nextRegion in our bases
			for(std::set<Base*>::iterator search = myBases.begin(); search != myBases.end(); ++search){
				if( (*search)->getBaseLocation()->getRegion() == nextRegion ){
					//The chokepoint does not need to be defended because the next Region is a base of ours
					toDef=false;
					break;
				}
			}
		}

		//If the field chokeToDef is NULL we consider we have to defend the base in the middle
		checkGroundDefense((*it),toDef);


	}

}

void DefenseManager::checkGroundDefense(Base * b, bool toDef){

	//Find the unitsGroup that must defend this base against ground attack
#ifdef __DEBUG__LOUIS__
	assert(this->groundDefenders.count(b) == 1);
#endif
	UnitsGroup * ug = (*this->groundDefenders.find(b)).second;


	//Check if they must defend at middle or at chokepoint
	if(b->chokeToDef != NULL){
		//If they must defend the chokepoint check if their DefendBaseGroundGoal is accomplished (enough units)
		if(toDef){
			if(ug->getLastGoal() != NULL){
				if( ug->getLastGoal()->getStatus() == GS_NOT_ENOUGH_UNITS ){
					//We need more units
					
					//Set bid on 1 unit until we have enough and record the unitsgroup that needed it

					std::set<BWAPI::Unit *> allUnits = BWAPI::Broodwar->getAllUnits();
					for(std::set<BWAPI::Unit * >::iterator selection = allUnits.begin() ; selection != allUnits.end() ; ++selection){
						if((*selection)->getType() == BWAPI::UnitTypes::Protoss_Zealot || (*selection)->getType() == BWAPI::UnitTypes::Protoss_Dragoon ){
							this->requesters.push_back(ug);
							this->arbitrator->setBid(this, (*selection), 60);
							break;
						}
					}

				} else {	
				//Nothing to do, the defense at this chokepoint is correct
				
				}
			}
		} else {
			//We do not need to defend
			if(ug->size() > 0){
				//We must give back those units to the WarManager
				for(std::vector<pBayesianUnit>::iterator units = ((*ug).units).begin(); units != ((*ug).units).end(); ++ units){
					this->arbitrator->setBid(this,(*units)->unit, 0);
					ug->giveUpControl((*units)->unit);
				}
			}
		}
		
	} else {
		//If they must defend in the middle of the base 


		//TODO
	}
}



void DefenseManager::onOffer(std::set<BWAPI::Unit*> units)
{
	for(std::set<BWAPI::Unit*>::iterator u = units.begin(); u != units.end(); u++){
		
		if(this->requesters.size() != 0 ){
			this->arbitrator->accept(this, *u);
			this->requesters.front()->takeControl(*u);
			this->requesters.pop_front();

		} else {
			this->arbitrator->decline(this, *u, 0);
		}
	}
}

void DefenseManager::onRevoke(BWAPI::Unit* unit, double bid)
{
	for(std::map<Base *, UnitsGroup *>::iterator it = this->groundDefenders.begin(); it != this->groundDefenders.end(); ++it){
		for(std::vector<pBayesianUnit>::iterator u = (*it).second->units.begin(); u != (*it).second->units.end(); ++u ){
			if((*u)->unit == unit ){
				(*it).second->giveUpControl((*u)->unit);
			}
		}
	}

}

void DefenseManager::onRemoveUnit(BWAPI::Unit* unit)
{
	//Find the unit in the unitsGroup
	for(std::map<Base *, UnitsGroup *>::iterator it = this->groundDefenders.begin(); it != this->groundDefenders.end(); ++it){

		if( it->second->size() != 0 ){
			for(std::vector<pBayesianUnit>::iterator u = (*it).second->units.begin(); u != (*it).second->units.end(); ++u ){
				if((*u)->unit == unit ){
					(*it).second->getLastGoal()->setStatus(GS_IN_PROGRESS);
					(*it).second->giveUpControl((*u)->unit);
					return;
				}
			}
		}
	}

}

void DefenseManager::update()
{
	this->checkDefenses();

//update unitsgroups depending of the defenseManager
	for(std::map<Base *, UnitsGroup *>::iterator it = this->groundDefenders.begin(); it != this->groundDefenders.end(); ++it){
		it->second->update();
	}
}

void DefenseManager::addBase(Base * b){
#ifdef __DEBUG_LOUIS__
	BWAPI::Broodwar->printf("Appel � addBase");
#endif
	UnitsGroup * ug = new UnitsGroup();
#ifdef __DEBUG__LOUIS__
	assert(this->groundDefenders.count(b) == 0);//We must not have already the groundDefenders for this base
#endif
	Goal * g = new DefendBaseGroundGoal(ug,b);
	ug->addGoal(pGoal(g));
	this->groundDefenders.insert(std::make_pair(b,ug));

}

std::string DefenseManager::getName() const
{
  return "Defense Manager";
}

std::string DefenseManager::getShortName() const
{
  return "Def";
}