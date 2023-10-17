#pragma once
#include <iostream>
#include "Category.h"
#include <vector>
#include <string>
using namespace std;


class Tranzaction : public Category {
protected:
	double now_balance;
	double total_expanses;
	vector<Category> arr;
public:
	Tranzaction() = default;

	virtual void Add() = 0;		
	virtual void MinusMoney() = 0;		
	virtual void Show();
	double GetBalance();
	void WriteReportToFile();
	void RatingMax();
};
