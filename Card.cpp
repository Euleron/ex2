#include <iostream>
#include "Card.h"
#include "utilities.h"



    Card(CardType effects, CardStats stats){
        m_effects = effects;
        m_stats = stats;
    }

    ~Card(){
        // Make sure that no dynamic memory allocation actually takes place.
    }

    // Uses player and applies encounter specified by card.
    void applyEncounter(Player& player) const{

        if(m_effects == CardType::Treasure){ // Treasure card encounter.
            player.addCoins(m_stats.loot); // Adds card's loot to player.
            return;
        }

        if(m_effects == CardType::Heal || m_effects == CardType::Buff){ // Heal / Buff card encounter.
            if(player.pay(m_stats.cost)){ // If player has the required funds.
                m_effects == CardType::Heal ? player.heal(m_stats.heal) : player.buff(m_stats.buff);
                return;  // ^^^ Based on card type, either heals or buffs.
            }   
        }

        if(m_effects == CardType::Battle){ // Battle card encounter.
            if(player.getAttackStrength() >= m_stats.force){ // If player has won the battle.
                player.levelUp();
                player.addCoins(m_stats.loot);
                printBattleResult(true);
                return;
            }
            player.damage(m_stats.hpLossOnDefeat); // Player lost battle.
            printBattleResult(false);
            return;
        }

        return; // Unrecognized card type.
     }

    // Prints card info with function declared in utilities.h
    void printInfo() const{
        switch(m_effects){
            case CardType::Battle:
                printBattleCardInfo(this);
                return;

            case CardType::Buff:
                printBuffCardInfo(this);
                return;

            case CardType::Heal:
                printHealCardInfo(this);
                return;

            case CardType::Treasure:
                printTreasureCardInfo(this);
                return;

            default:
                return;
        }
        
    }
