#include<iostream>
#include<queue>
#include<stack>
using namespace std;
//1.����������ʵ��һ��ջ
template<class T>
class Stack
{
private:
	queue<T> queue1;
public:
	void push(T x)
	{
		queue1.push(x);
	}

	void pop()
	{
		queue<T> queue2;
		while (queue1.size() > 1)
		{
			queue2.push(queue1.front());
			queue1.pop();
		}
		queue1 = queue2;
	}

	T& top()
	{
		return queue1.back();
	}

	bool empty()
	{
		return queue1.empty();
	}

	size_t size()
	{
		return queue1.size();
	}
};

int main1()
{
	Stack<int> st;
    st.push(1);
    st.push(2);
    st.pop();
    st.push(3);
    st.push(4);
    st.pop();
    cout << st.top() << endl;
    return 0;
}



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
int main()
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