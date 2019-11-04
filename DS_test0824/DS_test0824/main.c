#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

void Print(int *src, int n)
{
	for (int i = 0; i<n; i++)
	{
		printf("%d ", src[i]);
	}
	putchar('\n');
}

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

AdjustDown(int* data,int size, int n)//���µ����㷨��ֻ�������ڵ㣩
{
	int tmp;
	while (n * 2 + 1 < size)//�ж��Ƿ��Ƿ�Ҷ�ӽ�㣬���Ӳ�Խ��
	{
		if (n * 2 + 2 >= size)//�Һ��Ӳ�����
		{
			tmp = n * 2 + 1;//��¼��������
		}
		else
		{
			if (data[n * 2 + 1] > data[n * 2 + 2])//���Һ��Ӷ�����
			{
				tmp = n * 2 + 1;//������ң���¼������
			}
			else
			{
				tmp = n * 2 + 2;//�Ҵ����󣬼�¼������
			}
		}
		if (data[n] < data[tmp])//���ڵ����¼������ȣ���<tmp,����������break
		{
			Swap(&data[n], &data[tmp]);
			n = tmp;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(int *data,int size)//ɾ���Ѷ�Ԫ��,��֤�����¶�
{
	if (data == NULL)
	{
		return;
	}
	Swap(&data[0], &data[size - 1]);//����βԪ�ؽ���
	size--;//����--��������β���źõ����Ԫ��
	AdjustDown(data,size, 0);//��ͷ���ִ���������㷨��ʹ���ֳ�Ϊһ���¶�
}


void HeapSort(int *src, int n)
{
	assert(src);
	for (int i = (n - 1) / 2; i > 0; i--)
	{
		AdjustDown(src, n, i);//�����һ����Ҷ�ӽ�㵽����ִ�����µ����㷨���γ��¶�
	}
	for (int i = n; i > 1; i--)
	{
		HeapPop(src, i);//����--��������β���źõ����Ԫ�أ�ִ��n-1��ֱ���ź�
	}
}


int main()
{
	int src[] = { 10, 9, 3, 4, 6, 7, 2, 8, 1, 5 };
	int n = sizeof(src) / sizeof(src[0]);
	//SelectionSort(src, n);
	HeapSort(src, n);
	Print(src, n);
	return 0;
}
//HeapType* HeapTop(  hp)//�ж϶��Ƿ�Ϊ�գ�Ϊ�շ���0�����򷵻ص�һ��Ԫ��
//{
//	assert(hp);
//	if (data == NULL)
//	{
//		return (HeapType)0;
//	}
//	return data;
//
//}
//
//void HeapInit(  hp, HeapType* a, int n)//��ʼ����
//{
//	assert(hp);
//	hp->capacity = n * 2;
//	size = n;
//	data = (HeapType*)malloc(sizeof(HeapType)*hp->capacity);
//	for (int i = 0; i < n; i++)
//	{
//		data[i] = a[i];
//	}
//	for (int i = (n - 1) / 2; i>0; i--)//�����һ����Ҷ�ӽ�㿪ʼִ�����µ����㷨
//	{
//		AdjustDown(hp, i);
//	}
//}
//
//void SelectionSort(int *src, int n)
//{
//	int i, j;
//	int min;
//	for (i = 0; i < n - 1; i++)//���ѭ��ֻѭ��n-1�Σ�ǰn-1��Ԫ���ź���������������
//	{
//		min = i;//min��¼����Ҫ�����Ԫ������
//		for (j = i + 1; j < n; j++)//�ڴ�ѭ������Ϊi+1��Ԫ�ؿ�ʼֱ�����һ��Ԫ��
//		{
//			if (src[min] > src[j])//��δ����Ԫ���в�����С��Ԫ����min��¼��������
//			{
//				min = j;
//			}
//		}
//		if (src[i] > src[min])
//		{
//			Swap(&src[i], &src[min]);//�ҵ�δ����Ԫ���е���Сֵ��������
//		}
//	}
//}
//
//void ShellSort(int *src, int n)
//{
//	int gap;//��ļ��
//	int k;//���ڳ�Ա�ĸ���
//	int i, j;
//	for (gap = n / 2; gap > 0; gap /= 2)
//	{
//		for (k = 0; k < gap; k++)
//		{
//			for (i = gap + k; i< n; i += gap)//ÿ���Ա֮��ļ��Ϊgap
//			{
//				int tmp = src[i];
//				for (j = i; j >= gap && src[j - gap] > tmp; j -= gap)
//				{
//					src[j] = src[j - gap];
//				}
//				src[j] = tmp;
//			}
//		}
//	}
//}