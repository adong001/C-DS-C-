#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*ÿ�������ļ�����һ����������������һ���и�����ʽΪ��a1 / b1 a2 / b2����������������
���Ӻͷ�ĸ����long��Χ��,����и��ţ�������ֻ�����ڷ���ǰ�档��ĸ��֤Ϊ�������֡�

����ÿ��������������4�д�ӡ�ܺ͡����죬�����������ĳ˻����̡�

ÿ�ָ�ʽ���ǡ�number1 operator number2=�������
ע�⣬������������������򵥵���ʽ��ka/b��������k���������֣�a/b����򵥵ķ������֡�
�������Ϊ���������������һ��Բ���š�
��������еķ�ĸ���㣬�������ǡ�Inf��.����֤��������������ڷ�Χ�ڳ���
*/
typedef long long LL;
class RationalNumber
{
private:
	LL m_son;//����
	LL m_mother;//��ĸ
	LL m_inter;//��������
	bool m_zore;//��ĸΪ0����true
	bool m_negative;//Ϊ��������true;
public:
	RationalNumber(LL son, LL mother);//���캯��
};

RationalNumber::RationalNumber(LL son, LL mother)
{
	m_zore = false;
	m_negative = false;
	if (mother == 0)//ֱ�ӷ���
	{
		m_zore = true;
		return;
	}
	if (son < 0)
	{
		m_zore = true;
		if (m_mother < 0)
		{
			m_zore = !m_negative;
		}
	}
	m_inter = son / mother;//��������
	m_son = son % mother;
	m_mother = r

}
int main()
{
	LL n1, d1, n2, d2;
	scanf("%lld/%lld %lld/%lld", &n1, &d1, &n2, &d2);
	RationalNumber rn1(n1, d1), rn2(n2, d2); //����+����ʹ�ú���ʱ�� 
	cout << rn1 << " + " << rn2 << " = " << rn1 + rn2 << '\n';
	cout << rn1 << " - " << rn2 << " = " << rn1 - rn2 << '\n';
	cout << rn1 << " * " << rn2 << " = " << rn1 * rn2 << '\n';
	cout << rn1 << " / " << rn2 << " = " << rn1 / rn2 << '\n';
	return 0;
}