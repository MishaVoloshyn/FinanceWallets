#pragma once
#include "Card.h"
class Debit :public Card
{
private:
	int countCard;
	double now_Balance;
	int limit;
public:
	void EnterData();
	void Show();
	void Add();
	void MinusMoney();
	int GetAmountOfCard();
};
