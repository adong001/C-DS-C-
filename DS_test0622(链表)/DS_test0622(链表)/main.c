#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include"Node.h"
#include<assert.h>
void TestSList()
{
	SList test,list;
	SListNode *n;
	SListInit(&test);
	SListPushFront(&test, 4);
	SListPushFront(&test, 1);
	SListPushFront(&test, 5);
	SListPushFront(&test, 3);
	SListPushFront(&test, 9);
	test._head->_next->_next->_next->_next = test._head->_next;
	//SListInit(&list);
	//SListPushFront(&test, 2);
	//SListPushFront(&test, 1);
	//SListPushFront(&test, 7);
	//SListPushFront(&test, 8);
   /* n=SListFind(&test, 5);
	printf("%d\n", n->_data);*/
	//SListInsertAfter(test._head, 100);
	/*SListInsertAfter(test._head->_next, 111);
	SListInsertAfter(test._head->_next, 112);*/
	//SListRemove(&test, 1);
	//SListReverse(&test);
	//n=SListIntersect(&test, &list);
	// ��pos��ǰ����в���
	// SListEraseAfter(test._head ->_next);
	int p=SListHasCycle(&test);
	printf("%d\n", p);
	//SListPrint(&test);
}
int main()
{
	TestSList();
    system("pause");
    return 0;
}