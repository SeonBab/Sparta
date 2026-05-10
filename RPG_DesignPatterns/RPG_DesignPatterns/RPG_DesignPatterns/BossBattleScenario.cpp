#include "BossBattleScenario.h"
#include "Player.h"
#include <iostream>

BossBattleScenario::BossBattleScenario(Player& InitialPlayer) : BattleScenario(InitialPlayer)
{

}

void BossBattleScenario::Setup()
{
	std::cout << "보스가 나타났습니다." << std::endl;
}

void BossBattleScenario::PlayerAction()
{
	std::cout << "플레이어가 행동합니다." << std::endl;
	_Player.Attack();
}

void BossBattleScenario::EnemyAction()
{
	std::cout << "보스가 강력한 스킬을 사용합니다." << std::endl;
}

void BossBattleScenario::Conclude()
{
	std::cout << "전투 종료" << std::endl;
}
