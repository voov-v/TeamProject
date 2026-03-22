#pragma once

#include <string>

using namespace std;

class ACharacter;

class USkill
{
public:
    USkill(ACharacter* owner, string NewSkillName, int NewMpCost);

    virtual void OnPlay(ACharacter* Target) = 0;
    void Play(ACharacter* Target);

    bool CanUse();

    string GetSkillName() { return SkillName; }
    int GetMpCost() { return MpCost; }

protected:
    ACharacter* Owner;
    string SkillName;
    int MpCost;
};