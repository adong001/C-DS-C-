#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int N, M;//�Թ��ĺ�������
vector<vector<int>> maze;//�Թ�
vector<vector<int>> path_tmp;//·��
vector<vector<int>> path_best;//����·��

void FindPath(int n, int m)
{
	maze[n][m] = 1;//����Ϊ����
	path_tmp.push_back({ n, m });//����ǰ·���������
	if (n == N - 1 && m == M - 1)//�ߵ��յ�
	{
		//����ҵ���·��������·��֮ǰΪ�գ���������������·��
		//����ҵ���·������С��֮ǰ�ҵ���·������������������·��
		if (path_best.empty() || path_tmp.size() < path_best.size())
		{
			path_best = path_tmp;
		}
	}
	if (n + 1 < N && maze[n + 1][m] != 1)
	{
		FindPath(n + 1, m);
	}
	if (m + 1 < M && maze[n][m + 1] != 1)
	{
		FindPath(n, m + 1);
	}
	if (n - 1 >= 0 && maze[n - 1][m] != 1)
	{
		FindPath(n - 1, m);
	}
	if (m - 1 >= 0 && maze[n][m - 1] != 1)
	{
		FindPath(n, m - 1);
	}
	maze[n][m] = 0;//���λ���������н���󣬻ָ��ֳ�
	path_tmp.pop_back();//����ǰλ���˳�
}

int main2()
{
	while (cin >> N >> M)
	{
		maze.resize(N,vector<int>(M,0));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> maze[i][j];
			}
		}
		FindPath(0, 0);
		for (int i = 0; i < path_best.size(); i++)
		{
			cout << "(" << path_best[i][0] << "," << path_best[i][1] << ")" << endl;
		}
	}
    return 0;
}