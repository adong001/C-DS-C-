#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//class Base
//{
//public:
//	int m_a;
//	Base(int a = 0) :
//		m_a(a)
//	{}
//};
//
//class Test:public Base
//{
//public:
//	int m_b;
//	Test(int a = 0,int b = 0 ) :
//		Base(a),
//		m_b(b)
//	{}
//};
//
//void func1()
//{
//	int a = 10;
//	int b = 20;
//	if (a < b)
//	{
//		throw "�׳��쳣a>b";
//	}
//}
//
//
//void func2()
//{
//	func1();
//}
//
//int main()
//{
//	try
//	{
//		func2();
//
//	}
//	catch (char& a)
//	{
//		cout << a<<endl;
//	}
//	catch (const char* a)
//	{
//		cout << a << endl;
//	}
//	catch (...)
//	{
//		cout << "δ����" << endl;
//	}
//    system("pause");
//    return 0;
//}




int main()
{
	try{
		vector<int> v(10, 5);  // �������ϵͳ�ڴ治��Ҳ�����쳣    
		v.reserve(1000000000);// ����Խ������쳣       
		v.at(10) = 100;
	}
	catch (const exception& e) // ���ﲶ�������Ϳ���   
	{
		cout << e.what() << endl;
	}

	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}

	return 0;
}