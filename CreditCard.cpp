#include "CreditCard.h"
#include <iostream>
using namespace std;


void Credit::EnterData()
{
	cout << "��� ����� ��������: ";
	cin >> this->phone;
	this->now_Balance = 0;
	Card::countCard++;
}

void Credit::Show()
{
	for (int i = 0; i < countCard; i++) {
		cout << "� ��� ����:" << i + 1 << endl;
		cout << "������: " << this->GetBalance() << "$" << endl;
	}
}

void Credit::Add()
{
	double sum;
	cout << "��� ������: " << this->GetBalance() << endl;
	cout << "������� �����: ";
	cin >> sum;
	if (sum <= 0) {
		cout << "������" << endl;
	}
	else {
		this->now_Balance += sum;
		cout << "��� ������: " << now_Balance << endl;
	}
}



void Credit::MinusMoney()
{

	int day, month;
	double costs;

	cout << "������� �����: ";
	cin >> costs;
	if (costs > now_Balance) {
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
		arr.push_back(Category{ categoryName , day , month, costs, type = "�����" });
		for (size_t i = 0; i < arr.size(); ++i) {
			for (size_t j = 0; j < arr.size(); ++j) {
				cout << "���������: " << arr[i].category << "\t�������: " << arr[i].costs << "\t���� ����������: " << arr[i].day << "" << arr[i].month << "\t������/�����: " << arr[i].type << endl;
				i++;
			}
		}
		now_Balance -= costs;
		total_expanses += costs;
		Show();
	}


}