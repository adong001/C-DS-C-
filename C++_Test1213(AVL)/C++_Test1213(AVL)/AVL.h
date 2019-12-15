#pragma once




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
		int m_bf;//ƽ������
		TreeNode<T>* m_left;
		TreeNode<T>* m_right;
		TreeNode<T>* m_parent;
	public:
		TreeNode(const T& data = T()) :
			m_data(data),
			m_bf(0),
			m_left(nullptr),
			m_right(nullptr),
			m_parent(nullptr)
		{}
		template<class T>
		friend class AVLTree;
	};

	template<class T>
	class AVLTree
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

		void erase_node(TreeNode<T>* parent, TreeNode<T>* node)//ɾ���ڵ㺯��,��֤�ڵ�һ������
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


		void LRound(TreeNode<T>* pre)//����
		{

			TreeNode<T>* parent = pre->m_parent;
			TreeNode<T>* cur = pre->m_right;//����Ҫ����ʱ���Һ���(pre->m_bf = 2 ,pre->m_right->m_bf = 1ʱ����������)

			//��һ�����Լ��ĸ��׺��Һ�������
			cur->m_parent = parent;

			if (parent)//������״���
			{
				//�������Ҫ�ж�pre��parent�����ӻ����Һ���
				if (parent->m_left == pre)//���pre�Ǹ��׵����ӣ������׵�������cur����
				{
					parent->m_left = cur;
				}
				else//��cur�ҵ�parent���Һ�����
				{
					parent->m_right = cur;
				}
			}

			else//������ڵ㲻���ڣ���ôpre�Ѿ��Ǹ���,ֱ�ӻ�������
			{
				m_root = cur;
			}

			//�ڶ���������cur���ӵ����⣬��ΪcurҪ������ȥ����������Ҫָ��pre,
			//֮ǰ�����Ӿ͵ùҵ�pre���Һ�����(֮ǰpre���Һ�����cur,
			//cur������С��cur������pre, ����������pre���Һ���)

			pre->m_right = cur->m_left;//�����϶���

			//�����ϸ���
			if (cur->m_left)//��Ҫ�ж�cur�������Ƿ����
			{
				cur->m_left->m_parent = pre;
			}

			//������������cur��pre�Ĺ�ϵ����Ϊcur��������ȥ������cur��pre�ĸ���
			pre->m_parent = cur;
			cur->m_left = pre;

			//���Ĳ����ı�ƽ������
			//֮����Ҫ��pre��curִ������������Ϊ�ڲ����Ǹ��ڵ�֮ǰcur->m_bf = 0,pre->m_bf = 1,��ƽ�⣬
			//��cur���Һ��Ӳ���һ���ڵ�󣬵���cur->m_bf  = 1,pre->m_bf = 2,��Ҫ����pre��cur��
			//�ڵ������֮��cur���Һ���û�䣬�����Ӽ���һ��pre�ڵ㣬ʹ��cur->m_bf = 0
			//pre������û��,�Һ�������һ��cur��ʹ��pre->m_bf = 0

			cur->m_bf = pre->m_bf = 0;
		}

		void RRound(TreeNode<T>* pre)//����
		{
			//���������Ǿ����ϵ�����еĶ��������෴��

			TreeNode<T>* parent = pre->m_parent;
			TreeNode<T>* cur = pre->m_left;//����Ҫ����ʱ������(pre->m_bf = -2 ,pre->m_left->m_bf = -1ʱ����������)

			//��һ�����Լ��ĸ��׺���������
			cur->m_parent = parent;

			if (parent)//������״���
			{
				//�������Ҫ�ж�pre��parent�����ӻ����Һ���
				if (parent->m_left == pre)//���pre�Ǹ��׵����ӣ������׵�������cur����
				{
					parent->m_left = cur;
				}
				else//��cur�ҵ�parent���Һ�����
				{
					parent->m_right = cur;
				}
			}

			else//������ڵ㲻���ڣ���ôpre�Ѿ��Ǹ���,ֱ�ӻ�������
			{
				m_root = cur;
			}

			//�ڶ���������cur���ӵ����⣬��ΪcurҪ������ȥ�������Һ���Ҫָ��pre,
			//֮ǰ���Һ��Ӿ͵ùҵ�pre��������(֮ǰpre��������cur,
			//cur���Һ��Ӵ���cur��С��pre, ����������pre������)

			pre->m_left = cur->m_right;//�����϶���

			//�����ϸ���
			if (cur->m_right)//��Ҫ�ж�cur�������Ƿ����
			{
				cur->m_right->m_parent = pre;
			}

			//������������cur��pre�Ĺ�ϵ����Ϊcur��������ȥ������cur��pre�ĸ���
			pre->m_parent = cur;
			cur->m_right = pre;

			//���Ĳ����ı�ƽ������
			//֮����Ҫ��pre��curִ������������Ϊ�ڲ����Ǹ��ڵ�֮ǰcur->m_bf = 0,pre->m_bf = -1,��ƽ�⣬
			//��cur�����Ӳ���һ���ڵ�󣬵���cur->m_bf  = -1,pre->m_bf = -2,��Ҫ����pre��cur��
			//�ڵ������֮��cur������û�䣬���Һ��Ӽ���һ��pre�ڵ㣬ʹ��cur->m_bf = 0
			//pre���Һ���û��,��������һ��cur��ʹ��pre->m_bf = 0

			cur->m_bf = pre->m_bf = 0;
		}


		void LRRound(TreeNode<T>* pre)//����������
		{
			//�������������������

			TreeNode<T>* left = pre->m_left; //�ȶ�pre�����ӽ�����������
			TreeNode<T>* newroot = left->m_right;//����������ת֮��pre�����ӵ��Һ��ӽ�������pre��λ��

			int flag = newroot->m_bf;//��¼pre���ӵ��Һ��ӵ�ƽ������

			LRound(left);//�Ƚ�pre��������������������
			RRound(pre);//�ٶ�pre����������ʹ���ָ�ƽ��

			if (flag == 1)//���newroot�ڵ�֮ǰ��ƽ��������1��˵����newroot���Һ��Ӳ����˽ڵ�(��ɾ�������ӵ�ĳ���ڵ�)��
				//���Ӹ߶ȱ��Һ��Ӹ߶�С1��������ƽ�����ӱ��1��
				//������һ�ζ�left(newroot->parent)������֮��,newroot�������ܵ���left���Һ����ϣ����Ե���left�����ӱ��Һ��ӵ�1��
				//�پ�����pre������֮��ʹnewroot���Һ��ӹҵ���pre���Һ�����,pre�ĸ߶�ƽ��
			{
				left->m_bf = -1;  //����֮��left��newroot��ƽ�����Ӷ�����Ϊ0��������Ϊ��left��bf��Ϊ-1���ɣ�
			}

			else if (flag == -1)//���newroot�ڵ�֮ǰ��ƽ��������-1��˵�������Ӳ����˽ڵ�(��ɾ�����Һ��ӵ�ĳ���ڵ�)��
				//.......���newroot���Һ���(�ұ����1)����������ת���ҵ���pre��������
			{
				pre->m_bf = 1;
			}
			else//���flag == 0ʱ��˵��newroot���²���Ľڵ㣬û�����Һ��ӣ�������ת֮�������ڵ��bf������0
			{
				//do nothing
			}

		}

		void RLRound(TreeNode<T>* pre)//����������
		{
			//LRRound�ľ�������ȡ��
			//������������ң�������

			TreeNode<T>* right = pre->m_right; //�ȶ�pre���Һ��ӽ�����������
			TreeNode<T>* newroot = right->m_left;//����������ת֮��pre���Һ��ӵ����ӽ�������pre��λ��

			int flag = newroot->m_bf;//��¼pre�Һ��ӵ����ӵ�ƽ������

			RRound(right);//�Ƚ�pre���Һ���������������Һ�
			LRound(pre);//�ٶ�pre����������ʹ���ָ�ƽ��

			if (flag == 1)//���newroot�ڵ�֮ǰ��ƽ��������1��˵����newroot�����Ӳ����˽ڵ�(��ɾ�������ӵ�ĳ���ڵ�)��
				//���Ӹ߶ȱ��Һ��Ӹ߶�С1��������ƽ�����ӱ��1��
				//������һ�ζ�right(newroot->parent)������֮��,newroot���Һ����ܵ���right�������ϣ����Ե���right�����ӱ��Һ��ӵ�1��
				//�پ�����pre������֮��ʹnewroot�����ӹҵ���pre���Һ�����,pre�ĸ߶�ƽ��
			{
				right->m_bf = -1;  //����֮��right��newroot��ƽ�����Ӷ�����Ϊ0��������Ϊ��right��bf��Ϊ-1���ɣ�
			}

			else if (flag == -1)//���newroot�ڵ�֮ǰ��ƽ��������-1��˵�������Ӳ����˽ڵ�(��ɾ�����Һ��ӵ�ĳ���ڵ�)��
				//.......���newroot���Һ���(�ұ����1)����������ת���ҵ���pre��������
			{
				pre->m_bf = 1;
			}
			else//���flag == 0ʱ��˵��newroot���²���Ľڵ㣬û�����Һ��ӣ�������ת֮�������ڵ��bf������0
			{
				//do nothing
			}

		}

		void ModifyBF(TreeNode<T>* cur,TreeNode<T>* pre)
		{
			while (pre)
			{
				//�޸ĸ��ڵ�ƽ������
				if (pre->m_left == cur)//cur�������뵽cur�����
				{
					pre->m_bf--;
				}
				else//cur�����뵽pre���ұ�
				{
					pre->m_bf++;
				}

				if (pre->m_bf == 0)//����󸸽ڵ�ƽ������ = 0
					//˵�����ڵ���һ�����Ӵ��ڣ�����ƽ�⣬����cur��
					//pre->bf = 0,��ζ��pre�ĸ߶�û�䣬�Ͳ���Ӱ������ڵ��bf,���������ֱ��break
				{
					break;
				}

				else if (pre->m_bf == 1 || pre->m_bf == -1)
					//����cur��pre��bf��Ϊ1��-1��˵��pre�ڵ�ԭ���ĵ����Ҹ߶���ƽ��ģ�cur��������������һ�ߺ�
					//pre�����Ҹ߶Ȳ���ͬ���ͻᵼ�����ĸ��ڵ�߶ȸı�һֱ���ϱ�����ֱ����������Ҫ����
				{
					cur = pre;
					pre = pre->m_parent;
				}

				else //��ƽ�����Ӿ���ֵ����1ʱ�����Ǿ�Ҫ��ʼ����
				{
					if (pre->m_bf == 2)//���� �� ����
					{
						if (pre->m_right->m_bf == 1)//����
						{
							LRound(pre);//һ�������������
						}

						else//����  ����˯���гɶ��е��ʱ�����
						{
							RLRound(pre);//��������
						}
					}

					else
					{
						if (pre->m_left->m_bf == 1)//����
						{
							RRound(pre);//һ�������������
						}

						else//����
						{
							LRRound(pre);//��������
						}

					}
					break;//��ת������Ѿ�ƽ�⣬ֱ��break
				}

			}
		}

	public:

		AVLTree() :
			m_root(nullptr)
		{}

		~AVLTree()
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
			cur->m_parent = pre;

			/*******************��������Ϊ�޸�ƽ������*********************/

			ModifyBF(cur, pre);

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

		vector<T> InOrderTree()//�������
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