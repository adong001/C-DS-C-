#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>


//1.��������ָ��
//2.���⺯��ָ��Ͷ���
//3.���⺯��ָ������Ͷ��壬ת�Ʊ�
//4.����ָ����ָ�������ָ��Ͷ���
//5.����ص�������ʹ��
//6.��ɿ��ô������ϰ��
//7.��ϰʹ��qsort��������������͵����ݡ�
//8.ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������
#include <stdio.h> 

//qosrt������ʹ���ߵ�ʵ��һ���ȽϺ��� int int_cmp(const void * p1, const void * p2) {    return (*( int *)p1 > *(int *) p2); } 
int int_cmp(const void * p1, const void * p2) 
{
	return (*(int *)p1 > *(int *)p2); 
}
int main()
{ 
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };   
	int i = 0;        
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof (int), int_cmp);  
	for (i = 0; i< sizeof(arr) / sizeof(arr[0]); i++)    
	{ 
		printf("%d ", arr[i]);
	}  
	printf("\n");    
	return 0; }

int main1()
{
    system("pause");
    return 0;
}