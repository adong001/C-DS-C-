#include"data.h"

Data::Data(int year, int month, int day, int N_Day)
{
	m_year = year;
	m_month = month;
	m_day = day;
}
//Data::Data(int year, int month, int day, int N_Day)
//{
//	m_year = year;
//	m_month = month;
//	m_day = day;
//	if (N_Day)
//	{
//		FindNData(year,month,day, N_Day);
//		printf("��%d���Ϊ%d��%d��%d��\n", N_Day, year,month, day);
//	}
//}
//void Data::FindNData(int &year, int &month, int &day, int N_Day)
//{
//	while (N_Day)//Ҫ��ת��������Ϊѭ���˳�����
//	{
//if (N_Day >= 366)
//{
//	NewData.m_year + 1;
//	if (IsLeap(NewData.m_year))//������
//	{
//		N_Day -= 366;
//	}
//	else
//	{
//		N_Day -= 365;
//	}
//}
//		int _MonthDay = MonthDay(year, month);//�õ���������µ�����
//		if (N_Day <= (_MonthDay - day))//�ж�Ҫ��ת���������Ͻ���������Ƿ�������µ�������
//		{
//			day += N_Day;
//			return;
//		}
//		else//����ʣ������������ת������
//		{
//			N_Day -= (_MonthDay - day);//����������-������գ��������¿�������������
//			day = 0;//��������Ϊ0,����������¼Ӽ�
//			month++;//����������month++
//
//			if (month == 13)//��monthԽ��
//			{
//				year++;//�����µ�һ��
//				month = 1;
//			}
//		}
//	}
//}

int MonthDay(int year, int month)
{
	int ArrMon[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//�������ȡ��һ��Ԫ�أ�ƽ��1-12���δӵڶ���Ԫ��ȡ
	if (IsLeap(year) && month == 2)//��Ϊ������Ϊ���£�
	{
		return ArrMon[0];
	}
	return ArrMon[month];
}

int IsLeap(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

Data Data:: operator+(int N_Day)const
{
	int _MonthDay;
	Data NewData(m_year, m_month,m_day);
	while (N_Day)//Ҫ��ת��������Ϊѭ���˳�����
	{
		if (N_Day >= 366)
		{
			NewData.m_year += 1;
			if (IsLeap(NewData.m_year))//������
			{
				N_Day -= 366;
			}
			else
			{
				N_Day -= 365;
			}
			continue;
		}
	   _MonthDay = MonthDay(NewData.m_year, NewData.m_month);//�õ���������µ�����
		if (N_Day <= (_MonthDay - NewData.m_day))//�ж�Ҫ��ת���������Ͻ���������Ƿ�������µ�������
		{
			NewData.m_day += N_Day;
			return NewData;
		}
		else//����ʣ������������ת������
		{
			N_Day -= (_MonthDay - NewData.m_day);//����������-������գ��������¿�������������
			NewData.m_day = 0;//��������Ϊ0,����������¼Ӽ�
			NewData.m_month++;//����������month++

			if (NewData.m_month == 13)//��monthԽ��
			{
				NewData.m_year++;//�����µ�һ��
				NewData.m_month = 1;
			}
		}
	}
	return NewData;
}

ostream & operator <<(ostream & os, Data & data)
{
	os << data.m_year << "��" << data.m_month << "��" << data.m_day << "��" << endl;
	return os;
}