#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
//void bibble_sort(int arr[], int n)
//{
//	int tmp = 0;
//	//int flag = 1;
//	for (int i = 0; i < n-1; i++)
//	{
//		for (int j = 0; j <= n-i-1; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//			/*	flag = 0;*/
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//		//if (flag == 1)
//		//{
//		//	break;
//		//}
//	}
//}

//void  print(int arr[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//
//	int ar[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	print(ar, 10);
//	bibble_sort(ar, 10);
//	print(ar, 10);
//	system("pause");
//	return 0;
//}

//
//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
//
//
//void mult_print(int n)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%3d  ", i, j, i*j);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int n = 0;
//	printf("������Ҫ��ӡ�ĳ˷���������");
//	scanf("%d", &n);
//	mult_print(n);
//	system("pause");
//	return 0;
//}
//
//
//
//2.ʹ�ú���ʵ���������Ľ�����
//
//void Swap(int *px, int *py)
//{
//	int tmp = 0;
//	tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
//int main()
//{
//	int x = 10;
//	int y = 20;
//	printf("x=%d y=%d\n", x, y);
//	Swap(&x, &y);
//	printf("x=%d y=%d\n", x, y);
//	system("pause");
//	return 0;
//}
//
//3.ʵ��һ�������ж�year�ǲ������ꡣ
//
//int Is_prime(int year)
//{
//	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
//}
//
//int main()
//{
//	int year = 0;
//	while (1)
//	{
//	 printf("������Ҫ�жϵ���ݣ�");
//	 scanf("%d", &year);
//	 if (Is_prime(year) == 1)
//	 {
//		 printf("������\n\n");
//	 }
//	 else
//	 {
//		 printf("��������\n\n");
//	 }
//	
//	}
//	system("pause");
//	return 0;
//}
//
//4.
//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��
//
//
//void init(int ar[],int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		ar[i] = 0;
//	}
//}
//
//void empty(int ar[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		ar[i] = 0;
//	}
//}
//void reverse(int ar[], int n)
//{
//	for (int i = 0; i <= n / 2; i++)
//	{
//		int tmp = 0;
//		tmp = ar[i];
//		ar[i] = ar[n - i - 1];
//		ar[n - i - 1] = tmp;
//	}
//}
//
//void print(int ar[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", ar[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int ar[10]= { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int n = sizeof(ar) / sizeof(ar[0]);
//	print(ar, n);
//	reverse(ar, n);
//	print(ar, n);
//	empty(ar, n);
//	print(ar, n);
//	system("pause");
//	return 0;
//}
//
//
//5.ʵ��һ���������ж�һ�����ǲ���������
//
//int Is_prime(int n)
//{
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n%i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int n = 0;
//	while (1)
//	{
//		printf("��������Ҫ�жϵ�����");
//		scanf("%d", &n);
//		if (Is_prime(n) == 1)
//		{
//			printf("������\n\n");
//		}
//		else
//		{
//			printf("��������\n\n");
//		}
//
//	}
//	system("pause");
//	return 0;
//}



//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������

//int fib(int n)             //�ݹ飬�Ӻ���ǰ���㣬ÿ�μ��㶼Ҫ��ǰ����������
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//	  return fib(n - 1) + fib(n - 2);
//	}
//}

//int fib(int n)               //�ǵݹ飬��ǰ�����㣬�ڴ����бȵݹ��
//{
//	int ret = 0;
//	int num1 = 1;
//	int num2 = 2;
//	if (n <= 2)
//	{
//		return num1;
//	}
//	else
//	{
//		while (n > 2)
//		{
//			ret = num1 + num2;
//			num1 = num2;
//			num2 = ret;
//			n--;
//		}
//		return ret;
//	}
//}
//int main()
//{
//	int n = 0;
//	while (1)
//	{
//		scanf("%d", &n);
//		printf("%d\n\n",fib(n));
//	}
//	system("pause");
//	return 0;
//}
//
//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
//

//int fuc(int n,int k)
//{
//	if (k < -1)
//	{
//		return (1 / (fuc(n, -k)));
//	}
//	else if (k == 0)
//	{
//		return 1;
//	}
//	else if (k == 1)
//	{
//		return n;
//	}
//	else
//	{
//		
//			return  n*fuc(n, k - 1);
//		
//	}
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	while (1)
//	{
//		scanf("%d%d", &n, &k);
//		printf("sum=%d", fuc(n, k));
//	}
//	system("pause");
//	return 0;
//}

//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
//
//int DigitSum(unsigned int n)
//{
//	if (n > 9)
//	{
//		return ((n % 10) + DigitSum(n / 10));
//	}
//	else
//	{
//		return n;
//	}
//}
//int main()
//{
//	int n = 0;
//	while (1)
//	{
//		printf("������:");
//		scanf("%d", &n);
//		printf("Sum=%d\n\n",DigitSum(n));
//		system("pause");
//		return 0;
//	}
//}

//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�   **********
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������


//void reverse_string(char * string)  //�ݹ�
//{
//
//	if (*(++string)!= '\0')
//	{
//		reverse_string(string);
//	}
//	printf("%c",*(string-1));
//}
//char * reverse_string(char * string)   //�ǵݹ�
//{
//	char * ptr = string;
//	char str = NULL;
//	int count = 0;
//	while ((*ptr++)!='\0')
//	{
//		count++;
//	}
//	for (int i = 0; i <= count / 2; i++)
//	{
//		str = string[i];
//		string[i] = string[count - i - 1];
//		string[count - i - 1] = str;
//	}
//	return string;
//}

//int main()
//{
//	char string[] = "abcdef";
//    reverse_string(string);
//	system("pause");
//	return 0;
//}


//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen

//int my_strlen(char * string)          //�ݹ�
//{
//	while (*string != '\0')
//	{
//		return (1 + my_strlen(string + 1));
//	}
//	return 0;
//}

//int my_strlen(char * string)             //�ǵݹ�
//{
//	int count = 0;
//	while (*string++!= '\0')
//	{
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	char * str = "abcdef";
//	printf("%d\n", my_strlen(str));
//	system("pause");
//	return 0;
//}


//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�

 
//int fuc (int n)                      �ݹ�
//{
//	if (n == 0)
//	{
//		return 1;
//	}
//	else if (n < 0)
//	{
//	  return n*fuc(n + 1);
//	}
//	else
//	{
//	return n*fuc(n - 1);
//	}
//}
 
//int fuc(int n)           // �ǵݹ�
//{
//	int sum = 1;
//	if (n == 0)
//	{
//		return 1;
//	}
//	else if (n < 0)
//	{
//		while ( n < 0)
//		{
//			sum *= n;
//			n++;
//		}
//		return sum;
//		}
//	else
//	{
//	while (n>0)
//	   {
//		sum *= n;
//		n--;
//		}
//		return sum;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	while (1)
//	{
//		scanf("%d", &n);
//		printf("sum=%d\n", fuc(n));
//	}
//}

//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ

//int  fuc_print(int n)
//{
//	while (n > 9)
//	{
//	 printf("%d ",fuc_print(n / 10));
//	 return n % 10;
//    }   
//	return n;
//}
//int main()
//{
//	int n = 0;
//	while (1)
//	{
//		scanf("%d", &n);
//		printf("%d\n", fuc_print(n));
//	}
//	system("pause");
//	return 0;
//}