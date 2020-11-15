#pragma once 
#include<map>
namespace YD
{
	enum Color{ RED, BLACK };

	//�ڵ���
	template<class T>
	class RBTreeNode
	{
	private:
		T m_data;
		RBTreeNode<T>* m_lchild;
		RBTreeNode<T>* m_rchlid;
		RBTreeNode<T>* m_parent;
		Color m_color;
	public:
		RBTreeNode(const T& val = T(), Color color = RED) :
			m_color(color),
			m_data(val),
			m_lchild(nullptr),
			m_rchlid(nullptr),
			m_parent(nullptr)
		{}
		template<class T>
		friend class RBTree;
	};

	template<class T>
	class RBTree
	{
	private:
		RBTreeNode<T>* m_head;//head�ڵ�ĸ��ڵ�ָ��root��root�ĸ��ڵ�ָ��head
		size_t m_size;

		//����
		void lRound(RBTreeNode<T>* pre)
		{
			RBTreeNode<T>* parent = pre->m_parent;
			RBTreeNode<T>* cur = pre->m_rchlid;
			cur->m_parent = parent;
			//1.�͸��ڵ㽨����ϵ
			//Ҫ��ת�ĸ��ڵ㲻��head
			if (parent != m_head)
			{
				if (parent->m_lchild == pre)//pre�Ǹ��ڵ������
				{
					parent->m_lchild = cur;
				}
				else
				{
					parent->m_rchlid = cur;
				}
			}
			else
			{
				//���ڵ���head,��ֱ�Ӷ�head����
				m_head->m_parent = cur;
				cur->m_parent = m_head;
			}

			//2.�������ӣ�cur��������ȥ����Ϊpre�ĸ��ڵ㣬
			//pre��Ϊcur�������ӣ�cur�����ӳ�Ϊpre���Һ���
			pre->m_rchlid = cur->m_lchild;
			if (cur->m_lchild)
			{
				//�����ϸ���
				cur->m_lchild->m_parent = pre;
			}
			cur->m_lchild = pre;
			pre->m_parent = cur;
		}

		//����
		void rRound(RBTreeNode<T>* pre)
		{
			RBTreeNode<T>* parent = pre->m_parent;
			RBTreeNode<T>* cur = pre->m_rchlid;
			cur->m_parent = parent;

			if (parent != m_head)
			{
				if (pre == parent->m_lchild)
				{
					parent->m_lchild = cur;
				}
				else
				{
					parent->m_rchlid = cur;
				}
			}
			else
			{
				m_head->m_parent = cur;
				cur->m_parent = m_head;
			}

			pre->m_lchild = cur->m_rchlid;
			if (cur->m_rchlid)
			{
				cur->m_rchlid->m_parent = pre;
			}
			cur->m_rchlid = pre;
			pre->m_parent = cur;
		}

		//������
		void destory(RBTreeNode<T>* root)
		{
			if (root)
			{
				destory(root->m_lchild);
				destory(root->m_rchlid);
				delete root;
			}
		}

		//��ø��ڵ�
		RBTreeNode<T>* &getRoot()
		{
			return m_head->m_parent;
		}


		//����3��4��5�����
		void Adjust(RBTreeNode<T>*& parent, RBTreeNode<T>*& cur)
		{
			RBTreeNode<T>* grand = parent->m_parent;
			RBTreeNode<T>* uncle;
			//���3. 4.1 5.1 ��������
			if (parent == grand->m_lchild)
			{
				//ֻҪû�ҵ����ڵ㣬���߸��ڵ㲻Ϊ�ھͱ���һֱ���ϵ���
				while (parent != m_head && parent->m_color == RED)
				{
					grand = parent->m_parent;
					uncle = grand->m_rchlid;
					//���3�����죬��죬ү��
					if (uncle && uncle->m_color == RED)
					{
						//����Ϊ����ڣ�ү�죬��үλ�ü������ϵ�
						parent->m_color = BLACK;
						uncle->m_color = BLACK;
						grand->m_color = RED;
						cur = grand;
						parent = cur->m_parent;
					}
					//���4��5
					else
					{
						//���5.1������
						if (cur == parent->m_rchlid)
						{
							//һ��������������󣬱�����4.1
							lRound(parent);
							RBTreeNode<T>* tmp = parent;
							parent = cur;
							cur = tmp;
						}
						//���4.1;����һ������������ڣ�ү���
						rRound(grand);
						parent->m_color = BLACK;
						grand->m_color = RED;
						//���4��5ֻ��һ�ε���
						break;
					}
				}
			}
				//���3 4.2. 5.2 ���ң�����
			else
			{
				//ֻҪû�ҵ����ڵ㣬���߸��ڵ㲻Ϊ�ھͱ���һֱ���ϵ���
				while (parent != m_head && parent->m_color == RED)
				{
					grand = parent->m_parent;
					uncle = grand->m_lchild;
					//���3�����죬��죬ү��
					if (uncle && uncle->m_color == RED)
					{
						//����Ϊ����ڣ�ү�죬��үλ�ü������ϵ�
						parent->m_color = BLACK;
						uncle->m_color = BLACK;
						grand->m_color = RED;
						cur = grand;
						parent = cur->m_parent;
					}
					//���4��5
					else
					{
						//���5.2������
						if (cur = parent->m_lchild)
						{
							//һ��������������ң�������4.2
							rRound(parent);
							RBTreeNode<T>* tmp = parent;
							parent = cur;
							cur = tmp;
						}
						//���4.2;���ң�һ������������ڣ�ү���
						lRound(grand);
						parent->m_color = BLACK;
						grand->m_color = RED;
						//���4��5ֻ��һ�ε���
						break;
					}
				}
			}

		}

