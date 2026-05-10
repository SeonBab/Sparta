#include "Player.h"
#include "WeaponStrategy.h"
#include "PlayerState.h"
#include <iostream>

Player::Player(PlayerState* InitialState, WeaponStrategy* initialWeapon)
{
	CurrentState = InitialState;
	_WeaponStrategy = initialWeapon;
	AttackCount = 0;
}

void Player::SetState(PlayerState* NewPlayerState)
{
	delete CurrentState;
	CurrentState = NewPlayerState;
}

void Player::SetWeapon(WeaponStrategy* NewWeaponStrategy)
{
	delete _WeaponStrategy;
	_WeaponStrategy = NewWeaponStrategy;
}

void Player::Attack()
{
	CurrentState->handleAttack(*this);
}

void Player::UseWeapon()
{
	if (_WeaponStrategy)
	{
		_WeaponStrategy->UseWeapon();
	}
	else
	{
		std::cout << "무기를 장착중이 아닙니다!" << std::endl;
	}
}

int Player::GetAttackCount() const
{
	return AttackCount;
}

void Player::SetAttackCount(int NewAttackCount)
{
	AttackCount = NewAttackCount;
}
