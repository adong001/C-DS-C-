#include<vector>
class Solution {

private:
	//��ת90��
	vector<string> rotate(vector<string>& s)
	{
		int n = s.size();
		vector<string> ret(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ret[i] += s[n - j - 1][i];
			}
		}
		return ret;
	}

	string decip(vector<string>& s1, vector<string>& s2)
	{
		int n = s1.size();
		string ret;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (s1[i][j] == '0')
				{
					ret += s2[i][j];
				}
			}
		}
		return ret;
	}
public:
	/**
	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	* ����һ���ַ�������ʾԭ�ġ�
	* @param s1 string�ַ���vector N*N��01���󣬱�ʾ����ֽ��0��ʾ͸����1��ʾͿ��
	* @param s2 string�ַ���vector �ַ����󣬱�ʾ����
	* @return string�ַ��� */
	string rotatePassword(vector<string>& s1, vector<string>& s2)
	{
		string ret;
		for (int i = 0; i < 4; i++)
		{
			ret += decip(s1, s2);
			s1 = rotate(s1);
		}
		return ret;
	}
};