#pragma once
#include "BattleScenario.h"
class BossBattleScenario : public BattleScenario
{
public:
	BossBattleScenario(Player& InitialPlayer);

protected:
	virtual void Setup() override;

	virtual void PlayerAction() override;

	virtual void EnemyAction() override;

	virtual void Conclude() override;
};

