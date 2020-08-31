#pragma once
#include <iostream>
#include <vector>
#include <memory>
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
	int i, j, tmp;
	for (i = 1; i < n; i++)
	{
		//tmp��¼��ǰλ�õ�ֵ
		tmp = arr[i];

		//��ǰ���i-1�����ҵ�������ľͰѴ�����Ų
		for (j = i; j > 0 && cmp(tmp, arr[j - 1]); j--)
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
	for (i = 1; i < n; i++)
	{
		//peak��¼��i,n-1]�м�ֵ(����ֵ��Сֵ)
		peak = arr[i];
		//peak < arr[j - 1](��С����)ʱ�������ҳ�ǰ��ı�peakС��ֵ�����������棬û�ҵ�ʱǰ��ĸ��Ǻ����
		for (j = i; j > 0 && cmp(peak,arr[j - 1]); j--)
		{
			arr[j] = arr[j - 1];
		}
		//arr[j-1]�������ҵ��ļ�ֵ���������ĺ��棬arr[i]�ͱ�����peak��ֵ����
		arr[j] = peak;
	}
}


//4.ϣ������
//�㷨˼�룺(1)���ò�����������ԽС��˳����Խ�ߵ��ص㣬���������ݷֳ�grap��(grap��ʼ��=n/2)
//			(2)ÿ�������������Ϊgrap,grapΪ������ÿ���Աִ��һ�β�������,ÿ��grap/=2,ֱ��grap=0
template<class T>
void Shell_Sort(std::vector<T>& arr, size_t n, bool(*cmp)(T, T) = Less)
{
	std::cout << __FUNCTION__ << std::endl;
	int i, j, peak;
	//grap--������ִ��log2(n)�ˣ�
	//ÿ�˹�grap�飬ÿ���������ݾ���Ϊgrap��ÿ��n/grap��Ԫ��
	for (int grap = n / 2; grap > 0; grap /= 2)
	{
		//ÿ�˽�������ִ�в������򼴿�
		//�������ѭ������grap��
		for (i = 0; i < grap; i++)
		{
			//����ѭ���ǲ�������
			for (i = 1; i < n; i++)
			{
				//peak��¼��i,n-1]�м�ֵ(����ֵ��Сֵ)
				peak = arr[i];
				//peak < arr[j - 1](��С����)ʱ�������ҳ�ǰ��ı�peakС��ֵ�����������棬û�ҵ�ʱǰ��ĸ��Ǻ����
				for (j = i; j > 0 && cmp(peak, arr[j - 1]); j--)
				{
					arr[j] = arr[j - 1];
				}
				//arr[j-1]�������ҵ��ļ�ֵ���������ĺ��棬arr[i]�ͱ�����peak��ֵ����
				arr[j] = peak;
			}
		}
	}
}


//5.�鲢����
//�㷨˼�룺(1)�ǽ����ڹ鲢�����ϵ�һ����Ч�������㷨,���㷨�ǲ��÷��η���Divide and Conquer����һ���ǳ����͵�Ӧ�á�
//			(2)��������������кϲ����õ���ȫ��������У�����ʹÿ���������� ����ʹ�����жμ�����
//			(3)�������������ϲ���һ���������Ϊ��·�鲢��

