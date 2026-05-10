#include "WeaponBuilder.h"

WeaponBuilder::WeaponBuilder()
{
	Reset();
}

void WeaponBuilder::Reset()
{
	item = Item();
}

void WeaponBuilder::setName(const std::string& name)
{
	item.ItemName = name;
}

void WeaponBuilder::setHpRecovery(int hp)
{
	// 무기는 HP 회복 없음
}

void WeaponBuilder::setMpRecovery(int mp)
{
	// 무기는 MP 회복 없음
}

void WeaponBuilder::setAttackBoost(int atk)
{
	item.AttackBoost = atk;
}

void WeaponBuilder::setDefenseBoost(int def)
{
	item.DefenseBoost = def;
}

Item WeaponBuilder::build()
{
	return item;
}
