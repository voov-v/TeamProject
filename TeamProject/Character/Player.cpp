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

    result.PrintMessage(AttackMessage);
    return result;
}

void APlayer::UseSkill(ACharacter* Target)
{
    /*if (Stat.Mp < 10) 
    {
        return; 
    }

    Stat.Mp -= 10;*/
    int SkillDamage = Stat.Atk * 2;
    int FinalDamage = Target->TakeDamage(SkillDamage);

    FDamageResult result;
    result.Attacker = this;
    result.Target = Target;
    result.Damage = FinalDamage;
    result.bCritical = false;
    string AttackMessage = "강하게 찌르기";

    result.PrintMessage(AttackMessage);
}