#pragma once
#include "Tranzaction.h"
#include <iostream>
using namespace std;

class Wallet : public Tranzaction
{
private:
	double balance;
public:
	Wallet();
	Wallet(double bal);
	void AddMoney();
	void Add();
	void MinusMoney();
	void Show();
	double GetNowBal();
	

};