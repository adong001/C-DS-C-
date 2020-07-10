#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <cmath>
#include <vector> 
using namespace std;

int MonenyofMonth[] = { 29, 62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62 };//ÿ��ת��Ǯ
int DayofMonth[] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//ÿ������
vector<bool> month_prime = { false, true, true, false, true, //�Ƿ�Ϊ������
							false, true, false, false, false, true, false };
vector<int> year_money = { 580, 579 };//����/������һ�������棬

bool Isleap(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int main()
{
	int y1, m1, d1, y2, m2, d2;
	while (cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2)
	{
		int money = 0;
		bool f1 = Isleap(y1);//�Ƿ�Ϊ����
		bool f2 = Isleap(y2);

		if (y1 == y2 && m1 == m2)//ͬ��ͬ��
		{
			money += month_prime[m1 - 1] ? (d2 - d1 + 1) : (d2 - d1 + 1) * 2;//�������¾�Ҫ*2
		}
		else if (y1 == y2 && m1 != m2)//ͬ�겻ͬ��
		{
			//��ʼ��
			//(DayofMonth[m1] - d1 + 1) --��������һ��-��ʼ����+1��������¾�Ӫ��������
			//Isleap(y1) && m1 == 2) ? 1 : 0 --�������2�����������������������������29Ҫ+1
			//month_prime[m1 - 1] ? 1 : 2 --�����Ϊ�������¾�Ҫ*2
			money += ((DayofMonth[m1] - d1 + 1) + ((f1 && m1 == 2) ? 1 : 0)) * (month_prime[m1 - 1] ? 1 : 2);
			m1++;

			//�м���
			for (; m1 < m2; m1++)
			{
				if (m1 == 2 && f1)//������2�£���һ��
				{
					money++;
				}
				money += MonenyofMonth[m1];
			}

			//������
			money += d2  * (month_prime[m2 - 1] ? 1 : 2);
		}
		else //��ͬ�겻ͬ��
		{
			//��ʼ��
			//��ʼ��
			money += ((DayofMonth[m1] - d1 + 1) + ((f1 && m1 == 2) ? 1 : 0)) * (month_prime[m1 - 1] ? 1 : 2);
			m1++;
			//�м���
			for (; m1 <= 12; m1++)
			{
				if (m1 == 2 && f1)//������2�£���һ��
				{
					money++;
				}
				money += MonenyofMonth[m1];
			}
			y1++;

			//�м���
			for (; y1 < y2; y1++)
			{
				bool f = Isleap(y1);
				money += Isleap(y1) ? year_money[0]: year_money[1];//�����Ƿ�Ϊ���꼴��
			}

			//������
			money += d2 * (month_prime[m2 - 1] ? 1 : 2);
			for (--m2; m2 > 0; m2--)
			{
				if (m2 == 2 && f2)//������2�£���һ��
				{
					money++;
				}
				money += MonenyofMonth[m2];
			}
		}
		cout << money << endl;
	}
    return 0;
}