template<class T>
void Deal_Merge_Sort(std::vector<T>& arr, T* tmp,int start,int end, bool(*cmp)(T, T))
{
	//�ֽ��һ��Ԫ��ʱ���ٷֽ�
	if (start >= end)
	{
		return;
	}
	//1.�ֽ�

	int mid = (start + end) / 2;
	//�ݹ鴦��[start,mid]��������
	Deal_Merge_Sort(arr, tmp, start, mid, cmp);
	//�ݹ鴦��[mid + 1,end]��������
	Deal_Merge_Sort(arr, tmp, mid + 1, end, cmp);

	//2.�ϲ�
	//�ϲ������������飬�±�Ϊ[OrderArr1,OrderArr2)��[OrderArr2,end]
	//��������tmp�У��±�Ϊ[NewArr,end]
	int OrderArr1 = start;
	int OrderArr2 = mid + 1;
	int NewArr = start;

	//��ʼ�ϲ���
	while (OrderArr1 <= mid && OrderArr2 <= end)
	{
		//����cmp�Ǵ�С�������򣬾ͽ�С�ĸ�ֵ��tmp
		if (cmp(arr[OrderArr1], arr[OrderArr2]))
		{
			tmp[NewArr] = arr[OrderArr1];
			OrderArr1++;
		}
		else
		{
			tmp[NewArr] = arr[OrderArr2];
			OrderArr2++;	
		}
		NewArr++;
	}
	//�ϲ������У����ܻ�����ĳһ���������Խ�絼��ѭ����ֹ��
	//��ʱ��Ҫ��û��Խ����������δ���ʵ����ݼ��뵽tmp��

	//����arr[Orderarr1,mid]û��Խ�磬�ͽ���ʣ�µ���������ֱ�ӿ�������(������������ģ�����Ҫ��)
	for (; OrderArr1 <= mid; OrderArr1++, NewArr++)
	{
		tmp[NewArr] = arr[OrderArr1];
	}

	//����arr[Orderarr2,end]û��Խ�磬�ͽ���ʣ�µ���������ֱ�ӿ�������(������������ģ�����Ҫ��)
	for (; OrderArr2 <= end; OrderArr2++, NewArr++)
	{
		tmp[NewArr] = arr[OrderArr2];
	}

	//���tmp����һ���ź�������飬����������arr��
	for (int i = start; i <= end; i++)
	{
		arr[i] = tmp[i];
	}
}

template<class T>
void Merge_Sort(std::vector<T>& arr, size_t n, bool(*cmp)(T, T) = Less)
{
	std::cout << __FUNCTION__ << std::endl;
	//��һ�������ռ�
	////std::tr1::shared_ptr<T> tmp(new T(200));
	T* tmp = (T*)malloc(sizeof(T)*n);
	Deal_Merge_Sort(arr, tmp, 0, n - 1,cmp);
	free(tmp);
}


//5.��������
//�㷨˼��	:��ȡ������Ԫ�������� ��ĳԪ����Ϊ��׼ֵ�����ո������뽫�����򼯺Ϸָ���������У�
//			��������������Ԫ�ؾ�С�ڻ�׼ֵ����������������Ԫ�ؾ����ڻ�׼ֵ��
//			Ȼ���������������ظ��ù��̣�ֱ������Ԫ�ض���������Ӧλ����Ϊֹ
template<class T>
void GetPivot(std::vector<T>& arr, int start, int end)//��ȡ��׼ֵλ��
{
	srand((unsigned)time(NULL));
	//�����ȡһ��start - end�м��ֵ�����ڵ�һ��Ԫ�ص�λ��
	int pivot = rand() % (end - start + 1) + start;
	swap(arr[start], arr[pivot]);
}


template<class T>
void Recursion_Quick_Sort(std::vector<T>& arr, int start, int end, bool(*cmp)(T, T))
{
	if (start >= end)
	{
		return;
	}
	int left = start, right = end;
	//��ȡ��׼ֵ
	GetPivot(arr, start, end);
	int pivot = arr[start];
	//start�����һ������׼ֵ��start
	start++;
	while (start < end)
	{
		//���������ұȻ�׼ֵС��
		for (; start < end && cmp(pivot, arr[end]); end--);

		//���������ұȻ�׼ֵ���
		for (; start < end && cmp(arr[start], pivot); start++);

		//���߶��ҵ���δ�����ͽ���
		if (start < end)
		{
			swap(arr[start], arr[end]);
		}
	}
	//��ʱ,ѭ���˳�������ֻ����start==end,��һ���Ǵ�������ʱԽ�磬����arr[left]< arr[pivot],����pivot��leftλ��
	swap(arr[left], arr[end]);

	//�ڵݹ���һ����������
	Recursion_Quick_Sort(arr, left,end - 1, cmp);
	Recursion_Quick_Sort(arr, end + 1, right, cmp);
}

template<class T>
void Quick_Sort(std::vector<T>& arr, size_t n, bool(*cmp)(T, T) = Less)
{
	std::cout << __FUNCTION__ << std::endl;
	Recursion_Quick_Sort(arr, 0, n - 1, cmp);//�ݹ��
	//NonRecursion_Quick_Sort(arr, 0, n - 1, cmp);//�ǵݹ�
}