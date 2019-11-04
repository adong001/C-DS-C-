#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
//�������һ�������࣬�������¹��ܣ�
//1��ֻ��ͨ�����������ճ�ʼ����
//2�����Լ���һ������n������һ�������ں���n��֮������ڡ�
class Data
{
private:
	int m_year;
	int m_month;
	int m_day;
public:
	Data(int year, int month, int day);
	friend ostream & operator << (ostream & os, Data & data);
	Data operator + (int N_Day)const;
	Data operator = (Data & data);
	Data operator ++ ();
	Data operator -- ();
	Data operator - (int N_Day)const;
	bool operator < (Data & data)const;
	bool operator > (Data & data)const; 
	bool operator <= (Data & data)const;
	bool operator >= (Data & data)const;
	bool operator == (Data & data)const;
	bool operator != (Data & data)const;
	
};
int Yearday(int year, int month, int day);//��������������ĵڼ���
int MonthDay(int year, int month);//�ж�����������м���
int IsLeap(int year);//�ж�����֪��Ϊ����