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
//	TreeNode*  push(T* src);
//	//ͨ��ǰ�����������"ABDG##H#J###CE##FI###"����������
//	{
//		static int s_n = 0;//���徲̬������¼�����±�
//		if (src[s_n] == '#')//
//		{
//			s_n++;//�±�+1���ݹ����ֱ�ӷ�����һ��
//			return nullptr;
//		}
//		TreeNode* cur = new TreeNode();
//		cur->_data = src[s_n];
//		s_n++;//�±�+1���ݹ����ֱ�ӷ�����һ��
//		cur->lchild = BinaryTreeCreate(src);//���Һ��ӵݹ����
//		cur->rchild = BinaryTreeCreate(src);
//		return cur;
//	}
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
//class Solution 
//{
//public:
//	vector<int> preorderTraversal(TreeNode* root) {
//
//	}
//};


//vector<int> preorderTraversal(TreeNode* root)
//{
//	vector
//		static int count = 1;
//	if (count == 1)
//	{
//		cout << "[";
//	}
//
//	if (root)
//	{
//
//		count++;
//		cout << root->val;
//		if (root->left || root->right)
//		{
//			cout << ",";
//		}
//		preorderTraversal(root->left);
//		preorderTraversal(root->right);
//		cout << "]" << endl;
//	}
//}
int main1()
{
	system("pause");
	return 0;
}//



//2.�����沨����ʾ��������ʽ��ֵ��
//
//��Ч����������� + , -, *, / ��ÿ��������������������Ҳ��������һ���沨�����ʽ��
//
//˵����
//
//
//��������ֻ�����������֡�
//�����沨�����ʽ������Ч�ġ����仰˵�����ʽ�ܻ�ó���Ч��ֵ�Ҳ����ڳ���Ϊ 0 �������
//
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


class Solution {
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

int main()
{
	vector<string> vs{ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	Solution Solute;
	cout << Solute.evalRPN(vs) << endl;
	system("pause");
	return 0;
}