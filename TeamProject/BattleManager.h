#pragma once

#include "Character/Character.h"

class BattleManager
{
public:
    BattleManager();
    ~BattleManager();

    void RunBattle(ACharacter* Attacker, ACharacter* Defender);
    void WaitForPlayInput();
    bool BattleTurn(ACharacter* Attacker, ACharacter* Defender);
};

