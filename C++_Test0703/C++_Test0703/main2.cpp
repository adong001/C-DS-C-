#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int FindNum(vector<int>& arr, int val)//���ھͷ���-1�������ھͷ��ص�һ���������ֵ��
{
	int tmp = arr.size();
	for (int i = 0; i < arr.size(); i++)
	{
		if (val == arr[i])
		{
			return -1;
		}
		if (arr[i] > val)
		{
			tmp = i;
		}
	}
	return tmp;
}

bool GetNum(vector<int>& arr, int val)//�Ƿ�����Ӽ���Ϊval
{
	int ret = FindNum(arr, val);
	if (ret == -1)//���ھͷ�����
	{
		return true;
	}
	for (int i = 0; i < ret; i++)//�����ڣ����ڱ���С������������Ӽ��ҵ�val
	{

	}
}

int getFirstUnFormedNum(vector<int>& arr, int len)
{
	sort(arr.begin(), arr.end());
	for (int i = arr[1]; i < arr[len - 1]; i++)//[min,max]������min��maxһ�����Ӽ���ӵõ����������ж�
	{
		if (!GetNum(arr,i))
		{
			return arr[i];
		}
	}
	return arr[len - 1] + 1;
}
int main()
{
	int len;
	while (cin >> len)
	{
		vector<int> arr(len, 0);
		for (int i = 0; i < len; i++)
		{
			cin >> arr[i];
		}
		cout << getFirstUnFormedNum(arr, len) <<endl;
	}
    return 0;
}