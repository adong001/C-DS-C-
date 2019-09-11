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
	Data(int year, int month, int day,int N_Day = 0);
	void FindNData(int &year, int &month, int &day, int N_Day);
	Data operator+(int N_Day) const;
	friend ostream & operator <<(ostream & os, Data & data);
};

int MonthDay(int year, int month);//�ж�����������м���
int IsLeap(int year);//�ж�����֪��Ϊ����