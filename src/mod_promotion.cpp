/**
    This plugin can be used for common player customizations
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"
#include "GossipDef.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Language.h"
#include "DatabaseEnv.h"
#include "WorldSession.h"
#include "mod_promotion.h"

static bool promotionEnable;
static int promotionCount;

class announce_module : public PlayerScript{
public:
    announce_module() : PlayerScript("announce_module") { }

    void OnLogin(Player* player) override {
        if (sConfigMgr->GetBoolDefault("announce_module.enableHelloWorld", true)) {
            ChatHandler(player->GetSession()).SendSysMessage("Hello World from Promotion-Module!");
        }
    }
};

class npc_promotion : public CreatureScript
{
public:
    npc_promotion() : CreatureScript("npc_promotion") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        //ChatHandler handler();

        if (player->getClass() == CLASS_DEATH_KNIGHT)
        {
            //player->SendPreparedGossip();
            return true;
        }

        if (player->getLevel() != 1)
        {
            if (player && creature)
                SendGossipMenuFor(player, 68, creature);
                return true;
        }

        switch (player->getClass())
        {
        case CLASS_WARRIOR:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "PvP Dps", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "PvP Tank", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            break;
        case CLASS_WARLOCK:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "PvP Dps", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            break;
        case CLASS_DRUID:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "PvP Tank", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "PvP Heal", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "PvP Balance", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
            break;
        case CLASS_HUNTER:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "PvP Dps ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
            break;
        case CLASS_MAGE:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "PvP Dps", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
            break;
        case CLASS_ROGUE:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "PvP Dps", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
            break;
        case CLASS_PRIEST:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "PvP Heal", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "PvP Shadow", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
            break;
        case CLASS_PALADIN:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "PvP Tank", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "PvP Heal", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "PvP Dps", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);
            break;
        case CLASS_SHAMAN:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "PvP Elemental", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 15);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "PvP Restoration", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "PvP Enhancement", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 17);
            break;
        default:
            break;
        }

        SendGossipMenuFor(player, 68, creature);

        return true;
    }

    void WarriorPromotionDps(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_WARRIOR_DPS_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_WARRIOR_DPS_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_WARRIOR_DPS_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_WARRIOR_DPS_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_WARRIOR_DPS_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_WARRIOR_DPS_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_WARRIOR_DPS_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_WARRIOR_DPS_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_WARRIOR_DPS_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_WARRIOR_DPS_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_WARRIOR_DPS_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_WARRIOR_DPS_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_WARRIOR_DPS_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_WARRIOR_DPS_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_WARRIOR_DPS_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, EQUIPMENT_SLOT_WARRIOR_DPS_OFFHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_WARRIOR_DPS_RANGED, true);
    }

    void WarriorPromotionTank(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_WARRIOR_TANK_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_WARRIOR_TANK_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_WARRIOR_TANK_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_WARRIOR_TANK_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_WARRIOR_TANK_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_WARRIOR_TANK_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_WARRIOR_TANK_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_WARRIOR_TANK_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_WARRIOR_TANK_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_WARRIOR_TANK_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_WARRIOR_TANK_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_WARRIOR_TANK_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_WARRIOR_TANK_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_WARRIOR_TANK_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_WARRIOR_TANK_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, EQUIPMENT_SLOT_WARRIOR_TANK_OFFHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_WARRIOR_TANK_RANGED, true);
    }

    void PaladinPromotionTank(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_PALADIN_TANK_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_PALADIN_TANK_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_PALADIN_TANK_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_PALADIN_TANK_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_PALADIN_TANK_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_PALADIN_TANK_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_PALADIN_TANK_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_PALADIN_TANK_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_PALADIN_TANK_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_PALADIN_TANK_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_PALADIN_TANK_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_PALADIN_TANK_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_PALADIN_TANK_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_PALADIN_TANK_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_PALADIN_TANK_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, EQUIPMENT_SLOT_PALADIN_TANK_OFFHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_PALADIN_TANK_RANGED, true);
    }

    void PaladinPromotionHeal(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_PALADIN_HEAL_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_PALADIN_HEAL_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_PALADIN_HEAL_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_PALADIN_HEAL_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_PALADIN_HEAL_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_PALADIN_HEAL_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_PALADIN_HEAL_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_PALADIN_HEAL_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_PALADIN_HEAL_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_PALADIN_HEAL_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_PALADIN_HEAL_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_PALADIN_HEAL_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_PALADIN_HEAL_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_PALADIN_HEAL_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_PALADIN_HEAL_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, EQUIPMENT_SLOT_PALADIN_HEAL_OFFHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_PALADIN_HEAL_RANGED, true);
    }

    void PaladinPromotionDps(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_PALADIN_DPS_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_PALADIN_DPS_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_PALADIN_DPS_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_PALADIN_DPS_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_PALADIN_DPS_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_PALADIN_DPS_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_PALADIN_DPS_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_PALADIN_DPS_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_PALADIN_DPS_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_PALADIN_DPS_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_PALADIN_DPS_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_PALADIN_DPS_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_PALADIN_DPS_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_PALADIN_DPS_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_PALADIN_DPS_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_PALADIN_DPS_RANGED, true);
    }

    void HunterPromotion(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_HUNTER_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_HUNTER_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_HUNTER_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_HUNTER_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_HUNTER_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_HUNTER_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_HUNTER_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_HUNTER_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_HUNTER_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_HUNTER_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_HUNTER_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_HUNTER_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_HUNTER_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_HUNTER_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_HUNTER_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_HUNTER_RANGED, true);
    }

    void RoguePromotion(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_ROGUE_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_ROGUE_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_ROGUE_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_ROGUE_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_ROGUE_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_ROGUE_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_ROGUE_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_ROGUE_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_ROGUE_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_ROGUE_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_ROGUE_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_ROGUE_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_ROGUE_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_ROGUE_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_ROGUE_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, EQUIPMENT_SLOT_ROGUE_OFFHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_ROGUE_RANGED, true);
    }

    void PriestPromotionHeal(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_PRIEST_HEAL_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_PRIEST_HEAL_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_PRIEST_HEAL_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_PRIEST_HEAL_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_PRIEST_HEAL_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_PRIEST_HEAL_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_PRIEST_HEAL_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_PRIEST_HEAL_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_PRIEST_HEAL_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_PRIEST_HEAL_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_PRIEST_HEAL_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_PRIEST_HEAL_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_PRIEST_HEAL_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_PRIEST_HEAL_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_PRIEST_HEAL_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_PRIEST_HEAL_RANGED, true);
    }

    void PriestPromotionShadow(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_PRIEST_SHADOW_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_PRIEST_SHADOW_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_PRIEST_SHADOW_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_PRIEST_SHADOW_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_PRIEST_SHADOW_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_PRIEST_SHADOW_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_PRIEST_SHADOW_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_PRIEST_SHADOW_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_PRIEST_SHADOW_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_PRIEST_SHADOW_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_PRIEST_SHADOW_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_PRIEST_SHADOW_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_PRIEST_SHADOW_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_PRIEST_SHADOW_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_PRIEST_SHADOW_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_PRIEST_SHADOW_RANGED, true);
    }

    void ShamanPromotionCaster(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_SHAMAN_CASTER_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_SHAMAN_CASTER_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_SHAMAN_CASTER_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_SHAMAN_CASTER_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_SHAMAN_CASTER_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_SHAMAN_CASTER_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_SHAMAN_CASTER_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_SHAMAN_CASTER_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_SHAMAN_CASTER_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_SHAMAN_CASTER_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_SHAMAN_CASTER_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_SHAMAN_CASTER_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_SHAMAN_CASTER_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_SHAMAN_CASTER_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_SHAMAN_CASTER_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, EQUIPMENT_SLOT_SHAMAN_CASTER_OFFHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_SHAMAN_CASTER_RANGED, true);
    }

    void ShamanPromotionMelee(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_SHAMAN_MELEE_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_SHAMAN_MELEE_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_SHAMAN_MELEE_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_SHAMAN_MELEE_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_SHAMAN_MELEE_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_SHAMAN_MELEE_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_SHAMAN_MELEE_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_SHAMAN_MELEE_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_SHAMAN_MELEE_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_SHAMAN_MELEE_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_SHAMAN_MELEE_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_SHAMAN_MELEE_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_SHAMAN_MELEE_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_SHAMAN_MELEE_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_SHAMAN_MELEE_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, EQUIPMENT_SLOT_SHAMAN_MELEE_OFFHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_SHAMAN_MELEE_RANGED, true);
    }

    void ShamanPromotionHeal(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_SHAMAN_HEAL_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_SHAMAN_HEAL_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_SHAMAN_HEAL_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_SHAMAN_HEAL_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_SHAMAN_HEAL_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_SHAMAN_HEAL_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_SHAMAN_HEAL_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_SHAMAN_HEAL_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_SHAMAN_HEAL_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_SHAMAN_HEAL_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_SHAMAN_HEAL_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_SHAMAN_HEAL_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_SHAMAN_HEAL_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_SHAMAN_HEAL_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_SHAMAN_HEAL_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, EQUIPMENT_SLOT_SHAMAN_HEAL_OFFHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_SHAMAN_HEAL_RANGED, true);
    }

    void MagePromotionDps(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_MAGE_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_MAGE_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_MAGE_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_MAGE_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_MAGE_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_MAGE_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_MAGE_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_MAGE_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_MAGE_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_MAGE_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_MAGE_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_MAGE_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_MAGE_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_MAGE_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_MAGE_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_MAGE_RANGED, true);
    }

    void WarlockPromotionDps(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_WARLOCK_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_WARLOCK_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_WARLOCK_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_WARLOCK_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_WARLOCK_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_WARLOCK_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_WARLOCK_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_WARLOCK_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_WARLOCK_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_WARLOCK_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_WARLOCK_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_WARLOCK_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_WARLOCK_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_WARLOCK_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_WARLOCK_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_WARLOCK_RANGED, true);
    }

    void DruidPromotionTank(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_DRUID_TANK_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_DRUID_TANK_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_DRUID_TANK_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_DRUID_TANK_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_DRUID_TANK_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_DRUID_TANK_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_DRUID_TANK_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_DRUID_TANK_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_DRUID_TANK_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_DRUID_TANK_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_DRUID_TANK_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_DRUID_TANK_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_DRUID_TANK_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_DRUID_TANK_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_DRUID_TANK_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_DRUID_TANK_RANGED, true);
    }

    void DruidPromotionHeal(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_DRUID_HEAL_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_DRUID_HEAL_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_DRUID_HEAL_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_DRUID_HEAL_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_DRUID_HEAL_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_DRUID_HEAL_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_DRUID_HEAL_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_DRUID_HEAL_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_DRUID_HEAL_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_DRUID_HEAL_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_DRUID_HEAL_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_DRUID_HEAL_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_DRUID_HEAL_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_DRUID_HEAL_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_DRUID_HEAL_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_DRUID_HEAL_RANGED, true);
    }

    void DruidPromotionMelee(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_DRUID_MELEE_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_DRUID_MELEE_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_DRUID_MELEE_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_DRUID_MELEE_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_DRUID_MELEE_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_DRUID_MELEE_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_DRUID_MELEE_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_DRUID_MELEE_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_DRUID_MELEE_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_DRUID_MELEE_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_DRUID_MELEE_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_DRUID_MELEE_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_DRUID_MELEE_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_DRUID_MELEE_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_DRUID_MELEE_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_DRUID_MELEE_RANGED, true);
    }

    void DruidPromotionCaster(Player* player)
    {
        player->EquipNewItem(EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_DRUID_CASTER_HEAD, true);
        player->EquipNewItem(EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_DRUID_CASTER_NECK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, EQUIPMENT_SLOT_DRUID_CASTER_SHOULDERS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_CHEST, EQUIPMENT_SLOT_DRUID_CASTER_CHEST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WAIST, EQUIPMENT_SLOT_DRUID_CASTER_WAIST, true);
        player->EquipNewItem(EQUIPMENT_SLOT_LEGS, EQUIPMENT_SLOT_DRUID_CASTER_LEGS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FEET, EQUIPMENT_SLOT_DRUID_CASTER_FEET, true);
        player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, EQUIPMENT_SLOT_DRUID_CASTER_WRISTS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_HANDS, EQUIPMENT_SLOT_DRUID_CASTER_HANDS, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_DRUID_CASTER_FINGER1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, EQUIPMENT_SLOT_DRUID_CASTER_FINGER2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_DRUID_CASTER_TRINKET1, true);
        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_DRUID_CASTER_TRINKET2, true);
        player->EquipNewItem(EQUIPMENT_SLOT_BACK, EQUIPMENT_SLOT_DRUID_CASTER_BACK, true);
        player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_DRUID_CASTER_MAINHAND, true);
        player->EquipNewItem(EQUIPMENT_SLOT_RANGED, EQUIPMENT_SLOT_DRUID_CASTER_RANGED, true);
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        uint32 accountID = player->GetSession()->GetAccountId();
        QueryResult result = CharacterDatabase.PQuery("SELECT COUNT(`guid`) FROM `characters` WHERE `account`=%u", accountID);
        Field* fields = result->Fetch();
        uint32 pjts = fields[0].GetUInt32();

        ClearGossipMenuFor(player);
        if (promotionEnable && pjts)
        {
            if (action > GOSSIP_ACTION_INFO_DEF && action < 1020)
                // Level
                player->GiveLevel(80);

        //Money 5k
        player->ModifyMoney(25000000);

        // Riding 
        player->learnSpell(SKILL_RIDING_75);
        player->learnSpell(SKILL_RIDING_100);
        player->learnSpell(SKILL_RIDING_FLYING);
        player->learnSpell(SKILL_RIDING_ARTISING);


        // Mounts
        player->learnSpell(42777); //Swift Spectral Tiger
        player->learnSpell(37015); //Swift Nether Drake

        //Bags
        for (int slot = INVENTORY_SLOT_BAG_START; slot < INVENTORY_SLOT_BAG_END; slot++)
            if (Item* bag = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                player->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);

        for (int slot = INVENTORY_SLOT_BAG_START; slot < INVENTORY_SLOT_BAG_END; slot++)
            player->EquipNewItem(slot, 14156, true);

        switch (action)
        {
        case 1001:
            WarriorPromotionDps(player);
            break;
        case 1002: 
            WarriorPromotionTank(player);
            break;
        case 1003:
            WarlockPromotionDps(player);
            break;
        case 1004:
            DruidPromotionTank(player);
            break;
        case 1005:
            DruidPromotionHeal(player);
            break;
        case 1006:
            DruidPromotionCaster(player);
            break;
        case 1007:
            HunterPromotion(player);
            break;
        case 1008:
            MagePromotionDps(player);
            break;
        case 1009:
            RoguePromotion(player);
            break;
        case 1010:
            PriestPromotionHeal(player);
            break;
        case 1011:
            PriestPromotionShadow(player);
            break;
        case 1012:
            PaladinPromotionTank(player);
            break;
        case 1013:
            PaladinPromotionHeal(player);
            break;
        case 1014:
            PaladinPromotionDps(player);
        default:
            break;
        }
    }
        return true;
    }
};

class mod_promotion_conf : public WorldScript
{
public:
    mod_promotion_conf() : WorldScript("mod_promotion.conf") { }

    void OnBeforeConfigLoad(bool reload) override
    {
        if (!reload)
        {
            std::string conf_path = _CONF_DIR;
            std::string cfg_file = conf_path + "/mod_promotion.conf.conf";
#ifdef WIN32
            cfg_file = "mod_promotion.conf.conf";
#endif
            std::string cfg_def_file = cfg_file + ".dist";

            sConfigMgr->LoadMore(cfg_def_file.c_str());
            sConfigMgr->LoadMore(cfg_file.c_str());

            promotionEnable = sConfigMgr->GetBoolDefault("promotionEnable.enable", true);
            promotionCount = sConfigMgr->GetIntDefault("promotion.count", 1);
        }
    }
};

void AddSC_npc_promotion()
{
    new announce_module();
    new npc_promotion();
    new mod_promotion_conf();
}
