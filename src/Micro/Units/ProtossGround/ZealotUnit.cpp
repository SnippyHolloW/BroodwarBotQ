#include <PrecompiledHeader.h>
#include "Micro/Units/ProtossGround/ZealotUnit.h"
#include "Micro/UnitsGroup.h"
#include "Regions/MapManager.h"

using namespace std;
using namespace BWAPI;

ProbTables ZealotUnit::_sProbTables = ProbTables(UnitTypes::Protoss_Zealot.getID());

std::set<UnitType> ZealotUnit::setPrio;

ZealotUnit::ZealotUnit(Unit* u)
: GroundUnit(u, &_sProbTables)
{
    if (setPrio.empty())
    {
        setPrio.insert(UnitTypes::Protoss_Reaver);
        setPrio.insert(UnitTypes::Protoss_High_Templar);
        setPrio.insert(UnitTypes::Terran_Siege_Tank_Siege_Mode);
        setPrio.insert(UnitTypes::Terran_Siege_Tank_Tank_Mode);
        setPrio.insert(UnitTypes::Zerg_Hydralisk);
		setPrio.insert(UnitTypes::Zerg_Lurker);
		setPrio.insert(UnitTypes::Zerg_Defiler);
    }
    _fleeingDmg = 36; // one round of storm = 14
}

ZealotUnit::~ZealotUnit()
{
}

#ifdef __LEARNING_PROB_TABLES__
void ZealotUnit::initProbTables()
{
	_sProbTables = ProbTables(UnitTypes::Protoss_Zealot.getID());
}
#endif

int ZealotUnit::fightMove()
{
	if (Broodwar->getFrameCount() - _lastClickFrame <= Broodwar->getLatencyFrames())
		return 0;
    /// approach our target enemy if not in range and in our priority targets
    if (targetEnemy != NULL && targetEnemy->exists() && targetEnemy->isVisible() && targetEnemy->isDetected()
        && setPrio.count(targetEnemy->getType())
        && (targetEnemy->getDistance(_unitPos) > 45.0 || !inRange(targetEnemy)))
    {
		if (unit->getTarget() != targetEnemy)
	        unit->rightClick(targetEnemy);
        _lastClickFrame = Broodwar->getFrameCount();
        _lastMoveFrame = Broodwar->getFrameCount();
		_lastAttackFrame = Broodwar->getFrameCount();
        _fightMoving = true;
        return 1;
    }
    double dist = target.getDistance(_unitPos);
    /// approach out of range target
    if (oorTargetEnemy != NULL && oorTargetEnemy->exists() && oorTargetEnemy->isVisible() && targetEnemy->isDetected()
        && !inRange(oorTargetEnemy))
    {
		if (unit->getTarget() != oorTargetEnemy)
	        unit->rightClick(oorTargetEnemy);
        _lastClickFrame = Broodwar->getFrameCount();
        _lastMoveFrame = Broodwar->getFrameCount();
		_lastAttackFrame = Broodwar->getFrameCount();
        _fightMoving = true;
        return 2;
    }
    return 0;
}

bool ZealotUnit::decideToFlee()
{
	_fleeing = false;
	if (unit->getShields() < 5 && unit->isUnderAttack()
		&& !(targetEnemy && targetEnemy->exists() && targetEnemy->isVisible() && targetEnemy->isDetected()
		&& setPrio.count(targetEnemy->getType())))
		_fleeing = true;
    return _fleeing;
}

