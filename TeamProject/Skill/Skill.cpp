#include "Skill.h"
#include "../Character/Character.h"

USkill::USkill(ACharacter* owner, string NewSkillName, int NewMpCost)
{
    Owner = owner;
    MpCost = NewMpCost;
    SkillName = NewSkillName;
}

void USkill::Play(ACharacter* Target)
{
    Owner->ConsumeMp(MpCost);

    OnPlay(Target);
}

bool USkill::CanUse()
{
    return Owner->HasEnoughMp(MpCost);
}
