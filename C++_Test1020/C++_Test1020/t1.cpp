//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
////ģ���ػ�
//
////int tmp = 10;
//template<class T1,class T2>
//class Test
//{
//private:
//	T1 m_a;
//	T2 m_b;
//public:
//	Test()
//	{
//		cout << "T1 T2" << endl;
//	}
//};
////1.ȫ�ػ�
//template<>
//class Test<char,int>
//{
//private:
//	char m_a;
//	int m_b;
//public:
//	Test()
//	{
//		cout << "char int" << endl;
//	}
//};
////2.ƫ�ػ�
//template<class T1>
//class Test<T1, int>
//{
//private:
//	T1 m_a;
//	int m_b;
//public:
//	Test()
//	{
//		cout << "T1 int" << endl;
//	}
//};
//
//
//template<class T1,class T2>
//void Fun(T1 a,T2 b)//ģ�庯��
//{
//	cout << "ģ�庯��" <<endl;
//}
//
//template<>//ģ�庯����ȫ�ػ�
//void Fun(char a, int b)
//{
//	cout << "ȫ�ػ�" << endl;
//}
//
//template<class T1>//ģ�庯����ƫ�ػ�
//void Fun(T1 a, float b)
//{
//	cout << "ƫ�ػ�" << endl;
//}
//
//
//void Fun(char a, float b)//ģ�庯���ĺ�������1
//{
//	cout << "��������1" << endl;
//}
//
//void Fun(char a, int b)//ģ�庯���ĺ�������2
//{
//	cout << "��������2" << endl;
//}
//
//
//int main2()
//{
//	/*Test<double,float> t1;
//	Test<char, int> t2;
//	Test<double, int> t3;*/
//	char char_tmp = 0;
//	int int_tmp = 0;
//	float float_tmp = 0;
//
//	Fun(float_tmp, int_tmp);
//	Fun(char_tmp, int_tmp);
//	Fun(int_tmp, float_tmp);
//	Fun(char_tmp, float_tmp);
//	Fun(char_tmp, int_tmp);
//
//
//    system("pause");
//    return 0;
//}