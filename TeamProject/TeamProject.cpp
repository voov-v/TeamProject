#include "Character/Character.h"
#include "Character/Player.h"
#include "Character/Monster.h"
#include "BattleManager.h"
#include <Windows.h>
#include <memory>


int main()
{
    auto BM = make_unique<BattleManager>();

    FUnitStat PlayerStat(200, 20, 15, 7, 10);
    FUnitStat MonsterStat(220, 50, 10, 5, 10);

    unique_ptr<ACharacter> Player =  make_unique<APlayer>("나의 용사", PlayerStat);
    unique_ptr<ACharacter> Monster = make_unique<AMonster>("무서운 오크", MonsterStat);

    BM->RunBattle(Player.get(), Monster.get());

    BM->WaitForPlayInput();
    return 0;
}