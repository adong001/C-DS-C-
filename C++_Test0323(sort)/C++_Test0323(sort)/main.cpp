#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<ctime>
//#define SIZEOF(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;

template<class T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<class T>
bool Greater(T a, T b,bool flag = false)
{
	return flag ? a >= b : a > b;
}

template<class T>
bool Less(T a, T b, bool flag = false)
{
	return flag ? a <= b : a < b;
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
void Bubble_Sort(vector<T>& arr, size_t len, bool(*cmp)(T, T) = Less)//ð������
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
void Select_Sort(vector<T>& arr, size_t len, bool(*cmp)(T, T) = Less)//ѡ������
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
void Insert_Sort(vector<T>& arr, size_t len, bool(*cmp)(T, T) = Less)//��������
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
void Shell_Sort(vector<T>& arr, size_t len, bool(*cmp)(T, T) = Less)//ϣ������(���ݲ���������ŵ�Խ��������Խ����ŵ��Ż���һ�ַ���)
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


template<class T>
class HeapSort
{
private:
	static void AdjustDown(vector<T>& arr, size_t len, int pos, bool(*cmp)(T, T))//���µ����㷨������,LessĬ�Ϲ�����ѣ�������
	{
		int tmp;
		while (pos * 2 + 1 < len)//�ж��Ƿ�Ϊ��Ҷ�ӽڵ㣬��Ҷ�ӵ�Ͳ���Ҫ����
		{
			if (pos * 2 + 2 >= len)//û���Һ���
			{
				tmp = pos * 2 + 1;
			}
			else//���Һ��Ӷ���
			{
				if (cmp(arr[pos * 2 + 1], arr[pos * 2 + 2]))//Ҫ������ѣ���Ҫ���ں��ӣ���¼��ĺ���
				{
					tmp = pos * 2 + 2;
				}
				else
				{
					tmp = pos * 2 + 1;
				}
			}

			if (cmp(arr[pos], arr[tmp]))//����������
			{
				Swap(arr[pos], arr[tmp]);
				pos = tmp;//�������µ������������ĺ��ӿ϶�����²����Ӱ�죬û�б������Ĳ��ù�
			}
			else//��������������,�ǴӺ���ǰ���µ�����˵�����������Һ��ӣ�˵�����Һ���Ҳ����ȷ���Ͳ����پ�����������
			{
				break;
			}
		}
	}

	static void HeapPop(vector<T>& arr, size_t n, bool(*cmp)(T, T)) //�Ѷ��Ͷ�β����
	{
		Swap(arr[0], arr[n - 1]);//����β����
		n--;//����--
		AdjustDown(arr, n, 0, cmp);//�������µ���
	}


public:
	static void Heap_Sort(vector<T>& arr, size_t len, bool(*cmp)(T, T) = Less)
	{
		for (int i = (len - 1)/2; i >= 0; --i)//������
		{
			AdjustDown(arr, len, i, cmp);
		}
		for (int j = len; j > 0; --j)//��һ�Σ����¹���һ��
		{
			HeapPop(arr, j, cmp);
		}
	}
};


template<class T>
class MergeSort
{
private:

	static void Merge_Sort(vector<T>& arr, size_t start, size_t end, bool(*cmp)(T, T))
	{
		if (start >= end)//Խ��
		{
			return;
		}
		int mid = (start + end) / 2;
		Merge_Sort(arr, start, mid, cmp);//�ݹ�����С����
		Merge_Sort(arr, mid + 1, end, cmp);

		int x = start;
		int y = mid + 1;
		vector<int> tmp;
		while (x <= mid && y <= end)
		{
			if (cmp(arr[x], arr[y]))//�����������С��һ�ηŽ�ȥ
			{
				tmp.push_back(arr[x]);
				x++;
			}
			else
			{
				tmp.push_back(arr[y]);
				y++;
			}
		}

		for (; x <= mid; x++)//һ������Խ�磬��һ��û����ȫ�Ž�ȥ������ĸ�û��Խ��Ž�ȥ
		{
			tmp.push_back(arr[x]);
		}
		for (; y <= end; y++)
		{
			tmp.push_back(arr[y]);
		}

		for (int i = start; i <= end; i++)//�ź������ڶ�Ӧλ��
		{
			arr[i] = tmp[i - start];
		}
	}
public:
	static void Merge_Sort(vector<T>& arr, size_t len, bool(*cmp)(T, T) = Less)
	{
		Merge_Sort(arr,0, len - 1, cmp);
	}
};

template<class T>
class QuickSort
{
private:
	static int GetPivot(vector<T>& arr, int start, int end)//��ȡ��׼Ԫ�أ��Ż��㷨
	{
		srand((unsigned int)(time(NULL)));
		int pos = rand() % (end - start + 1) + start;
		return pos;
	}
public:
	static void Quick_Sort(vector<int>& arr, int start, int end, bool(*cmp)(T, T,bool) = Less)
	{
		int left = start,right = end;
		int pivot = GetPivot(arr, start, end);
		Swap(arr[start], arr[pivot]);//��start��Ϊ��׼Ԫ��
		while (start < end)
		{
			for (; start < end && cmp(arr[end], pivot, true) ; end--);//��������Ȼ�׼ֵС��
			
			for (; start < end && cmp(pivot,arr[start], true) ; start++);//�������ұȻ�׼ֵ���

			if (start < end)//��δ�����ͽ���
			{
				Swap(arr[start], arr[end]);
			}
		}
		Swap(arr[left], arr[end]);
		Quick_Sort(arr, left, end - 1);
		Quick_Sort(arr, end + 1, right);
	}
};


int main()
{
	//vector<int> arr = { 2, 3, 4, 1, 6 };
	 vector<int> arr = { 2, 3, 4, 1, 6, 7, 8, 10, 5, 9 ,0,111,2,3,1,3,34,3,23,2,34};
	//int arr[] = { 2, 3, 4, 1, 6, 7, 8, 10, 5, 9 };
	//Bubble_Sort(arr,arr.size());
	//Select_Sort(arr,arr.size());
	//Insert_Sort(arr,arr.size());
	//Shell_Sort(arr,arr.size());
	//HeapSort<vector<int>>::Heap_Sort(arr, arr.size());
	 //MergeSort<int>::Merge_Sort(arr, arr.size());
	 QuickSort<int>::Quick_Sort(arr, 0,arr.size()-1);
	Print(arr, arr.size());
	system("pause");
	return 0;
}