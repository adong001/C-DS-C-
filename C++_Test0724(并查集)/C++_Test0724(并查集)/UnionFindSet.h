#pragma once
#include<vector>
#include<list>
#include<iostream>
using namespace std;

class UnionFindSet
{
private:
	vector<int> m_a;

public:
	UnionFindSet(size_t Size = 0)//���캯��
	{
		m_a.resize(Size, -1);
	}
	UnionFindSet(const vector<int>& v):
		m_a(v)
	{}

	int FindRoot(int index)//����index�ĸ�
	{
		while (m_a[index] >= 0)
		{
			//ÿ��Ԫ�ش洢��ֵ�Ǹ��ڵ���±�(>=0)��ֻ�и��ڵ�洢����������ϵĸ���(<0)
			index = m_a[index];
		}
		return index;
	}

	bool Union(int x1, int x2)//�ϲ���������
	{
		if (x1 == x2)
		{
			return true;
		}
		int root1 = FindRoot(x1);//�ҵ����ڵ���±�
		int root2 = FindRoot(x2);
		if (root1 != root2)//����һ�����ϲźϲ�
		{
			if (m_a[root1] > m_a[root2])//��֤root1Ϊ�󼯺ϣ�С���Ϻϲ����󼯺���
			{
				int tmp = root1;
				root1 = root2;
				root2 = tmp;
			}
			m_a[root1] += m_a[root2];//���ڵ��ֵ�����ºϲ��ĸ���
			m_a[root2] = root1;//���ϲ����ϵĸ��ڵ��ֵ����µĸ��ڵ���±�
			return true;
		}
		return false;
	}
		
	size_t Count()const//ͳ�Ƹ��ĸ���,�����ϵĸ���
	{
		size_t cnts = 0;
		for (auto& e : m_a)
		{
			if (e < 0)
			{
				cnts++;
			}
		}
		return cnts;
	}
};