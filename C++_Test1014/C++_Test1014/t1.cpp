#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
//����һ�������ж����ʹ�ü������쳲�������(ֻ�ܸ������+1��-1)
//  쳲��������У�1 1 2 3 5 8 13 21......
//���磺
//      ���룺  15       //15 -1 -1 = 13 
//      �����   2  
class Solution {
public:
	size_t BecomeFibSteps(size_t num)
	{
		int fn, fn_1 = 0, fn_2 = 1;
		fn = fn_1 + fn_2;
		while (fn < num)//�ҵ���num��Ļ���ȵ��Ǹ�쳲�������
		{
			fn_2 = fn_1;
			fn_1 = fn;
			fn = fn_1 + fn_2;
		}  
		int a = fn - num;
		int b = fn_1 - num;

		return min(abs(a), abs(b));

	}
}; //1 2 3 5 8 13 21 
int main1()
{   
	Solution s;
	cout << s.BecomeFibSteps(4) << endl;
    system("pause");
    return 0;
}