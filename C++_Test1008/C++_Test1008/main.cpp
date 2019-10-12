#include<iostream>
#include<stack>
using namespace std;

//���һ��֧�� push��pop��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
//
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


/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/


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
int main()
{
	MinStack minStack ;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-5);
	minStack.push(10);
	minStack.push(8);
	minStack.push(-10);
	cout << minStack.getMin() << endl;  // --> ���� - 10.
	minStack.pop();
	cout << minStack.top()<< endl;  //  --> ���� 8.
	cout << minStack.getMin() << endl;  // --> ���� - 5.

    system("pause");
    return 0;
}