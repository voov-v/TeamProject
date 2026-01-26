#pragma once

#include "Character.h"

class APlayer : public ACharacter
{
public:
	APlayer(const string& NewName, const FUnitStat& NewStat);
	~APlayer() override;
	
protected:
	int Level;
	int Exp;
	
public:
	void LevelUp();
	bool UseItem();
	//함수: 레벨업, 아이템사용
};
