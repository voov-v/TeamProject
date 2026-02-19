#include "BattleManager.h"

BattleManager::BattleManager()
{
}

BattleManager::~BattleManager()
{
}

void BattleManager::RunBattle(ACharacter* Player, ACharacter* Monster)
{
    cout << "===  데스매치 시작!  ===" << endl;
    WaitForPlayInput();

    while (!Player->IsDead() && !Monster->IsDead())
    {
        if (BattleTurn(Player, Monster) == true)
        {
            break;
        }
        if (BattleTurn(Monster, Player) == true)
        {
            break;
        }
    }
}

void BattleManager::WaitForPlayInput()
{
    system("pause");
    cout << endl;
}

bool BattleManager::BattleTurn(ACharacter* Attacker, ACharacter* Defender)
{
    cout << "[System] " << Attacker->GetName() << "의 턴입니다\n";
    Attacker->PlayTurn(Defender);
    Attacker->ShowStat();
    Defender->ShowStat();
    WaitForPlayInput();
    if (Defender->IsDead())
    {
        cout << "[System] " << Defender->GetName() << " 사망...";
    }
    return Defender->IsDead();
}

