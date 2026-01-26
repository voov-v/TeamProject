#pragma once

#include "Character.h"

class APlayer : public ACharacter
{
public:
	APlayer(const string& NewName, const FUnitStat& NewStat, int NewLevel, int NewExp);
	~APlayer() override;
	
protected:
	int Level;
	int Exp;
	
public:
	void LevelUp();
	/*bool UseItem();*/
};
