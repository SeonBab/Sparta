#include "MobBattleScenario.h"
#include "Player.h"
#include <iostream>

MobBattleScenario::MobBattleScenario(Player& InitialPlayer) : BattleScenario(InitialPlayer)
{

}

void MobBattleScenario::Setup()
{
	std::cout << "몬스터가 나타났습니다." << std::endl;
}

void MobBattleScenario::PlayerAction()
{
	std::cout << "플레이어가 행동합니다." << std::endl;
	_Player.Attack();
}

void MobBattleScenario::EnemyAction()
{
	std::cout << "몬스터가 공격합니다." << std::endl;
}

void MobBattleScenario::Conclude()
{
	std::cout << "전투 종료" << std::endl;
}
