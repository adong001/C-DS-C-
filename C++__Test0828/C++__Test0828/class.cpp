#include<iostream>
using namespace std;
class ct//����һ������Ľṹ�壬�ṹ��û����Ķ�̬���̳���
{
public:
	char a;
	int b;
	double c;
	void Print1()
	{
		cout << b << endl;
	}
	void Print2();

};

void ct:: Print2()
{
	cout << c << endl;
}

int main()
{
	ct c;
	c.b = 100;
	c.c = 3.4;
	c.Print1();
	c.Print2();
	cout << sizeof(ct) << endl;
    system("pause");
    return 0;
}