#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


typedef int ElemType;
typedef enum Status
{
	OK = 1
}Status;

typedef struct LNode   //������
{

	ElemType data;
	struct LNode *next;
}LNode,*LinkList;



LinkList CreatLink()   //��������
{
	LinkList  p, s, head;
	head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	p = head;
	printf("��������ֵ(����-1����):\n");
	while (1){
		s = (LinkList)malloc(sizeof(LNode));        //�����½ڵ�
		scanf("%d", &s->data);                      //����������
		if (s->data < 0)                            //���븺�� �����
		{
			break;  
		}                     
		p->next = s;
		p = s;
	}
	p->next = NULL;        //���һ���ڵ�����ָ��Ϊ��
	return head;
}

void PutLink(LinkList L)             //�������
{
	int count = 0;
	if (L == NULL)
	{
		printf("������Ϊ�գ�����\n\n");
	}
	LinkList p;
	p = L->next;                //LΪ��ͷ��㣬PΪ��һ����Ч���
	if (p==NULL)
	{
		printf("������Ϊ�գ�����\n\n");
	}
	while (p != NULL)
	{
		printf("\n���������%d��",count);
		++count;
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
Status InsertLink(LinkList L)
{
	int i = 0;  //λ��
	ElemType e = 0;   //����
    int count = 0;   //������
	LinkList s=L, p;
	printf("������Ҫ�����λ�ú����ݣ�");
	scanf("%d%d", &i, &e);
	
	while (count != i)
	{
		s = s->next;
		++count;
	}
	p = (LinkList)malloc(sizeof(LNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
	return OK;
}

Status DeleteLink(LinkList L)
{
	int i = 0;  //λ��
	ElemType e = 0;   //����
	int count = 0;   //������
	LinkList s=L, p;
	printf("������Ҫɾ�����ݵ�λ�ã�");
	scanf("%d", &i);
	while (count != i)
	{
		s = s->next;
		++count;
	}
	p = s->next;
	s->next = s->next->next;
	free(p);
	return OK;
}

Status DestoryLink(LinkList L)
{
	LinkList p=L ,q= L;
	L->next= NULL;
	while (p)
	{
		p = q->next;
		q->next = NULL;
		free(q);
		q = p;
	}
	free(p);
	p = q = NULL;
	return OK;
}

int menu()
{
	int choice = 0;
	printf("\t\t\t\t********************\n");
	printf("\t\t\t\t*****1.¼������*****\n");
	printf("\t\t\t\t*****2.��������*****\n");
	printf("\t\t\t\t*****3.ɾ������*****\n");
	printf("\t\t\t\t*****4.ɾ������*****\n");
	printf("\t\t\t\t*****5.�˳�    *****\n");
	printf("\t\t\t\t********************\n\n");
	printf("\t\t\t\t�������ѡ��:");
	scanf("%d", &choice);
	return choice;
}
int main()
{
	LinkList L=NULL;
	while (1)
	{
	int choice = menu();
		switch (choice)
		{
		case 1:
			system("cls");
			L = CreatLink();
			PutLink(L);
			break;
		case 2:
			system("cls");
			InsertLink(L);
			PutLink(L);
			break;
		case 3:
			system("cls");
			DeleteLink(L);
			PutLink(L);
			break;
		case 4:
			system("cls");
			DestoryLink(L);
			PutLink(L);
			break;
		case 5:
			exit(1);
		default:system("cls"); printf("������󣡣���"); /*goto loop;*/
		}
	}
	system("pause");
	return 0;
}

