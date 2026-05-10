#pragma once

class Player;

class PlayerState
{
public:
	virtual void handleAttack(Player& player) = 0;
	
};

