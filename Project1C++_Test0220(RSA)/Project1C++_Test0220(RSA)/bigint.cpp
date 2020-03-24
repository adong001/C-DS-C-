//#include"bigint.h"
//#include"rsa.h"
//BigInt::BigInt()
//{
//	RSA rsa;
//	rsa.getKeys();
//	Key key = rsa.getallKey();
//}
//
//BigInt::BigInt(const string& num) //���캯��
//{
//	m_number = num;
//}
//
//
//BigInt::BigInt(const int num)//���캯��
//{
//	int tmp = num;
//	while (tmp)
//	{
//		m_number.insert(0, 1, tmp % 10 + '0');
//		tmp /= 10;
//	}
//}
//
//bool BigInt::less( string& num1,  string& num2)//num1<num2������
//{
//	if (num1.size() > num2.size())
//	{
//		return false;
//	}
//	else if (num1.size() < num2.size())
//	{
//		return true;
//	}
//	else
//	{
//		return num1 < num2;
//	}
//}
//
//
////RSA�㷨�����ݶ��Ǵ�����������������ﲻ�ÿ��Ǹ�����0
//string BigInt::add(string num1, string num2)
//{
//	int len1 = num1.size();
//	int len2 = num2.size();
//	string ret;
//
//	if (less(num1, num2))//��num1���ϴ����
//	{
//		swap(num1, num2);
//		swap(len1, len2);
//	}
//
//	ret.resize(len1);
//	int step = 0;//��λ
//	int i, j, tmp;
//
//	for (i = len1 - 1, j = len2 - 1; i >= 0; --i)//�Ӻ���ǰ��
//	{
//		if (j >= 0)//��С������δ����
//		{
//			tmp = num1[i] + num2[j] + step - 2 * '0';
//			--j;
//		}
//		else//��С�������꣬�ϴ�����ͽ�λ��
//		{
//			tmp = num1[i] + step - '0';
//		}
//
//		ret[i] = tmp % 10 + '0';//����ĸ�λ����ret����
//		step = tmp / 10;//��λ
//	}
//	if (step == 1)
//	{
//		ret.insert(0, 1, '1');//�����λ���Ͻ�λ��ֻ�ܽ�1
//	}
//	return ret;
//
//}
//
////RSA�㷨�Ĳ����õ�����������ֻ��Ϊ��д������ֻ���Ǵ�����������С��������������0�������������
//string BigInt::sub(string num1, string num2)
//{
//	string ret;
//	int len1 = num1.size();
//	int len2 = num2.size();
//
//	ret.resize(len1);
//	int step = 0;//��λ
//	int i, j, tmp;
//
//	for (i = len1 - 1, j = len2 - 1; i >= 0; --i)
//	{
//		tmp = 0;
//		if (j >= 0)//��С������δ����
//		{
//			if (num1[i] < num2[j])//��Ҫ��λ
//			{
//				tmp = 10;//����һλ��һλ���൱��+10
//				num1[i - 1]--;//���Ͻ�λ��һλ-1
//			}
//			ret[i] = num1[i] + tmp - num2[j] + '0';
//			--j;
//		}
//
//		else
//		{
//			if (num1[i] < '0')//��һλ����һλ�����С��0������ǰһλ��
//			{
//				ret[i] = num1[i] + 10;
//				--num1[i - 1];
//			}
//			else
//			{
//				ret[i] = num1[i];//��λ����0���ͱ���
//			}
//		}
//
//	}
//	//ɾ��ǰ��0,����0008---��8
//	while (ret.size() > 1 && ret[0] == '0')
//	{
//		ret.erase(0, 1);//����ɾ��ͷ����0
//	}
//	return ret;
//}
//
//
////ͬ�����˷�ֻ���Ǵ�������*��������
//string BigInt::mul(string num1, string num2)
//{
//	
//	int len1 = num1.size();
//	int len2 = num2.size();
//	if (less(num1, num2))//��num1���ϴ����
//	{
//		swap(num1, num2);
//		swap(len1, len2);
//	}
//    string ret = "0";
//	for (int i = len2 - 1; i >= 0; --i)
//	{
//		int digit = num2[i] - '0';//��õ�ǰ������Ӧλ��ֵ
//		int step = 0;//��λ
//
//		string tmp = num1;//��ǰ�˻����
//		for (int j = len1 - 1; j >= 0; --j)
//		{
//			tmp[j] = (tmp[j] - '0') * digit + step;//����ֵ
//
//			if (tmp[j] > 9)
//			{
//				step = tmp[j] / 10;
//				tmp[j] %= 10;
//			}
//
//			else//û�н�λ
//			{
//				step = 0;
//			}
//			tmp[j] += '0';//��ԭ���ַ�
//
//		}
//		if (step > 0)//�ж������һλ�Ƿ�Ҫ��λ
//		{
//			tmp.insert(0, 1, step + '0');
//		}
//		tmp.append(len2 - 1 - i, '0');//num2��λ��num1 tmp���治��0��ʮλ��˼�һ��0���Դ�����
//
//		//�����ۼ�һ�γ˷��Ľ��
//		ret = add(ret, tmp);
//	}
//	return ret;
//}
//
//
//
//pair<string, string> BigInt::div(string num1, string num2)//���������̺�����
//{
//	//��������ʵ��-->105/2 = 105-20-20-20-20-20  ��=���Ĵ���������=���ܼ�����
//
//	int len1 = num1.size();
//	int len2 = num2.size();
//	if (less(num1, num2))//�������ֻ��������ȡ����, num1 % num2 = num2 % num1,Ϊ�˷�����㣬���ô��С
//	{
//		swap(num1, num2);
//		swap(len1, len2);
//	}
//	string ret;//��
//	string rem = num1;//����
//
//	int diffNum = num1.size() - num2.size();//���������зŴ󣬰���10�ı����Ŵ�
//	num2.append(diffNum, '0');
//	for (int i = 0; i <= diffNum; ++i)
//	{
//		//��¼����ִ�еĴ���
//		char count = '0';
//		while (true)
//		{
//			if (less(rem, num2))//����С�ڳ���
//			{  
//				break;
//			}
//			rem = sub(rem, num2);//�������ϼ�ȥ���������Ĵ���count������
//			++count;
//		}
//		ret += count;
//		//������С10��
//		num2.pop_back();
//	}
//
//	//ɾ��ǰ�õ�0
//	while (ret.size() > 1 && ret[0] == '0')
//	{
//		ret.erase(0, 1);
//	}
//
//	return make_pair(ret, rem);
//}
//
//
//BigInt BigInt::operator+(BigInt& bi)
//{
//	string ret = add(m_number, bi.m_number);
//	return BigInt(ret);
//}
//
//BigInt BigInt::operator-(BigInt& bi)
//{
//	string ret = sub(m_number, bi.m_number);
//	return BigInt(ret);
//}
//
//BigInt BigInt::operator*(BigInt& bi)
//{
//	string ret = mul(m_number, bi.m_number);
//	return BigInt(ret);
//}
//
//BigInt BigInt::operator/(BigInt& bi)
//{
//	string ret = div(m_number, bi.m_number).first;
//	return BigInt(ret);
//}
//
//BigInt BigInt::operator%(BigInt& bi)
//{
//	string ret = div(m_number, bi.m_number).second;
//	return BigInt(ret);
//}
//
//
//ostream& operator<<(ostream& os, BigInt& bi)
//{
//	os << bi.m_number;
//	return os;
//}
//istream& operator>>(istream& is, BigInt& bi)
//{
//	is >> bi.m_number;
//	return is;
//}
//
//
//