void ZealotUnit::updateTargetEnemy()
{
	/// oorTarget = closest in the setPrio
	oorTargetEnemy = NULL;
	double closest = DBL_MAX;
	for (map<Unit*, Position>::const_iterator it = _unitsGroup->enemies.begin();
		it != _unitsGroup->enemies.end(); ++it)
	{
		if (!it->first->exists() || !it->first->isVisible() || !it->first->isDetected() || it->first->getType().isFlyer())
            continue;
		if (it->first->isDefenseMatrixed() 
			|| it->first->isHallucination()
			|| it->first->isInvincible())
			continue;
        if (!it->first->getType().isFlyer()
			&& setPrio.count(it->first->getType())
			&& it->first->getDistance(_unitPos) < closest)
		{
			closest = it->first->getDistance(_unitPos);
			oorTargetEnemy = it->first;
		}
	}
	/// targetEnemy = in range, the ones in setPrio have the priority
	/// otherwise the closest
	targetEnemy = NULL;
	Unit* closestEnemy = NULL;
	closest = DBL_MAX;
	for (map<Unit*, Position>::const_iterator it = _unitsGroup->enemies.begin();
		it != _unitsGroup->enemies.end(); ++it)
	{
		/// Rule out what we don't want to attack
		if (!it->first->exists() || !it->first->isVisible() || !it->first->isDetected() || it->first->getType().isFlyer())
            continue;
		if (it->first->isDefenseMatrixed() 
			|| it->first->isHallucination()
			|| it->first->isInvincible())
			continue;
        UnitType testType = it->first->getType();
        if (testType.isBuilding() 
            && testType != UnitTypes::Protoss_Photon_Cannon
			&& (testType != UnitTypes::Terran_Bunker || !it->first->isAttacking())
            && testType != UnitTypes::Terran_Missile_Turret
            && testType != UnitTypes::Zerg_Sunken_Colony
            && testType != UnitTypes::Zerg_Spore_Colony)
            continue;
		/// Take one in the setPrio and in range or one in range or the closest
		if (inRange(it->first))
		{
			targetEnemy = it->first;
			if (setPrio.count(it->first->getType()))
				break;
		} else
		{
			if (it->first->getDistance(_unitPos) < closest)
			{
				closest = it->first->getDistance(_unitPos);
				closestEnemy = it->first;
			}
		}
	}
	if (targetEnemy == NULL)
		targetEnemy = closestEnemy;
}

void ZealotUnit::flee()
{
	//if (_lastTotalHP < 60)
	{
		for each (Unit* u in _targetingMe)
		{
			if (isOutrangingMe(u))
				return;
		}
	}
    _fightMoving = false;
    if (!this->mapManager->groundDamages[_unitPos.x()/32 + _unitPos.y()/32*Broodwar->mapWidth()])
    {
        _fleeing = false;
        return;
    }
    _fleeing = true;
    updateDir();
    clickDir();
}

void ZealotUnit::micro()
{
    int currentFrame = Broodwar->getFrameCount();
    if (unit->isStartingAttack())
        _lastAttackFrame = currentFrame;
    updateTargetingMe();
    /// Dodge storm, drag mine, drag scarab
    if (dodgeStorm() || dragMine() || dragScarab()) 
        return;
    decideToFlee();
	updateTargetEnemy();
	if (currentFrame - _lastClickFrame <= Broodwar->getLatencyFrames())
		return;
    if (currentFrame - _lastAttackFrame <= getAttackDuration()) // not interrupting attacks
        return;

    if (unit->getGroundWeaponCooldown() <= Broodwar->getLatencyFrames() + 2)
    {
		if (targetEnemy != NULL && targetEnemy->exists() && targetEnemy->isVisible() && targetEnemy->isDetected()) 
		{
			_lastClickFrame = Broodwar->getFrameCount();
			_lastAttackFrame = Broodwar->getFrameCount();
			if (unit->getTarget() == targetEnemy)
				return;
			// attack enemy unit
			unit->rightClick(targetEnemy);
		}
		else
		{
			if (unit->getOrder() != Orders::AttackMove || unit->getOrderTargetPosition().getApproxDistance(_unitsGroup->enemiesCenter) > 3*TILE_SIZE)
				unit->attack(_unitsGroup->enemiesCenter);
		}
    }
    else if (unit->getGroundWeaponCooldown() > Broodwar->getLatencyFrames() + 2) // (Broodwar->getLatencyFrames()+1)*2, safety
    {
        if (_fleeing)
        {
#ifdef __SIMPLE_FLEE__
            simpleFlee();
#else
			//if (unit->isStuck()) // TODO do something with it
			//	simpleFlee();
			//else
				flee();
#endif
        }
        else
        {
            fightMove();
        }
    }
}

void ZealotUnit::check()
{
    if (unit->getUpgradeLevel(UpgradeTypes::Leg_Enhancements) && !setPrio.count(UnitTypes::Terran_Siege_Tank_Siege_Mode))
    {
        setPrio.insert(UnitTypes::Protoss_High_Templar);
    }
}

int ZealotUnit::getAttackDuration()
{
    return 1;
}

std::set<UnitType> ZealotUnit::getSetPrio()
{
    return ZealotUnit::setPrio;
}