#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//��Ŀ��A, B, C�������Ǻ�����, ÿ�������ﶼ��һЩ�ǹ�, ���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�, 
//��������֪�����µ���Ϣ��A - B, B - C, A + B, B + C.���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.
//������Ҫͨ�����ĸ���ֵ�����ÿ���������ж��ٸ��ǹ�, ��A, B, C�����ﱣ֤���ֻ��һ������A, B, C������������������

//void FindCandy()
//{
//	int A, B, C;
//	vector<int> v;
//	int n;
//	while (cin >> n)
//		v.push_back(n);
//	A = (v[0] + v[2]) / 2;
//	B = (v[1] + v[3]) / 2;
//	C = v[3] - B;
//	if ((A - B == v[0]) && (B - C == v[1]) && (A + B == v[2]) && (B + C == v[3])){
//		cout << A << " " << B << " " << C << endl;
//	}
//	else{
//		cout << "No" << endl;
//	}
//}
void FindCandy()
{
	int A_B, B_C, AB, BC;
	int A, B, C;
	cin >> A_B >> B_C >> AB >> BC;
	if (A_B<-30 || A_B>30 || B_C<-30 || B_C>30 ||
		AB<-30 || AB>30 || BC<-30 || BC>30 ||
		A_B > AB || B_C > BC)
	{
		cout << "NO" << endl;
		return;
	}
	A = (A_B + AB) / 2;
	B = (B_C + BC) / 2;
	C = BC - B;
	if (((A - B) == A_B) && ((B - C) == B_C) && ((A + B) == AB) && ((B + C) == BC))
	{
		cout << A << " " << B << " " << C << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

}

int main1()
{
	FindCandy();
	system("pause");
	return 0;
}