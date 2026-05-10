#pragma once

#include <string>

class Item;

class ItemBuilder
{
public:
    virtual void Reset() = 0;
    virtual void setName(const std::string& name) = 0;
    virtual void setHpRecovery(int hp) = 0;
    virtual void setMpRecovery(int mp) = 0;
    virtual void setAttackBoost(int atk) = 0;
    virtual void setDefenseBoost(int def) = 0;
    virtual Item build() = 0;
};

