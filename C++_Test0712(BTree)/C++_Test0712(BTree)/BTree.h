#pragma once
#include<vector>
#include<time.h>

template<class K, size_t M = 3>
struct BTreeNode
{
	K m_keys[M];//�νڵ�洢��ֵ
	BTreeNode<K, M>* m_child[M + 1];//���ӽڵ����
	BTreeNode<K, M>* m_parent;//���ڵ㣬�п������������ڵ㣬ֻ�����С���Ǹ�
	size_t m_keysize;//�νڵ㹲�м���ֵ

	BTreeNode()//���캯��
	{
		for (int i = 0; i < M; i++)
		{
			m_child[i] = nullptr;
		}
		m_parent = nullptr;
		m_keysize = 0;
	}
};

template<class K, size_t M>
class BTree
{
	typedef BTreeNode<K, M> Node;
private:
	Node* m_root;
public:
	/*BTree() :
		m_root(nullptr)
	{}*/
	/*���Һ�����
	�ɹ�-first=���ڵ�,	second=�νڵ�����һ���λ��;
	ʧ��-first=���ڵ�,	second=-1;*/
	pair<Node*,int> Find(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = m_root;
		while (cur)
		{
			int i;
			for (i = 0; i < cur->m_keysize;)
			{
				if (key < cur->m_keys[i])//С�ڵ�ǰֵ��break��ȥ������,
				{
					break;
				}
				else if (key > cur->m_keys[i])//��С�뵱ǰֵ,ȥ��ǰֵ����һ��Ԫ��ȥ��
				{
					++i;
				}
				else//�ҵ���
				{
					return make_pair(cur, i);
				}
			}

			//�������ӻ��ҵ����һ��ֵ��û�ҵ�ʱ������һ��
			parent = cur;
			cur = cur->m_child[i];
		}
		return make_pair(parent, -1);
	}

	void InsertKey(Node* node, const K& key, Node* child)//��node�ڵ����key
	{
		int end = node->m_keysize - 1;
		for (; end >= 0 && node->m_keys[end] > key; end--)//���ֵ�����һ���󣬾ͰѺ�������Ų
		{
			node->m_keys[end + 1] = node->m_keys[end];
			node->m_child[end + 2] = node->m_child[end + 1];
		}
		node->m_keys[end + 1] = key;//�Ѵ���key��Ų����ȥ��end+1�Ϳ����ˣ��Լ�����ȥ
		node->m_child[end + 2] = child;
		if (child)
		{
			child->m_parent = node;
		}
		node->m_keysize++;

	}

	bool Insert(const K& key)//���뺯����
	{
		if (m_root == nullptr)//��һ�β��룬��Ϊ��
		{
			m_root = new Node;
			m_root->m_keys[0] = key;
			m_root->m_keysize = 1;
			return true;
		}
		pair<Node*, int> ret = Find(key);
		if (ret)//���ھͲ����ٲ���
		{
			return false;
		}

		Node* node = ret.first;
		K k = key;
		Node* child = nullptr;
		while (1)
		{
			InsertKey(node, key, child);//�Ȳ��룬M�����ǿ�����M��ֵ�����Դ洢M��ֵ
			//��ֻҪÿ�β����ͻ��ж��Ƿ���Ҫ�ַ��ѣ���֤����Խ��

			if (node->m_keysize < M)//û�г���ÿһ���ڵ����ֵ�ĸ����Ͳ���ɹ�
			{
				return true;
			}
			else//node->m_keysize == M,˵���ڵ����ˣ���Ҫ����
			{

				int mid = M / 2;
				Node* newnode = new Node;
				int i;
				for (i = mid + 1; i < M; i++)//���Ұ벿�ֿ������½ڵ���
				{
					newnode->m_keys[i - mid - 1] = node->m_keys[i];
					newnode->m_child[i - mid - 1] = node->m_child[i];//����Ҳ��������
					if (node->m_child[i])
					{
						node->m_child[i]->m_parent = newnode->m_keys[i - mid - 1];//�����ϸ���
					}
					node->m_keys[i - mid - 1] = K();//��ֵŲ�߾��ÿ�
					node->m_child[i] = nullptr;//����Ų�߾��ÿ�
					node->m_keys[i - mid - 1] = nullptr;
					newnode->m_keysize++;
				}
				newnode->m_child[i - mid - 1] = node->m_child[i];//���һ���Һ��Ӻ�������ΪM
				if (node->m_child[i])
				{
					node->m_child[i]->m_parent = newnode->m_keys[i - mid - 1];//�����ϸ���
				}
				node->m_child[i] = nullptr;//����Ų�߾��ÿ�
				node->m_keysize -= (newnode->m_keysize + 1);

				//��mid��ֵҪ�õ�parent��ȥ�������������
				if (node->m_parent == nullptr)//���ڵ�Ϊ��
				{
					m_root = new Node;
					m_root->m_keys[0] = node->m_keys[mid];//��mid��ֵҪ�õ�parent��һ��ֵ��
					m_root->m_child[0] = node;//���ڵ������ǵ�ǰ�ڵ�
					m_root->m_child[1] = newnode;//�Һ����Ƿ��ѳ����Ľڵ�
					node->m_parent = newnode->m_parent = m_root;
					node->m_keys[mid] = K();//�ýڵ�Ų�߾��ÿ�
					return true;
				}
				else//���ڵ㲻Ϊ�գ����൱�ڸ����ڵ����һ��ֵΪnode->m_keys[mid]�ĺ���
				{
					//ʹ�õ�����node��ɸ��ڵ㣬child���ڵ����ӣ�ѭ����ȥ�����Ǹ�node����k
					k = node->m_keys[mid];
					child = newnode;
					node = node->m_parent;
				}
			}
		}
		return true;
	}

	void _InOrder(Node* cur)
	{
		if (cur == nullptr)
		{
			return;
		}
		int i = 0;
		for (; i < cur->m_keysize;i++)//
		{
			_InOrder(cur->m_child[i]);//�ȱ���������
			cout << cur->m_keys[i] << " ";//����Լ�
		}
		_InOrder(cur->m_child[i]);//�������һ��ֵ��������
	}

	void InOrder()
	{
		_InOrder(m_root);
		cout << endl;
	}
};

