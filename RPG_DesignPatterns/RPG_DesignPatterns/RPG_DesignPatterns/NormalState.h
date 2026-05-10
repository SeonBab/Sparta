#pragma once
#include "PlayerState.h"

class NormalState : public PlayerState
{
public:
	virtual void handleAttack(Player& player) override;
};

