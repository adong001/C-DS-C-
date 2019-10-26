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

	vector<T> LevelOrder()//����ǵݹ��
	{
		queue<TreeNode<T>*> qtmp;
		vector<T> vres;
		if (!m_root)
		{
			return vres;
		}

		TreeNode<T>* cur = m_root;
		qtmp.push(cur);//�Ƚ����ڵ�push��ȥ

		while (!qtmp.empty())
		{
			cur = qtmp.front();
			qtmp.pop();
			vres.push_back(cur->m_val);
			if (cur->m_left)
			{
				qtmp.push(cur->m_left);
			}

			if (cur->m_right)
			{
				qtmp.push(cur->m_right);
			}
		}
		return vres;

	}

	size_t TreeDepth()//���������,��Ҫ�ݹ飬�͵ô��Σ�ֻ������һ��������װһ��
	{
		return TreeDepth(m_root);
	}

	size_t TreeDepth(TreeNode<T>* root)//���������
	{
		if (!root)
		{
			return 0;
		}
		int LeftChildDepth = TreeDepth(root->m_left);
		int RightChildDepth = TreeDepth(root->m_right);
		return LeftChildDepth > RightChildDepth ? LeftChildDepth + 1 : RightChildDepth + 1;
	}
	// �ݹ�ʵ�ֲ������
	//���ڲ��������һ�ֹ�����ȵı���������������Ҫͨ������������������������
	//ÿ��ѭ������Ҫ����Ĳ���
	//Ȼ�󵱲���������0ʱ�����µݹ飬ÿ�εݹ������һ
	//����������0��ʱ����˵���Ѿ�������Ҫ�������һ�㣬�ݹ�Ľ��������������ˣ�ֱ�����ֵ����
	//vector<T> LevelOrder_Recursive()
	//{
	//	size_t LevelNum = TreeDepth();
	//	vectoc<T> vres;
	//	vres = LevelOrder_Recursive(m_root, LevelNum,vres);
	//	return vres;
	//}

	//vector<T> LevelOrder_Recursive(TreeNode<T>* root, int LevelNum, vector<T> vtmp)
	//{
	//	vector<T> vres = vtmp;
	//	if (!root)
	//	{
	//		vres.push_back(root->m_val);//����Ϊ�գ��ȰѸ�push��ȥ
	//        if(LevelNum > 1)
	//		{
	//			LevelOrder_Recursive(root->m_left, LevelNum - 1, vres);
	//			LevelOrder_Recursive(root->m_right, LevelNum - 1,vres);
	//		}
	//	}
	//	return vres;
	//}

	vector<int> LevelNodeNums()//��ÿ��ڵ����
	{
		queue<TreeNode<T>*> qtmp;
		vector<int> vres;//ģ���ػ�Ϊint����ڵ����
		if (!m_root)
		{
			return vres;
		}
		int length = 1;
		TreeNode<T>* cur = m_root;
		qtmp.push(cur);//�Ƚ����ڵ�push��ȥ
		while (!qtmp.empty())
		{
			vres.push_back(length);
			for (int i = 0; i < length; i++)
			{
				cur = qtmp.front();
				qtmp.pop();
				if (cur->m_left)
				{
					qtmp.push(cur->m_left);
				}

				if (cur->m_right)
				{
					qtmp.push(cur->m_right);
				}
			}//forѭ���������ʹ���һ�����
			length = qtmp.size();
		}
		return vres;
	}

	vector<T> LevelNodeMax()//��ÿ��ڵ�����ֵ
	{
		queue<TreeNode<T>*> qtmp;
		vector<T> vres;
		T Max;
		int length = 1;
		TreeNode<T>* cur = m_root;
		if (!m_root)
		{
			return vres;
		}
		qtmp.push(cur);//�Ƚ����ڵ�push��ȥ

		while (!qtmp.empty())
		{
			Max = qtmp.front()->m_val;
			for (int i = 0; i < length; i++)//lengthΪ���Ľڵ�����һ��forѭ��Ϊһ�����
			{
				cur = qtmp.front();
				if (Max < qtmp.front()->m_val)
				{
					Max = qtmp.front()->m_val;
				}
				qtmp.pop();

				if (cur->m_left)
				{
					qtmp.push(cur->m_left);
				}

				if (cur->m_right)
				{
					qtmp.push(cur->m_right);
				}
			}//forѭ���������ʹ���һ�����
			vres.push_back(Max);
			length = qtmp.size();
		}
		return vres;
	}

	vector<T> LevelNodeAverage()//��ÿ��ڵ��ƽ��ֵ
	{
		queue<TreeNode<T>*> qtmp;
		vector<T> vres;
		T sum = 0;//һ��ڵ�ֵ���ܺͣ������п���Ϊint float ,double��ģ��
		T average;//һ��ڵ�ƽ��ֵ������ʹ��ģ�����ͣ�������������Ը�
		int length = 1;//һ��ڵ����
		TreeNode<T>* cur = m_root;

		if (!m_root)
		{
			return vres;
		}

		qtmp.push(cur);//�Ƚ����ڵ�push��ȥ

		while (!qtmp.empty())
		{
			for (int i = 0; i < length; i++)//lengthΪ���Ľڵ�����
			{
				cur = qtmp.front();
				sum += qtmp.front()->m_val;//���������н��ֵ���
				qtmp.pop();

				if (cur->m_left)
				{
					qtmp.push(cur->m_left);
				}

				if (cur->m_right)
				{
					qtmp.push(cur->m_right);
				}
			}//forѭ���������ʹ���һ�����
			average = sum / length;//�����ƽ��ֵ
			sum = 0; //sum ��0��Ϊ��һ����׼��
			vres.push_back(average);
			length = qtmp.size();//���еĳ��Ⱦ�����һ����ĸ���
		}
		return vres;
	}


	//���������Ķ�����������任ΪԴ�������ľ���
	//void  Mirror(TreeNode<T>* root)//�ݹ��
	//{
	//	if (!root)
	//	{
	//		return;
	//	}


	//}

	void  Mirror()//�ǵݹ��
	{
		queue<TreeNode<T>*> qtmp;
		if (!m_root)
		{
			return ;
		}
		TreeNode<T>* cur = m_root;
		qtmp.push(cur);//�Ƚ����ڵ�push��ȥ
		while (!qtmp.empty())
		{
			cur = qtmp.front();
			swap(cur->m_left, cur->m_right);
			qtmp.pop();
			if (cur->m_left)
			{
				qtmp.push(cur->m_left);
			}

			if (cur->m_right)
			{
				qtmp.push(cur->m_right);
			}
		}
	}

	TreeNode<T>* lowestCommonAncestor(TreeNode<T>* p, TreeNode<T>* q)//��С�������Ƚڵ�
	{
		TreeNode<T>* cur = m_root;
		stack<TreeNode<T>*> stmp;
		stack<bool> tag;
		stack<TreeNode<T>*> s1;
		stack<TreeNode<T>*> s2;
		//�˷������ú������ ���ӱ������ȳ����ص�
		if (!cur && !p && !q)
		{
			return nullptr;
		}

		do
		{
			for (; cur; cur = cur->m_left)//�����е�����
			{
				stmp.push(cur);
				tag.push(false);//���ʱ�־λ��false
			}

			while (!stmp.empty() && tag.top())
			{
				cur = stmp.top();//�ҵ�����ڵ�ʱ�������s1ջ�������stmpջ������¼�˴Ӹ��ڵ㵽p�ڵ��·��
				//ͬ���ķ���,ʹs2ջҲ����stmp,��¼�Ӹ��ڵ㵽q�ڵ��·��
				if (p == cur || q == cur)//s1��s2�ǽڵ�ĵ�ַ��������Ψһ�ģ����õ����ظ�
				{
					if (s1.empty())//˭Ϊ�ո�˭
					{
						s1 = stmp;
					}

					else
					{
						s2 = stmp;
					}
				}
				stmp.pop();
				tag.pop();
			}

			if (!stmp.empty())
			{
				cur = stmp.top()->m_right;
				tag.top() = true;
			}
		} while (!stmp.empty());

		if (s1.size() < s2.size())//ʹs1��Ϊһ������ջ
		{
			swap(s1, s2);
		}

		int i;
		int len = s1.size() - s2.size();
		for (i = 0; i < len; i++)//����������
		{
			s1.pop();
		}
		while (s1.top() != s2.top())//����������ȣ�����ͬ���Ǹ����Ⱦͺ���
		{
			s1.pop();
			s2.pop();
		}
		return s1.top();
	}
};
