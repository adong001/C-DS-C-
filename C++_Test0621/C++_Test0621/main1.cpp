#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string src, det;
	while (cin >> src >> det)
	{
		string ret;
		int max = 0,start;
		if (src.size() > det.size())//��src����С���Ǹ�
		{
			src.swap(det);
		}
		vector<vector<int>> vv(src.size() + 1, vector<int>(det.size() + 1, 0));
		for (int i = 1; i <= src.size(); i++)
		{
			for (int j = 1; j < det.size(); j++)
			{
				if (src[i] == det[j])//�����ַ���ȣ������б�
				{
					vv[i][j] = vv[i][j - 1] + 1;
				}
				if (vv[i][j] > max)
				{
					max = vv[i][j];
					start = i - max;//start��¼��ǰ�ҵ��������������ʼλ�ã�Ϊ��ǰλ��i��ȥmax
				}
			}
		}
		cout << max << endl;
	}
    return 0;
}