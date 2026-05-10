#pragma once

class Player;

class BattleScenario
{
public:
	BattleScenario(Player& InitialPlayer);

	void RunScenario();

protected:
	virtual void Setup() = 0;

	virtual void PlayerAction() = 0;

	virtual void EnemyAction() = 0;

	virtual void Conclude() = 0;

protected:
	Player& _Player;
};

