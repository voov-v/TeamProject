#include "UPlayerShieldSkill.h"
#include "../Character/Character.h"

UPlayerShieldSkill::UPlayerShieldSkill(ACharacter* owner)
    : USkill(owner)
{
}

void UPlayerShieldSkill::Play(ACharacter* Target)
{
    Owner->Shield(50);
}
