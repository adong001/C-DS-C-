#ifndef _SORT_H_
#define _SOTR_H_
#include<stdio.h>
#include<stdlib.h>

void Print(int *ar, int n);

void InsertSort(int *ar, int n);//��������

void ShellSort(int *ar, int n);//ϣ������(��С������)

void SelectioSort(int *ar, int n);//ѡ������

void BubbleSort(int *ar, int n);//ð������

void HeapSort(int *ar, int n);//������

void QuickSort(int *ar, int n);//����

void MergeSort(int *ar,int n);//�鲢����

void mergesort(int *arr, int *tmp, int start, int end);
#endif 