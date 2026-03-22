#include "UPlayerStrikeSkill.h"
#include "../Character/Character.h"

UPlayerStrikeSkill::UPlayerStrikeSkill(ACharacter* owner)
    : USkill(owner, "두 배 아픈 일반 공격", 20)
{
}

void UPlayerStrikeSkill::OnPlay(ACharacter* Target)
{
    int SkillDamage = Owner->GetAtk() * 2;
    int FinalDamage = Target->TakeDamage(SkillDamage);

    FDamageResult result;
    result.Attacker = Owner;
    result.Target = Target;
    result.Damage = FinalDamage;
    result.bCritical = false;
    string AttackMessage = "강하게 찌르기";

    result.PrintMessage(AttackMessage);
}
