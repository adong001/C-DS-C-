#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


//����ĳ�ϰ���Ҫһ���ܿ��ټ��㶩���۸�ĳ�������������һ���ࣺ
//1�����������Ҫԭ�ۺ�������ԭ�۴�һ�������ж������ɣ����ж������飩��������Ҫ��ʼ����
//2���ϰ�᲻���ڵ����۸񣬵����ķ�ʽ��ͨ������һ���۸�ϵ�������ϵ������ԭ�ۼ�Ϊ���ռ۸�
//����ۿۻ�Ӱ�쵽���в�Ʒ��������Ƴ�һ���������ϰ����ɸ㶨��һ�С�
class Goods
{
private:
	static double m_discount;//�ۿ�
	static int m_kinds;//��Ʒ����
	double m_price;//����
	int m_amount;//����
	static void Purchase();//����
	static void ShowMenu 
public:
	Goods(float price = 0, int amount = 0);
	void Discount(int discount);
	

};
int Goods::m_kinds = 0;
double Goods::m_discount = 1;
void BossMenu();
