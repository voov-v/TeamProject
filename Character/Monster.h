#pragma once

#include "Character.h"

class AMonster : ACharacter 
{
public:
    AMonster(const string& NewName, FUnitStat NewStat);
    ~AMonster();

protected:
    string name;
    FUnitStat Stat;

};

