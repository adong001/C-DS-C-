#include"data.h"


Data::Data(int year, int month, int day)
{
	m_year = year;
	m_month = month;
	m_day = day;
}


ostream & operator << (ostream & os, Data & data)
{
	os << data.m_year << "��" << data.m_month << "��" << data.m_day << "��" << endl;
	return os;
}
Data Data::operator + (int N_Day)const
{
	Data tmp = *this;
	if (!N_Day)
	{
		return tmp;
	}
	while (N_Day)//Ҫ��ת��������Ϊѭ���˳�����
	{
		if (N_Day >= 366)
		{
			if ((tmp.m_month >= 3 && IsLeap(tmp.m_year + 1)) || (tmp.m_month <= 2 && IsLeap(tmp.m_year)))
			//if (IsLeap(tmp.m_year))
			{
				N_Day -= 366;
			}
			else
			{
				N_Day -= 365;
			}
			tmp.m_year += 1;
			continue;
		}
		int _MonthDay = MonthDay(tmp.m_year, tmp.m_month);//�õ���������µ�����
		if (N_Day <= (_MonthDay - tmp.m_day))//�ж�Ҫ��ת���������Ͻ���������Ƿ�������µ�������
		{
			tmp.m_day += N_Day;
			return tmp;
		}
		else//����ʣ������������ת������
		{
			N_Day -= (_MonthDay - tmp.m_day);//����������-������գ��������¿�������������
			tmp.m_day = 0;//��������Ϊ0,����������¼Ӽ�
			tmp.m_month++;//����������month++

			if (tmp.m_month == 13)//��monthԽ��
			{
				tmp.m_year++;//�����µ�һ��
				tmp.m_month = 1;
			}
		}
	}
	return tmp;
}

Data Data::operator = (Data & data)
{
	m_year = data.m_year;
	m_month = data.m_month;
	m_day = data.m_day;
	return *this;
}

Data Data::operator ++ ()
{
	return (*this= (*this + 1));
}

Data Data::operator -- ()
{
	return (*this = (*this - 1));
}

Data Data:: operator -(int N_Day)const
{
	Data tmp = *this;
	if (!N_Day)
	{
		return tmp;
	}
	while (N_Day)//Ҫ��ת��������Ϊѭ���˳�����
	{
		if (N_Day >= 366)
		{
			if ((tmp.m_month >= 3 && IsLeap(tmp.m_year))||(tmp.m_month<=2 && IsLeap(tmp.m_year - 1)))
			{
				N_Day -= 366;
			}
			else
			{
				N_Day -= 365;
			}
			tmp.m_year -= 1;
		}
		else if (N_Day <= tmp.m_day)//�ж�Ҫ��ת���������Ͻ���������Ƿ�������µ�������
		{
			tmp.m_day -= N_Day;
			if (tmp.m_day == 0)//��ֹ��Ϊ0
			{
				tmp.m_month--;//����������month++
				if (tmp.m_month == 0)//��monthԽ��
				{
					tmp.m_year--;//�����µ�һ��
					tmp.m_month = 12;
				}
				tmp.m_day = MonthDay(tmp.m_year, tmp.m_month);;//������Ϊ���µ����һ��
			}
			return tmp;
		}
		else//����ʣ������������ת������
		{
			N_Day -= tmp.m_day;//����������-������գ��������¿�������������	
			tmp.m_month--;//����������month++
			if (tmp.m_month == 0)//��monthԽ��
			{
				tmp.m_year--;//�����µ�һ��
				tmp.m_month = 12;
			}
			tmp.m_day = MonthDay(tmp.m_year, tmp.m_month);;//������Ϊ���µ����һ��
		}
	}
	return tmp;
}
bool Data:: operator <(Data & data)const
{
	if (m_year < data.m_year)
	{
		return true;
	}
	else if (m_year == data.m_year)
	{
		if (m_month < data.m_month)
		{
			return true;
		}
		else if (m_month == data.m_month)
		{
			if (m_day < data.m_day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Data:: operator >(Data & data)const
{
	if (m_year > data.m_year)
	{
		return true;
	}
	else if (m_year == data.m_year)
	{
		if (m_month > data.m_month)
		{
			return true;
		}
		else if (m_month == data.m_month)
		{
			if (m_day > data.m_day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Data:: operator <=(Data & data)const
{
	return !(*this>data);
}

bool Data:: operator >=(Data & data)const
{
	return !(*this < data);
}

bool Data:: operator ==(Data & data)const
{
	return (m_year == data.m_year && 
		    m_month == data.m_month &&
			m_day == data.m_day);
}

bool Data:: operator !=(Data & data)const
{
	return !(*this == data);
}

int Yearday(int year, int month, int day)
{
	int ArrMon[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int num = day;
	for (int i = 1; i < month;i++)
	{
		num += ArrMon[i];
	}
	if (IsLeap(year))
	{
		num++;
	}
	return num;
}

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