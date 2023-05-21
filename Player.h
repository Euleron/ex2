//
// Created by jonah on 5/16/2023.
//
#include <iostream>
#include <string>
#include <stdbool.h>
#include "utilities.h"
class Player{
private:
std::string m_name;
int m_level;
int m_force;
int m_maxHp;
int m_hp;
int m_coins;

public:
    Player(std::string name,int force=5,int maxHp=100);
    ~Player();
    Player(const Player&);
    Player& operator=(const Player&);
    //
    void printInfo() const;
    void levelUp();
    int getLevel() const;
    void buff(int force);
    void heal(int hp);
    void damage(int damage);
    bool isKnockedOut();
    void addCoins(int coins);
    bool pay(int coins);
    int getAttackStrength();



};



#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#endif //EX2_PLAYER_H