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
    //int, long, 포인터 4~8
    //클래스, 구조체 -> 포인터, 참조자
    ACharacter(const string& NewName, const FUnitStat& NewStat);
    ~ACharacter();

protected:
    string Name;
    FUnitStat Stat;

public:
    // getters
    int GetHp() { return Stat.Hp; }
    bool IsDead() { return Stat.Hp <= 0; }
    int GetAtk() { return Stat.Atk; }
    
    void Attack(ACharacter* Target);
    void TakeDamage(int DamageAmount);

private:
    int GetRandomInt();
};