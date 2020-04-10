#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#define SIZEOF(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;

template<class T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<class T>
bool Greater(T a, T b)
{
	return a > b;
}

template<class T>
bool Less(T a, T b)
{
	return a < b;
}

//template<class T>
//class Pre
//{
//	bool operator()
//	{
//
//	}
//};

template<class T>
void Print(T arr, size_t len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T>
void Bubble_Sort(T arr[], size_t len, bool (*cmp)(T,T) = Less)//ð������
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (cmp(arr[j + 1], arr[j]))//����С��ǰ��
			{
				Swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template<class T>
void Select_Sort(T arr[], size_t len, bool (*cmp)(T,T) = Less)//ѡ������
{
	int min;
	for (int i = 0; i < len - 1; i++)
	{
		min = i;//min��¼����Ҫ�����Ԫ������
		for (int j = i + 1; j < len; j++)
		{
			if (cmp(arr[j], arr[min]))//ѡ����С��
			{
				min = j;

			}
		}
		if (arr[min] < arr[i])
		{
			Swap(arr[min], arr[i]);//����ʼλ�ý���
		}
	}
}

template<class T>
void Insert_Sort(T arr[], size_t len, bool(*cmp)(T,T) = Less)//��������
{
	int i,j,tmp;
	for (i = 1; i < len; i++)
	{
		tmp = arr[i];
		for (j = i; j > 0 && cmp(arr[j], arr[j - 1]); j--)//����С��ǰ��ͽ�ǰ�渲�ǵ�����
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
}

template<class T>
void Shell_Sort(T arr[], size_t len, bool(*cmp)(T, T) = Less)//ϣ������(���ݲ���������ŵ�Խ��������Խ����ŵ��Ż���һ�ַ���)
{
	int i, j, k, gap, tmp;
	for (gap = len / 2; gap > 0; gap /= 2)//������(gap / 2 > 0)��
	{
		for (k = 0; k < gap; k++)//ÿ��gap��,��ÿ����в�������
		{
			for (i = k + gap; i < len; i+=gap)//ÿ����ʼλ��Ϊk + gap,
			{
				tmp = arr[i];
				for (j = i; j >= gap && cmp(tmp, arr[j - gap]); j-=gap)//�����Աÿ�����gap
				{
					arr[j] = arr[j - gap];
				}
				arr[j] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 2, 3, 4, 1, 6, 7, 8, 10, 5, 9 ,0,111,2,3,1,3,34,3,23,2,34};
	//int arr[] = { 2, 3, 4, 1, 6, 7, 8, 10, 5, 9 };
	//Bubble_Sort(arr, SIZEOF(arr));
	//Select_Sort(arr, SIZEOF(arr));
	//Insert_Sort(arr, SIZEOF(arr));
	Shell_Sort(arr, SIZEOF(arr));
	Print(arr, SIZEOF(arr));
	system("pause");
	return 0;
}