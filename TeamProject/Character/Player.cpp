#include "Player.h"

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
    : ACharacter(NewName, NewStat)
{
    
}

APlayer::~APlayer()
{
}

void APlayer::LevelUp()
{
    if (Exp >= 100)
    {
        Level++;
        Exp -= 100;
    }
}

bool APlayer::UseItem()
{
    return true;
}