#pragma once
#include "Skill.h"

class UPlayerStrikeSkill : public USkill
{
public:
    UPlayerStrikeSkill(ACharacter* owner);

    virtual void Play(ACharacter* Target) override;
};

