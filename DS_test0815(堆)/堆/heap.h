#ifndef HEAP_H
#define HEAP_H
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>
typedef int HPDataType;

typedef struct Heap
{
	HPDataType *data;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n);//��ʼ����
void HeapDestory(Heap* hp);//���ٶ�
void HeapPush(Heap* hp, HPDataType x);//����Ԫ��x,��֤�����¶�
void HeapPop(Heap* hp);//ɾ���Ѷ�Ԫ��,��֤�����¶�
HPDataType HeapTop(Heap* hp);//�ж϶��Ƿ�Ϊ�գ�Ϊ�շ���0�����򷵻ص�һ��Ԫ��
int HeapSize(Heap* hp);//�������ݵ�����
int HeapEmpty(Heap* hp);//��ն�
void HeapPrint(Heap* hp);//��ӡ��
void AdjustDown(Heap* hp, int n);//��n�ڵ㴦���µ�������
void AdjustUp(Heap* hp);//(�����һ���ڵ�)���ϵ�������
void HeapSort(int* a, int n);// ������ 
void TestHeap();

#endif 
