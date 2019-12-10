#include<stack>
#include<vector>
#include <iostream>
using namespace std;

namespace YD
{
	template<class T>
	class TreeNode
	{
	private:
		T m_data;
		TreeNode<T>* m_left;
		TreeNode<T>* m_right;
	public:
		TreeNode(const T& data = T()) :
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

		void erase_node(TreeNode<T>*& parent, TreeNode<T>*& node)//ɾ���ڵ㺯��,��֤�ڵ�һ������
		{

			if (!node->m_left && !node->m_right)//���Һ��Ӷ������ڣ�ֱ��ɾ��
			{
				delete node;
				node = nullptr;
			}

			else if (!node->m_left)//����Ϊ��
			{
				if (parent == node)//ɾ���Ǹ�
				{
					m_root = node->m_right;
				}
				else
				{
					if (parent->m_left == node)//�����׵����Լ����Һ�������
					{
						parent->m_left = node->m_right;
					}
					else
					{
						parent->m_right = node->m_right;
					}
				}
				delete node;
			}

			else if (!node->m_right)//�Һ���Ϊ��
			{
				if (parent == node)//ɾ���Ǹ�
				{
					m_root = node->m_left;
				}
				else
				{
					if (parent->m_left == node)//�����׵����Լ����Һ�������
					{
						parent->m_left = node->m_left;
					}
					else
					{
						parent->m_right = node->m_left;
					}
				}
				delete node;
			}

			else//���Һ��Ӷ�����
			{
				TreeNode<T>* tmp = node->m_right;
				TreeNode<T>* cur = node->m_left;

				for (; tmp->m_left; tmp = tmp->m_left);//�ҵ����ڵ��Һ�������С��(Ҳ���Ǹ��ڵ��Һ�����һֱ�ҵ�����Ϊ��Ϊֹ)

				tmp->m_left = cur->m_right;//�ұ��е���Сֵ������ָ��  ��ߺ����е����ֵ
				cur->m_right = node->m_right;//�Һ��Ӽ̳�ɾ���ڵ���Һ���

				if (parent == node)//ɾ���Ǹ�
				{
					m_root = cur;
				}
				else
				{
					if (parent->m_left == node)//�����ڵ���½ڵ���������
					{
						parent->m_left = cur;
					}
					else
					{
						parent->m_right = cur;
					}
				}
				delete node;
			}
		}

	public:

		Tree() :
			m_root(nullptr)
		{}

		~Tree()
		{
			Destory(m_root);
		}

		bool Find(TreeNode<T>* & parent, TreeNode<T>*& node, const T& val)//ͨ���ڵ��ֵ�������ĵ�ַ�͸��ڵ�ĵ�ַ
		{
			parent = node = m_root;
			if (node->m_data == val)//val��ֵΪ���ڵ�ʱ
			{
				return true;
			}

			while (node)
			{
				if (node->m_data == val)//�ҵ�����
				{
					return true;
				}

				parent = node;//û�ҵ����¸��ڵ㣬������

				if (parent->m_data > val)//���ڵ�ǰ�ڵ�����������
				{
					node = parent->m_left;
				}

				else//С�ڵ�ǰ�ڵ����Һ�������
				{
					node = parent->m_right;
				}

			}

			return false;
		}

		bool Insert(const T& val)
		{
			if (!m_root)
			{
				m_root = new TreeNode<T>(val);
				return true;
			}

			TreeNode<T>* cur = m_root;
			TreeNode<T>* pre = m_root;

			while (cur)
			{
				if (cur->m_data == val)//����ͬ��ֵ���벻�ɹ�
				{
					return false;
				}

				pre = cur;

				if (cur->m_data > val)//valֵС�ڵ�ǰ�ڵ�ֵ������߲�
				{
					cur = pre->m_left;
				}

				else   //valֵ���ڵ�ǰ�ڵ�ֵ������߲�
				{
					cur = pre->m_right;
				}
			}

			cur = new TreeNode<T>(val);//��ʱ�ҵ��Ľڵ�϶��ǿյģ����ͱ���������λ��

			if (pre->m_data > cur->m_data)//����߲�
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

			TreeNode<T>* parent = nullptr, *node = nullptr;

			if (!Find(parent, node, val))
				//���ҵ�Ҫɾ���Ľڵ�,�Ҳ���ֱ�ӷ���false,
				//�����nodeָ��Ҫɾ���Ǹ��ڵ�,parentָ�����ĸ���
			{
				return false;
			}

			erase_node(parent, node);//���涼�Ѿ���֤����ڵ���ڣ��Ǿ�һ����ɾ���ɹ���
			return true;
		}

		vector<T> InOrderTree()
		{
			vector<T> res;
			if (!m_root)
			{
				return res;
			}

			stack<TreeNode<T>*> st;
			TreeNode<T>* cur = m_root;

			while (cur || !st.empty())
			{
				for (; cur; cur = cur->m_left)
				{
					st.push(cur);
				}

				if (!st.empty())
				{
					cur = st.top();
					res.push_back(cur->m_data);
					st.pop();
					cur = cur->m_right;
				}
			}
			return res;
		}

	};
};