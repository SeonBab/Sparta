#include "ItemDirector.h"
#include "Item.h"
#include "ItemBuilder.h"

Item ItemDirector::constructBasicHealingPotion(ItemBuilder& builder)
{
    builder.setName("기본 회복 물약");
    builder.setHpRecovery(50);
    builder.setMpRecovery(20);

    return builder.build();
}

Item ItemDirector::constructIronSword(ItemBuilder& builder)
{
    builder.setName("철검");
    builder.setAttackBoost(10);
    builder.setDefenseBoost(2);
    
    return builder.build();
}
