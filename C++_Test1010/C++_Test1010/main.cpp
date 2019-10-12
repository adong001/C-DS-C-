#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<cctype>
#include<cstdlib>
//1.����һ������������������ǰ�������
//template<class T>
//class TreeNode
//{
//private:
//	T m_data;  //�洢�˽ڵ������
//	TreeNode* m_lchild;  //�洢���ӵĵ�ַ
//	TreeNode* m_rchild; //�洢�Һ��ӵĵ�ַ
//public:
//	TreeNode() :
//		m_lchild(nullptr),
//		m_rchild(nullptr)
//	{}
//
//	//TreeNode<T>*  push(T* src);
//	////ͨ��ǰ�����������"ABDG##H#J###CE##FI###"����������
//	//{
//	//	static int s_n = 0;//���徲̬������¼�����±�
//	//	if (src[s_n] == '#')//
//	//	{
//	//		s_n++;//�±�+1���ݹ����ֱ�ӷ�����һ��
//	//		return nullptr;
//	//	}
//	//	TreeNode<T>* cur = new TreeNode<T>();
//	//	cur->_data = src[s_n];
//	//	s_n++;//�±�+1���ݹ����ֱ�ӷ�����һ��
//	//	cur->lchild = BinaryTreeCreate(src);//���Һ��ӵݹ����
//	//	cur->rchild = BinaryTreeCreate(src);
//	//	return cur;
//	//}
//
//	~TreeNode()
//	{
//		if (root != NULL)
//		{
//			BinaryTreePostOrder(root->lchild);
//			BinaryTreePostOrder(root->rchild);
//			free(root);
//		}
//	}
//};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
		val(x),
		left(NULL),
		right(NULL)
	{}
};
class Solution
{
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		TreeNode* cur = root;
		vector<int> vres;
		stack<TreeNode*> stmp;
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
		}while (cur != root) ;//��ջ��ֻ��һ����ʱ���˳�

		cout << "[";
		for (auto& i : vres)
		{
			cout << i << ",";
		}
		cout << "]";
		return vres;
	}
};


vector<int> preorderTraversal2(TreeNode* root)//�ݹ��
{
	static vector<int> res;
	if (root)
	{
		res.push_back(root->val);
		preorderTraversal2(root->left);
		preorderTraversal2(root->right);
	}
	return res;
}



int main()
{
	TreeNode* root = new TreeNode(100);
	TreeNode* rootl = new TreeNode(1);
	TreeNode* rootr = new TreeNode(17);
	root->left = rootl;
	root->right = rootr;
	TreeNode* rootll = new TreeNode(39);
	TreeNode* rootlr = new TreeNode(48);
	rootl->left = rootll;
	rootl->right = rootlr;
	TreeNode* rootlrl = new TreeNode(12);
	TreeNode* rootlrll = new TreeNode(43);
	rootlr->left = rootlrl;
	rootlrl->left = rootlrll;
	TreeNode* rootrl = new TreeNode(9);
	TreeNode* rootrr = new TreeNode(90);
	rootr->left = rootrl;
	rootr->right = rootrr;
	/*Solution s;
	s.preorderTraversal(root);*/

	vector<int> iv = preorderTraversal2(root);
	for (auto& i : iv)
	{
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}//



//2.�����沨����ʾ��������ʽ��ֵ��
//
//��Ч����������� + , -, *, / ��ÿ��������������������Ҳ��������һ���沨�����ʽ��

//��������ֻ�����������֡�
//�����沨�����ʽ������Ч�ġ����仰˵�����ʽ�ܻ�ó���Ч��ֵ�Ҳ����ڳ���Ϊ 0 �������

//
//ʾ�� 1��
//
//���� : ["2", "1", "+", "3", "*"]
// ��� : 9
//  ���� : ((2 + 1) * 3) = 9
//
//
//	   ʾ�� 2��
//
//   ���� : ["4", "13", "5", "/", "+"]
//	��� : 6
//	 ���� : (4 + (13 / 5)) = 6
//
//
//	ʾ�� 3��
//
//	  ���� : ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
//	   ��� : 22
//		���� :
//		   ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//		   = ((10 * (6 / (12 * -11))) + 17) + 5
//		   = ((10 * (6 / -132)) + 17) + 5
//		   = ((10 * 0) + 17) + 5
//		   = (0 + 17) + 5
//		   = 17 + 5
//		   = 22


class Solution2 {
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> tmp;
		int num1, num2;
		for (auto& i : tokens)
		{
			if (isdigit(i[0]) || i.size() > 1)
			{
				tmp.push(atoi(i.c_str()));
			}
			else
			{
				num1 = tmp.top();
				tmp.pop();
				num2 = tmp.top();
				switch (i[0])
				{
				case '+':
					tmp.top() = num2 + num1;
					break;
				case '-':
					tmp.top() = num2 - num1;
					break;
				case '*':
					tmp.top() = num2 * num1;
					break;
				case '/':
					tmp.top() = num2 / num1;
					break;
				}
			}
		}
		return tmp.top();
	}
};

int main2()
{
	vector<string> vs{ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	Solution2 Solute;
	cout << Solute.evalRPN(vs) << endl;
	system("pause");
	return 0;
}