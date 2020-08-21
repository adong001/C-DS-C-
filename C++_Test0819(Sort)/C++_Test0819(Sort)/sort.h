#pragma once
#include<iostream>
#include<vector>
#include"Tool.h"
/*
���򷽷�		ƽ�����		������		����	�����ռ�		�ȶ���

ð��			O(n^2)			O(n)			O(n^2)		O(1)			�ȶ�
ѡ��			O(n^2)			O(n^2)			O(n^2)		O(1)			�ȶ�
����			O(n^2)			O(n)			O(n^2)		O(1)			�ȶ�
ϣ��			O(nlogn)-O(n^2)	O(n^1.3)		O(n^2)		O(1)			���ȶ�
��				O(nlogn)		O(nlogn)		O(nlogn)	O(1)			���ȶ�
�鲢			O(nlogn)		O(nlogn)		O(nlogn)	O(n)			�ȶ�
����			O(nlogn)		O(nlogn)		O(n^2)		O(logn)-O(n)	���ȶ�

*/
//����������������ʽΪ 
//template<class T>
//void Sort(vector<T>& arr, size_t n, bool(*cmp)(T, T) = Less)
//Ĭ�ϱȽϹ���Ϊ��С��������(Less)���Ӵ�С�޸ĵ���������ΪGreater����

//1.ð������
//�㷨˼�룺(1)�ӵ�0��Ԫ�ؿ�ʼ���ͺ����n-1��Ԫ�رȽϣ���������С�ģ��ͽ�����
//			(2)�ٴӵ�1��Ԫ�ؿ�ʼ�ȽϺ���n-2��....ֱ�����굽n-1Ϊֹ
template<class T>
void Bubble_Sort(std::vector<T>& arr, size_t n, bool(*cmp)(T, T) = Less)
{
	std::cout << __FUNCTION__ << std::endl;
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (!cmp(arr[j], arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}


//2.��������
//�㷨˼�룺(1)�ӵ�1��Ԫ�ؿ�ʼ���Ӻ���ǰ�ң��ҵ�ǰ���һ���������Ԫ�ؾ����Ų��	
//			(2)ֱ���ҵ�����С��Ԫ�ػ��ҵ��߽�Ϊֹ....�����ҵ���n��
template<class T>
void Insert_Sort(std::vector<T>& arr, size_t n, bool(*cmp)(T, T) = Less)
{
	std::cout << __FUNCTION__ << std::endl;
	int i, j,tmp;
	for (i = 1; i < n; i++)
	{
		//tmp��¼��ǰλ�õ�ֵ
		tmp = arr[i];

		//��ǰ���i-1�����ҵ�������ľͰѴ�����Ų
		for (j = i; j > 0 && cmp(tmp, arr[j-1]); j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;

	}
}

//3.ѡ������
//�㷨˼�룺(1)ÿһ�δӴ����������Ԫ����ѡ����С������󣩵�һ��Ԫ�أ���������е���ʼλ�ã�
//			(2)ֱ��ȫ��������� ����Ԫ������
template<class T>
void Choice_Sort(std::vector<T>& arr, size_t n, bool(*cmp)(T, T) = Less)
{
	std::cout << __FUNCTION__ << std::endl;
	int i, j, peak;
	for (i = 0; i < n - 1; i++)//���ֻ��n-1���ͽ�����
	{
		//peak��¼��i,n-1]�м�ֵ(����ֵ��Сֵ)���±�
		peak = i;

		//�ҳ���i,n-1]�еļ�ֵ
		for (j = i + 1; j < n; j++)
		{
			//arr[j] < arr[peak] ����peak��ֵΪj
			if (cmp(arr[j], arr[peak]))
			{
				peak = j;
			}
		}
		//����ҵ��ļ�ֵС��(����)arr[i]�ͽ���
		if (cmp(arr[peak], arr[i]))
		{
			swap(arr[peak], arr[i]);
		}
	}
}


//4.ϣ������
//�㷨˼�룺(1)ÿһ�δӴ����������Ԫ����ѡ����С������󣩵�һ��Ԫ�أ���������е���ʼλ�ã�
//			(2)ֱ��ȫ��������� ����Ԫ������
template<class T>
void Choice_Sort(std::vector<T>& arr, size_t n, bool(*cmp)(T, T) = Less)
{
	std::cout << __FUNCTION__ << std::endl;
	int i, j, peak;
	for (i = 0; i < n - 1; i++)//���ֻ��n-1���ͽ�����
	{
		//peak��¼��i,n-1]�м�ֵ(����ֵ��Сֵ)���±�
		peak = i;

		//�ҳ���i,n-1]�еļ�ֵ
		for (j = i + 1; j < n; j++)
		{
			//arr[j] < arr[peak] ����peak��ֵΪj
			if (cmp(arr[j], arr[peak]))
			{
				peak = j;
			}
		}
		//����ҵ��ļ�ֵС��(����)arr[i]�ͽ���
		if (cmp(arr[peak], arr[i]))
		{
			swap(arr[peak], arr[i]);
		}
	}
}