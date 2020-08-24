#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//�жϻ��Ĵ�
bool Palindrome(const char* str)
{
	const char* end = str;
	const char* start = str;
	//�ҵ��ַ���ĩβ


	end = str + strlen(str) - 1;
	if (start == end)
	{
		//ֻ��һ���ַ��ͷ���true;
		return true;
	}

	for (; start < end; start++, end--)
	{
		//���ǻ�ζ��ֱ�ӷ���
		if (*start != *end)
		{
			return false;
		}
	}
	//��������о�true
	return true;
}

int main()
{
	char src[100] = { 0 };
	int n;
	while (scanf("%s", src) != EOF)
	{
		if (Palindrome(src))
		{
			printf("true\n");
		}
		else
		{
			printf("false\n");
		}
		memset(src, 0, 100);
	}
	return 0;
}