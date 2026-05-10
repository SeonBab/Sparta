#include "BattleScenario.h"

BattleScenario::BattleScenario(Player& InitialPlayer) : _Player(InitialPlayer)
{
	
}

void BattleScenario::RunScenario()
{
	Setup();
	PlayerAction();
	EnemyAction();
	Conclude();
}
