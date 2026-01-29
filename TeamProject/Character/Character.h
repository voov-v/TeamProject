#pragma once

#include <iostream>
#include <string> 
#include <random>

using namespace std;

struct FUnitStat
{
    int MaxHp;
    int MaxMp;
    int Atk;
    int Def;
    int Critical;

    int Hp = 0;
    int Mp = 0;

    FUnitStat()
    {
    }

    FUnitStat(int MaxHp, int MaxMp, int NewAtk, int NewDef, int NewCritical)
    {
        this->MaxHp = MaxHp;
        this->MaxMp = MaxMp;

        this->Atk = NewAtk;
        this->Def = NewDef;
        this->Critical = NewCritical;
    }
};

struct FDamageResult
{
    int Damage;
    bool bCritical;
};

class ACharacter
{
public:
    ACharacter(const string& NewName, const FUnitStat& NewStat);
    virtual ~ACharacter();

protected:
    string Name;
    FUnitStat Stat;

public:
    int GetHp() { return Stat.Hp; }
    bool IsDead() { return Stat.Hp <= 0; }
    int GetAtk() { return Stat.Atk; }
    string GetName() { return Name; }

    virtual FDamageResult Attack(ACharacter* Target);
    int TakeDamage(int DamageAmount);

private:
    int GetRandomInt();

};