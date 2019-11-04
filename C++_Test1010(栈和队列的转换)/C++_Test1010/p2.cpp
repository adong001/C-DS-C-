
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
//2.������ջʵ��һ������
template<class T>
class Queue
{
private:
	stack<T> st1;
public:
	void push(T x)
	{
		st1.push(x);
	}

	void pop()
	{
		stack<T> tmp;
		stack<T> st2;

		while (st1.size() > 1)
		{
			st2.push(st1.top());//��st1�е�����������ջ��st2
			st1.pop();
		}
		st1.pop();//��st1��գ�

		while (!st2.empty())
		{
			st1.push(st2.top());//�ٽ�st2������������ջ��st1,��ʱ��st1�Ѿ�pop����һ��Ԫ�ء�
			st2.pop();
		}
	}

	T& front()
	{
		T res;
		stack<T> tmp;
		tmp = st1;

		while (st1.size() > 1)
		{
			st1.pop();
		}
		res = st1.top();//��¼front��ֵ

		st1 = tmp;
		return res;
	}

	T& back()
	{
		return st1.top();
	}

	bool empty()
	{
		return st1.empty();
	}

	size_t size()
	{
		return st1.size();
	}

};
int p2()
{
	Queue<int> qu;
	qu.push(1);
	qu.push(2);
	qu.pop();
	cout << qu.front() << endl;
	qu.push(3);
	qu.push(4);
	qu.push(5);
	qu.pop();
	cout << qu.back() << " " << qu.front() << endl;
	system("pause");
	return 0;
}