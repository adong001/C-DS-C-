#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

namespace YD
{
	class DealInt
	{
	public:
		int operator ()(const int num)
		{
			return num;
		}
	};

	class DealString
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

	template<class T>//�ڵ���
	class HashBucketNode
	{
		T m_val;
		HashBucketNode<T>* m_next;
		HashBucketNode(const T& val = T()) :
			m_val(val),
			m_next(nullptr)
		{}
		template<class T, class SW>
		friend class HashSet;
	};

	template<class T, class SW>
	class iterator//��������
	{
	private:
		unordered_set<T, SW>* m_it;
		
	};


	template<class T, class SW = DealInt>
	class unordered_set//��ɢ������̽��
	{
	private:
		vector<HashBucketNode<T>*> m_data;//����ָ��
		size_t m_size;//�Ѳ���Ԫ�صĸ���
		static long long s_m_primeTable[30];//��ϣ������ĳ��ȵ�����
		//�����Ԫ�ض����������ڶ��������ǵ�һ���������������������Ǹ��������Դ�����
		//����ѧ���ۿ�֪��ʹ�ó�������������ϣ���������Ϊ����ʱ��������ϣ��ͻ�ĸ�����ͣ�
		//��Ϊ��ÿ�ζ�Ҫmod�����������������Ϊ����ʱ������������ֻ���Լ���1��������ͻֻ��
		//��������һ��
		static int s_m_PrimePos;//��ϣ������ĳ��ȵ�������±�

		int HashFunc(const T& value)//��ɢ������̽��
		{
			SW func;//�ȸ���Ԫ�ص����ͷֱ����int��
			return func(value) % capacity();//���ó�����������ȡKeyֵ
		}

		void CheckCapacity()
		{
			if (m_size * 100 / capacity() >= 70)//�غ�����������0.7---0.8֮��
				//�غ����� = m_size / m_table.size();
			{
				vector<HashBucketNode<T>*> tmp(s_m_primeTable[++s_m_PrimePos], nullptr);
				HashBucketNode<T>* cur;
				tmp.swap(m_data);
				m_size = 0;
				for (int i = 0; i < tmp.size(); i++)
				{
					for (cur = tmp[i]; cur; cur = cur->m_next)
					{
						insert(cur->m_val);
					}
				}
				tmp.clear();
			}
		}

	public:
		unordered_set(size_t capacity = s_m_primeTable[0]) ://���캯��
			m_data(capacity, nullptr),//ע�⣺m_table.size()�ǹ�ϣ���������m_size�ǵ�ǰ�����м���Ԫ��
			m_size(0)
		{}

		size_t size()const//��ϣ������ڵ�Ԫ�صĸ���
		{
			return m_size();
		}

		size_t capacity()const//���ع�ϣ���������
		{
			return m_data.size();
		}

		bool empty()const//�жϹ�ϣ�����Ƿ�Ϊ��
		{
			return m_size == 0;
		}

		void swap(unordered_set<T, SW>& ht)//��������Ԫ�ص�λ��
		{
			m_data.swap(ht);
		}

		bool insert(const T& val)//����Ԫ��
		{
			CheckCapacity();//����Ƿ����㹻�������Բ���

			int n = HashFunc(val);//��ȡ���ļ�ֵ
			HashBucketNode<T>* tmp;
			if (m_data[n])//���������ͷ����Ϊ�գ������
			{
				for (tmp = m_data[n]; tmp; tmp = tmp->m_next)
				{
					if (tmp->m_val == val)//�ҵ���ͬ��return 
					{
						return false;
					}
				}
			}
			tmp = new HashBucketNode<T>(val);
			tmp->m_next = m_data[n];//ͷ��
			m_data[n] = tmp;
			m_size++;
			return true;
		}


		HashBucketNode<T>* Find(const T& value)//����Ԫ��
		{
			int n = HashFunc(value);//��ȡ������Ԫ�صļ�
			HashBucketNode<T>* cur;

			for (cur = m_data[n]; cur; cur = cur->m_next)
			{
				if (cur->m_val == value)
				{
					return cur;
				}
			}
			return nullptr;
		}

		bool erase(const T& value)//ɾ��Ԫ��
		{
			int n = HashFunc(value);//��ȡ������Ԫ�صļ�
			HashBucketNode<T>* tmp;
			HashBucketNode<T>* cur;
			if (m_data[n])//ȷ�����Ͱ����Ԫ��
			{
				if (m_data[n]->m_val == value)//ͷ�����Ǵ�ɾֵ
				{
					tmp = m_data[n];
					m_data[n] = tmp->m_next;
					delete tmp;
				}
				else//ɾ��Ԫ�����м�򲻴���
				{
					for (tmp = m_data[n]; tmp->m_next; tmp = tmp->m_next)
					{
						if (tmp->m_next->m_val == value)
						{
							cur = tmp->m_next;
							tmp->m_next = cur->m_next;
							delete cur;
							break;
						}
					}
				}
				m_size--;
				return true;
			}
			return false;
		}

		void clear()
		{
			HashBucketNode<T>* tmp;
			for (auto& head : m_data)
			{
				while (head)
				{
					tmp = head;
					head = head->m_next;
					delete tmp;
				}
			}
			m_size = 0;
		}

		~unordered_set()
		{
			clear();
		}

	};
	template<class T, class SW>
	long long unordered_set<T, SW>::s_m_primeTable[30] = {
		11, 23, 47, 89, 179,
		353, 709, 1409, 2819, 5639,
		11273, 22531, 45061, 90121, 180233,
		360457, 720899, 1441807, 2883593, 5767169,
		11534351, 23068673, 46137359, 92274737, 184549429,
		369098771, 738197549, 1476395029, 2952790016u, 4294967291u };
	template<class T, class SW>
	int unordered_set<T, SW>::s_m_PrimePos = 0;
};