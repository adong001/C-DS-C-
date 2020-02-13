#pragma once
#include <iostream>
#include<string>
#include<vector>
#include <unordered_map>
#include<algorithm>
using namespace std;

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
		return sum & 0x7fffffff;//����Խ�磬ȡ��32λ����(��תҲ�У�����ʿת��)
	}
};

enum Status
{
	EMPTY,
	EXIST,
	DELETE
};


template<class Key, class Value,class DealFunc = DealInt>
class HashTable
{
private:

	struct Elem
	{
		pair<Key, Value> m_val;
		Status m_status;
		Elem(const Key& key = Key(), const Value& value = Value(), const Status& status = Status()) :
			m_val(key, value),
			m_status(status)
		{}
	};

	vector<Elem> m_table;
	size_t m_size;

	int HashFunc(const Key& key)//��ϣ�㷨���������Զ���
	{
		DealFunc func;
		return func(key) % m_table.capacity();
	}


public:

	HashTable(size_t capacity = 11) :
		m_table(capacity),//ע�⣺m_table.size()�ǹ�ϣ����������m_size�ǵ�ǰ�����м���Ԫ��
		m_size(0)
	{}

	//���ڻ�û��ʵ�ֵ�����������������һ���ӿڷ��ʱ������Ԫ��
	vector<Elem> Table()
	{
		return m_table;
	}

	size_t capacity()
	{
		return m_table.size();
	}

	bool empty()
	{
		return m_size == 0;
	}

	void swap(HashTable<Key, Value>& ht)
	{
		m_table.swap(ht.m_table);
		swap(m_size, ht.m_size);
	}

	bool insert(const pair<Key, Value>& p)
	{
		/*if (!checkCapacity())//����Ƿ����㹻�������Բ���
		{
			return false;
		}*/

		int n = HashFunc(p.first);
		while (m_table[n].m_status == EXIST)
		{
			if (m_table[n].m_val.first == p.first)
			{
				return false;
			}
			n = (n == capacity()) ? 0 : n + 1;
		}

		m_table[n].m_val = p;
		m_table[n].m_status = EXIST;
		m_size++;
		return true;
	}


	int Find(const Key& key)
	{
		int n = HashFunc(key);
		int flag = n;//��¼�����λ��
		while (m_table[n].m_status != EMPTY)
		{
			if (m_table[n].m_status == EXIST && m_table[n].m_val.first == key)
			{
				return n;
			}
			n = (n == m_size) ? 0 : n + 1;
			if (flag == n)
			{
				return -1;//ѭ���һ�����˵��û�д˼�ֵ��
			}
		}
	}

	bool erase(const Key& key)
	{
		int ret = Find(key);

		if (ret < 0)
		{
			return false;
		}

		else
		{
			m_table[ret].m_status = DELETE;
			m_size--;
		}
	}

};