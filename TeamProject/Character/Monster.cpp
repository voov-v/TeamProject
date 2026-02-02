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
    
    result.PrintMessage(AttackMessage);
    return result;
}

void AMonster::UseSkill(ACharacter* Target)
{
    if (Stat.Mp < 10) 
    {
        return;
    }

    Stat.Mp -= 10;
    int FinalDamage = Target->TakeDamage(Stat.Atk);
    Stat.Hp += FinalDamage;
    Stat.Hp = std::min(Stat.Hp, Stat.MaxHp);

    FDamageResult result;
    result.Attacker = this;
    result.Target = Target;
    result.Damage = FinalDamage;
    result.bCritical = false;
    string AttackMessage = "피 회복";
    
    result.PrintMessage(AttackMessage);
}