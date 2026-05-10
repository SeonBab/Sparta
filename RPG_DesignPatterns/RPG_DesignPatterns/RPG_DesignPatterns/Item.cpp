#include "Item.h"
#include <iostream>

Item::Item()
{
    ItemName = "";
    HpRecovery = 0;
    MpRecovery = 0;
    AttackBoost = 0;
    DefenseBoost = 0;
}

void Item::ShowInfo() const
{
    std::cout << "아이템: " << ItemName << std::endl;
    std::cout << "HP 회복: " << HpRecovery << ", MP 회복: " << MpRecovery << std::endl;
    std::cout << "공격력 증가: " << AttackBoost << ", 방어력 증가: " << DefenseBoost << std::endl;
}
