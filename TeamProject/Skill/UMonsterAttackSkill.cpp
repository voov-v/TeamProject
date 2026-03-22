#include "UMonsterAttackSkill.h"
#include "../Character/Character.h"

UMonsterAttackSkill::UMonsterAttackSkill(ACharacter* owner)
    : USkill(owner, "일반 공격", 0)
{
}

void UMonsterAttackSkill::OnPlay(ACharacter* Target)
{
    int Damage = Owner->GetAtk();
    bool bCritical = Owner->GetRandomInt() < Owner->GetCritical();
    if (bCritical)
    {
        Damage = static_cast<int>(Damage * 1.5f);
    }

    int FinalDamage = Target->TakeDamage(Damage);
    FDamageResult result;
    result.Attacker = Owner;
    result.Target = Target;
    result.Damage = FinalDamage;
    result.bCritical = bCritical;

    string AttackMessage = "이(가) 박치기 공격을 합니다.";
    if (result.bCritical)
    {
        AttackMessage = "이(가) 몽둥이 공격을 합니다.";
    }

    result.PrintMessage(AttackMessage);
}


