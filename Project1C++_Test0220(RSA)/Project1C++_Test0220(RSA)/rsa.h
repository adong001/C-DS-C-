#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<ctime>
#include<fstream>
#include<cmath>
#define NUMBER 256
using namespace std;
typedef long DataType;
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
	DataType getPKey(DataType prime1,DataType prime2);//��ȡ��Կ
	DataType getOrla(DataType prime1, DataType prime2);//ŷ������
	DataType getEKey(DataType orla);//��ȡ��Կe
	DataType getDKey(DataType ekey, DataType orla);
	DataType getGcd(DataType data1, DataType data2);//��ȡ�����������Լ��
	void getKeys();
	Key getallKey();


	void ecrept(const char* filename, const char* fileout)//�ļ�����
	{
		ifstream fin(filename, ifstream::binary);
		ofstream fout(fileout, ifstream::binary);
		if (!fin.is_open())
		{
			perror("input file open failed\n");
			return;
		}
		char* buffer = new char[NUMBER];
		DataType* bufferout = new DataType[NUMBER];
		while (!fin.eof())
		{
			fin.read(buffer, NUMBER);
			int curNum = fin.gcount();//�����������ֽ���
			for (int i = 0; i < curNum; i++)
			{
				ecrept((DataType)buffer[i],m_key._eKey, m_key._pKey);//��DataTypeΪ��λ���м���
			}
			fout.write((char*)bufferout, curNum * sizeof(DataType));//���ܺ�д�뵽fout��
		}
		fin.close();
		fout.close();
	}
	void dcrept(const char* filename, const char* fileout)//�ļ�����
	{

		ifstream fin(filename, ifstream::binary);
		ofstream fout(fileout, ifstream::binary);
		if (!fin.is_open())
		{
			perror("input file open failed\n");
			return;
		}
		char* bufferout = new char[NUMBER];
		DataType* buffer = new DataType[NUMBER];
		while (!fin.eof())
		{
			fin.read((char*)buffer, NUMBER*sizeof(DataType));
			int curNum = fin.gcount();//�����������ֽ���
			curNum /= sizeof(DataType);
			for (int i = 0; i < curNum; i++)
			{
				bufferout[i] = decrept((buffer[i], m_key._eKey, m_key._pKey);//��DataTypeΪ��λ���м���
			}
			fout.write(bufferout, curNum);//���ܺ�д�뵽fout��
		}
		fin.close();
		fout.close();
	}
};