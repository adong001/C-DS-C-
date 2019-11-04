#ifndef _NODE_H_
#define _NODE_H_

// 1����ͷ�����ѭ��������ɾ���ʵ�� 
typedef int SLTDataType; 
typedef struct SListNode
{   
	SLTDataType _data; 
    struct SListNode* _next; 
}SListNode;

typedef struct SList 
{ 
	SListNode* _head;
}SList;

void SListInit(SList* plist); 
void SListDestory(SList* plist);

SListNode* BuySListNode(SLTDataType x);

void SListPushFront(SList* plist, SLTDataType x); 

void SListPopFront(SList* plist); 

SListNode* SListFind(SList* plist, SLTDataType x); 
// ��pos�ĺ�����в��� 
void SListInsertAfter(SListNode* pos, SLTDataType x); 
// ��pos��ǰ����в���
void SListInsertBefore(SListNode* pos, SLTDataType x);
void SListEraseAfter(SListNode* pos); 
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist);
void SListReverse(SList *plist);
SListNode* SListIntersect(SList *plist1, SList *plist2);//�ҵ����������ཻ�ĵ�һ���ڵ㷵��(�����޻�)
int SListSize(SList *plist);
int SListHasCycle(SList *plist);//�ж�plist�Ƿ��л�

SListNode *SListDelectCycle(SList* plist);//�ҳɻ��ĵ�һ���ڵ�
void TestSList(); 
#endif _NODE_H_