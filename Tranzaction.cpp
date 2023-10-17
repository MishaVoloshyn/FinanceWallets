#include "Tranzaction.h"
#include <iostream>
#include <fstream>

using namespace std;

void Tranzaction::Show()
{
}

double Tranzaction::GetBalance()
{
	return now_balance;
}

void Tranzaction::WriteReportToFile()
{
	{
		string fileName = "Finance.txt";
		ofstream out(fileName);
		string report;
		int choose;
		int day, month;

		cout << "1. - ����  2. - ������   3. - �����" << endl;
		cin >> choose;
		cout << "����: ";
		cin >> day;
		cout << "�����: ";
		cin >> month;
		switch (choose)
		{
		case 1:
			if (out.is_open())
			{
				out << "����� ��: " << day << "" << month << endl;
				for (size_t i = 0; i < arr.size(); ++i) {
					for (size_t j = 0; j < arr.size(); ++j) {
						if (day == arr[i].day || month == arr[i].month) {
							//cout << "Category: " << arr[i].category << "\tCosts: " << arr[i].costs << "\tDate: " << arr[i].day << "/" << arr[i].month << "\tType: " << arr[i].type << endl;
							//i++;

							report = arr[i].category + ": " + to_string(arr[i].costs) + "$\n";
							out << report;
							i++;
						}

					}
				}
				out.close();
				cout << "��� ����������" << fileName << endl;
			}
			else
			{
				cout << "���� �� �������� " << fileName << endl;
			}
			break;
		case 2:
			if (out.is_open())
			{
				int stop = 0;
				out << "����� ��: " << day << "" << month << " �� " << day + 7 << "" << month << endl;
				for (size_t i = 0; i < arr.size(); ++i) {
					for (size_t j = 0; j < arr.size(); ++j) {
						if (day == arr[i].day || month == arr[i].month) {
							if (stop == 7) {
								break;
							}
							report = arr[i].category + ": " + to_string(arr[i].costs) + "$\n";
							out << report;
							i++;
							stop++;
						}

					}
				}
				out.close();
				cout << "��� ���������� " << fileName << endl;
			}
			else
			{
				cout << "���� �� �������� " << fileName << endl;
			}
			break;
		case 3:
			if (out.is_open())
			{
				int stop = 0;
				out << "����� ��: " << day << "" << month << " �� " << day + 7 << "" << month << endl;
				for (size_t i = 0; i < arr.size(); ++i) {
					for (size_t j = 0; j < arr.size(); ++j) {
						if (day == arr[i].day || month == arr[i].month) {
							if (stop == 30) {
								break;
							}
							report = arr[i].category + " : " + to_string(arr[i].costs) + "$";
							out << report; 
							i++;
							stop++;
						}

					}
				}
				out.close();
				cout << "��� ���������� " << fileName << endl;
			}
			else
			{
				cout << " ���� �� ��������" << fileName << endl;
			}
			break;
		default:
			cout << "������ � ������" << endl;
			break;
		}
	}
}

void Tranzaction::RatingMax()
{
	{
		string fileName = "Finance.txt";
		ofstream out(fileName);
		string report;
		int choose;



		cout << "1. - ����  2. - �����" << endl;
		cout << "(your answer): ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			if (out.is_open())
			{
				int stop = 0;
				int max = arr[0].costs;
				int index;
				out << "��� ��� � ������ ������:" << endl;
				for (size_t i = 0; i < arr.size(); ++i) {
					for (size_t j = 0; j < arr.size(); ++j) {

						if (stop == 7) {
							break;
						}
						else {
							if (arr[i].costs > max)
							{
								max = arr[i].costs;
								index = i;
							}
						}
						stop++;
					}
				}
				report = arr[index].category + ": " + to_string(max) + "$\n";
				out << report;

				out.close();
				cout << "��� ���������� " << fileName << endl;
			}
			else
			{
				cout << "���� �� �������� " << fileName << endl;
			}
			break;
		case 2:
			if (out.is_open())
			{
				int stop = 0;
				int count = 0;

				out << "��� 3 ����� � �����:" << endl;
				for (size_t i = 0; i < arr.size(); ++i) {
					for (size_t j = 0; j < arr.size(); ++j) {

						if (stop == 30 || count == 3)
						{
							break;
						}
						else {
							report = arr[i].category + ": " + to_string(arr[i].costs) + "$\n";
							out << report;
							count++;
						}
						stop++;
					}
				}
				out.close();
				cout << "��� ���������� " << fileName << endl;
			}
			else
			{
				cout << "���� �� �������� " << fileName << endl;
			}
			break;
		default:
			cout << "�� �� ������" << endl;
			break;
		}
	}
}