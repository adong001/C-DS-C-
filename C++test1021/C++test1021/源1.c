//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<math.h>
//float k1, k2, k3;
//#define f(t) (k1*t*t+k2*t+k3)
//
//void RetreatMethod(float X1, float H, float n[])
//{
//	float f1, f2, f3;
//	float x1, x2, x3;
//	float h, temp;
//	//��ֵ����
//	h = 0.1;
//	x1 = X1;
//	f1 = f(x1);
//	x2 = x1 + h;
//	f2 = f(x2);
//	printf("***���˷�ȷ����Сֵ����***\r\n��ֵx1=%f ����=%f\r\n\r\n", x1, h);
//	if (f1 < f2)	//�ж���������
//	{
//		//��ʼ������󣬷�������
//		h = -h;
//		//����x1��x2
//		temp = x2;
//		x2 = x1;
//		x1 = temp;
//		//����f1��f2
//		temp = f2;
//		f2 = f1;
//		f1 = temp;
//		//����x3��f3
//		x3 = x2 + h;
//		f3 = f(x3);
//	}
//	else
//	{		//��ʼ������ȷ����������
//		//���󲽷�������x3,f3
//		h = 2 * h;
//		x3 = x2 + h;
//		f3 = f(x3);
//	}
//
//	//ѭ������Ƚ�f2��f3��ֱ�����㡰��-��-�ߡ�����
//	while (!(f2 < f3))
//	{
//		x1 = x2;
//		x2 = x3;
//		f2 = f3;
//		x3 = x2 + h;
//		f3 = f(x3);
//
//	}
//	//�����Сֵ����
//	if (x1 < x3)
//	{
//
//		n[0] = x1;
//		n[1] = x3;
//
//	}
//	else
//	{
//
//		n[1] = x1;
//		n[0] = x3;
//
//	}
//
//
//}
//
//
//int main()
//{
//	double g, g1, g2, x, e, u, a, b;
//	float a1, b1;
//	float n[2];
//	printf("�����������ϵ��k1=");
//	scanf("%lf", &k1);
//	printf("������һ����ϵ��k2=");
//	scanf("%lf", &k2);
//	printf("�����볣����k3=");
//	scanf("%lf", &k3);
//	printf("��������������e=");
//	scanf("%lf", &e);
//	u = 0.618;
//	RetreatMethod(0, 0.1, n);
//	a = n[0];
//	b = n[1];
//	do
//	{
//		a1 = b - u*(b - a);
//		g1 = f(a1);
//		b1 = a + u*(b - a);
//		g2 = f(b1);
//		if (g1<g2)
//		{
//			b = b1;
//		}
//		else
//		{
//			a = a1;
//		}
//
//	} while (b - a >= e);
//	x = 0.5*(a + b);
//	g = k1*x*x + k2*x + k3;
//	printf("\n�ƽ�ָ��������[a,b]:");
//	printf("\na=%lf,b=%lf", a, b);
//	printf("\n��Ѳ�������ֵx�����Ӧ�ĺ���ֵg:");
//	printf("\nx=%lf,g=%lf", x, g);
//	return 0;
//}
//
