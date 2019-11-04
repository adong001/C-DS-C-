#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//1.ʵ��strcpy
char* my_strcpy(char* str, const char* soure)
{
	char* dest = str;
	assert(dest != NULL && soure != NULL);
	while (*dest++ = *soure++);
	return str;
}
//2.ʵ��strcat
char* my_strcat(char* str, const char* soure)
{
	char* dest = str;
	assert(dest != NULL && soure != NULL);
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *soure++);
	return str;
}
//3.ʵ��strstr

char * my_strstr(const char *str1, const char *str2)
{
	char* p = str1;
	char* t = str2;
	char *q;
	assert(p != NULL && t != NULL);
	if (*t == '\0')
	{
		return NULL;
	}
	while (*p)
	{
		q = p;//qָ����p�ĳ�ʼλ�ã��ҵ��ͷ�����
		while (*p && *t && *t == *p)//str1��str2��û�������ҵ�����ַ���ָ���ƶ�
		{
			p++;
			t++;
		}
		if (*t == '\0')//�����ҵ�
		{
			return q;
		}
		p++;//�˴�ѭ��û�ҵ�,����������һ��Ѱ��
	}
}

//4.ʵ��strchr
char *my_strchr(const char *src, char value)
{
	assert(src != NULL);
	if (value == '\0')
	{
		return NULL;
	}
	while (*src && (*src != value))
	{
		src++;
	}
	if (src != '\0')
	{
		return src;
	}
	return NULL;

}
//5.ʵ��strcmp
size_t my_strcmp(const char* str1, const char* str2)
{
	const unsigned char* src1 = (const unsigned char*)str1;
	//ǿת��const unsigned char* ��Ϊ����������ָ���ֵ��ascii���
	const unsigned char* src2 = (const unsigned char*)str2;
	int ret = 0;
	assert(src1 != NULL && src2 != NULL);
	while (!(*src1 - *src2) && *src2)//�������ֵ����Ȼ�*src2��asciiΪ0,
	{//(*src1-*src2,�������*src2��ascii��ֵΪ0,��*src1�ͱ�*src2������,��Ȼ�������֪��,�˳�ѭ����,
		//�ͼ����ж�, ������������ֵ���˳�ѭ��
		src1++, src2++;
	}
	ret = (*src1 - *src2);
	if (ret < 0)
	{
		return -1;
	}
	else if (ret>0)
	{
		return 1;
	}
	return (ret);
}
//6.ʵ��memcpy
void *my_memcpy(void *dest, const void *src, size_t num)
{
	char *str1 = (char *)dest;//ӦΪ�˺���Ҫ��dest��n���ֽ�copy��dest
	char *str2 = (char *)src;//������ǿתΪchar*
	assert(dest != NULL && dest != NULL);//ʹ��assert���ԣ���ֹ����ָ��
	while (num--)
	{
		*str1++ = *str2++;//�мǲ��ܰѴ���������while()��,��������ǿת��char*
	}//ʱ֮����ܻ����'\0'���ֽڣ��ᵼ��while�Ľ���
	return dest;
}
//��Դdest��ָ���ڴ��ַ����ʼλ�ÿ�ʼ����n���ֽڵ�Ŀ��dest��ָ���ڴ��ַ����ʼλ����
//7.ʵ��memmove
void *my_memmove(void * dest, const void * src, size_t num)
{
	char *str1 = (char*)dest;//��һ����char*ָ��Ҫ����������ַ������׵�ַ
	char *str2 = (char*)src;//memmove���ֽ��ƶ�����������ǿתΪchar*��
	assert(str1 != NULL&&str2 != NULL);//����ָ���ȶ���
	if (str1 <= str2 || str1 >= str2 + num)//���¾��Ƕ����ڴ��ص�ʱ��memcpy�Ĳ�֮ͬ����
	{//��Ϊ�����������һ�֣�dest�ڵ͵�ַ��һ���ַ��������ҵ�ַ�ɸߵ��ͣ���dest�ڸߵ�ַ
		//������һ���ƶ��ͺã����ᷢ���ڴ��ص����ڶ��֣�dest�ڸߵ�ַ��dest�ڵ͵�ַ��
		//��Ҫ�ƶ��ĳ��Ȳ�����ʹ�䷴���ڴ��ص���
		*str1++ = *str2++;
	}
	else//�����֣�dest�ڸߵ�ַ��dest�ڵ͵�ַ���ƶ��ĳ������ûᷢ���ڴ��ص�
	{//�������������ԭ���Ĵ������ƶ���Ϊ���������ƶ����Ȱ��ڴ��ص������
		//�ַ��ƶ��ߣ��Ͳ��ᱻ�ߵ�ַ�ĸ��ǵ���
		str1 += num - 1;//str1��str2���ƶ����ڴ��ص���������һ���ַ���
		str2 += num - 1;
		while (num--)
		{//���δ������Ҹ�ֵ
			*str1-- = *str2--;
		}
	}
}

int main()
{
	char str[] = "- This, a sample string.";
	char * pch;
	printf("Splitting string \"%s\" into tokens:\n", str);
	pch = strtok(str, " ,.-");
	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
	}
    system("pause");
    return 0;
}
//strtok
//char * strtok(char * str, const char * sep);
//sep�����Ǹ��ַ����������������ָ������ַ�����
//��һ������ָ��һ���ַ�������������0�����߶����sep�ַ�����һ�����߶���ָ����ָ�ı�ǡ� 
//strtok�����ҵ�str�е���һ����ǣ��������� \0 ��β������һ��ָ�������ǵ�ָ�롣
//��ע��strtok������ �ı䱻�������ַ�����������ʹ��strtok�����зֵ��ַ���һ�㶼����ʱ���������ݲ��ҿ��޸ġ���
//strtok�����ĵ�һ��������Ϊ NULL ���������ҵ�str�е�һ����ǣ�strtok���������������ַ����е�λ�á�
//strtok�����ĵ�һ������Ϊ NULL �� ��������ͬһ���ַ����б������λ�ÿ�ʼ��������һ����ǡ�
//����ַ����в����ڸ���ı�ǣ��򷵻� NULL ָ�롣
//strerror
//char * strerror(int errnum)
//ͨ����׼����ı�ţ���ô���������ַ��� ���������Ĵ�����תΪ�ַ��������������û����Ҵ���
//#include <errno.h>//���������ͷ�ļ