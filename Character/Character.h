#pragma once

#include <iostream>
#include <string> 

using namespace std;


class ACharacter
{
public:
    ACharacter(string NewName, int NewHp, int NewAtk, int NewDef, int NewCritical);

    ~ACharacter();

protected:
    string Name;
    int Hp;
    int Atk;
    int Def;
    int Critical;

public:
    void Attack(ACharacter* Target);

    void TakeDamage(int DamageAmount);

    int GetHp();

    //bIsDead < b는 변수에만 해당되는 코딩스타일 입니다.
    bool bIsDead();

    int GetAtk();

};