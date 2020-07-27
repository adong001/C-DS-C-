#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class LRUCache
{
private:
	//first�洢key,second�洢����list��val�ĵ�����
	unordered_map<int, list<pair<int,int>>::iterator> m_ht;
	//list�洢val
	list<pair<int,int>> m_lt;//����洢key��val,����ֻ�洢val,��ɾ��back��ʱ��map�Ҳ���key
	int m_capacity;
public:
	LRUCache(int capacity) :
		m_capacity(capacity)
	{}

	int get(int key)
	{
		auto it = m_ht.find(key);
		if (it != m_ht.end())//�ҵ�
		{
 			//m_lt.splice(m_lt.begin(),m_lt,it->second);//splice(it1,list,it2)�ǰ�list�е�it2��λ�ü��е�it1��λ��
			m_lt.push_front(make_pair(key, it->second->second));//�Ȱ�get��ֵ���µ���һ��
			m_lt.erase(it->second);//ɾ��ԭ����λ��
			m_ht[key] = m_lt.begin();//����map��val��λ��
			return m_lt.front().second;//����list�и��µ�ֵ
		}
		return -1;//û�ҵ��ͷ���-1
	}

	void put(int key, int value)
	{
		auto it = m_ht.find(key);
		if (it != m_ht.end())//�ҵ�
		{
			// m_lt.splice(m_lt.begin(),m_lt,it->second);
			m_lt.push_front(make_pair(key, value));//�Ȱ�put��ֵ���µ���һ��
			m_lt.erase(it->second);//ɾ��ԭ����λ��
			m_ht[key] = m_lt.begin();
		}
		else//���ݲ����ڣ���Ҫ���
		{
			if (m_ht.size() == m_capacity)//LRU�Ѿ����ˣ���Ҫɾ��һ��
			{
				m_ht.erase(m_lt.back().first);//ɾ����ϣ���е�����õ�
				m_lt.pop_back();//ɾ������������õ�
			}
			m_lt.push_front(make_pair(key, value));//��put��ֵ���µ�������ǰ��
			m_ht[key] = m_lt.begin();//����map�е�ֵ
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