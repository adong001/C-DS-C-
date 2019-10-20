#pragma once
#include<vector>
#include<queue>
#include<stack>
#include"TreeNode.h"
using namespace std;


template<class T>
class Tree
{
private:
	TreeNode<T>* m_root;
	static TreeNode<T>* MakeTree(const T* src, const T& flag, size_t& count)//����һ����
	{
		TreeNode<T>* root;
		if (src[count] == flag)
		{
			count++;     //count����&�󣬺���������count��Ȼ��̳��ϴ��޸ĵ�ֵ
			return nullptr;
		}
		root = new TreeNode<T>(src[count]);
		count++;
		root->m_left = MakeTree(src, flag, count);
		root->m_right = MakeTree(src, flag, count);
		return root;
	}

public:
	Tree() :
		m_root(nullptr)
	{}
	Tree(const T* src, T& flag) //���캯��
	{
		if (!src)
		{
			m_root = nullptr;
		}
		else
		{
			size_t i = 0;
			m_root = MakeTree(src, flag, i);
		}
	}

	TreeNode<T>* ReturnRoot()
	{
		return m_root;
	}
	
	vector<T> PreOrder()//����ǵݹ�
	{
		TreeNode<T>* cur = m_root;
		vector<T> vres;
		stack<TreeNode<T>*> stmp;
		if (!cur)
		{
			return vres;
		}

		while (cur)
		{
			vres.push_back(cur->m_val);//������ֵpush��������

			if (cur->m_right)//�Һ��Ӵ��ڣ��Һ�����ջ���Һ��������ʣ�����ջ��
			{
				stmp.push(cur->m_right);
			}

			if (cur->m_left)//���Ӵ���,������ջ
			{
				stmp.push(cur->m_left);
			}

			if (!stmp.empty())//ջ��Ϊ��ʱ����
			{
				cur = stmp.top();//ȡջ������
				stmp.pop();//ȡ��ջ��pop��ջ��Ԫ��
			}

			else //ջΪ�գ�˵�����Һ��Ӷ�û�У�ֱ�Ӹ����ÿգ��˳�ѭ��
			{
				cur = nullptr;
			}
		}
		return vres;
	}

	vector<T> PreOrder_Recursive(TreeNode<T>* root)//����ݹ��
	{
		static vector<T> res;
		if (root)
		{
			res.push_back(root->m_val);
			PreOrder_Recursive(root->m_left);
			PreOrder_Recursive(root->m_right);
		}
		return res;
	}


	vector<T> InOrder()//�������
	{
		TreeNode<T>* cur = m_root;
		vector<T> vres;
		stack<TreeNode<T>*> stmp;

		if (!cur)
		{
			return vres;
		}
		stmp.push(cur);

		while (cur || !stmp.empty())//����ջ��Ϊ��ʱ����
		{
			for (; cur && cur->m_left; cur = cur->m_left)//�Ȱ����Ӷ���ջ
			{
				stmp.push(cur->m_left);
			}

			if (!stmp.empty())//ջ��Ϊ�գ�ȡջ����push��vres����pop.
			{
				cur = stmp.top();
				vres.push_back(cur->m_val);
				stmp.pop();
			}

			else //��ջΪ�գ�˵�����ĸ��ڵ������ѷ�����ϣ�ֱ�Ӹ�vres push������ֵ�������Һ���
			{
				vres.push_back(cur->m_val);
			}

			cur = cur->m_right;//��������
			if (cur) //�Һ����벻Ϊ�գ��Ȱ��Һ��ӵĸ�push��������
			{
				stmp.push(cur);
			}
		}
		return vres;

	}
	vector<T> InOrder_Recursive(TreeNode<T>* root)//����ݹ��
	{
		static vector<T> vres;
		if (root)
		{
			InOrder_Recursive(root->m_left);
			vres.push_back(root->m_val);
			InOrder_Recursive(root->m_right);
		}
		return vres;
	}

};
