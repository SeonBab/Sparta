#include "NormalState.h"
#include "Player.h"
#include "BerserkState.h"
#include <iostream>

void NormalState::handleAttack(Player& player)
{
	std::cout << "[NormalState] 플레이어가 공격합니다." << std::endl;
	// 플레이어 무기로 공격
	player.UseWeapon();

	// 공격 횟수 증가
	int CurPlayerAttackCount = player.GetAttackCount();
	++CurPlayerAttackCount;
	player.SetAttackCount(CurPlayerAttackCount);

	// 공격 횟수가 특정 횟수 이상이라면 BerserkState로 변경
	if (3 <= CurPlayerAttackCount)
	{
		std::cout << "NormalState에서 BerserkState로 변경됩니다." << std::endl;

		player.SetState(new BerserkState);
		player.SetAttackCount(0);
	}
}
