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
		cout << "��������: ";
		cin >> replenishment;
		if (replenishment <= 0)
		{
			cout << "������, ����� �� ����������" << endl;
		}
	} while (replenishment < 1);
	now_balance += replenishment;
	cout << "��� ������: " << GetNowBal() << "$" << endl;
}

void Wallet::Add()
{
}

void Wallet::MinusMoney()
{

	int day, month;
	double costs;

	cout << "������� �����: ";
	cin >> costs;
	if (costs > now_balance) {
		cout << "��� ������� ����� " << endl;
	}
	else
	{
		string categoryName;
		cout << "������� ���������: ";
		cin.ignore();
		getline(cin, categoryName);
		string date;
		cout << "����: ";
		cin >> day;
		cout << "�����: ";
		cin >> month;
		arr.push_back(Category{ categoryName , day , month, costs, type = "�������" });
		for (size_t i = 0; i < arr.size(); ++i) {
			for (size_t j = 0; j < arr.size(); ++j) {
				cout << "���������: " << arr[i].category << "\t�������: " << arr[i].costs << "\t���� ����������: " << arr[i].day << "" << arr[i].month << "\t������/�����: " << arr[i].type << endl;
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
	cout << "������ ������: " << now_balance << "$" << endl;
}

double Wallet::GetNowBal()
{
	return now_balance;
}

