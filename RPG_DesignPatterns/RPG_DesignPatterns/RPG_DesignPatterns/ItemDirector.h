#pragma once

class Item;
class ItemBuilder;

class ItemDirector
{
public:
    static Item constructBasicHealingPotion(ItemBuilder& builder);

    static Item constructIronSword(ItemBuilder& builder);
};

