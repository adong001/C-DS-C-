#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//1.��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬
//���ҳ�������֡�
//��������һ������Ϊ9������{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }��
//��������2�������г�����5�Σ��������鳤�ȵ�һ�룬
//������2����������������0��
int MoreThanHalfNum_Solution1(vector<int>&numbers)
{
	int sum = 0, tmp = 0;
	for (auto& i :numbers)
	{
		sum = (sum^i)&~tmp;
		tmp = (tmp^i)&~sum;
	}
	return sum;
}

int MoreThanHalfNum_Solution2(vector<int>& numbers)
{
	int tmp = numbers[0], icount = 1;
	for (int i = 1; i < numbers.size(); i++)
	{
		if (numbers[i] == tmp)
		{
			icount++;
		}
		else
		{
			if (icount > 1)
			{
				icount--;
			}
			else
			{
				tmp = numbers[i];
			}
		}
	}

	if (numbers.size() / 2 < count(numbers.begin(), numbers.end(), tmp))
	{
		return tmp;
	}
	return 0;
}
int main()
{
	int ar2[] = { 1, 2, 3, 2, 4, 2, 5, 2, 3 };
	int ar1[] = { 2, 2, 2, 2, 2, 1, 3, 4, 5 };
	int ar[]  =  { 1, 2, 3, 2, 2, 2, 5, 4, 2};
	vector<int>v;
	for (int i = 0; i < 9; i++)
	{
		v.push_back(ar[i]);
	}
	cout << MoreThanHalfNum_Solution2(v) << endl;
	system("pause");
	return 0;
}


//����:{6, -3, -2, 7, -15, 1, 2, 2}, 
//	����������������Ϊ8(�ӵ�0����ʼ, ����3��Ϊֹ)��
//	��һ�����飬��������������������еĺ�
template<class T>
T Max(T a, T b)
{
	return a > b ? a : b;
}
int FindGreatestSumOfSubArray(vector<int>& array)
{
	if (!array.size())
	{
		cout << "���鳤�ȴ���";
		return errno;
	}
	int maxResult = 0;
	int i;
	int *tmp = new int[array.size()];
	memset(tmp, 0, sizeof(int)* array.size());
	*tmp = array[0];
	for (i = 1; i < array.size(); i++)
	{
		tmp[i] = Max(array[i] + tmp[i - 1], array[i]);
		if (maxResult < tmp[i])
		{
			maxResult = tmp[i];
		}
	}
	return maxResult;
}
int main2()
{
	int ar[] = { 6, -3, -2, 7, -15, 1, 2, 2 };
	int ar1[] = { 0, -2, 11, -4, 13, -5, -2 };
	vector<int>v;
	for (auto& i : ar)
	{
		v.push_back(i);
	}
	cout << FindGreatestSumOfSubArray(v) << endl;
	system("pause");
	return 0;
}

//
//����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ�
//��������Ԫ�ؾ��������Ρ��ҳ�ֻ����һ�ε�������Ԫ�ء�

vector<int> singleNumber(vector<int>& nums)
{
	vector<int>res;
	int num1 = 0, num2 = 0;
	int tmp = 0;

	for (auto& i : nums)//������������򣬵õ����������������ֵ
	{
		tmp ^= i;
	}

	int j;
	for (j = 0; j < 32; j++)
	{
		if ((tmp >> j) & 1)//�����ֵĳһλΪ1˵��������������һλ����ͬ�����ȡһλΪ1�Ķ����ԡ�
		{	               
			break;
		}
	}

	for (auto& i : nums)//��һλΪ1�ı�num1�����ͬ����Ȼ����0�����ֻʣ�µ������е�һ����num2һ����
	{
		if ((i >> j) & 1)
		{
			num1 ^= i;
		}
		else
		{
			num2 ^= i;
		}
	}

	res.push_back(num1);//����ҵ�������������push��res�з��ء�
	res.push_back(num2);
	return res;
}

int main3()
{
	int ar[] = { 1, 2, 1, 3, 2, 5 };
	vector<int>v;
	v.insert(v.begin(), ar, ar + 6);
	cout << singleNumber(v)[0] << " " << singleNumber(v)[1] << endl;
	system("pause");
	return 0;
}

