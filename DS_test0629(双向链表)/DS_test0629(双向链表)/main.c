#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include"List.h"
int main()
{
	List test,p;
	//test = p._head;
	ListInit(&test);
	ListPushFront(&test, 4);
	ListPushFront(&test, 3);
	ListPushFront(&test, 2);
	ListPushFront(&test, 1);
	ListPushBack(&test, 5);
	ListPushBack(&test, 6);
	ListPushBack(&test, 7);
	ListPushBack(&test, 8);
	//ListPopBack(&test);

	//ListPopFront(&test);

	//p=ListFind(&test, 12); // ��pos��ǰ����в���
	//if (p != NULL)
	//	printf("%d\n", p->_data);
	//else
	//	printf("sdsd\n");
	//p = ListFind(&test, 3); // ��pos��ǰ����в���
	//if (p != NULL)
	//	printf("%d\n", p->_data);
	//else
	//	printf("sdsd\n");
	ListInsert(test._head->_next->_next->_next,212);  

	//ListErase(test._head->_next->_next->_next);//ע�⣺test._head��ListNode*����

	//ListRemove(&test,2);
	/*p = test._next->_next;
	ListErase(p)*/;

	//ListDestory(&test);
	ListPrint(&test);
	system("pause");
	return 0;
}

