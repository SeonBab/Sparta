#pragma once
#include "ItemBuilder.h"
#include "Item.h"

class PotionBuilder : public ItemBuilder
{
public:
    PotionBuilder();

    virtual void Reset();

    virtual void setName(const std::string& name) override;
    virtual void setHpRecovery(int hp) override;
    virtual void setMpRecovery(int mp) override;
    virtual void setAttackBoost(int atk) override;
    virtual void setDefenseBoost(int def) override;

    virtual Item build() override;

private:
    Item item;
};

