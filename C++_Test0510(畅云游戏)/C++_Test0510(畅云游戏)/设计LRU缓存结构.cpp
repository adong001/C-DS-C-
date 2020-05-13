#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

struct Elem
{
	int m_key;
	int m_value;

	Elem operator = (Elem e)
	{
		m_key = e.m_key;
		m_value = e.m_value;
		return *this;
	}
};

class LRU
{
private:
	int m_size;
	list<Elem> m_lkv;
	unordered_map<int, list<Elem>::iterator> m_umlit;

public:
	LRU(int size) :
		m_size(size)
	{}

	void Set(Elem k_val)
	{
		if (m_umlit.find(k_val.m_key) == m_umlit.end())//������
		{
			if (m_lkv.size() == m_size)//��������
			{
				//back��������ã�front�������
				int k = m_lkv.back().m_key;
				m_lkv.pop_back();//ɾ������õ�
				m_umlit.erase(k);//map��Ҳɾ������õ�Ԫ��
			}
			m_lkv.push_front(k_val);//����µ�Ϊ��õ�
			m_umlit[k_val.m_key] = m_lkv.begin();//����ӵ�secondΪ����m_lkv��λ��

			
		}
		else//Ҫ��ӵ�Ԫ�ش��ڣ��Ǿ��޸�����value
		{
			auto itl = m_umlit[k_val.m_key];
			itl->m_value = k_val.m_value;
			Elem tmp = *itl;//������޸ĵ�Ԫ�ر����õģ��ȱ���������ɾ������������frontλ�ü���
			m_umlit.erase(itl->m_key);
			m_umlit[k_val.m_key] = m_lkv.begin();
			m_lkv.push_front(tmp);
		}
	}

	void Get(int key)
	{
		if (m_umlit.find(key) == m_umlit.end())//������
		{
			cout << -1 << endl;
		}
		else//����
		{
			//������޸ĵ�Ԫ�ر����õģ��ȱ���������ɾ������������frontλ�ü���
			auto itl = m_umlit[key];
			Elem tmp = *itl;
			m_lkv.erase(itl);
			m_lkv.push_front(tmp);
			m_umlit[key] = m_lkv.begin();
			cout << tmp.m_value << endl;
		}
	}

};



int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		int op,ky;
		Elem tmp;
		LRU lru(k);
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> op;
			if (op == 1)//set����
			{
				cin >> tmp.m_key >> tmp.m_value;
				lru.Set(tmp);
			}
			else //get����
			{
				cin >> ky;
				lru.Get(ky);
			}
		}
	}
    return 0;
}