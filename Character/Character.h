#pragma once

#include <iostream>
#include <string> 

using namespace std;

struct FUnitStat
{
    int Hp;
    int Atk;
    int Def;
    int Critical;
};

class ACharacter
{
public:
    ACharacter(string NewName, const FUnitStat& NewStat);

    ~ACharacter();

protected:
    string Name;
    FUnitStat Stat;

public:
    void Attack(ACharacter* Target);

    void TakeDamage(int DamageAmount);

    int GetHp();

    bool IsDead();

    int GetAtk();

};