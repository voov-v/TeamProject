#pragma once
#include "Skill.h"

class UMonsterDrainSkill : public USkill
{
public:
    UMonsterDrainSkill(ACharacter* owner);

    virtual void Play(ACharacter* Target) override;
};