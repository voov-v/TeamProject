#include "Character.h"

ACharacter::ACharacter()
{
    this->Name = "Unknown";

    this->Hp = 100;

    this->Atk = 10;

    cout << "ACharacter 생성됨: " << Name << " (HP: " << Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "ACharacter 소멸됨" << endl;
}

void ACharacter::Attack()
{
    cout << Name << "가 공격합니다." << endl;

}

void ACharacter::TakeDamage(int DamageAmount)
{
    Hp -= DamageAmount;

    cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
}