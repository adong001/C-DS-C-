#include<iostream>
#include"string.h"
#include<cstdio>
#include<typeinfo>
using namespace std;



int main()
{
	string s1;//���캯����20��
	string s2("wuyifan");
	string s3(s2);
	string s4(5, '6');
	s4 += s3;
	s4 += "hahaha";
	//cout << s1 << endl
	//	 << s2 << endl
	//	 << s3 << endl
	//	 << s4 << endl;
	//cout << s1.size() << endl//�ַ���������size��lengthû������ʵ��Ҳ��ͬ
	//	 << s2.size() << endl
	//	 << s3.size() << endl
	//	 << s4.size() << endl;
	//cout << s1.length() << endl
	//	 << s2.length() << endl
	//	 << s3.length() << endl
	//	 << s4.length() << endl;
	//cout << s1.capacity() << endl//������СΪ16�ı���-1��ֻ������
	//	 << s2.capacity() << endl
	//	 << s3.capacity() << endl
	//	 << s4.capacity() << endl;

	//s1.push_back('1');
	//s1.resize(10,'n');//ȱʡ�ո񣬲�������ȱʡ�Ĳ���
	//cout << s1.size() << endl;
	//s1.push_back('2');
	//cout << s1 << endl;

	//s2.reserve(20);//����������С��16�����ı䣬��������16
	//cout << s2.size() << "  " << s2.capacity() << endl;

	//string::iterator i;//������  
	//for (i = s2.begin(); i != s2.end(); i++)//c++98д��
	//{
	//	cout << *i;
	//}

	//cout << endl;

	//for (auto &j : s2)//c++11д��(�ײ�Ϊ������д��)
	//{
	//	cout << j;
	//}
	s1 += "Hello";
	s1.resize(10);
	s1 += 'a';
	cout << typeid(s1).name() << endl;
	cout << typeid(s1.c_str()).name() << endl;//s1.c_str��s1�����еĳ�Ա�ַ���
	cout << s1 <<endl;//<<�����ش�ӡ����Ϊsize
	cout << s1.c_str() << endl;//������\0��ֹͣ
	//cout << s4.empty() << endl;//�пգ�Ϊ�շ���1�����򷵻�0
	//s4.clear();//���(ֻ������ݣ�����capacity,size = 0)
	//cout << s4.empty() << endl;

	s2.append(10, 'a');//����+10��'a'
	s2.append("hahah");//��+=һ������ʹ��+=
	s2.append("adadaad");
	cout << s2 << endl;
	//s1.getline();
	//s4.resize(100);//��size��ֵ��������capacit�����reserve()
	//cout << s4.size() << endl;
    system("pause");
    return 0;
}