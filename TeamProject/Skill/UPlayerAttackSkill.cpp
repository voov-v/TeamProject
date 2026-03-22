#include "UPlayerAttackSkill.h"
#include "../Character/Character.h"

UPlayerAttackSkill::UPlayerAttackSkill(ACharacter* owner)
    : USkill(owner, "일반 공격", 0)
{

}

void UPlayerAttackSkill::OnPlay(ACharacter* Target)
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

    string AttackMessage = "이(가) 베기 공격을 합니다.";

    if (result.bCritical)
    {
        AttackMessage = "이(가) 찌르기 공격을 합니다.";
    }

    result.PrintMessage(AttackMessage);
}
