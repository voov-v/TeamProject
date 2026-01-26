#include "Player.h"

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat, int NewLevel, int NewExp)
    : ACharacter(NewName, NewStat)
{
    Level = NewLevel;
    Exp = NewExp;
}

APlayer::~APlayer()
{
}

void APlayer::LevelUp()
{
}

//bool APlayer::UseItem()
//{
//}