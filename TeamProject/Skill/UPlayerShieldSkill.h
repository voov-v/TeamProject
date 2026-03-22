#pragma once
#include "Skill.h"

class UPlayerShieldSkill : public USkill
{
public:
    UPlayerShieldSkill(ACharacter* owner);

    virtual void OnPlay(ACharacter* Target) override;
};