		static RBTreeNode<T> * increasement(RBTreeNode<T> * cur)
		{
			RBTreeNode<T> * tmp = cur;
			if (cur->m_right)
			{
				tmp = cur->m_right;
				for (; tmp->m_left; tmp = tmp->m_left);
			}
			else
			{
				tmp = tmp->m_parent;
				for (; cur != tmp->m_left && cur == tmp->m_right; tmp = tmp->m_parent)
				{
					cur = tmp;
				}
			}
			return tmp;
		}

		static RBTreeNode<T> * decreasement(RBTreeNode<T> * cur)
		{
			RBTreeNode<T> * tmp = cur;
			if (cur->m_left)
			{
				tmp = cur->m_left;
				for (; tmp->m_right; tmp = tmp->m_right);
			}
			else
			{
				tmp = tmp->m_parent;
				for (; cur != tmp->m_right && cur == tmp->m_left; tmp = tmp->m_parent)
				{
					cur = tmp;
				}
			}
			return tmp;
		}
		public:
			RBTree() :
				m_size(0)
			{
				m_head = new RBTreeNode<T>;
			}
			~RBTree()
			{
				m_size = 0;
				destory(m_head);
				m_head->m_lchild = m_head->m_rchlid = m_head->m_parent = nullptr;
			}

			size_t size()
			{
				return m_size;
			}

			bool empty()
			{
				return m_head->m_parent = nullptr;
			}

			//��һ�����ӣ���Сֵ
			RBTreeNode<T>* FirstChild()
			{
				RBTreeNode<T>* cur = getRoot();
				for (; cur->m_lchild; cur = cur->m_lchild);
				return cur;
			}
			//���һ�����ӣ����ֵ
			RBTreeNode<T>* LastChild()
			{
				RBTreeNode<T>* cur = getRoot();
				for (; cur->m_rchlid; cur = cur->m_rchlid);
				return cur;
			}

			RBTreeNode<T>* Find(const T& val)
			{
				RBTreeNode<T>* root = getRoot();
				if (root)
				{
					RBTreeNode<T>* cur = root;
					while (cur)
					{
						if (cur->m_data == val)
						{
							return cur;
						}
						else if (cur->m_data < data)
						{
							cur = cur->m_lchild;
						}
						else
						{
							cur = cur->m_rchlid;
						}
					}
					return nullptr;
				}
				return nullptr;
			}

			pair<RBTreeNode<T>*,bool> Insert(const T& val)
			{
				pair<RBTreeNode<T>*, bool> ret(nullptr, false);
				RBTreeNode<T>* & root = getRoot();
				//����Ϊ��
				if (root)
				{
					RBTreeNode<T>* cur = root;
					RBTreeNode<T>* pre = nullptr;
					while (cur)
					{
						if (cur->m_data < val)
						{
							pre = cur;
							cur = cur->m_rchlid;
						}
						else if (cur->m_data > val)
						{
							pre = cur;
							cur = cur->m_lchild;
						}
						else//���и�ֵ����ʧ��
						{
							ret.first = cur;
							return ret;
						}
					}

					cur = new RBTreeNode<T>(val);
					ret.first = cur;
					if (val < pre->m_data)
					{
						pre->m_lchild = cur;
					}
					else
					{
						pre->m_rchlid = cur;
					}
					cur->m_parent = pre;

					//��ʼ���������
					//���3.4.5
					if (pre->m_color == RED)
					{
						Adjust(pre, cur);
					}
					//���2�����ڲ���Υ���κι���ֱ�Ӳ���
					else
					{
						//do nothing
					}

				}
				//���1����Ϊ�գ�������Ǹ��ڵ�
				else
				{
					root = new RBTreeNode<T>(val, BLACK);
					root->m_parent = m_head;
					m_head->m_parent = root;
					ret.first = root;
				}
				root->m_color = BLACK;
				m_head->m_lchild = FirstChild();
				m_head->m_rchlid = LastChild();
				m_size++;
				ret.second = true;
				return ret;
			}

			bool erase(const T &val)
			{
				if (m_root == nullptr)
				{
					return false;
				}

				RBTreeNode<T> * cur = m_root;
				RBTreeNode<T> * pre = m_root;

				while (cur)
				{
					if (val < cur->m_data)
					{
						pre = cur;
						cur = cur->m_left;
					}
					else if (val > cur->m_data)
					{
						pre = cur;
						cur = cur->m_right;
					}
					else
					{
						break;
					}
				}

				if (cur == nullptr)
				{
					return false;
				}

				if (cur->m_left && cur->m_right)
				{
					RBTreeNode<T> * cur2 = cur->m_left;
					RBTreeNode<T> * pre2 = cur;

					if (cur2->m_right)
					{
						for (; cur2->m_right; pre2 = cur2, cur2 = cur2->m_right);
						pre2->m_right = cur2->m_left;
						cur2->m_left = cur->m_left;
					}

					cur2->m_right = cur->m_right;

					if (cur == pre)
					{
						m_root = cur2;
					}
					else
					{
						if (cur->m_data < pre->m_data)
						{
							pre->m_left = cur2;
						}
						else
						{
							pre->m_right = cur2;
						}
					}

					delete cur;
				}
				else if (cur->m_left)
				{
					if (cur == pre)
					{
						m_root = cur->m_left;
					}
					else
					{
						if (cur->m_data < pre->m_data)
						{
							pre->m_left = cur->m_left;
						}
						else
						{
							pre->m_right = cur->m_left;
						}
					}
					delete cur;
				}
				else
				{
					if (cur == pre)
					{
						m_root = cur->m_right;
					}
					else
					{
						if (cur->m_data < pre->m_data)
						{
							pre->m_left = cur->m_right;
						}
						else
						{
							pre->m_right = cur->m_right;
						}
					}

					delete cur;
				}
			}
	};
};
