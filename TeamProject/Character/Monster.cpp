#include "Monster.h"

AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
    : ACharacter(NewName, NewStat)
{
    
}

AMonster::~AMonster()
{
}

void AMonster::Attack(ACharacter* Target)
{
    cout << "몬스터 공격" << endl;

    Target->TakeDamage(Stat.Atk);
}