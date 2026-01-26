#pragma once

#include "Character.h"

class APlayer : public ACharacter
{
public:
	APlayer(const string& NewName, const FUnitStat& NewStat);
	~APlayer() override;
	
	//변수: 레벨 경험치
	//함수: 레벨업, 아이템사용
};
