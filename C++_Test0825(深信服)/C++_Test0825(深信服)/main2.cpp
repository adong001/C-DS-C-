#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int GetPlanNums(vector<int>& goods, int n, int m, int k)
{
	//˼·�����ҳ�һ����������k�����䣬�жϳ����Ƿ����m,С�ھ�����һ�����䣬���ھ�++�������ķ�����
	//���������㣺[start,end]�����ڣ�������=(end-start)-m+1
	int start = 0;
	int end = 0;
	int cnts = 0;//������
	for (; start < n; start = end)
	{
		//1.�ҳ�һ����������k������
		for (; end < n && goods[end] >= k; end++);

		//2.�ó�����plan��
		//���䳤�ȴ���m
		if ((end - start) >= m)
		{
			cnts += ((end - start) - m + 1);
			//Խ��С��k������
		}
		for (; end < n && goods[end] < k; end++);
	}
	return cnts;
}

int main3()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		vector<int> goods(n);
		for (int i = 0; i < n; i++)
		{
			cin >> goods[i];
		}
		cout << GetPlanNums(goods, n, m, k) << endl;
	}
	return 0;
}