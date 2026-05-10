#include "PotionBuilder.h"

PotionBuilder::PotionBuilder()
{
	Reset();
}

void PotionBuilder::Reset()
{
	item = Item();
}

void PotionBuilder::setName(const std::string& name)
{
	item.ItemName = name;
}

void PotionBuilder::setHpRecovery(int hp)
{
	item.HpRecovery = hp;
}

void PotionBuilder::setMpRecovery(int mp)
{
	item.MpRecovery = mp;
}

void PotionBuilder::setAttackBoost(int atk)
{
	// 포션은 공격력 증가 없음
}

void PotionBuilder::setDefenseBoost(int def)
{
	// 포션은 방어력 증가 없음
}

Item PotionBuilder::build()
{
	return item;
}
