#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//1. ��ӡ100~200֮�������
int main()
{
	int i, j;
	for (i = 100; i <= 200; ++i)
	{
		for (j = 2; j <= sqrt(i); ++j)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j > sqrt(i))
		{
			printf("%d ", i);
		}
	}
	system("pause");
	return 0;
}
//2. ����˷��ھ���
//int main()
//{
//	for (int i = 1; i <= 9; ++i)
//	{
//		for (int j = 1; j <= i; ++j)
//		{
//			printf("%d*%d=%2d ", i, j, i*j);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
//
////3. �ж�1000��-- - 2000��֮�������
//
//int main()
//{
//	int year;
//	for (year = 1000; year <= 2000; ++year)
//	{
//		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//		{
//			printf("%d ", year);
//		}
//	}
//	system("pause");
//	return 0;
//}

//1. �����������α�����ֵ��������ֵ�����ݽ��н�����

//void swap1(int *x, int *y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
////int *tmp=x;  ע�����������������ʵ�ε����ݣ�
//// x=y;        ֻ�ǽ������β�x��y��ָ��
//// y=tmp;      �����е�ֵû�иı�
//}
//void swap2(int &x, int &y)//�β�����ʵ�Σ��βξ���ʵ�εı���
//{                         //ʵ����һ���ģ�ֻ��cpp�ļ�����Ч
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//int main()
//{
//	int x = 10;
//	int y = 20;
//	swap1(&x, &y);//��ָ�봫����ʵ�εĵ�ַ
//	printf("x=%d ,y=%d ", x, y);
//	swap2(x, y); //���þ�ֱ�Ӹ�ʵ�ε�ֵ
//	printf("\nx=%d ,y=%d ", x, y);
//	system("pause");
//	return 0;
//}
//2. ����������ʱ���������������������ݣ������⣩
//int main()
//{  //˼·���κ�������Լ�Ϊ0
//	int x = 10;
//	int y = 20;
//	x = x^y;
//	y = x^y; //�õ�x��ֵ��
//	x = x^y; //�õ�y��ֵ��
//	printf("x=%d y=%d\n", x, y);
//	system("pause");
//	return 0;
//}
////3.��10 �����������ֵ��
//int Max(int ar[], int n)
//{
//	int max = ar[0];
//	for (int i=1; i < n; ++i)
//	{
//		max = max>ar[i] ? max : ar[i];
//	}
//	return max;
//}
//int main()
//{
//	int ar[] = { 10, 2, 3, 17, 4, 2, 8, 4, 1, 6 };
//	int n = SIZEOF(ar);
//	printf("max=%d\n", Max(ar, n));
//	system("pause");
//	return 0;
//}
////4.�����������Ӵ�С�����
//void swap(int *x, int *y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 30;
//	int c = 20;
//	if (a < b)
//	{
//	  swap(&a, &b);
//	}
//	if (a < c)
//	{
//		swap(&a, &c);
//	}
//	if (b < c)
//	{
//		swap(&b, &c);
//	}
//	printf("%d %d %d\n", a, b, c);
//	system("pause");
//	return 0;
}
////5.�������������Լ����
//int main()
//{
//	while (1)
//	{
//		int x, y;
//		int max,min;
//		int tmp;
//		scanf("%d%d", &x, &y);
//		max = x > y ? x : y;
//		min = x < y ? x : y;
//		while (min)
//		{
//			tmp = min;
//			min = max%min;
//			max = tmp;
//		}
//		printf("���Լ��=%d\n",tmp);
//	}
//	system("pause");
//	return 0;
//}
////6.������������С��������
//int main()
//{
//	while (1)
//	{
//		int x, y;
//		int max, min;
//		int tmp;
//		scanf("%d%d", &x, &y);
//		max = x > y ? x : y;
//		min = x < y ? x : y;
//		while (min)
//		{
//			tmp = min;
//			min = max%min;
//			max = tmp;
//		}
//		tmp *= (x / tmp)*(y / tmp);
//		printf("��С������=%d\n", tmp);
//	}
//	system("pause");
//	return 0;
//}