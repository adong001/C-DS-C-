#pragma once
#include"bigint.h"
//
//#include<boost/multiprecision/cpp_int.hpp>
//#include<boost/multiprecision/miller_rabin.hpp>//���������
#define NUMBER 20
using namespace std;
typedef long DataType;
//typedef boost::multiprecision::int1024_t DataType;
struct Key
{
	DataType _eKey;//������Կ��e
	DataType _dKey;//������Կ, d
	DataType _pKey;//n
};

/*
	1.��������
	2.��n
	3.��f(n)
	4.��e (1< e < f(n), e��f(n)���ɻ��ʣ����ѡ��)
	5.��d (e * d % f(n) = 1)
	(e , n) (d , n)
	*/

class RSA
{
private:
	Key m_key;
public:
	DataType ecrept(DataType data, DataType ekey, DataType pkey);//���ܺ���
	DataType decrept(DataType data, DataType dkey, DataType pkey);//���ܺ���
	DataType getPrime();//��ȡ����
	bool IsPrime(DataType data);//�ж��Ƿ�Ϊ����
	DataType getPKey(DataType prime1, DataType prime2);//��ȡ��Կ
	DataType getOrla(DataType prime1, DataType prime2);//ŷ������
	DataType getEKey(DataType orla);//��ȡ��Կe
	DataType getDKey(DataType ekey, DataType orla);
	DataType getGcd(DataType data1, DataType data2);//��ȡ�����������Լ��
	void getKeys();
	Key getallKey();

	void ecrept(const char* filename, const char* fileout);//�ļ�����
	void dcrept(const char* filename, const char* fileout);//�ļ�����

};