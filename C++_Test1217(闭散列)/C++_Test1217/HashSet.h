#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

namespace YD
{
	class DealInt//�º���,����ֵ����Ϊintʱ����int
	{
	public:
		int operator ()(const int num)
		{
			return num;
		}
	};

	class DealString//����ֵ����Ϊstringʱ�����int����
	{
	public:
		int operator ()(const string& str)
		{
			int seed = 128;//����
			int sum = 0;
			for (auto& e : str)
			{
				sum = seed * sum + e;//128���ƣ���һλ�ǵ�һ���ַ����ڶ�λ�ǵڶ����ַ�
			}
			return sum & 0x7fffffff;//����Խ�磬ȡ��32λ����(��תҲ�У�����ʽת��)
		}
	};

	enum Status//����Ԫ�ص�״̬
	{
		EMPTY,//��
		EXIST,//����Ԫ��
		DELETE//��ɾ������λ�ÿ��Բ��룬�����滹����ͬKeyֵ��Ԫ��
	};

	template<class Value>
	struct Elem//ÿ��Ԫ�ص�����
	{
		Value m_val;//ֵ
		Status m_status;//״̬
		Elem(const Value& value = Value(), const Status& status = Status()) :
			m_val(value),
			m_status(status)
		{}
	};

	template<class Value, class DealFunc = DealInt>
	class HashSet//��ɢ������̽��
	{
	private:

		vector<Elem<Value>> m_table;//��ϣ����
		size_t m_size;//��ϣ��Ԫ�صĸ���
		static long long s_m_primeTable[30];//��ϣ������ĳ��ȵ�����
		//�����Ԫ�ض����������ڶ��������ǵ�һ���������������������Ǹ��������Դ�����
		//����ѧ���ۿ�֪��ʹ�ó�������������ϣ���������Ϊ����ʱ��������ϣ��ͻ�ĸ�����ͣ�
		//��Ϊ��ÿ�ζ�Ҫmod�����������������Ϊ����ʱ������������ֻ���Լ���1��������ͻֻ��
		//��������һ��
		static int s_m_PrimePos;//��ϣ������ĳ��ȵ�������±�

		int HashFunc(const Value& value)//��ɢ������̽��
		{
			DealFunc func;//�ȸ���Ԫ�ص����ͷֱ����int��
			return func(value) % capacity();//���ó�����������ȡKeyֵ
		}


		void CheckCapacity()
		{
			if (m_size * 100 / capacity() >= 70)//�غ�����������0.7---0.8֮��
				//�غ����� = m_size / m_table.size();
			{
				HashSet<Value> newHt(s_m_primeTable[++s_m_PrimePos]);
				for (int i = 0; i < capacity(); i++)
				{
					if (m_table[i].m_status == EXIST)
					{
						newHt.insert(m_table[i].m_val);
					}
				}
				swap(newHt);
			}
		}

	public:
		HashSet(size_t capacity = 11) ://���캯��
			m_table(capacity),//ע�⣺m_table.size()�ǹ�ϣ���������m_size�ǵ�ǰ�����м���Ԫ��
			m_size(0)
		{
			for (int i = 0; i < capacity; i++)//��ʼ��״̬
			{
				m_table[i].m_status = EMPTY;
			}
		}

		//vector<Elem> Table()//
		//{
		//	return m_table;
		//}
		size_t size()const//��ϣ������ڵ�Ԫ�صĸ���
		{
			return m_size();
		}

		size_t capacity()const//���ع�ϣ���������
		{
			return m_table.size();
		}

		bool empty()const//�жϹ�ϣ�����Ƿ�Ϊ��
		{
			return m_size == 0;
		}

		void swap(HashSet<Value>& ht)//��������Ԫ�ص�λ��
		{
			m_table.swap(ht.m_table);
		}

		bool insert(const Value& p)//����Ԫ��
		{
			CheckCapacity();//����Ƿ����㹻�������Բ���

			int n = HashFunc(p);//��ȡ���ļ�ֵ
			while (m_table[n].m_status == EXIST)//��������Ѿ�����Ԫ�أ����������̽��
			{
				if (m_table[n].m_val == p)
				{
					return false;
				}
				n = (n == capacity()) ? 0 : n + 1;//�����һ��Ԫ�ػ�û��̽�����������һ������ѭ��̽��
				//��Ϊ��һ���Ѿ�CheckCapacity������֤��
			}

			m_table[n].m_val = p;//�ҵ����ʵ�λ�ã��޸��Ǹ�λ�õ�ֵ��״̬
			m_table[n].m_status = EXIST;
			m_size++;//��ϣ���������Ԫ�س���++
			return true;
		}


		int Find(const Value& value)//����Ԫ��
		{
			int n = HashFunc(value);//��ȡ������Ԫ�صļ�
			int flag = n;//��¼��
			while (m_table[n].m_status != EMPTY)//�����λ�õ�״̬����Ԫ�ػ���ɾ��
			{
				if (m_table[n].m_status == EXIST && m_table[n].m_val == value)
				{//�ҵ�״̬ΪԪ�ش�����ֵ���ڲ��ҵ�Ԫ�ؾͷ��������±�
					return n;
				}
				n = (n == m_size) ? 0 : n + 1;//ѭ��
				if (flag == n)
				{
					return -1;//ѭ���һ�����û�оͷ���-1
				}
			}
			return -1;
		}

		bool erase(const Value& value)//ɾ��Ԫ��
		{
			int ret = Find(value);//��ȡ��ɾ��Ԫ�صļ�
			if (ret < 0)//�Ȳ��ң����Ҳ�����ֱ��return
			{
				return false;
			}

			else//�ҵ��ͽ��Ǹ�λ�õ�״̬��ΪDELETE,��ֹ�Ҳ��������Ԫ��ͬһ����Ԫ��
			{
				m_table[ret].m_status = DELETE;
				m_size--;
				return true;
			}
		}

		void claer()
		{
			m_table.clear();
			m_size = 0;
		}

	};
		
	template<class Value, class DealFunc>
	long long HashSet<Value, DealFunc>::s_m_primeTable[30] = {
		11, 23, 47, 89, 179,
		353, 709, 1409, 2819, 5639,
		11273, 22531, 45061, 90121, 180233,
		360457, 720899, 1441807, 2883593, 5767169,
		11534351, 23068673, 46137359, 92274737, 184549429,
		369098771, 738197549, 1476395029, 2952790016u, 4294967291u };
	template<class Value, class DealFunc>
	int HashSet<Value, DealFunc>::s_m_PrimePos = 0;
};