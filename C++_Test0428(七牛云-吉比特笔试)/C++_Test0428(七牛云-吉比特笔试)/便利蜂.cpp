#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int GetMaxBag(int n, vector<int> w, vector<int> v)
{
	if (n < 1 || w.empty() || v.empty())
	{
		return 0;
	}
	int N = w.size();
	int M = n + 1;
	vector<vector<int>> dp(N, vector<int>(M, 0));
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			//��i����Ʒ��A�ж�Ӧ������Ϊi-1: i��1��ʼ
			//�����i����Ʒ����j,˵���Ų��£� ����(i,j)������ֵ��(i-1,j)��ͬ
			if (w[i - 1] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			//�������װ�£������������װ���߲�װ
			//�����װ����Ϊ(i-1, j)
			//���װ����Ҫ�ڳ��ŵ�i����Ʒ��С�Ŀռ䣺 j - A[i-1],
			//װ��֮�������ֵ��Ϊ(i - 1, j - A[i - 1]) + ��i����Ʒ�ļ�ֵV[i - 1]
			//�����װ�벻װ��ѡ�����ļ�ֵ
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
			}
		}
	}
	return dp[N - 1][M - 1];
}

int main()
{
	int n;
	while (cin >> n)
	{
		string s1, s2;
		cin >> s1;
		cin >> s2;
		int len1 = s1.size();
		int len2 = s2.size();
		vector<int> w;
		vector<int> v;
		for (int i = 0; i < len1;)
		{
			string tmp;
			if (s1[i] == ',')
			{
				i++;
				continue;
			}
			for (; i < len1 && s1[i] != ','; i++)
			{
				tmp += s1[i];
			}
			w.push_back(atoi(tmp.c_str()));
		}
		for (int i = 0; i < len2;)
		{
			string tmp;
			if (s2[i] == ',')
			{
				i++;
				continue;
			}
			for (; i < len2 && s2[i] != ','; i++)
			{
				tmp += s2[i];
			}
			v.push_back(atoi(tmp.c_str()));
		}
		cout << GetMaxBag(n, w, v) << endl;
	}
    return 0;
}