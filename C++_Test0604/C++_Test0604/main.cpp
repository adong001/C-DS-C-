#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class A
//{
//private:
//	int a;
//public:
//
//	static int b;
//};
//int A::b = 0;
class Date
{
public:
	//Date(int year)
	//	:_year(year)
	//{}
explicit Date(int year)
:_year(year)
{}

private:
	int _year;
	int _month;
	int _day;
};
		void TestDate()
	{
			Date d1(2018);

			// ��һ�����α������������Ͷ���ֵ
			// ʵ�ʱ������������2019����һ������������������������d1������и�ֵ 
			d1 = 2019;
		}
int main()
{
	TestDate();
	//A::b = 0;
	//cout << sizeof(A) << endl;
    return 0;
}