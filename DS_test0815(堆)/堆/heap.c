#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"


void HeapInit(Heap* hp, HPDataType* a, int n)//�ѵĳ�ʼ��
{
	assert(hp != NULL);
	hp->capacity = 2 * n;
	hp->size = n;
	hp->data = (HPDataType*)malloc(sizeof(HPDataType)*hp->size);
	int i;
	for (i = 0; i < n; i++)
	{
		hp->data[i] = a[i];
	}
	for (i = n/2; i >= 0; i--)//�ӵ�һ����Ҷ�ӽڵ�����ִ�����µ����㷨
	{
		AdjustDown(hp,i);
	}
}

void HeapDestory(Heap* hp)//���ٺ���
{
	assert(hp != NULL);
	if (hp->data != NULL)
	{
		free(hp->data);
		hp->data = NULL;
	}
	hp->capacity = 0;
	hp->size = 0;
}
void HeapPush(Heap* hp, HPDataType x)//��������Ԫ��
{
	assert(hp != NULL);
	Heap *cur = hp;
	int i;
	hp->size++;//�����С��1
	hp->data[hp->size] = x;//������β�������
	for (i = (hp->size - 2 )/ 2; i >= 0; i--)//
	{
		AdjustDown(hp, i);
	}
}
void HeapPop(Heap* hp)//ɾ���Ѷ�Ԫ��
//�����һ��Ҷ�ӽڵ��滻Ϊ�Ѷ���size--,��ִ�����µ����㷨
{
	assert(hp != NULL);
	if (hp->size == 0)
	{
		return;
	}
	int tmp = hp->data[0];//���������׺�β������
	hp->data[0] = hp->data[hp->size - 1];
	hp->data[hp->size - 1] = tmp;
	hp->size--;//�����Ǹ�Ԫ�ؾͱ�ɾ��
	AdjustDown(hp, 0);//��ִ�����µ����㷨���õ�һ���µĶ�
}

HPDataType HeapTop(Heap* hp)//�ж϶��Ƿ�Ϊ�գ�Ϊ�շ���0�����򷵻ص�һ��Ԫ��
{
	assert(hp != NULL);
	if (hp->data == NULL)
	{
		return (HPDataType) 0;
	}
	return hp->data[0];
}

int HeapSize(Heap* hp)//����ѵ����ݳ���
{
	assert(hp != NULL);
	return hp->size;
}

int HeapEmpty(Heap* hp)//���
{
	assert(hp != NULL);
	memset(&hp, 0, sizeof(HPDataType)* hp->size);
	hp->capacity = 0;
	hp->size = 0;
	return 1;
}

void HeapPrint(Heap* hp)//��ӡ
{
	int i;
	int rn = 0;
	int bin = 1;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);
		if (i == rn)
		{
			putchar('\n');
			bin *= 2; 
			rn += bin; 
		}
	}
	putchar('\n');
	putchar('\n');
}

void AdjustDown(Heap* hp, int num)//���µ�������(���),�˺���ֻ��������num�±�Ľڵ�
//   1.if ( �Һ��Ӳ�����)       
//        ��¼��������(whileѭ�����жϣ��˽ڵ�һ��������Ҷ�ӽڵ㣬��������һ������)
//   2.else(���Һ��Ӷ�����)
//	       if ������>�Һ���,��¼��������		
//         else :����<=�Һ���,��¼�Һ�������
//   3.if(�˽ڵ��ֵ<����1.2��¼����ֵ)       
//        �򽻻����ߵ�ֵ����¼���������ӵ����꣬���뺢�ӽڵ㣬������ڵ㲻��Ҷ�ӽڵ㣬����ѭ��(��ֹ�ϴ�ѭ���ı������С��)
//     else        
//        break;
{
	int cur = num;//Ҫ���µ������±�
	int n;
	while (cur * 2 + 1 < hp->size)//�������겻��Խ��
	{
		if (cur * 2 + 2 >= hp->size)//û���Һ���
		{
			n = cur * 2 + 1;//��¼����ڵ��±�
		}
		else
		{
			if (hp->data[cur * 2 + 1] > hp->data[cur * 2 + 2])//�����Һ���������>�Һ���
			{
				n = cur * 2 + 1;//��¼�����±�
			}
			else//�����¼�Һ����±�
			{
				n = cur * 2 + 2;
			}
		}
		if (hp->data[cur]< hp->data[n])//���˽ڵ�ȼ�¼�ĺ���ֵС���򽻻����ߵ�ֵ
		{
			int tmp = hp->data[cur];
			hp->data[cur] = hp->data[n];
			hp->data[n] = tmp;
			cur = n;//��¼����������꣬���������ж�
		}
		else //���ڵ�Ⱥ���ֵ�󣬲���������������
		{
			break;
		}
	}
}

void AdjustUp(Heap* hp,int num)//(�����һ���ڵ�)���ϵ�������
{
	int tmp = num;//Ҫ���ϵ���������
	assert(hp != NULL);
	int i;
	int parent = (num - 1) / 2;
	while (parent > 0)
	{
		if (hp->data[parent] > hp->data[(parent - 1) / 2])
		{
			int tmp = hp->data[parent];
			hp->data[parent] = hp->data[(parent - 1) / 2];
			hp->data[(parent - 1) / 2] = tmp;
			parent = (parent - 1) / 2;//�����ɹ�����λ�����ڵ㣬����ѭ��ֱֻ�������ڵ㡣
		}
		else
		{
			break;
		}
	}
}


void HeapSort(Heap* hp)// ������ 
{
	assert(hp != NULL);
	int i;
	int tmp = hp->size;//��¼�ѵĴ�С
	for (i = 0; i < hp->size; i++)
	{
		HeapPop(hp);//�ѵ�һ��Ԫ����󣬲�ͣ����ֱ������Ԫ�ؽ���
	}
	hp->size = tmp;//����Ԫ��ʵ���ϲ�û��ɾ����ֻ�ǰ�size����0��,�ź����
	//���¸�size��ԭֵ�������С�ָֻ������ź�����������Ͳ����Ƕ��ˣ�ֻ��һ�����������
}

void TestHeap()
{
	int data[] = { 1, 5, 3, 8, 7, 6 };
	Heap hp;
	HeapInit(&hp, data, 6);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPush(&hp, 8);
	HeapPrint(&hp);
	AdjustUp(&hp,5);
	HeapPrint(&hp);
	system("pause");
	return 0;
}


