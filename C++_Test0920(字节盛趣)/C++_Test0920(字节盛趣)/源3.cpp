
 struct Interval {
	int start;
	int end;
 };


class Solution
{
private:
	static const int mod;
	int FindPath(vector<vector<bool>> vv, int start, int end)
	{
		static int cnts = 0;
		int sum = 0;
		if (vv[start][end] == true && end == vv.size() - 1)
		{
			return cnts;
		}
		if (vv[start][end] == false)
		{
			return -1;
		}
		return FindPath(vv, )
	}
public:
	/**
	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	* ��Interval���з��ؽ��������start��ʾ��Ч�ֵĸ�����end��ʾȫ����Ч�ֱ�ŵĺͳ���100000007��������
	* @param N int���� �ֵ�����
	* @param M int���� ���ӹ�ϵ������
	* @param conn Interval��vector ȫ�����ӹ�ϵ
	* @return Interval��
	*/

	Interval trim(int N, int M, vector<Interval>& conn)
	{
		Interval ret;
		//������ͨ��ֵtrue
		vector<vector<bool>> grap(N + 2, vector<bool>(N + 2, false));
		for (int i = 0; i < M; i++)
		{
			vv[conn[i].start][conn[i].end] = true;
		}
		for (int i = 1; i <= N; i++)
		{
			int cnts = 0;
			if (vv[0][i] == true)
			{
				cnts += FindPath(vv, i);
			}
		}
		ret.start =
			return ret;
	}
};
int Solution::mod = 100000007;