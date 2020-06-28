#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//struct Data
//{
//	char a;
//	int b;
//	long long c;
//	char d;
//};
//Data data[2][10];
int main1()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int n1 = s1.size();
		int n2 = s2.size();
		int i, j;
		int flag = 1;
		vector<vector<int>> vv(n1 + 1, vector<int>(n2 + 1, 0));
		for (i = 0; i <= n1; i++)
		{
			vv[i][0] = i;
		}
		for (i = 1; i <= n2; i++)
		{
			vv[0][i] = i;
		}
		for (i = 1; i <= n1; i++)
		{
			for (j = 1; i <= n2; i++)
			{
				flag = s1[i] == s2[j] ? 0 : 1;
				//���������һ���ַ��Ƿ���ͬ,����ͬ��ֻ��vv[i-1][j-1]�޸�һ�ξ������
				//4�������
				//1.s2[j-1]��s2[j]�Ļ������޸�һ�εõ�s1[i]
				//2.s1[i-1]��s1[i]�Ļ������޸�һ�εõ�s2[j]
				//3.s1[i-1]��s2[j-1]��ͬʱ��s1[i]�õ�s2[j]����s1[i-1]�õ�s2[j-1]
				//4.s1[i-1]��s2[j-1]��ͬʱ��s1[i]�õ�s2[j]���ǽ�s1[i]��s2[j]�޸�һ��
				vv[i][j] = min(min(vv[i][j - 1]+1, vv[i - 1][j]+1),vv[i-1][j-1] + flag);
			}
		}
		cout << vv[i][j] << endl;
	}
    return 0;
}