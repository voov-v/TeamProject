#include "Player.h"

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
    : ACharacter(NewName, NewStat)
{
    Level = 1;
    Exp = 0;
}

APlayer::~APlayer()
{
}

void APlayer::LevelUp()
{
}

bool APlayer::UseItem()
{
    return true;
}