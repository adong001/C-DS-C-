#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//BTNode* BinaryTreeCreate(BTDataType* src)//����������
//{
//	static int s_n = 0;
//	if (src[s_n] == '#')
//	{
//		s_n++;
//		return NULL;
//	}
//	BTNode *cur = (BTNode *)malloc(sizeof(BTNode));
//	cur->_data = src[s_n];
//	s_n++;
//	cur->lchild = BinaryTreeCreate(src);
//	cur->rchild = BinaryTreeCreate(src);
//	return cur;
//}
//
//void BinaryTreeDestory(BTNode* root)//�����������
//{
//	if (root != NULL)
//	{
//		BinaryTreePostOrder(root->lchild);
//		BinaryTreePostOrder(root->rchild);
//		free(root);
//	}
//}
class MinStack
{
private:
	stack<int> m_Data;
	stack<int> m_MinData;
public:
	MinStack()
	{

	}

	void push(int x)
	{
		m_Data.push(x);
		if (m_MinData.size() < 1 || x < m_MinData.top())//MinData��û�����ݻ�MinData��ջ��ֵ����x
		{
			m_MinData.push(x);
		}
	}

	void pop()
	{
		if (m_Data.top() <= m_MinData.top())
		{
			m_MinData.pop();
		}
		m_Data.pop();
	}

	int top()
	{
		if (m_Data.empty())
		{
			return INT_MAX;
		}
		return m_Data.top();
	}

	int getMin()
	{
		if (m_MinData.empty())
		{
			return INT_MAX;
		}
		return m_MinData.top();
	}
};
//���һ��֧�� push��pop��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
//
//push(x) --��Ԫ�� x ����ջ�С�
//pop() --ɾ��ջ����Ԫ�ء�
//top() --��ȡջ��Ԫ�ء�
//getMin() --����ջ�е���СԪ�ء�

//ʾ�� :
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> ���� - 3.
//minStack.pop();
//minStack.top();      --> ���� 0.
//minStack.getMin();   --> ���� - 2.


int p1()
{
	MinStack minStack;
	minStack.push(-2);
	/*minStack.push(0);
	minStack.push(-3);*/
	cout << minStack.getMin() << endl;;
	minStack.pop();
	cout << minStack.top() << endl;;
	cout << minStack.getMin() << endl;;
	return 0;
}
