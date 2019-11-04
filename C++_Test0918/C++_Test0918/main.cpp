#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
void CoutVector(vector<int>& v)
{
	for (auto i = v.begin(); i != v.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
void test_vector_insert()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	cout << "v1 = ";
	CoutVector(v1);
	// ����1: 
	//iterator insert(iterator pos1,const value_type& val)
	//��pos1λ�ò���val,value_typeΪһ��ģ�壬����ֻ��Ϊvector���������
	v1.insert(v1.begin() + 1, 40);
	cout << "v1 = ";
	CoutVector(v1);

	// ����2:
	//iterator insert(iterator pos1,size_t num,const value_type& val)
	//��pos1λ�ò���num��val,value_typeΪһ��ģ�壬����ֻ��Ϊvector���������
	v1.insert(v1.begin() + 2, 4, 50);
	cout << "v1 = ";
	CoutVector(v1);

	// ����3:
	//iterator insert(iterator pos1,iterator pos2,iterator pos3)
	//��pos1��pos2λ�÷ֱ����pos3��ֵ
	v1.insert(v1.begin() + 1, v1.begin() + 2, v1.begin() + 4);
	cout << "v1 = ";
	CoutVector(v1);
}
void test_vector_erase()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	v1.push_back(70);
	v1.push_back(80);
	v1.push_back(50);
	v1.push_back(60);
	v1.push_back(70);
	v1.push_back(80);
	cout << "v1.size = " << v1.size() << " " << v1.capacity() << endl;
	cout << "v1 = ";
	CoutVector(v1);

	//����1��
	//iterator erase(const_iterator pos);
	//ɾ��posλ�õ�Ԫ��
	v1.erase(v1.begin());
	cout << "v1.size = " << v1.size() << " " << v1.capacity() << endl;
	cout << "v1 = ";
	CoutVector(v1);

	//����2��
	//iterator erase(const_iterator first, const_iterator last);
	//ɾ��first��lastλ�õ�Ԫ��
	//ע�⣺1.ɾ��ʱ������firstλ�� ��������lastλ�á�
	//      2.��firstԽ��(����ǰԽ���Ǻ�Խ���ᱨ��)  
	//      3.��lastԽ��(����ǰԽ���Ǻ�Խ���ᱨ��)last��v1.begin()+size+1���Ż�Խ��

	v1.erase(v1.begin() +1, v1.begin() +11);
	cout << "v1.size = " << v1.size() << " " << v1.capacity() << endl;
	cout << "v1 = ";
	CoutVector(v1);
}


int main()
{

	//test_vector_insert();
	test_vector_erase();
	//vector<int>v1;
	//cout << v1.size()<<endl;
	//vector<int>v2;
	////cout << v2.size() << endl;
	//for (int i = 0; i < 30; i++)
	//{
	//	v2.push_back(i);
	//	cout << "capacity=" << v2.capacity() << endl;//capacity������1����ÿ����1.5��(vs)/2��(gcc)
	//}
	//for (auto i = v2.begin(); i != v2.end(); i++)
	//{
	//	cout << *i<<" ";
	//}
	//cout << endl;
	//for (auto i = v2.rbegin(); i != v2.rend(); i++)
	//{
	//	cout << *i << " ";
	//}

	//v2.insert()
	//	iterator insert(iterator position, const value_type& val);//��position֮ǰ����val

	//iterator erase(iterator position);//ɾ��positionλ�õ�����
	//insert();//����
	//erase()//����
	system("pause");
	return 0;
}


int main1()
{
	char *p1;
	p1 = (char *)malloc(10);
	strcpy(p1, "hello");
	free(p1);
	printf("%s\n", p1);
	/*for (int i = 0; i < 10; i++)
	{
	printf("%d ", *(p2 + i));
	}*/
	//*(p1 + 99) = 1234;
	//printf("%d\n", *(p1 + 99));
	//p1 = (int *)realloc(p1, sizeof(int)* 10);
	//*(p1 + 9) = 1234;
	//printf("%d\n", *(p1 + 9));
	//p1 = (int *)realloc(p1, sizeof(int)* 1000);
	//*(p1 + 999) = 1234;
	//printf("%d\n", *(p1 + 999));
	//free(p1);
	//p2 = (int *)calloc(10, sizeof(int));
	//free(p2);
	/*for (int i = 0; i < 10; i++)
	{
	*(p1 + i) = i;
	}

	for (int i = 0; i < 10; i++)
	{
	printf("%d ",*(p1+i));
	}*/

	//free(p1);
	system("pause");
	return 0;
}