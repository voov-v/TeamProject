#pragma once
#include "Skill.h"

class UMonsterAttackSkill : public USkill
{
public:
    UMonsterAttackSkill(ACharacter* owner);

    virtual void OnPlay(ACharacter* Target) override;
};

