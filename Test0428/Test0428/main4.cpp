#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//��4������һ�������������������е��±�
#define ERROR 1
#define LONGERROR -1
#define POINTERROR -2
int Find(int ar[], int p, int n)
{
	if (p == NULL)return POINTERROR;
	if (n < 1)return LONGERROR;
	for (int i = 0; i < n; i++)
	{
		if (p == ar[i]){ return i + 1; }
	}
	return ERROR;
}


int main4()
{
	char ch;

	int a, b, ar[] = { 12, 23, 34, 45, 56, 67, 78, 89, 90, 100 };
	int n = sizeof(ar) / sizeof(ar[0]);
	for (;;)
	{
		cout << "���Ҫ���ҵ�����";
		cin >> a;
		b = Find(ar, a, n);
		switch (b)
		{
		case POINTERROR:cout << "���������Ϊ��" << endl << endl; break;
		case LONGERROR: cout << "������Ϊ��" << endl << endl; break;
		case ERROR:cout << "��������û�������" << endl << endl; break;
		default:cout << "���ǵ�" << b << "����" << endl << endl; break;
		}
		cout << "������������Y���˳�����N" << endl << endl;
		cin >> ch;
		if (ch == 'N' || ch == 'n')break;
	}
	return 0;
}