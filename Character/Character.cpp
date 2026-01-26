#include "Character.h"

ACharacter::ACharacter(){}

ACharacter::ACharacter(const string& NewName, const FUnitStat& NewStat)
{
    Name = NewName;
    Stat = NewStat;

    cout << "ACharacter 생성됨: " << Name << " (HP: " << Stat.Hp << ")" << endl;
}   

ACharacter::~ACharacter()
{
    cout << "ACharacter 소멸됨" << endl;
}

void ACharacter::Attack(ACharacter* Target)
{
    int Rand = GetRandomInt();
    int Damage = Stat.Atk;
    cout << Name << "가 공격합니다." << endl;
    
    if (Rand < Stat.Critical)
    {
        Damage = static_cast<int>(Stat.Atk * 1.5f);
    }

    Target->TakeDamage(Damage);
}

void ACharacter::TakeDamage(int DamageAmount)
{
    int Damage = DamageAmount - Stat.Def;

    Damage = std::max(Damage, 0);

    Stat.Hp -= Damage;

    Stat.Hp = std::max(Stat.Hp, 0);

    cout << Name << "가 " << Damage << "의 피해를 입었습니다." << endl;
    cout << "  -> 남은 체력: " << Stat.Hp << endl;
}

int ACharacter::GetRandomInt()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 99);
    return dis(gen);
}