#pragma once

#include <iostream>
#include <string> 
#include <random>

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
    ACharacter();
    ACharacter(const string& NewName, const FUnitStat& NewStat);
    ~ACharacter();

protected:
    string Name;
    FUnitStat Stat;

public:
    int GetHp() { return Stat.Hp; }
    bool IsDead() { return Stat.Hp <= 0; }
    int GetAtk() { return Stat.Atk; }

    void Attack(ACharacter* Target);
    void TakeDamage(int DamageAmount);



private:
    int GetRandomInt();

};