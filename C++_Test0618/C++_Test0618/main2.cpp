#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
class A{
public:
	A(){ p();}
	virtual void p(){
		printf("A");
	}
	virtual ~A(){ p(); }
};
class B :public A
{
public:
	B(){ p(); }
	void p(){
		printf("B");
	}
	~B(){ p(); }
};
int main2()
{
	A* a = new B();
	delete a;
	string src;
	while (getline(cin, src))
	{
		if (src.find("joker JOKER") != -1)
		{
			cout << "joker JOKER" << endl;
			continue;
		}
		string flag = "345678910JQKA2jokerJOKER";
		int pos = src.find('-');
		string car1 = src.substr(0, pos);
		string car2 = src.substr(pos + 1);
		int Size1 = count(car1.begin(), car1.end(), ' ');
		int Size2 = count(car2.begin(), car2.end(), ' ');
		string s1 = car1.substr(0, car1.find(' '));
		string s2 = car2.substr(0, car2.find(' '));
		if (Size1 == Size2)//����������ȣ�ֻ��Ƚϵ�һ������
		{
			if (flag.find(s1) > flag.find(s2))
			{
				cout << car1 << endl;
			}
			else
			{
				cout << car2 << endl;
			}
		}
		else//������������ȣ�˵��һ������ը
		{
			if (Size1 == 3)//˭���ĸ�˭����ը����
			{
				cout << car1 << endl;
			}
			else if (Size2 == 3)
			{
				cout << car2 << endl;
			}
			else
			{
				cout << "ERROR" << endl;
			}
		}
	}
	return 0;
}