#include "Player.h"
#include "../Skill/UPlayerAttackSkill.h"
#include "../Skill/UPlayerStrikeSkill.h"
#include "../Skill/UPlayerShieldSkill.h"

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
    : ACharacter(NewName, NewStat)
{
    Level = 1;
    Exp = 0;
    Skills.push_back(make_unique<UPlayerAttackSkill>(this));
    Skills.push_back(make_unique<UPlayerStrikeSkill>(this));
    Skills.push_back(make_unique<UPlayerShieldSkill>(this));
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

//FDamageResult APlayer::Attack(ACharacter* Target)
//{
//    FDamageResult result = ACharacter::Attack(Target);
//    string AttackMessage = "이(가) 베기 공격을 합니다.";
//    
//    if (result.bCritical)
//    {
//        AttackMessage = "이(가) 찌르기 공격을 합니다.";
//    }
//
//    result.PrintMessage(AttackMessage);
//    return result;
//}

//void APlayer::UseSkill(ACharacter* Target)
//{
//    int SkillDamage = Stat.Atk * 2;
//    int FinalDamage = Target->TakeDamage(SkillDamage);
//
//    FDamageResult result;
//    result.Attacker = this;
//    result.Target = Target;
//    result.Damage = FinalDamage;
//    result.bCritical = false;
//    string AttackMessage = "강하게 찌르기";
//
//    result.PrintMessage(AttackMessage);
//}

void APlayer::PlayTurn(ACharacter* Target)
{
    cout << "=== 스킬 목록 ===" << endl;
    for (int i = 0; i < Skills.size(); i++)
    {
        cout << i + 1 << ", " << Skills[i]->GetSkillName() << " (MP: " << Skills[i]->GetMpCost() << ")" << endl;
    }

    int choice = 0;
    while (choice < 1 || choice > Skills.size())
    {
        cout << "스킬을 선택하세요." << endl;
        cin >> choice;

        if (choice < 1 || choice > Skills.size())
        {
            cout << "잘못된 선택입니다." << endl;
            continue;
        }

        if (Skills[choice - 1]->CanUse() == false)
        {
            cout << "[MP 부족] 다른 스킬을 선택하세요." << endl;
            choice = 0;
            continue;
        }
    }

    Skills[choice - 1]->Play(Target);
}