#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <map>
using namespace std;

//���ַ���src������a�ַ�ת�����ַ�b
void ChangeStr(string& src, const string& det,char b)
{
	for (auto& e : src)
	{
		if(det.find(e) != string::npos)
		{
			e = b;
		}
	}
}

int main()
{
	int n;
	string src;
	while (cin >> src >> n)
	{
		int a, b;
		map<char, string> mdet;//�洢�޸ĵļ�ֵ�ԣ�����0-1,0-2,3-4��4-5�����մ洢Ϊ(0,1),(1,#)(3,54)
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			//������ı���ַ�δ����ʱ����Ҫ����
			if (!mdet[a + '0'].empty())
			{
				if (!mdet[b + '0'].empty())
				{
					//0-1 ,1-2 ,�洢����(0,1),(1,#)->(0,12),(2,#)
					mdet[]
				}
			}
		}
		string det;
		ChangeStr(src, det, b + '0');
		cout << src << endl;
	}
	return 0;
}