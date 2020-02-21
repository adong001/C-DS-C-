#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<ctime>
#include<algorithm>
#include<string>
#include<fstream>
#include<cmath>
#include<utility>
using namespace std;
class BigInt
{
private:
	string m_number;
public:
	//ͨ���ַ�����ʾ����
	string add(string num1, string num2);
	string sub(string num1, string num2);
	string mul(string num1, string num2);
	pair<string,string> div(string num1, string num2);//���������̺�����


	BigInt(){}
	BigInt(const string& num);
	BigInt(const int num);
};