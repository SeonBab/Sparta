#include "BerserkState.h"
#include "Player.h"
#include "NormalState.h"
#include <iostream>

void BerserkState::handleAttack(Player& player)
{
	std::cout << "[BerserkState] 플레이어가 공격합니다." << std::endl;
	// 플레이어 무기로 공격
	// 해당 상태에서는 2회 공격
	player.UseWeapon();
	player.UseWeapon();

	// 공격 횟수 증가
	int CurPlayerAttackCount = player.GetAttackCount();
	++CurPlayerAttackCount;
	player.SetAttackCount(CurPlayerAttackCount);

	// 공격 횟수가 특정 횟수 이상이라면 NormalState로 변경
	if (3 <= CurPlayerAttackCount)
	{
		std::cout << "BerserkState에서 NormalState로 변경됩니다." << std::endl;

		player.SetState(new NormalState);
		player.SetAttackCount(0);
	}
}
