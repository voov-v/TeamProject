#include "Character.h"
#include <random>

ACharacter::ACharacter(const string NewName, const FUnitStat& NewStat)
{
    Name = NewName;
    Stat = NewStat;

    cout << "ACharacter 생성됨: " << Name << " (HP: " << Stat.Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "ACharacter 소멸됨" << endl;
}

// 0부터 100 사이의 정수 난수를 반환하는 함수
int GetRandomInt()
{
    // 시드값 생성기 (한 번만 초기화하기 위해 static 사용)
    static std::random_device rd;

    // 메르센 트위스터 엔진 (고품질 난수 생성기)
    static std::mt19937 gen(rd());

    // 0부터 100까지 균등하게 분포 (양 끝값 포함)
    std::uniform_int_distribution<int> dis(0, 99);

    return dis(gen);
}

void ACharacter::Attack(ACharacter* Target)
{
    int Rand = GetRandomInt();
    int Damage = Stat.Atk;
    cout << Name << "가 공격합니다." << endl;
    
    if (Rand < Stat.Critical)
    {
        //static_cast<> 캐스팅 찾아보세요.
        int CriticalAtk = Stat.Atk * 1.5;
        Damage = CriticalAtk;
    }

    Target->TakeDamage(Damage);
}

void ACharacter::TakeDamage(int DamageAmount)
{
    int Damage = DamageAmount - Stat.Def;

    if (Damage < 0)
    {
        Damage = 0;
    }

    Stat.Hp -= Damage;

    if (Stat.Hp < 0)
    {
        Stat.Hp = 0;
    }

    cout << Name << "가 " << Damage << "의 피해를 입었습니다." << endl;
    cout << "  -> 남은 체력: " << Stat.Hp << endl;
}

int ACharacter::GetHp()
{
    return Stat.Hp;
}

bool ACharacter::IsDead()
{
    if (Stat.Hp <= 0)
    {
        return true;
    }
    return false;
}

int ACharacter::GetAtk()
{
    return Stat.Atk;
}