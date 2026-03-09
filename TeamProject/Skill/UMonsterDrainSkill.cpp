#include "UMonsterDrainSkill.h"
#include "../Character/Character.h"

UMonsterDrainSkill::UMonsterDrainSkill(ACharacter* owner)
    : USkill(owner)
{
}

void UMonsterDrainSkill::Play(ACharacter* Target)
{
    int FinalDamage = Target->TakeDamage(Owner->GetAtk());
    Owner->Heal(FinalDamage);
    
    FDamageResult result;
    result.Attacker = Owner;
    result.Target = Target;
    result.Damage = FinalDamage;
    result.bCritical = false;
    string AttackMessage = "피 회복";
}
