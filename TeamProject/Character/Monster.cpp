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
    cout << Name << "가 박치기 공격합니다." << endl;

    ACharacter::Attack(Target);
}