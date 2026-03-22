#pragma once
#include "Skill.h"

class UPlayerAttackSkill : public USkill
{
public:
    UPlayerAttackSkill(ACharacter* owner);

    virtual void OnPlay(ACharacter* Target) override;
};

