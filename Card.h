#pragma once
#include "Tranzaction.h"

class Card :public Tranzaction
{
protected:
	int phone;
	static int countCard;
	int limit;
public:
	Card();
	virtual void EnterData();
	virtual void Add();
	virtual void MinusMoney();
	virtual void Show();
	int GetAmountOfCard();
};
