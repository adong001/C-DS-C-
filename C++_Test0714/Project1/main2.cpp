#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> vs(n);
		vector<bool> flag(n, true);
		for (int i = 0; i < n; i++)
		{
			cin >> vs[i];
		}
		sort(vs.begin(), vs.end());
		for (int i = 0; i < n - 1; i++)
		{
			if (vs[i] == vs[i + 1])//��ǰ������һ������ȣ�����ǰ����false
			{
				flag[i] = false;
			}
			//��ǰ������һ�������Ӵ�����ǰ����false
			else if(vs[i].size() < vs[i+1].size() &&
				   vs[i] == vs[i+1].substr(0,vs[i].size()) && 
				   vs[i+1][vs[i].size()] == '\\')
			{
				flag[i] == false;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (flag[i])
			{
				cout << "mkdir -p "<< vs[i] <<endl;
			}
		}
		
	}
    return 0;
}