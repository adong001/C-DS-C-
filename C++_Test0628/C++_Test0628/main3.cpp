#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main4()
{
	int n;
	string s;
	while (cin >> n >> s)
	{
		int num = 1, first = 1;
		if (n <= 4)//һҳ����ֱ����ʾ�ĸ�
		{
			for (int i = 0; i < s.size(); i++)
			{
				if (num == 1 && s[i] == 'U')//��ǰλ�ô��ڵ�һ��Ҫ���Ϸ���λ�þͱ�����һ��
				{
					num = n;
				}
				else if (num == n && s[i] == 'D')//��ǰλ�ô������һ��Ҫ���·���λ�þͱ�ɵ�һ��
				{
					num = 1;
				}
				else if (s[i] == 'U')//������
				{
					num--;
				}
				else
				{
					num++;
				}

			}
			for (int i = 1; i <= n - 1; i++)//��ʾ
			{
				cout << i << ' ';
			}
			cout << n << endl;
			cout << num << endl;
		}
		else
		{
			for (int i = 0; i < s.size(); i++)
			{
				//firstΪǰ�߽�
				if (first == 1 && num == 1 && s[i] == 'U')//��ǰΪ��һ��Ҫ���Ϸ���ǰ�߽�first���nǰ��ĵ�����
				{
					first = n - 3;
					num = n;
				}
				else if (first == n - 3 && num == n && s[i] == 'D')//��ǰΪ���һ��Ҫ���·���ǰ�߽�first��ɵ�һ��
				{
					first = 1;
					num = 1;
				}
				else if (first != 1 && first == num && s[i] == 'U')//��ǰλ�ú�ǰ�߽紦��ͬһλ�ã��Ҳ��ǵ�һ�������Ϸ�ת��Ҫ��ǰ�߽�ͬʱ����
				{
					first--;
					num--;
				}
				else if (first != n - 3 && first + 3 == num && s[i] == 'D')//��ǰλ�ú�ǰ�߽����3��λ�ã��Ҳ������һ�������·�ת��Ҫ��ǰ�߽�ͬʱ����
				{
					first++;
					num++;
				}
				else if (s[i] == 'U')//��ǰλ����{ǰ�߽�+1��ǰ�߽�+2֮��},���Ϸ�
				{
					num--;
				}
				else//��ǰλ����{ǰ�߽�+1��ǰ�߽�+2֮��},���·�
				{
					num++;
				}
			}
			for (int i = first; i < first + 3; i++)
			{
				cout << i << ' ';
			}
			cout << first + 3 << endl << num;
			cout << num << endl;
		}
	}
	return 0;
}