#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n, 0);
		vector<int> tmp(n, 1);
		int money = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		for (int i = 1; i<n; i++)//�����
		{
			if (v[i] > v[i - 1])
			{
				tmp[i] = tmp[i - 1] + 1;
				money += tmp[i];
			}
		}
		for (int i = n-2; i >= 0; i--)//�����ټ�һ�β���ƽ��
		{
			if (v[i] > v[i + 1] && tmp[i] < tmp[i+1] + 1)
			{
				tmp[i] = tmp[i + 1] + 1;
				money++;
			}
		}
		cout << money << endl;
	}
	return 0;
}