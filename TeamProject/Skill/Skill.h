#pragma once

class ACharacter;

class Skill
{
public:
    Skill(ACharacter* owner);

    virtual void Play(ACharacter* Target) = 0;

protected:
    ACharacter* Owner;
};