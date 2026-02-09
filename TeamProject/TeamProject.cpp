#include "Character/Character.h"
#include "Character/Player.h"
#include "Character/Monster.h"
#include <Windows.h>

void WaitForPlayInput()
{
    system("pause");
    cout << endl;
}

int main()
{
    APlayer* Player = new APlayer("나의 용사", { 200, 50, 15, 7, 10 });
    AMonster* Monster = new AMonster("무서운 오크", { 100, 30, 10, 5, 10 });

    cout << "===  데스매치 시작!  ===" << endl;
    WaitForPlayInput();

    while (!Player->IsDead()&& !Monster->IsDead())
    {
        Player->PlayTurn(Monster);

        if (Monster->IsDead())
        {
            cout << "몬스터가 쓰러졌습니다! 승리!" << endl;
            break;
        }

        WaitForPlayInput();

        Monster->PlayTurn(Player);

        if (Player->IsDead())
        {
            cout << "플레이어가 쓰러졌습니다... 패배..." << endl;
            break;
        }

        WaitForPlayInput();
    }

    delete Player;
    delete Monster;
    return 0;
}