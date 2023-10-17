#include "DebitCard.h"
#include <string>
using namespace std;

int Card::countCard = 0;
void Debit::EnterData()
{
	cout << "Ваш номер телефона: ";
	cin >> this->phone;
	this->now_Balance = 0;
	Card::countCard++;
}

void Debit::Show()
{
	for (int i = 0; i < countCard; i++) {
		cout << "У вас кард:" << i + 1 << endl;
		cout << "Баланс: " << this->GetBalance() << "$" << endl;
	}
}

void Debit::Add()
{
	double sum;
	cout << "Ваш баланс: " << this->GetBalance() << endl;
	cout << "Введите сумму: ";
	cin >> sum;
	if (sum < 0) {
		cout << "Ошибка" << endl;
	}
	else {
		this->now_Balance += sum;
		cout << "Ваш баланс: " << now_Balance << endl;
	}
}


int Debit::GetAmountOfCard()
{
	return countCard;
}


void Debit::MinusMoney()
{
	
	int day, month;
	double costs;
	
		cout << "Введите сумму: ";
		cin >> costs;
		if (costs > now_Balance) {
			cout << "Нет столько денег "<< endl;
		}
		else
		{
			string categoryName;
			cout << "Введите категорию: " ;
			cin.ignore();
			getline(cin, categoryName);
			string date;
			cout << "День: ";
			cin >> day;
			cout << "Месяц: ";
			cin >> month;
			arr.push_back(Category{ categoryName , day , month, costs, type = "Карта" });
			for (size_t i = 0; i < arr.size(); ++i) {
				for (size_t j = 0; j < arr.size(); ++j) {
					cout << "Категория: " << arr[i].category << "\tЗатрата: " << arr[i].costs << "\tДата транзакции: " << arr[i].day << "" << arr[i].month << "\tКошеле/Карта: " << arr[i].type << endl;
					i++;
				}
			}
			now_Balance -= costs;
			total_expanses += costs;
			Show();
		}
	
	
}