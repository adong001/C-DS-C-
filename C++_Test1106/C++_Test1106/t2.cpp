#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
//���磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��


//void DeleteString(char* src, const char* dest)
//{
//	if (src|| dest)
//	{
//		return;
//	}
//	char* p1;
//	const char* p2 = dest;
//	for (; p2; p2++)
//	{
//		for (p1 = src; p1; p1++)
//		{
//			if (*p1 == *p2)
//			{
//				while (p1)
//				{
//					*p1 = *(p1 + 1);
//					if()
//				}
//			}
//		}
//	}
//}
template<class T>
void DeleteString(T& src,const T& dest)
{
	string src_str(src);
	string dest_str(dest);
	if (src_str.empty() || dest_str.empty())
	{
		return;
	}
	int pos = 0;
	string::iterator ip1 = src_str.begin();
	string::iterator ip2 = dest_str.begin();
	for (; ip2 != src_str.end(); ip2++)
	{
		while(pos>=0)
		{
			pos = src_str.find(*ip2);
			if (pos >= 0)
			{
				ip1 = src_str.begin() + pos;
				src_str.erase(ip1);
			}
			else
			{
				ip1++;
			}
		}
	}
}

int main2()
{
	//string src = "They are students";
	//string dest = "aeiou"; //���
	char* src = "They are students";
	char* dest = "aeiou"; //���
	DeleteString(src, dest);
	cout << src<< endl;
    system("pause");
    return 0;
}