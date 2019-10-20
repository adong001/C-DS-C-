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

	vector<T> PostOrder()//����ǵݹ��
	{
		TreeNode<T>* cur = m_root;
		vector<T> vres;
		stack<TreeNode<T>*> stmp;
		stack<int> sflag;//���ʱ��λ��1Ϊ�����Ѿ����ʣ�0Ϊδ��������

		if (!cur)
		{
			return vres;
		}
		do
		{	//����1
			for (; cur; cur = cur->m_left)
			{
				stmp.push(cur);//�Ѹ�����������push��ջ
				sflag.push(0);//���ʱ�־λ��0
			}
			//����3
			while (!stmp.empty() && sflag.top())//ջ��Ϊ���ҷ��ʱ�־λΪ1(�����ѷ���),��ʼ��ӡ,ѭ����ӡ��ֱ��ջΪ�ջ��־λΪ0ʱ
			{
				cur = stmp.top();//ȡջ��
				vres.push_back(cur->m_val);//push��vres
				stmp.pop();//pop��ջ��
				sflag.pop();//����ڵ����Һ��Ӽ��Լ����Է�����ϣ���־λpop��
			}

			//����2
			if (!stmp.empty())//������ʱ��˵��û��������
			{
				cur = stmp.top();//ȡջ��
				sflag.top() = 1;//û���ӣ���־λ��Ϊ1
				cur = cur->m_right;//����û�У������Һ���
			}

		} while (!stmp.empty());
		return vres;
	}




	vector<T> PostOrder_Recursive(TreeNode<T>* root)//����ݹ��
	{
		static vector<T> vres;
		if (root)
		{
			InOrder_Recursive(root->m_left);
			InOrder_Recursive(root->m_right);
			vres.push_back(root->m_val);
		}
		return vres;
	}

	//vector<T> LevelOrder(TreeNode<T>* root)//����ǵݹ��
	//vector<T> LevelOrder_Recursive(TreeNode<T>* root)//����ݹ��


};
