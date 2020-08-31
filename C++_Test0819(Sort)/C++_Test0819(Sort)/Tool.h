#pragma once
#define SORTNUMBERS 12

//������������
template<class T>
void swap(T& num1, T& num2)
{
	T tmp = num1;
	num1 = num2;
	num2 = tmp;
}

//��ӡ����
template<class T>
void print(T& arr)
{
	for (auto& e : arr)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

//�º�����Greater-�Ӵ󵽴��ţ�Less-�Ӵ�С��
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

template<class T>
void Test_Sort(void(*sort)(std::vector<T>&, size_t, bool(*cmp)(int, int)), std::vector<T>& v, size_t n)
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++)
	{
		v[i] = rand() % n;
	}
	sort(v, SORTNUMBERS, Less);
	print(v);
}