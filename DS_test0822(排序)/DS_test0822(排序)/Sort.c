#include"Sort.h"

void Print(int *ar, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ar[i]);
	}
	putchar('\n');
}

void InsertSort(int *ar, int n)//��������
{ 
	//ʱ�临�Ӷ� :O(n^2)
	//�ŵ�: 1.�����ģԽС������Խ��
	//      2.����Խ���򣬲���Խ��
	int tmp;
	int i, j;
	for (i = 1; i < n; i++)
	{
		tmp = ar[i];
		for (j = i; j > 0 && ar[j - 1]>tmp; j--)
		{
			ar[j] = ar[j - 1];
		}
		ar[j] = tmp;
	}
}

void ShellSort(int *ar, int n)//ϣ������(��С������)
{ 
	//���ز������򣬶Զ��ز���������Ż�(�����ģԽС��Խ����)
	int i, j, k;
	int grap, tmp; 
	for (grap = n / 2; grap > 0; grap /= 2)//����
	{      
		for (k = 0; k<grap; k++)//����
		{
			for (i = grap + k; i < n; i += grap)
			{
				tmp = ar[i];
				for (j = i; j >= grap && ar[j - grap]>tmp; j -= grap)
				{
					ar[j] = ar[j - grap];
				}
				ar[j] = tmp;
			}
		}
	}
}

//void SelectioSort(int *ar, int n)
//{
//
//}

void MergeSort(int *ar, int n)//�鲢����
{//��Ҫ����һ�������ռ�
	int *tmp = (int *)malloc(n*sizeof(int));
	mergesort(ar, tmp, 0, n - 1);
	free(tmp);
}
void mergesort(int *arr, int *tmp, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	mergesort(arr, tmp, start, mid);
	mergesort(arr, tmp, mid + 1,end);
	int a = start;
	int b = mid + 1;
	int c = start;
	while (a<mid && b<=end)
	{

		if (arr[a] < arr[b])
		{
			tmp[c] = arr[a];
			a++;
		}
		else
		{
			tmp[c] = arr[b];
			b++;
		}
		c++;
	}
	for (; a <= mid; a++)
	{
		tmp[c] = arr[a];
		c++;
	}
	for (; b <= end; b++)
	{
		tmp[c] = arr[b];
		c++;
	}

	for (int i = start; i <= end; i++)
	{
		arr[i] = tmp[i];
	}
}��


int left = start,right = end;
//		GetPivot(arr,start, end);//��start��Ϊ��׼Ԫ��
//		int pivot = arr[start];
//
//		while (start < end)
//		{
//			for (; start < end && cmp(pivot,arr[end] , true) ; end--);//��������Ȼ�׼ֵС��
//			
//			for (; start < end && cmp(arr[start],pivot, true) ; start++);//�������ұȻ�׼ֵ���
//
//			if (start < end)//��δ�����ͽ���
//			{
//				Swap(arr[start], arr[end]);
//			}
//		}
//		Swap(arr[left], arr[end]);//�м��ǻ�׼ֵ����߱Ȼ�׼ֵС���ұ߱Ȼ�׼ֵ��
//		return end;