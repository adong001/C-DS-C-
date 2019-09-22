#include<iostream>
#include<vector>
using namespace std;

//vector������insert��3�֣���erase��2�֣�������

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
	//��pos1λ�ú�pos2λ�õ�pos3��ֵ(ֻ����pos2λ�õ�ֵ������pos3��ֵ������������Ϊpos3-pos2)
	v1.insert(v1.begin() + 1, v1.begin() +0, v1.begin() + 1);
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

	v1.erase(v1.begin() + 1, v1.begin() + 11);
	cout << "v1.size = " << v1.size() << " " << v1.capacity() << endl;
	cout << "v1 = ";
	CoutVector(v1);
}


int main()
{
	test_vector_insert();
	//test_vector_erase();
    system("pause");
    return 0;
}