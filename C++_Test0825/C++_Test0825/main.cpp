#include<iostream>
using namespace std;//����ʹ�ÿ��ṩ��std���ֿռ��ڵĿ⺯��
//namespace N0
//{
//	namespace N1//���ֿռ�
//	{
//		int add(int a, int b)
//		{
//			cout << "1\n";
//			return a + b;
//		}
//	}
//
//	namespace N2
//	{
//		int add(int a, int b)
//		{
//			cout << "2\n";
//			return a + b;
//		}
//	}
//}
void fun(int a = 0)
{
	cout << a << endl;
}

void fun1(int a = 10,int b=20,int c=  30)
{
	cout << a << endl;
	cout << b << endl; 
	cout << c << endl;
}
void fun2(int a , int b = 20, int c = 30)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
void fun3(int a , int b , int c = 30)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
void fun4(int a , int b , int c )
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
int main()
{
	fun(10);
	fun();
	fun2(200, 300);
	//cout <<N1::add(2, 5);//std��ϵͳ�ṩ�����ֿռ䣬cout�Զ�ʶ�����ʹ�ӡ
	//cout <<N0:: N1::add(2, 5);//���ֿռ��Ƕ��
	system("pause");
    return 0;
}
