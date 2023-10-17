#include "Tranzaction.h"
#include "Wallet.h"
#include "Category.h"
#include "Card.h"
#include "DebitCard.h"
#include "CreditCard.h"
#include <iostream>
#include <vector>

using namespace std;



void ShowMenu()
{
	cout << "|||МЕНЮ|||:" << endl;
	cout << "Выберите действие:" << endl;
	cout << "|||КОШЕЛЕК|||:" << endl;
	cout << "1. Пополнить кошелек" << endl;
	cout << "2. Внести затрату из кошелька " << endl;
	cout << "3. Показать баланс кошелька" << endl;
	cout << "4. Вывести расходы по кошельку" << endl;
	cout << "|||Карта(Дебет)|||:" << endl;
	cout << "5. Создать Дебетовую карту " << endl;
	cout << "6. Пополнить Дебетовую карту" << endl;
	cout << "7. Внести затрату с Дебетовой карты " << endl;
	cout << "8. Показать баланс Дебетовой карты" << endl;
	cout << "9. Вывести расходы по Дебетовой карте" << endl;
	cout << "|||Карта(Кредит)|||:" << endl;
	cout << "10. Создать Кредитовую карту " << endl;
	cout << "11. Пополнить Кредитовую карту" << endl;
	cout << "12. Внести затрату с Кредитовой карты " << endl;
	cout << "13. Показать баланс Кредитовой карты" << endl;
	cout << "14. Вывести расходы по Кредитовой карте" << endl;
	cout << "15. Выход" << endl;

	cout << "Ваш выбор 1-15: ";
}




int main()
{
	setlocale(LC_ALL, "ru");
	Tranzaction* Tranzaction = nullptr;
	Card* debit = new Debit();
	Card* credit = new Credit();
	Wallet wallet(600);
	int choice;
	bool check = true;
	cout << "У вас есть один кошелек с суммой денег в нем: 600$" << endl;

	do
	{
		ShowMenu();
		cin >> choice;
		switch (choice) {
		case 1:
			wallet.AddMoney();
			break;
		case 2:
			wallet.MinusMoney();
			break;
		case 3:
			wallet.GetNowBal();
			break;
		case 4:
			wallet.WriteReportToFile();
			break;
		case 5:
			debit->EnterData();
			break;
		case 6:
			debit->Add();
			break;
		case 7:
			debit->MinusMoney();
			break;
		case 8:
			debit->GetBalance();
			break;
		case 9:
			debit->WriteReportToFile();
			break;
		case 10:
			credit->EnterData();
			break;
		case 11:
			credit->Add();
			break;
		case 12:
			credit->MinusMoney();
			break;
		case 13:
			credit->GetBalance();
			break;
		case 14:
			credit->WriteReportToFile();
		case 15:
			cout << "Выход из программы" << endl;
		default:
			cout << "Неверный вариант" << endl;
			check = false;
			break;
		}
		int Check;
		cout << "Продолжить? 1 - да   0 - нет\n";
		cin >> Check;
		if (Check == 1) {
			check = false;
		}
		else if (Check == 0) {
			check = true;
		}
		else {
			cout << "Неверный вариант" << endl;
		}
	} while (!check);
}
