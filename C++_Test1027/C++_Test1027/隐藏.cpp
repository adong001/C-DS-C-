#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//���� : 
// ������1.������̳л���
//       2.�������������������Ա����(���麯��)
// �����1.�����
//
class Base //����
{
public:
	int m_a;//������Ա����
	Base() :
		m_a(10)
	{}
	void func() //������Ա����
	{
		cout << "Base" << endl;
	}

};


class Test :public Base //������
{
public:
	int m_a;//������Ա����
	Test() :
		m_a(20)
	{}
	void func()//������Ա����
	{
		cout << "Test" << endl;
	}
};
//����һ�������ָ�븳ֵ�������࣬��ͨ�������ָ����з��ʡ�

int add(int a, int b)
{
	return a + b;

}

int add(int a, int b,int c)
{
	return a + b + c;

}

int main5()
{

	cout << add(1, 2) << endl;
	cout << add(1, 2, 3) << endl;
	/*Test T ;
	Base *Bptr = &T;
	cout << T.m_a<< endl;
	T.func();
	cout << Bptr->m_a << endl;
	Bptr->func();*/
	system("pause");
	return 0;
}