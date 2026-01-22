#include "Character.h"
#include <random>

ACharacter::ACharacter(string NewName, int NewHp, int NewAtk, int NewDef, int NewCritical)
{
    Name = NewName;
    Hp = NewHp;
    Atk = NewAtk;
    Def = NewDef;
    Critical = NewCritical;

    cout << "ACharacter 생성됨: " << Name << " (HP: " << Hp << ")" << endl;
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
    int rand = GetRandomInt();

    cout << Name << "가 공격합니다." << endl;
    
    if (rand < Critical)
    {
        int CriticalAtk = Atk * 1.5;
        Target->TakeDamage(CriticalAtk);
    }
    else
    {
        Target->TakeDamage(Atk);
    }
}

void ACharacter::TakeDamage(int DamageAmount)
{
    int Damage = DamageAmount - Def;

    if (Damage < 0)
        Damage = 0;

    Hp -= Damage;

    if (Hp < 0)
        Hp = 0;

    cout << Name << "가 " << Damage << "의 피해를 입었습니다." << endl;
    cout << "  -> 남은 체력: " << Hp << endl;
}

int ACharacter::GetHp()
{
    return Hp;
}

bool ACharacter::bIsDead()
{
    if (Hp <= 0)
    {
        return true;
    } 
    else
    {
        return false;
    }
}

int ACharacter::GetAtk()
{
    return Atk;
}