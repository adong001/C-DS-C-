#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
using namespace std;

//���ַ����еĿո�ת��Ϊ%20(Դ�ַ��ռ�һ�㹻��)
class Solution1 {
public:
	void replaceSpace(char *str, int length)//lengthΪstr�ַ��Ŀռ����ֽ���
	{
		if (!str && length <= 0)
		{
			return;
		}
		int blankcount = 0;//�ո���
		int newlen;
		char* cur = str;
		int oldlen = 0;//�ַ�������
		while (*cur != '\0')//�ҳ��ո�ĸ������ַ�������
		{
			if (*cur == ' ')
			{
				blankcount++;
			}
			cur++;
			oldlen++;
		}

		newlen = oldlen + blankcount * 2;//�µ��ַ�������

		if (newlen > length)//�ж������ĳ����Ƿ��㹻���ո������%20
		{
			return;
		}

		for (int i = newlen; cur != str;cur--)//�����һ����ʼ���ֵ
		{
			if (*cur == ' ')
			{
				str[i] = '0';
				str[i - 1] = '2';
				str[i - 2] = '%';
				i -= 3;
			}
			else
			{
				str[i] = *cur;
				i--;
			}
		}
	}

};


int main1()
{
	char str[30] = "we are friend ";
	Solution1 s;
	s.replaceSpace(str, 30);
	cout << str << endl;
	system("pause");
	return 0;
}