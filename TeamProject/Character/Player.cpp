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
}

//bool APlayer::UseItem()
//{
//}