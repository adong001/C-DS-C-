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
//4.ʵ��strchr
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
//7.ʵ��memmove



size_t my_strlen(const char* str)
{
	int size=0;
    assert(str != NULL);
	while (*str++ != '\0'){ size++; }
	return size;
}

char *my_strncpy(char* str, const char* soure, size_t n)//��src��ָ�ַ�����ǰn���ַ����
{
	char *dest = str;
	assert(str != NULL && soure != NULL);//ע�����assert�е�ֵΪ0ʱֱ�ӻ���ֹ������
	while ((n-- > 0) && (*dest++ = *soure++));
	return str;
}
char *my_strncat(char* str, const char* soure, size_t n)//��src��ָ�ַ�����ǰn���ַ����
{
	char *dest = str;
	while (*dest){ dest++; };
    assert(str != NULL && soure != NULL);//ע�����assert�е�ֵΪ0ʱֱ�ӻ���ֹ������
	while (*dest){ dest++; };
    while ((n-- > 0) && (*dest++ = *soure++));
    return str;
}

size_t my_strncmp(const char* str1, const char* str2,size_t n)//�Ƚ������ַ���ǰn���ַ�
{
	const unsigned char* src1 = (const unsigned char*)str1;
	//ǿת��const unsigned char* ��Ϊ����������ָ���ֵ��ascii���
	const unsigned char* src2 = (const unsigned char*)str2;
	int ret = 0;
	assert(src1 != NULL && src2 != NULL);
	while (!(*src1 - *src2) && *src2 && n > 0 )//�������ֵ����Ȼ�*src2��asciiΪ0,
	{//(*src1-*src2,�������*src2��ascii��ֵΪ0,��*src1�ͱ�*src2������,��Ȼ�������֪��,�˳�ѭ����,
	 //�ͼ����ж�, ������������ֵ���˳�ѭ��
		src1++, src2++,n--;
	}
	ret = (*(--src1) - *(--src2));//�Ƚ�n���ַ�ָ���ƶ�����n+1��λ�ã�-1����n�ķ�Χ��
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

//int main()
//{
//	char str1[20]= "abcd";
//	char str2[20] = "abcdef";
//	printf("%d\n",my_strcmp(str1, str2));
//	return 0;
//}
//| ����ֵ | str1   str2 |
//| -- | -- |
//| 1 | > ||
//| 0 |= |
//| -1 | < |
/*char str[20];
char str1[20]="i am ";
char str2[20] = "a student ";
my_strcpy(str,my_strcat(str1, str2));
puts(str);

}*/
//int my_strcmp(const char* str1, const char* str2)
//{
//
//}
//typedef struct student
//{
//	
//	char name[20];   //20
//	char sex;        //4
//	int num;         //4
//}student;
//#include <stdio.h> #pragma pack(8)
//struct S1 {    
//	char c1;   
//	int i;
//    char c2; };
//#pragma pack()
//int main()
//{
//	printf("%d\n", sizeof(struct S1));
//
//	char str[10];
//	char str2[10];
//	printf("%d\n", strcmp(str, str2));
	/*char str[20];
	char str1[20]="i am ";
	char str2[20] = "a student ";
	my_strcpy(str,my_strcat(str1, str2));
	puts(str);

}*/



//#include <string.h>
//
//int main() 
//{
//	char str[] = "- hhhhhhh, a sample string,"; 
//char * pch; d
//printf("Splitting string \"%s\" into tokens:\n", str);
//pch = strtok(str, " ,,-"); 
//
//while (pch != NULL) 
//{ printf("%s\n", pch);
//pch = strtok(NULL, " ,,-"); } 
//return 0; }
////int mainl()
////{
////	char str[] = "hahah\012";
////	printf("%d\n", my_strlen(str));
////    system("pause");
////    return 0;


//
//char *my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 != NULL);
//	char *s1 = (char*)str1;
//	char *s2 = (char*)str2;
//	char *p = (char*)str1;
//	if (str2 == NULL)
//	{
//		return NULL;
//	}
//	while (*p)
//	{
//		s1 = p;
//		s2 = str2;
//		while (*s1&&*s2&&*s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return p;
//		}
//		p++;
//	}
//	return 0;
//}
//
//int main()
//{
//
//	char str1[] = "abcdcdefggg";
//	char str2[] = "cdef";
//	puts(my_strstr(str1, str2));
//}
	/*while (*s1)
	{
		p = s1;
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		s2 = str2;
	}

}*/

//typedef struct student
//{
//	int num;
//	char name[20];
//	char sex;
//}stu;
//int main()
//{
//	stu a = { 1, "�", 'f' };  //�ṹ������ֻ�ܳ�ʼ��
//	printf("%d %s %c\n", a.num, a.name, a.sex);
//	//stu b;
//	//b = { 2, "����", '��' };    //����ֱ�Ӹ�ֵ���������� 
//	//char ar[10] = "ajdjajd";
//	//char arr[10];
//	//arr = "adwokoefowkef";      //����ֱ�Ӹ�ֵ��ֻ�ܳ�ʼ��
//	stu b;                       //��Ҫ��ֵ��ֻ�ֱܷ�Գ�Ա��ֵ��
//	b.num = 2;
//	strcpy(b.name, "����");
//	b.sex = '��';
//	stu c;
//	c = a;
//	printf("%d %s %c\n", c.num, c.name, c.sex);
//	system("pause");
//	return 0;
//}

//#pragma pack(2)
//struct data
//{
//	int a;  // 4  2
//	char b; // 1  2
//}; 
//#pragma pack() 
//int main()
//{
//	printf("%d\n", sizeof(struct data));
//}

//#define my_offsetof(s,m)  (size_t)&(((s *)0)->m)
//typedef struct student
//{
//	int num;       //4
//	char name[20]; //20
//	char sex;      //4
//}stu;
//int main()
//{
//	printf("%d\n", my_offsetof(stu,name));
//}

//struct A    
//{   //λ��
//	int a : 2; 
//	int b : 5; //2 ��5, 10 ռһ��int�ֽڣ�
//	int c : 10;
//	int d : 30;//30�Լ�ռһ��int�ֽ�
//};
//int main()
//{
//	struct A a;
//	a.a = 2;
//	a.b = 5;
//	printf("%d\n", sizeof(struct A));
//}

//typedef enum week
//{
//	Mon=1,Tues,Wed,Thu=3,Fri,Sat,Sun
//}week;
//int main1()
//{
//	week W;
//	W = Wed;
//	printf("%d\n", W);
//}
//typedef union Un
//{
//	int a;
//	char b;
//	double c;//�������С�����ĳ�ԱΪ׼
//}Un;

//int main()-
//{
//	Un U;
//	//U.a = 10;
//	//U.b = '3';
//	//printf("%d\n", sizeof(Un));
//	//printf("%p\n", U.a);
//	//printf("%p\n", U.b);=
//	U.a = 0x11223344;
//	U.c = 0x55;
//	printf("%x\n", U.a);
//	printf("%x\n", U.c);
//}
//int sys_check()
//{
//	int a = 1;
//	return *(((char*)a) & 1);
//}
//union data
//{
//	short int a;
//	char b[2];sss
//
//};


//register int i;
//(����)�����ڼĴ�����������棬����û�е�ַ��
//volatile 
//volatile����������Ϊָ��ؼ��֣�ȷ������ָ�������������Ż���ʡ�ԣ���Ҫ��ÿ��ֱ�Ӷ�ֵ��
//static 
//���ƺ����ͱ�����������;
//����