#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
//�������һ�������࣬�������¹��ܣ�
//1��ֻ��ͨ�����������ճ�ʼ����
//2�����Լ���һ������n������һ�������ں���n��֮������ڡ�
class Date
{
private:
	int m_year;
	int m_month;
	int m_day;
public:
	Date(int year, int month, int day);
	friend ostream & operator << (ostream & os, Date & date);
	Date operator + (int N_Day)const;
	Date operator = (Date & date);
	Date operator ++ ();
	Date operator -- ();
	Date Date::operator ++ (int);
	Date Date::operator -- (int);
	Date operator - (int N_Day)const;
	int operator - (Date & date)const;
	bool operator < (Date & date)const;
	bool operator > (Date & date)const; 
	bool operator <= (Date & date)const;
	bool operator >= (Date & date)const;
	bool operator == (Date & date)const;
	bool operator != (Date & date)const;
	
};
int Yearday(int year, int month, int day);//��������������ĵڼ���
int MonthDay(int year, int month);//�ж�����������м���
int IsLeap(int year);//�ж�����֪��Ϊ����