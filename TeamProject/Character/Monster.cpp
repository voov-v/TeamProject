#include "Monster.h"

AMonster::AMonster(const string& NewName, FUnitStat NewStat)
{
    Name = NewName;
    Stat = NewStat;

    cout << "APlayer 생성됨: " << Name << " (HP: " << Stat.Hp << ")" << endl;
}

AMonster::~AMonster()
{
}
