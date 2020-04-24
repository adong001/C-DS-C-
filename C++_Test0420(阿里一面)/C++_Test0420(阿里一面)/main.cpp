#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

// ���ݸ����������ϵ, �滻ԭ�ı���ָ������
// ӳ���ϵ:
// {
// 123321 : _1231_,
// 123    : _1232_,
// 123456 : _1233_
// }
// �������:
// 123aa123321bb123456   --> _1232_aa_1231_bb_1233_
// cc123aa123321bb123456 --> cc_1232_aa_1231_bb_1233_
// cc123aa123321123456   --> cc_1232_aa_1231__1233_
// cc123321aa123123456   --> cc_1231_aa_1232__1233_
// 1. ���ܻ�ͬʱƥ�����ж��ӳ��, ��Ҫ���㷨ȥ��ѡ��
// 2. �滻���γɵ����ı�, ����������滻, �Ϳ��ܻ᲻����Ԥ����
bool Isnum(char ch)
{
	return ('0' <= ch && ch <= '9');
}

bool Ispha(char ch)
{
	return ('a' <= ch && ch <= 'z');
}


std::string replace(std::string const &source, std::unordered_map<std::string, std::string> const &table)
{
	std::unordered_map<std::string, std::string>  t = table;
	std::string dest;
	int len = source.size();
	int pos = 0;
	int end;
	t[source.substr(i, j - i + 1)] = 1;
	for (int i = 0, j = 0; i < len && j <= len;)
	{
		if (Isnum(source[j]))//����
		{
			for (auto & e : table)
			{ 
				string s = source.substr(i, j - i + 1);
				if (e.first == source.substr(i,j - i + 1))
				{
					pos = j + 1;//��¼λ��
					break;
				}
			}
			j++;
		}
		else//��ĸ
		{
			if (j >= len)
			{
				j--;
				for (auto & e : table)
				{

					if (e.first == source.substr(i, pos - i))
					{
						dest += e.second;
						break;
					}
				}
				return dest;
			}
			else if (Ispha(source[j]) && j > 0 && Isnum(source[j - 1]))
			{
				for (auto & e : table)
				{

					if (e.first == source.substr(i, pos - i ))
					{
						dest += e.second;
						break;
					}
				}
			}

			dest += source[j];
			j++;
			i = j;
		}

	}
	return dest;
}
void main()
{
	std::unordered_map<std::string, std::string> table = 
	{
		{ "123321", "_1231_" },
		{ "123", "_1232_" },
		{ "123456", "_1233_" },
	};

	std::cout << replace("123aa123321bb123456", table) << std::endl; // --> _1232_aa_1231_bb_1233_
	std::cout << replace("cc123aa123321bb123456", table) << std::endl; // --> cc_1232_aa_1231_bb_1233_
	std::cout << replace("cc123aa123321123456", table) << std::endl; // --> cc_1232_aa_1231__1233_
	std::cout << replace("cc123321aa123123456", table) << std::endl; // --> cc_1231_aa_1232__1233_
}

