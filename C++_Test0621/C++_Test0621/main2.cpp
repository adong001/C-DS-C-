#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int countbottle(int num)
{
	int sum = 0;
	while (num > 1)
	{
		int result = num / 3;//���Զһ���ƿ
		int remainder = num % 3;//�һ���ʣ�༸ƿû��
		sum += result;//�����Ѿ��һ���ƿ�ӣ�
		num = result + remainder;//ʣ��ɶһ��ľ����Ѿ��һ����ϻ�û�һ���
		if (num == 2)//ʣ���ƿ����2ƿ���Խ�һƿ�������ڻ���ȥ
		{
			++sum;
			break;
		}
	}
	return sum;
}
int main2()
{
	int n;
	while (cin >> n)
	{
		cout << countbottle(n) << endl;
	}
    return 0;
}