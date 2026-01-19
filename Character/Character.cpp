#include "Character.h"

ACharacter::ACharacter(string NewName, int NewHp, int NewAtk)
{
    Name = NewName;
    Hp = NewHp;
    Atk = NewAtk;

    cout << "ACharacter 생성됨: " << Name << " (HP: " << Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "ACharacter 소멸됨" << endl;
}

void ACharacter::Attack(ACharacter* Target)
{
    cout << Name << "가 공격합니다." << endl;
    
    Target->TakeDamage(Atk);
}

void ACharacter::TakeDamage(int DamageAmount)
{
    Hp -= DamageAmount;

    if (Hp < 0)
        Hp = 0;

    cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
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