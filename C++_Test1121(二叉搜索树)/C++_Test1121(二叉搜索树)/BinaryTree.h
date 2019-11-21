#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;

namespace YD
{
	template<class T>
	class TreeNode
	{
	private:
		T m_data;
		T* m_left;
		T* m_right;
	public:
		TreeNode(const T& data = TreeNode()) :
			m_data(data),
			m_left(nullptr),
			m_right(nullptr)
		{}
		template<class T>
		friend class Tree;
	};

	template<class T>
	class Tree
	{
	private:
		TreeNode<T>* m_root;
		void Destory(TreeNode<T>* root)
		{
			if (root)
			{
				Destory(root->m_left);
				Destory(root->m_right);
				delete root;
			}
		}
		map<TreeNode<T>*, bool> findpos(TreeNode<T>* root)
		{
			TreeNode<T>* cur = m_root;
			TreeNode<T>* pre = m_root;
			bool flag = false;//����һ��flag������߲�Ϊtrue,�ұ߲�Ϊfalse
			while (cur)
			{
				if (cur->m_data == val)//����ͬ��ֵ���벻�ɹ�
				{
					return false;
				}

				else if (cur->m_data > val)//valֵС�ڵ�ǰ�ڵ�ֵ������߲�
				{
					pre = cur;
					cur = cur->m_left;
					flag = true;
				}

				else   //valֵ���ڵ�ǰ�ڵ�ֵ������߲�
				{
					pre = cur;
					cur = cur->m_right;
					flag = false;
				}
			}
			map<TreeNode<T>*, bool> m;
			m.insert(pair<TreeNode<T>*, bool>(root, false));
			return m;
		}

	public:

		Tree() :
			m_root(nullptr)
		{}

		~Tree(
		{
			Destory(m_root);
		}

		TreeNode<T>* Find(const T& val)
		{
			if (!m_root)
			{
				return nullptr;
			}

			TreeNode<T>* cur = m_root;

			while (cur)
			{
				if (cur->m_data == val)//�ҵ�����
				{
					return cur;
				}

				else if (cur->m_data > val)//valֵС�ڵ�ǰ�ڵ�ֵ���������
				{
					cur = cur->m_left;
				}

				else   //valֵ���ڵ�ǰ�ڵ�ֵ�����ұ���
				{
					cur = cur->m_right;
				}
			}
			return nullptr;
		}

		bool Insert(const T& val)
		{
			if (!m_root)
			{
				m_root = new TreeNode<T>*(val);
				return true;
			}

			TreeNode<T>* cur = m_root;
			TreeNode<T>* pre = m_root;
			bool flag = false;//����һ��flag������߲�Ϊtrue,�ұ߲�Ϊfalse

			while (cur)
			{
				if (cur->m_data == val)//����ͬ��ֵ���벻�ɹ�
				{
					return false;
				}

				else if (cur->m_data > val)//valֵС�ڵ�ǰ�ڵ�ֵ������߲�
				{
					pre = cur;
					cur = cur->m_left;
					flag = true;
				}

				else   //valֵ���ڵ�ǰ�ڵ�ֵ������߲�
				{
					pre = cur;
					cur = cur->m_right;
					flag = false;
				}
			}

			cur = new TreeNode<T>(val);//��ʱ�ҵ��Ľڵ�϶��ǿյģ����ͱ���������λ��

			if (flag)//����߲�
			{
				pre->m_left = cur;
			}
			else //���ұ߲�
			{
				pre->m_right = cur;
			}
			return true;
		}

		bool erase(const T& val)
		{
			if (!m_root)
			{
				return false;
			}


		}

	};
};