#pragma once
#include "BattleScenario.h"
class MobBattleScenario : public BattleScenario
{
public:
	MobBattleScenario(Player& InitialPlayer);

protected:
	virtual void Setup() override;

	virtual void PlayerAction() override;

	virtual void EnemyAction() override;

	virtual void Conclude() override;
};

