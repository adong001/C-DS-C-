#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int size;
	cin >> size;
	vector<int> nums(size);
	for (size_t i = 0; i < size; ++i)
		cin >> nums[i];
	int result = nums[0];
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < nums.size(); i++)    {
		// ���㵽num[i]�������������       
		sum2 = sum1 >= 0 ? sum1 + nums[i] : nums[i];
		if (sum2 > result)
			result = sum2;
		if (sum2 < 0)#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
			using namespace std;

		bool IsPalindrome(string& src)
		{
			if (src.empty())
			{
				return false;
			}
			int _size = src.size();
			for (int i = 0; i < _size / 2; i++)
			{
				if (src[i] != src[_size - i - 1])
				{
					return false;
				}
			}
			return true;
		}

		int ToPalindrome()
		{
			string src;
			string dest;
			getline(cin, src);
			getline(cin, dest);
			if (src.empty() || dest.empty)
			{
				return -2;
			}
			int src_size = src.size();
			string::iterator ip = src.begin();
			string tmp;
			int i;
			for (i = -1; i < src.size(); i++)
			{
				tmp = src;
				tmp.insert(ip - 1, dest);
				if (IsPalindrome(tmp))
				{
					return i;
				}
				tmp.clear();
			}

		}


		int main()
		{
			cout << IsPalindrome();
			system("pause");
			return 0;
		}



		//�жϻ����ַ���
		bool palindrome(const string& str) {	//������
			int begin = 0;
			int end = str.size() - 1;
			while (begin<end) {
				if (str[begin] != str[end]) {
					return false;
				}
				begin++;
				end--;
			}
			return true;
		}
		int main() {
			std::string str1, str2;
			getline(cin, str1);
			getline(cin, str2);
			int count = 0;
			for (int i = 0; i <= str1.size(); ++i) {
				// ���ַ���2���뵽�ַ���1��ÿ��λ�ã����ж��Ƿ��ǻ���        
				string str = str1;
				str.insert(i, str2);
				if (palindrome(str)) {
					++count;
				}
			}
			cout << count << endl;
			system("pause");
			return 0;
		}





			sum2 = 0;
		sum1 = sum2;
	}
	cout << result << endl;
	system("pause");
	return 0;
}
��������������������������������
��Ȩ����������ΪCSDN������Xdut����ԭ�����£���ѭ CC 4.0 BY - SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https ://blog.csdn.net/qq_42659468/article/details/97764219#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main()
{
    system("pause");
    return 0;
}