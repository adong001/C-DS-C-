//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//
//void adjustdown(int* data, int size,int num)//���µ�������(���)
//{
//	int cur = num;//Ҫ���µ������±�
//	int n;//�±�
//	
//	while (cur * 2 + 1 < size)//���������һ����Ҷ�ӽڵ�����
//	{
//		if (cur * 2 + 2 >= size)//û���Һ���
//		{
//			n = cur * 2 + 1;//��¼����ڵ�
//		}
//		else
//		{
//			if (data[cur * 2 + 1] > data[cur * 2 + 2])//����>�Һ���
//			{
//				n = cur * 2 + 1;//��¼�����±�
//			}
//			else//�����¼�Һ����±�
//			{
//				n = cur * 2 + 2;
//			}
//		}
//		if (data[cur]< data[n])//���˽ڵ�ȼ�¼�ĺ���ֵС���򽻻����ߵ�ֵ
//		{
//			int tmp = data[cur];
//			data[cur] = data[n];
//			data[n] = tmp;
//			cur = n;//��¼����������꣬���������ж�
//		}
//		else //
//		{
//			break;
//		}
//	}
//}
//
//void heappop(int* data,int size)//ɾ���Ѷ�Ԫ��
////�����һ��Ҷ�ӽڵ��滻Ϊ�Ѷ���size--,��ִ�����µ����㷨
//{
//	if (size == 0)
//	{
//		return;
//	}
//
//	int tmp = data[0];
//	data[0] = data[size - 1];
//	data[size - 1] = tmp;
//	size--;	
//	adjustdown(data, size,0);
//	
//}
//
//void heapsort( int* src, int size)//�ѵĳ�ʼ��
//{
//	int i;
//	for (i = size/2-1; i >= 0; i--)
//	{
//		adjustdown(src,size,i);
//	}
//
//	for (; size> 1; size--)
//	{
//		heappop(src, size);
//	}
//}
//
//
//
//void printArray(int *src, int size)
//{
//	int i;
//	for (i = 0; i < size; i++)
//	{
//		printf("%d ", src[i]);
//	}
//	putchar('\n');
//}
//
//
//int Find_X_Max(int *src, int size, int X)
//{
//	int i;
//	int value;
//	if (size <= 0)
//	{
//		return errno;
//	}
//	
//	for (i = size / 2 - 1; i >= 0; i--)
//	{
//		adjustdown(src, size, i);//��ʼ����
//	}
//
//	while (X)
//	{
//		value = src[0];
//		heappop(src, size);
//		--size;
//		--X;
//	}
//	return value;
//
////}
////int main()
////{
////	int data[] = { 1, 20 ,8/*, , 3, 4, 5, 7 , 8,  10 ,6, 9*/ };
////	heapsort(data, 3);
////	printArray(data, 3);
////	/*for (int i = 1; i < 12;i++)
////	printf("%d\n",Find_X_Max(data, 11, i));
////	*/
////    system("pause");
////    return 0;
////}
