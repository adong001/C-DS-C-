#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<string>
#include <unordered_map>
using namespace std;

int main1()
{
	unordered_map<string,int> um;
	//��map���������map��������򣬶����ֻ�Ǹ��ݲ���˳����д洢
	//��Ϊmap�ײ�ʵ���Ǻ�����������ɾ��ʱ����е������Ӷ���������һֱ��˳��洢��
	//��unordered_map�ײ�ʵ���ǹ�ϣ
	um.insert(pair<string, int>("AAA", 100));
	um.insert(pair<string, int>("CCC", 300));
	um.insert(pair<string, int>("DDD", 400));
	um.insert(make_pair("FFF", 600));
	um.insert(pair<string, int>("EEE", 500));
	um["BBB"] = 200;
	um["GGG"] = 700;
	for (auto& e : um)
	{
		cout << e.first << " " << e.second << endl;
	}

    system("pause");
    return 0;
}