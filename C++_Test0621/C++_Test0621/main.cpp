#include <iostream>
#include <string>
using namespace std;
//int main()
//{
//	int month;
//	while (cin >> month)
//	{
//		int f0 = 0, f1 = 1, f2 = 1, fn;
//		while (--month)
//		{
//			fn = f2;
//			f2 += f1;
//			f0 = f1;
//			f1 = fn;
//			
//		}
//		cout << f1 << endl;
//	}
//}

//#include <iostream>
//#include <string>
//using namespace std;
//bool Match(const char* src, const char* det)
//{
//	if (*src == '\0'&& *det == '\0')//����ĩβ��˵��ƥ����ȷ
//	{
//		return true;
//	}
//	if (*src == '\0' || *det == '\0')//�������Լ���£���һ��������˵��δƥ����ȷ
//	{
//		return false;
//	}
//	if (*src == *det)//�����ַ�����ͬ��ͬʱƥ��
//	{
//		return Match(src + 1, det + 1);
//	}
//	else if (*src == '?')//ƥ�䵥��
//	{
//		return Match(src + 1, det + 1);
//	}
//	else if (*src == '*')//ƥ��0����1�������
//	{
//		return Match(src + 1, det) || Match(src + 1, det + 1) || Match(src, det + 1);
//	}
//	return false;
//}
//int main()
//{
//	string src, det;
//	while (cin >> src >> det)
//	{
//		if (Match(src.c_str(), det.c_str()))
//		{
//			cout << "true" << endl;
//		}
//		else
//		{
//			cout << "false" << endl;
//		}
//	}
//}