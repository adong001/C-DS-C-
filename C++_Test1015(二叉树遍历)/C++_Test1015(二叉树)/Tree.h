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
	TreeNode<T>* MakeTree(TreeNode<T>* root, T* src, T& flag, size_t count)//����һ����
	{
		TreeNode<T>* cur = root;

		if (src[count] == flag)
		{
			return nullptr;
		}
		root = new TreeNode<T>;
		root->m_val = src[count];
		count++;
		root->m_left = MakeTree(root->m_left, src, flag, count);
		cout++;
		root->m_right = MakeTree(root->m_right, src, flag, count);
		return cur;
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
			m_root = MakeTree(m_root, src, flag, 0);
		}
	}

	vector<T> PreOrder()//����ǵݹ�
	{
		TreeNode* cur = m_root;
		vector<T> vres;
		stack<TreeNode<T>*> stmp;
		if (!cur)
		{
			return vres;
		}

		stmp.push(cur);//�Ѹ���ѹ��ȥ

		do{
			vres.push_back(cur->val);

			if (cur->right)//�Һ��Ӵ��ڣ��Һ�����ջ
			{
				stmp.push(cur->right);
			}

			if (cur->left)//���Ӵ��ڣ����ӵ�ֵpush��������,������ջ
			{
				stmp.push(cur->left);
			}

			cur = stmp.top();//ȡջ������
			stmp.pop();//ȡ��ջ��pop��ջ��Ԫ��
		} while (cur != root);//��ջ��ֻ��һ����ʱ���˳�
		return vres;
	}

	vector<T> PreOrder_Recursive()//����ݹ��
	{
		static vector<T> res;
		if (m_root)
		{
			res.push_back(m_root->val);
			PreOrder_Recursive(m_root->left);
			PreOrder_Recursive(m_root->right);
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
			for (; cur && cur->left; cur = cur->left)//�Ȱ����Ӷ���ջ
			{
				stmp.push(cur->left);
			}

			if (!stmp.empty())//ջ��Ϊ�գ�ȡջ����push��vres����pop.
			{
				cur = stmp.top();
				vres.push_back(cur->val);
				stmp.pop();
			}

			else //��ջΪ�գ�˵�����ĸ��ڵ������ѷ�����ϣ�ֱ�Ӹ�vres push������ֵ�������Һ���
			{
				vres.push_back(cur->val);
			}

			cur = cur->right;//��������
			if (cur) //�Һ����벻Ϊ�գ��Ȱ��Һ��ӵĸ�push��������
			{
				stmp.push(cur);
			}
		}
		return vres;

	}
	vector<T> InOrder_Recursive()//����ݹ��
	{
		static vector<T> vres;
		if (root)
		{
			InOrder_Recursive(m_root->left);
			vres.push_back(m_root->val);
			InOrder_Recursive(m_root->right);
		}
		return vres;
	}

};
