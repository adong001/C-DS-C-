#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int backpack(int m, vector<int>& A, vector<int>& V)
{
	if (A.empty() || V.empty() || m < 1)
	{
		return 0;
	}
	const int N = A.size();
	//���һ�У��������ó�ʼ��������Ϊ��һ����ƷҪ�õ�ǰ��ĳ�ʼֵ
	const int M = m + 1;
	vector<int> result;
	//��ʼ������λ��Ϊ0����һ�ж�Ϊ0����ʼ����
	result.resize(M, 0);
	//������Ʒ������λ�ò���Ҫƫ�ƣ�Ҫ��δ�Ż��ķ������ֿ�
	//�����i-1���Ϊ��һ�У�����δ���µ�һά����ֵ
	for (int i = 0; i != N; ++i)
	{
		for (int j = M - 1; j > 0; --j)
		{
			//�����i����Ʒ����j,˵���Ų��£� ����(i,j)������ֵ��(i-1,j)��ͬ
			if (A[i] > j)
			{
				result[j] = result[j];
			}
			//�������װ�£������������װ���߲�װ
			//�����װ����Ϊ(i-1, j)
			//���װ����Ҫ�ڳ��ŵ�i����Ʒ��С�Ŀռ䣺 j - A[i],װ��֮�������ֵ��Ϊ(i - 1, j A[i-1]) + ��i����Ʒ�ļ�ֵV[i]
			//�����װ�벻װ��ѡ�����ļ�ֵ
			else
			{
				int newValue = result[j - A[i]] + V[i];
				result[j] = max(newValue, result[j]);
			}
		}
	}
	//����װ��ǰN����Ʒ����Ʒ��СΪm������ֵ
	return result[m];
}

int main2()
{
	//��Ϸ�������������
	int Games, PlayDays;
	//�������һ��01�����任��
	while (cin >> Games >> PlayDays)
	{
		vector<int> A(Games);//��Ϸ����
		vector<int> V(Games);//��Ϸʱ��
		for (int i = 0; i < Games; i++)
		{
			cin >> A[i] >> V[i];
		}
		cout << backpack(PlayDays, A, V) << endl;

	}
	return 0;
}