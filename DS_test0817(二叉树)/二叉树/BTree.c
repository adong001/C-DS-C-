#include"BTree.h"
#include"Queue.h"
#include"stack.h"


BTNode* BinaryTreeCreate(BTDataType* src)//����������
{
	static int s_n = 0;
	if (src[s_n] == '#')
	{
		s_n++;
		return NULL;
	}
	BTNode *cur = (BTNode *)malloc(sizeof(BTNode));
	cur->_data = src[s_n];
	s_n++;
	cur->lchild = BinaryTreeCreate(src);
	cur->rchild = BinaryTreeCreate(src);
	return cur;
}

void BinaryTreeDestory(BTNode* root)//�����������
{
	if (root != NULL)
	{
		BinaryTreePostOrder(root->lchild);
		BinaryTreePostOrder(root->rchild);
		free(root);
	}
}

int BinaryTreeDeep(BTNode* root)//�������
{
	if (root == NULL) //�νڵ�Ϊ�շ���0
	{
		return 0;
	}
	int LeftlChildDeth = BinaryTreeDeep(root->lchild);//�ݹ��������
	int RightChildDeth = BinaryTreeDeep(root->rchild);//�ݹ�����Һ���
	return LeftlChildDeth > RightChildDeth ? LeftlChildDeth + 1 : RightChildDeth + 1;
	//���Һ��Ӷ�Ϊ����return 0+1���Զ�Ϊ2����Ϊ����
    //����Ϊ�գ��Һ��Ӳ�Ϊ�գ���return 1+1
	//���Ӳ�Ϊ�գ��Һ���Ϊ�գ���return 1+1
	//���Һ��Ӷ���Ϊ�գ���return 1+1
}

int BinaryTreeSize(BTNode* root)//��ڵ����
{
	int count = 0;
	BTNode *cur = root;
	if (cur == NULL)
	{
		return 0;
	}
	count++;
	count += BinaryTreeSize(cur->lchild);
	count += BinaryTreeSize(cur->rchild);
	return count;
}

int BinaryTreeLeafSize(BTNode* root)//��Ҷ�ӽڵ����
{
	int count = 0;
	BTNode *cur = root;
	if (cur == NULL)
	{
		return 0;
	}
	if (cur->lchild == NULL && cur->rchild == NULL)
	{
		count++;
		return count;
	}
	count += BinaryTreeLeafSize(cur->lchild);
	count += BinaryTreeLeafSize(cur->rchild);
	return count;
}

//int BinaryTreeLevelKSize(BTNode* root, int k)//�����K��ڵ����(�ǵݹ�)
//{
//	assert(root);
//	if (k < 1 ||  k > BinaryTreeDeep(root))//�ж�����Ĳ����Ƿ�Ϸ�
//	{
//		return 0;
//	}
//	if (k == 1)//�����һ�㣬�ɵ�һ�п�֪��������ִ�е���һ����˵�����ڵ���ڣ���һ��ֻ��һ�����ڵ㷵��1
//	{
//		return 1;
//	}	
//	Dequeue qu;//����һ�����б���
//	BTNode *cur;//���������м����
//	int flag = 1;
//	int ret = 1;//�������Ľڵ��������Ϊ��һ���ѭ����������һ�γ�ʼ��Ϊ1���������Һ��Ӻ������
//	dequeueInit(&qu);
//	dequeuePush(&qu, root);//���ڵ������
//	while (k - 2 > 0)//�����룬ѭ��k-2�ε�k-1�㣬���k-1������нڵ�����Һ��Ӽ�Ϊ��������Ŀ��(���whileֻ���k-1��ڵ�ĸ���)
//	{
//		int tmp = ret;//�м����tmp,��¼ret��ֵ(��һ��ڵ����)��Ϊѭ������,�����²�ڵ����
//		for (int i = 0; i < tmp;i++)//ͨ��ret��¼���ϲ�ڵ����
//		{
//			cur = dequeueTop(&qu);//ȡ����
//			if (cur->lchild)//���Ӵ��ڣ�������ӣ�����¼��һ��νڵ�ĺ�����
//			{
//				dequeuePush(&qu, cur->lchild);
//				ret++;
//			}
//			if (cur->rchild)//�Һ��Ӵ��ڣ��Һ�����ӣ�����¼��һ��νڵ�ĺ�����
//			{
//				dequeuePush(&qu, cur->rchild);
//				ret++;
//			}
//			if (flag)//��һ�ν���ret--������ѭ�����ܽ��룬���Եڶ���ڵ����Ϊret=1+1+1-1=2(���ڵ�����Һ��Ӷ�����)
//			{
//				ret--;
//				flag = 0;
//			}
//			dequeuePop(&qu);//���ڵ���ӡ�
//		} 
//		k--;
//	}
//	int count = 0;//��K��ڵ����
//	while (dequeueIsEmpty(&qu))//���в�Ϊ��
//	{
//		cur = dequeueTop(&qu);//ȡ����
//		if (cur->lchild)//���Ӵ���count++
//		{
//			count++;
//		}
//		if (cur->rchild)//�Һ��Ӵ���count++
//		{
//			count++;
//		}
//		dequeuePop(&qu);//���׳���
//
//	}
//	dequeueDestory(&qu);
//	return count;
//}//
int BinaryTreeLevelKSize(BTNode* root, int k)//�����K��ڵ����
{
	static int i = 1, size;//������������̬������¼���Ĳ�������ֹÿ�εݹ鶼����BinaryTreeDeep����������С��ջ�Ŀ���
	if (i)
	{
		size = BinaryTreeDeep(root);
		i = 0;
	}
	if (k < 1 || k >size || root == NULL)//�ж�����Ĳ����ʹνڵ��Ƿ�Ϸ�
	{
		return 0;
	}
	if (k == 1)//�����һ�㣬�ɵ�һ�п�֪��������ִ�е���һ����˵�����ڵ���ڣ���һ��ֻ��һ�����ڵ㷵��1
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->lchild, k - 1) + BinaryTreeLevelKSize(root->rchild, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode *cur = NULL;
	if (root != NULL)
	{
		if (root->_data == x)
		{
			return root;
		}
		cur = BinaryTreeFind(root->lchild, x);
		cur = BinaryTreeFind(root->rchild, x);
	}
	return cur;
}



