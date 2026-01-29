#include "Monster.h"

AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
    : ACharacter(NewName, NewStat)
{
    
}

AMonster::~AMonster()
{
}

FDamageResult AMonster::Attack(ACharacter* Target)
{
    FDamageResult result = ACharacter::Attack(Target);
    string AttackMessage = "이(가) 박치기 공격을 합니다.";
    if (result.bCritical)
    {
        AttackMessage = "이(가) 몽둥이 공격을 합니다.";
    }
    
    cout << Name << AttackMessage << " 데미지: " << result.Damage << endl;
    cout << Target->GetName() << " HP: " << Target->GetHp() << endl;

    return result;
}