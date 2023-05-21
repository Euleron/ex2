//
// Created by jonah on 5/16/2023.
//
#include "Player.h"

Player::Player(std::string name, int force, int maxHp)
:m_name(name),m_level(1),m_force(force),m_maxHp(maxHp),m_coins(0),m_hp(maxHp) {
    if(m_force<=0)
    {
       m_force=5;
    }
    if(m_maxHp<=0)
    {
        m_maxHp = 100;
        m_hp = 100;
    }
}

//defult d'ctor
Player::~Player(){};

//copy c'tor maybe will change it to list
Player::Player(const Player& player){
    m_name=player.m_name;
    m_level=player.m_level;
    m_force=player.m_force;
    m_maxHp=player.m_maxHp;
    m_hp=player.m_hp;
    m_coins=player.m_coins;
}

Player& Player::operator=(const Player& player)
{
    //this prevents for p1=p1;
    if(this==&player)
    {
        return *this;
    }
    m_name=player.m_name;
    m_level=player.m_level;
    m_force=player.m_force;
    m_maxHp=player.m_maxHp;
    m_hp=player.m_hp;
    m_coins=player.m_coins;
    return *this;
}


void Player::printInfo() const
{
    printPlayerInfo(m_name.c_str(),m_level,m_force,m_hp,m_coins);
}

void Player::levelUp()
{
    if(m_level>=10)
    {
        return;
    }
    m_level++;
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(int force)
{
    if(force<=0){
        return;
    }
    m_force+=force;
}

void Player::heal(int hp)
{
    if(hp<=0)
    {
        return;
    }
    int fullHp=hp+m_hp;
    if(fullHp>=m_maxHp)
    {
        m_hp=m_maxHp;
        return;
    }
    m_hp+=hp;
}

void Player::damage(int damage)
{
    if(damage<=0)
    {
        return;
    }
    if(damage>=m_hp)
    {
        m_hp=0;
        return;
    }
    m_hp-=damage;
}

bool Player::isKnockedOut()
{
    if(m_hp==0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int coins)
{
    if(coins<=0)
    {
        return;
    }
    m_coins+=coins;
}

bool Player::pay(int coins)
{
    if(coins<=0)
    {
        return false;
    }
    if(m_coins<coins)
    {
        return false;
    }
    m_coins-=coins;
    return true;
}

int Player::getAttackStrength()
{
    return (m_force+m_level);
}