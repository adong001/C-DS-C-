#pragma once
#include<vector>
#include<queue>
#include<stack>
#include"TreeNode.h"

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

	int PreOrder()//����ǵݹ�
	{
		TreeNode<T>* cur = m_root;s
		vector<T> vres;
		stack<TreeNode<T>*> stmp;
		if (!cur)
		{
			return vres;
		}

		while (cur)
		{
			vres.push_back(cur->val);//������ֵpush��������

			if (cur->right)//�Һ��Ӵ��ڣ��Һ�����ջ���Һ��������ʣ�����ջ��
			{
				stmp.push(cur->right);
			}

			if (cur->left)//���Ӵ���,������ջ
			{
				stmp.push(cur->left);
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

	//vector<T> PreOrder_Recursive()//����ݹ��
	//{
	//	static vector<T> res;
	//	if (m_root)
	//	{
	//		res.push_back(m_root->val);
	//		PreOrder_Recursive(m_root->left);
	//		PreOrder_Recursive(m_root->right);
	//	}
	//	return res;
	//}


	//vector<T> InOrder()//�������
	//{
	//	TreeNode<T>* cur = m_root;
	//	vector<T> vres;
	//	stack<TreeNode<T>*> stmp;

	//	if (!cur)
	//	{
	//		return vres;
	//	}
	//	stmp.push(cur);

	//	while (cur || !stmp.empty())//����ջ��Ϊ��ʱ����
	//	{
	//		for (; cur && cur->left; cur = cur->left)//�Ȱ����Ӷ���ջ
	//		{
	//			stmp.push(cur->left);
	//		}

	//		if (!stmp.empty())//ջ��Ϊ�գ�ȡջ����push��vres����pop.
	//		{
	//			cur = stmp.top();
	//			vres.push_back(cur->val);
	//			stmp.pop();
	//		}

	//		else //��ջΪ�գ�˵�����ĸ��ڵ������ѷ�����ϣ�ֱ�Ӹ�vres push������ֵ�������Һ���
	//		{
	//			vres.push_back(cur->val);
	//		}

	//		cur = cur->right;//��������
	//		if (cur) //�Һ����벻Ϊ�գ��Ȱ��Һ��ӵĸ�push��������
	//		{
	//			stmp.push(cur);
	//		}
	//	}
	//	return vres;

	//}
	//vector<T> InOrder_Recursive()//����ݹ��
	//{
	//	static vector<T> vres;
	//	if (root)
	//	{
	//		InOrder_Recursive(m_root->left);
	//		vres.push_back(m_root->val);
	//		InOrder_Recursive(m_root->right);
	//	}
	//	return vres;
	//}

};
