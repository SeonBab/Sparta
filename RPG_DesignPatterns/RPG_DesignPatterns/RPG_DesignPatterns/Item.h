#pragma once

#include <string>

class Item
{
public:
    Item();

    void ShowInfo() const;

public:
    std::string ItemName;
    int HpRecovery;
    int MpRecovery;
    int AttackBoost;
    int DefenseBoost;
};

