#include "Character/Character.h"
#include "Character/Player.h"
#include "Character/Monster.h"
#include "BattleManager.h"
#include <Windows.h>


int main()
{
    APlayer* Player = new APlayer("나의 용사", { 200, 20, 15, 7, 10 });
    AMonster* Monster = new AMonster("무서운 오크", { 230, 50, 17, 5, 10 });
    BattleManager* BM = new BattleManager;
    
    BM->RunBattle(Player, Monster);


    delete Player;
    delete Monster;

    BM->WaitForPlayInput();

    delete BM;
    return 0;
}