#include "UPlayerShieldSkill.h"
#include "../Character/Character.h"

UPlayerShieldSkill::UPlayerShieldSkill(ACharacter* owner)
    : USkill(owner, "쉴드", 20)
{
}

void UPlayerShieldSkill::OnPlay(ACharacter* Target)
{
    Owner->Shield(10);

    FDamageResult result;
    result.Attacker = Owner;
    result.Target = Target;
    result.Damage = 0;
    result.bCritical = false;
    string AttackMessage = "쉴드";

    result.PrintMessage(AttackMessage);
}
