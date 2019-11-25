
#include<stack>
#include<vector>

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

		void erase_root(TreeNode<T>* parent, TreeNode<T>* node, const int& status)//ɾ���ڵ㺯��,��֤�ڵ�һ������
		{
			TreeNode<T>* cur = node;

			if (!cur->m_left && !cur->m_right)//���Һ��Ӷ������ڣ�ֱ��ɾ��
			{
				delete cur;
				cur = nullptr;
			}

			else if (!cur->m_left)//����Ϊ��
			{
				delete cur;
				cur = cur->m_right;
			}

			else if (!cur->m_right)//�Һ���Ϊ��
			{
				delete cur;
				cur = cur->m_left;
			}

			else//���Һ��Ӷ�����
			{
				TreeNode<T>* tmp = node->m_right;
				cur = node->m_left;

				for (; tmp->m_left; tmp = tmp->m_left);//�ҵ����ڵ��Һ�������С��(Ҳ���Ǹ��ڵ��Һ�����һֱ�ҵ�����Ϊ��Ϊֹ)

				tmp->m_left = cur->m_right;//�ұ��е���Сֵ������ָ��  ��ߺ����е����ֵ
				cur->m_right = node->m_right;//�Һ��Ӽ̳�ɾ���ڵ���Һ���
				delete node;
			}

			if (parent == m_root)//ɾ���Ǹ��ڵ�
			{
				parent = cur;
			}

			else if (status == true)//ɾ����parent������
			{
				parent->m_left = cur;
			}
			else
			{
				parent->m_right = cur; // ɾ����parent���Һ��ӣ����丸�ڵ�ָ���µĽڵ�
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

		bool Find(TreeNode<T>* parent, TreeNode<T>* node, bool& status, const T& val)//
		{
			parent = node = m_root;
			if (parent->m_data == val)//val��ֵΪ���ڵ�ʱ
			{
				return true;
			}

			//status�����ҵ�Ŀ��ڵ�node�Ǹ��ڵ�parent�����ӻ����Һ��ӵı�־λ��true---���ӣ� false---�Һ��ӣ�

			while (node)
			{
				if (node->m_data == val)//�ҵ�����
				{
					break;
				}

				else
				{
					parent = node;//û�ҵ����¸��ڵ㣬������
				}

				if (parent->m_data > val)//���ڵ�ǰ�ڵ�����������
				{
					node = parent->m_left;
					status = true;
				}

				else if (parent->m_data < val)//С�ڵ�ǰ�ڵ����Һ�������
				{
					node = parent->m_left;
					status = false;
				}
			}

			if (!node)//�ҵ��Ľڵ�Ϊ�գ�����false
			{
				return false;
			}
			return true;
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
				m_root = new TreeNode<T>(val);
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
			TreeNode<T>* parent = nullptr, *node = nullptr;
			bool status;

			if (!Find(parent, node, status, val))//���ҵ�Ҫɾ���Ľڵ�,�Ҳ���ֱ�ӷ���false
			{
				return false;
			}
#if 0
			
#else
			erase_root(parent, node, status);//ɾ���Ǹ��ڵ㼴�ɣ���ʱһ���ᱣ��ɾ���ɹ�
			return true;
#endif 

		}

		//vector<T> InOrderTree()
		//{
		//	vector<T> res;
		//	if (!m_root)
		//	{
		//		return res;
		//	}

		//	stack<TreeNode<T>*> st;
		//	TreeNode<T>* cur = m_root;
		//	while (cur || !st.empty())
		//	{
		//		for (; cur; cur = cur->m_left)
		//		{
		//			st.push(cur);
		//		}
		//		
		//		if (!st.empty())
		//		{
		//			cur = st.top();
		//			res.push_back(cur->m_data);
		//			st.pop();
		//			cur = cur->m_right;
		//		}
		//	}
		//	return res;
		//}


	};
};