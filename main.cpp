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
	cout << "|||����|||:" << endl;
	cout << "�������� ��������:" << endl;
	cout << "|||�������|||:" << endl;
	cout << "1. ��������� �������" << endl;
	cout << "2. ������ ������� �� �������� " << endl;
	cout << "3. �������� ������ ��������" << endl;
	cout << "4. ������� ������� �� ��������" << endl;
	cout << "|||�����(�����)|||:" << endl;
	cout << "5. ������� ��������� ����� " << endl;
	cout << "6. ��������� ��������� �����" << endl;
	cout << "7. ������ ������� � ��������� ����� " << endl;
	cout << "8. �������� ������ ��������� �����" << endl;
	cout << "9. ������� ������� �� ��������� �����" << endl;
	cout << "|||�����(������)|||:" << endl;
	cout << "10. ������� ���������� ����� " << endl;
	cout << "11. ��������� ���������� �����" << endl;
	cout << "12. ������ ������� � ���������� ����� " << endl;
	cout << "13. �������� ������ ���������� �����" << endl;
	cout << "14. ������� ������� �� ���������� �����" << endl;
	cout << "15. �����" << endl;

	cout << "��� ����� 1-15: ";
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
	cout << "� ��� ���� ���� ������� � ������ ����� � ���: 600$" << endl;

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
			cout << "����� �� ���������" << endl;
		default:
			cout << "�������� �������" << endl;
			check = false;
			break;
		}
		int Check;
		cout << "����������? 1 - ��   0 - ���\n";
		cin >> Check;
		if (Check == 1) {
			check = false;
		}
		else if (Check == 0) {
			check = true;
		}
		else {
			cout << "�������� �������" << endl;
		}
	} while (!check);
}
