#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class LRUCache
{
private:
	//first�洢key,second�洢����list��val�ĵ�����
	unordered_map<int, list<int>::iterator> m_ht;
	//list�洢val
	list<int> m_lt;
	int m_capacity;
	
public:

	LRUCache(int capacity) :
		m_capacity(capacity)
	{}

	int get(int key)
	{
		auto it = m_ht.find(key);//
		if (it != m_ht.end())//�ҵ�
		{
			m_lt.push_front(*it->second);//�Ȱ�get��ֵ���µ���һ��
			m_lt.erase(it->second);//ɾ��ԭ����λ��
			m_ht[key] = m_lt.begin();
			return m_lt.front();//
		}
		return -1;
	}

	void put(int key, int value)
	{
		auto it = m_ht.find(key);
		if (it != m_ht.end())//�ҵ�
		{
			m_lt.push_front(value);//�Ȱ�get��ֵ���µ���һ��
			m_lt.erase(it->second);//ɾ��ԭ����λ��
			m_ht[key] = m_lt.begin();
			return;
		}
		else//���ݲ����ڣ���Ҫ���
		{
			if (m_ht.size() == m_capacity)//LRU�Ѿ����ˣ���Ҫɾ��һ��
			{
				if (m_ht.size() == 1)
				{
					
				}
				m_ht.erase(m_lt.back());//ɾ����ϣ���е�����õ�
				m_lt.pop_back();//ɾ������������õ�
			}
			m_lt.push_front(value);
			m_ht[key] = m_lt.begin();
		}
	}
};

int main()
{
	LRUCache lru(1);
	lru.put(2,1);
	lru.get(2);
	lru.put(3, 2);
	lru.get(2);
	lru.get(3);
	
    return 0;
}