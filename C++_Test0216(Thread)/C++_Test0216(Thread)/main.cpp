#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<thread>
#include<atomic>
using namespace std;

int main()
{
	int a = 10;
	int b = 20;
	thread t1;
	thread t2;
	thread t3([&](int num)//֧��lamba���ʽ
	{
		a += 10;
		b += 20;
	}, 5);

	atomic_long s = 100;//long��ԭ������
	system("pause");
	return 0;
}