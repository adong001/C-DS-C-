#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int main1()
{
	//��������ͱߵĸ���,�յ�·��
	int vertex, edge, end;
	int Inf = 0x3fffffff;
	while (cin >> vertex >> edge)
	{
		//�ڽӾ���洢����֮���Ȩֵ;�ȳ�ʼ��Ϊ���ֵ������ͨ
		vector<vector<int>> Graph(vertex, vector<int>(vertex, Inf));
		//������ߵ�ֵ
		int x, y;
		for (int i = 0; i < edge; i++)
		{
			cin >> x >> y;
			cin >> Graph[x][y];
		}
		//�����յ�·��
		cin >> end;
		//�����·����Floyd�㷨����Դ���·��),����Ӧ��
		for (int k = 0; k < vertex; k++)
		{
			for (int i = 0; i <vertex; i++)
			{
				for (int j = 0; j < vertex; j++)
				{
					//i->j���·����iֱ�ӵ�j��i��k,k��j��ӵ������Сֵ
					if (Graph[i][j] > Graph[i][k] + Graph[k][j])
					{
						Graph[i][j] = Graph[i][k] + Graph[k][j];
					}
				}
			}
		}
		cout << Graph[0][end] << endl;
	}
	return 0;
}