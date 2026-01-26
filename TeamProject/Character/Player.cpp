#include "Player.h"

APlayer::APlayer(const string NewName, const FUnitStat& NewStat)
{
    Name = NewName;
    Stat = NewStat;

    cout << "APlayer 생성됨: " << Name << " (HP: " << Stat.Hp << ")" << endl;
}

APlayer::~APlayer()
{
}

