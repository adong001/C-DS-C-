#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//��1��������������������ǽ���ڼ���

#define MONTHERROR -1
#define YEARERROR-2
bool Year(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
int YearMonth_days(int year, int month)
{
	int day;
	if (year < 1)return YEARERROR;
	else if (month < 1 || month>12)return MONTHERROR;
	int Month[12] = { 29, 31, 28, 31, 30, 31, 30.31, 31, 30, 31, 30, 31 };
	if (month == 2 && Year(year))
	{
		day = Month[0];
	}
	else
	{
		day = Month[month];
	}
	return day;
}
int main1()
{
	int year, month, days;
	char ch;
	for (;;)
	{
		cout << "���������£�\n";
		cin >> year >> month;
		days = YearMonth_days(year, month);
		switch (days)
		{
		case YEARERROR:cout << "�����������,���������룺\n"; break;
		case MONTHERROR:cout << "�����·�����,���������룺\n"; break;
		default:cout << year << "��" << month << "����" << days << "��" << endl; break;
		}
		cout << "�����밴Y���˳��밴N:\n";
		cin >> ch;
		if (ch == 'N' || ch == 'n')break;
	}
	return 0;
}







