#ifndef _SEQLIST_C
#define _SEQLIST_C
#define CAPACITY 100 //�����ռ��С
typedef int  SLDataType;

typedef struct SeqList // ˳���Ķ�̬�洢 
{
	SLDataType* array; // ָ��̬���ٵ�����   
	size_t size;       // ��Ч���ݸ���     
	size_t capacity;   // �����ռ�Ĵ�С
}SeqList;

// ������ɾ��Ľӿ� 
void SeqListInit(SeqList* psl, size_t capacity); 
void SeqListDestory(SeqList* psl);
void CheckCapacity(SeqList* psl);
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl); 
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);
int SeqListFind(SeqList* psl, SLDataType x);
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x); 
void SeqListErase(SeqList* psl, size_t pos); 
void SeqListRemove(SeqList* psl, SLDataType x); 
void SeqListModify(SeqList* psl, size_t pos, SLDataType x); 
void SeqListPrint(SeqList* psl);
void SeqListBubbleSort(SeqList* psl);
int SeqListBinaryFind(SeqList* psl, SLDataType x); 
void SeqListRemoveAll(SeqList* psl, SLDataType x);

#endif _SEQLIST_H