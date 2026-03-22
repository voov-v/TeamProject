#include "Monster.h"
#include "../Skill/UMonsterAttackSkill.h"
#include "../Skill/UMonsterDrainSkill.h"
#include "vector"

AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
    : ACharacter(NewName, NewStat)
{
    Skills.push_back(make_unique<UMonsterAttackSkill>(this));
    Skills.push_back(make_unique<UMonsterDrainSkill>(this));
}

AMonster::~AMonster()
{
}

//FDamageResult AMonster::Attack(ACharacter* Target)
//{
//    FDamageResult result = ACharacter::Attack(Target);
//    string AttackMessage = "이(가) 박치기 공격을 합니다.";
//    if (result.bCritical)
//    {
//        AttackMessage = "이(가) 몽둥이 공격을 합니다.";
//    }
//    
//    result.PrintMessage(AttackMessage);
//    return result;
//}

//void AMonster::UseSkill(ACharacter* Target)
//{
//    int FinalDamage = Target->TakeDamage(Stat.Atk);
//    Stat.Hp += FinalDamage;
//    Stat.Hp = std::min(Stat.Hp, Stat.MaxHp);
//
//    FDamageResult result;
//    result.Attacker = this;
//    result.Target = Target;
//    result.Damage = FinalDamage;
//    result.bCritical = false;
//    string AttackMessage = "피 회복";
//    
//    result.PrintMessage(AttackMessage);
//}

void AMonster::PlayTurn(ACharacter* Target)
{
    vector<USkill*> CanUseSkills;
    for (auto& skill : Skills)
    {
        if (skill->CanUse())
        {
            CanUseSkills.push_back(skill.get());
        }
    }

    if (CanUseSkills.empty())
    {
        cout << Name << "은 행동 불가" << endl;
        return;
    }

    int index = GetRandomInt(static_cast<int>(CanUseSkills.size()));
    CanUseSkills[index]->Play(Target);
}
