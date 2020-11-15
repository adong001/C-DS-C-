/**
* struct Interval {
*	int start;
*	int end;
* };
*/

class Solution
{
private:
	//���г��������
	vector<string> dp(int n, int k, string str2, int cnts)
	{
		vector<string> ret;
		if (cnts <= 0)
		{
			return ret;
		}
		char ch = 'x';
		if (int i = 0; i <= n - k; i++)
		{
			string tmp = str2;
			cnts--;
			dp(, )

		}
		return ret;
	}
public:
	/**
	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	* ����Interval�࣬start�����������������˶��ٵ��⣬end����������������˶��ٵ��⡣
	* @param n int���� ѡ��������
	* @param k int���� �������Ե�����
	* @param str1 string�ַ��� ����Ϊnֻ����ABCD���ַ��������е�i���������е�i��������ѡ��
	* @param str2 string�ַ��� ����Ϊnֻ����ABCD���ַ��������е�i���������ѵ�i��������ѡ��
	* @return Interval��
	*/
	Interval solve(int n, int k, string str1, string str2)
	{
		solve ret;
		int Max = -1;
		int Min = n + 1;
		vector<string> vs = dp(str2);
		for (int i = 0; i < vs.size(); i++)
		{
			int cnts = 0;
			for (int j = 0; j < n; j++)
			{
				if (str1[j] == vs[i][j])
				{
					cnts++;
				}
			}
			Min = Min > cnts ? cnts : Min;
			Max = Max < cnts ? cnts : Max;
		}
		ret.start = Min;
		ret.end = Max;
		return ret;
	}
};