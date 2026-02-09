#include "Character.h"

void FDamageResult::PrintMessage(const string& AttackMessage)
{
    cout << "-------------------------------------------------" << endl;
    Attacker->PrintName();
    cout << AttackMessage << '\n';

    Target->PrintName();
    cout << "'받은 데미지': " << Damage << " -> '남은 HP': " << Target->GetHp() << endl;
    cout << "-------------------------------------------------" << endl;
}

ACharacter::ACharacter(const string& NewName, const FUnitStat& NewStat)
{
    Name = NewName;
    Stat = NewStat;

    Stat.Hp = Stat.MaxHp;
    Stat.Mp = Stat.MaxMp;

    cout << "ACharacter 생성됨: " << Name << " (HP: " << Stat.Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "ACharacter 소멸됨" << endl;
}

FDamageResult ACharacter::Attack(ACharacter* Target)
{
    int Damage = Stat.Atk;
    bool bCritical = GetRandomInt() < Stat.Critical;
    if (bCritical)
    {
        Damage = static_cast<int>(Damage * 1.5f);
    }

    int FinalDamage = Target->TakeDamage(Damage);
    FDamageResult result;
    result.Attacker = this;
    result.Target = Target;
    result.Damage = FinalDamage;
    result.bCritical = bCritical;
    return result;
}

int ACharacter::TakeDamage(int DamageAmount)
{
    int Damage = DamageAmount - Stat.Def;
    Damage = std::max(Damage, 0);

    Stat.Hp -= Damage;
    Stat.Hp = std::max(Stat.Hp, 0);

    return Damage;
}

int ACharacter::GetRandomInt()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 99);
    return dis(gen);
}

void ACharacter::PrintName()
{
    cout << "[" << Name << "] ";
}

void ACharacter::Heal(int amount)
{
    int PrevHp = Stat.Hp;
    Stat.Hp += amount;
    Stat.Hp = std::min(Stat.MaxHp, Stat.Hp);

    int ActualHeal = Stat.Hp - PrevHp;

    PrintName();
    cout << ActualHeal << " HP를 회복했습니다...!" << endl;
}

void ACharacter::PlayTurn(ACharacter* Target)
{
    const int AttackRate = 70;
    const int SkillMp = 10;

    if (GetRandomInt() < AttackRate)
    {
        Attack(Target);
        return;
    }

    if (Stat.Mp >= SkillMp)
    {
        UseSkill(Target);
        Stat.Mp -= SkillMp;
        return;
    }
    Attack(Target);
}