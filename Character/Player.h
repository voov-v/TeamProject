#pragma once

#include "Character.h"

class APlayer : ACharacter 
{
public:
    APlayer(const string name, const FUnitStat& NewStat);
    ~APlayer();

protected:
    string name;
    FUnitStat Stat;
};