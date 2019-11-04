#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
//三、设计一个日期类，包含以下功能：
//1、只能通过传入年月日初始化。
//2、可以加上一个数字n，返回一个该日期后推n天之后的日期。
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
int Yearday(int year, int month, int day);//返回这天是这年的第几天
int MonthDay(int year, int month);//判断这年的这月有几天
int IsLeap(int year);//判断这年知否为闰年