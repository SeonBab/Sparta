#pragma once
#include "PlayerState.h"
class BerserkState : public PlayerState
{
public:
	virtual void handleAttack(Player& player) override;
};

