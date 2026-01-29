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

FDamageResult APlayer::Attack(ACharacter* Target)
{
    FDamageResult result = ACharacter::Attack(Target);
    string AttackMessage = "이(가) 베기 공격을 합니다.";
    if (result.bCritical)
    {
        AttackMessage = "이(가) 찌르기 공격을 합니다.";
    }

    cout << Name << AttackMessage << " 데미지: " << result.Damage << endl;
    cout << Target->GetName() << " HP: " << Target->GetHp() << endl;

    return result;
}