// ����
void BinaryTreePrevOrder(BTNode* root)//�������
{
	if (root != NULL)
	{
		putchar(root->_data);
		BinaryTreePrevOrder(root->lchild);
		BinaryTreePrevOrder(root->rchild);
	}
}
void BinaryTreeInOrder(BTNode* root)//�������
{
	if (root != NULL)
	{
		BinaryTreeInOrder(root->lchild);
		putchar(root->_data);
		BinaryTreeInOrder(root->rchild);
	}
}

void BinaryTreePostOrder(BTNode* root)//�������
{
	if (root != NULL)
	{
		BinaryTreePostOrder(root->lchild);
		BinaryTreePostOrder(root->rchild);
		putchar(root->_data);
	}
}

// �ǵݹ���� // 
void BinaryTreeLevelOrder(BTNode* root)// �������
{
	Dequeue qu;
	BTNode *cur;
	dequeueInit(&qu);
	dequeuePush(&qu, root->_data);
	while (dequeueIsEmpty(&qu))
	{
		cur = dequeueTop(&qu);
		putchar(cur->_data);
		if (cur->lchild)
		{
			dequeuePush(&qu, cur->lchild);
		}
		if (cur->rchild)
		{
			dequeuePush(&qu, cur->rchild);
		}
		dequeuePop(&qu);
	}
	dequeueDestory(&qu);
}
 
int BinaryTreeComplete(BTNode* root)//�ж��Ƿ�Ϊ��ȫ������
{

	Dequeue qu;
	BTNode *cur;
	dequeueInit(&qu);
	int tag = 0;
	dequeuePush(&qu, root);
	while (dequeueIsEmpty(&qu))
	{
		cur = dequeueTop(&qu);
		
		if (!cur->lchild && cur->rchild)
		{
			return 0;
		}
		if (tag && ((cur->lchild) || (cur->rchild)))
		{
			return 0;
		}
		if (cur->lchild)
		{
			dequeuePush(&qu, cur->lchild);
		}
		if (cur->rchild)
		{
			dequeuePush(&qu, cur->rchild);
		}
		else
		{
			tag = 1;
		}
		dequeuePop(&qu);
	}
	dequeueDestory(&qu);
	return 1;	
}

void BinaryTreePrevOrderNonR(BTNode* root) // �������(�ǵݹ�)
{
	Stack st;
	BTNode *cur = root;//�Ӹ���ʼ
	StackInit(&st,100);
	while (cur)
	{
		putchar(cur->_data);
		cur = StackTop(&st);
		
		if (cur->rchild)
		{
			StackPush(&st, cur->rchild);
		}
		if (cur->lchild)
		{
			cur = cur->lchild;
		}
		else
		{
			cur = StackTop(&st);
			StackPop(&st);
		}
	}
	StackDestory(&st);
}

void BinaryTreeInOrderNonR(BTNode* root)// �������(�ǵݹ�)
{
	Stack st;
	BTNode *cur = root;
	StackInit(&st, 100);
	while (1)
	{
		for (; cur; cur = cur->lchild)   
		{
			StackPush(&st, cur);
		}
		cur = StackTop(&st);
		putchar(cur->_data);
		StackPop(&st);
		cur = cur->rchild;
	}
	StackDestory(&st);
}

void BinaryTreePostOrderNonR(BTNode* root)// �������(�ǵݹ�)
{
	char tag[64];
	Stack st;
	BTNode *cur = root;
	StackInit(&st, 100);
	
	do{
		for (; cur; cur = cur->lchild)
		{
			StackPush(&st, cur);
			tag[st._size - 1] = 0;
		}
		while (StackIsEmpty(&st) && tag[st._size - 1])
		{
			cur = StackTop(&st);
			putchar(cur->_data);
			StackPop(&st);
		}
		if (cur != NULL)
		{
			cur = StackTop(&st);
			tag[st._size - 1] = 1;
			cur = cur->rchild;
		}
	} while (StackIsEmpty(&st));
	StackDestory(&st);
}

void BinaryTreeTest()
{
	char src[] = "ABD##E#H##CF##G##";//AB##C##
	BTNode *cur;
	BTNode *root = BinaryTreeCreate(src);
	BinaryTreePrevOrder(root);
	putchar('\n');
	BinaryTreeInOrder(root);
	putchar('\n');
	BinaryTreePostOrder(root);
	putchar('\n');
	printf("%d\n", BinaryTreeLeafSize(root));
	printf("%d\n", BinaryTreeSize(root));
	cur = BinaryTreeFind(root, 'C');
	if (cur == NULL)
	{
	printf("not Find\n");
	}
	else
	{
	printf("find value is %c\n", cur->_data);
	}
	printf("%d\n", BinaryTreeDeep(root));
	printf("%d\n", BinaryTreeComplete(root));
	printf("%d\n", BinaryTreeLevelKSize(root, 4));
	BinaryTreeDestory(root);
}