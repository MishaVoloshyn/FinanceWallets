#include "Tranzaction.h"
#include "Wallet.h"
#include "Category.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
using namespace std;

Wallet::Wallet()
{
}

Wallet::Wallet(double bal)
{
	now_balance = bal;
}

void Wallet::AddMoney()
{
	double replenishment;
	do
	{
		cout << "Добавить: ";
		cin >> replenishment;
		if (replenishment <= 0)
		{
			cout << "Ошибка, сумма не правильная" << endl;
		}
	} while (replenishment < 1);
	now_balance += replenishment;
	cout << "Ваш баланс: " << GetNowBal() << "$" << endl;
}

void Wallet::Add()
{
}

void Wallet::MinusMoney()
{

	int day, month;
	double costs;

	cout << "Введите сумму: ";
	cin >> costs;
	if (costs > now_balance) {
		cout << "Нет столько денег " << endl;
	}
	else
	{
		string categoryName;
		cout << "Введите категорию: ";
		cin.ignore();
		getline(cin, categoryName);
		string date;
		cout << "День: ";
		cin >> day;
		cout << "Месяц: ";
		cin >> month;
		arr.push_back(Category{ categoryName , day , month, costs, type = "Кошелек" });
		for (size_t i = 0; i < arr.size(); ++i) {
			for (size_t j = 0; j < arr.size(); ++j) {
				cout << "Категория: " << arr[i].category << "\tЗатрата: " << arr[i].costs << "\tДата транзакции: " << arr[i].day << "" << arr[i].month << "\tКошеле/Карта: " << arr[i].type << endl;
				i++;
			}
		}
		now_balance -= costs;
		total_expanses += costs;
		Show();
	}


}

void Wallet::Show()
{
	cout << "Баланс сейчас: " << now_balance << "$" << endl;
}

double Wallet::GetNowBal()
{
	return now_balance;
}

