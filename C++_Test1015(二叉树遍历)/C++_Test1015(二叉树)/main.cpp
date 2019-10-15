#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

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
		} while (cur != root);//��ջ��ֻ��һ����ʱ���˳�

		cout << "[";
		for (auto& i : vres)
		{
			cout << i << ",";
		}
		cout << "]";
		return vres;
	}
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
	vector<int> inorderTraversal(TreeNode* root)
	{
		TreeNode* cur = root;
		vector<int> vres;
		stack<TreeNode*> stmp;

		if (!cur)
		{
			return vres;
		}
		stmp.push(cur);

		while (cur || !stmp.empty())//����ջ��Ϊ��ʱ����
		{
			for (; cur && cur->left; cur = cur->left)//�Ȱ����Ӷ���ջ
			{
				stmp.push(cur->left);
			}

			if (!stmp.empty())//ջ��Ϊ�գ�ȡջ����push��vres����pop.
			{
				cur = stmp.top();
				vres.push_back(cur->val);
				stmp.pop();
			}

			else //��ջΪ�գ�˵�����ĸ��ڵ������ѷ�����ϣ�ֱ�Ӹ�vres push������ֵ�������Һ���
			{
				vres.push_back(cur->val);
			}

			cur = cur->right;//��������
			if (cur) //�Һ����벻Ϊ�գ��Ȱ��Һ��ӵĸ�push��������
			{
				stmp.push(cur);
			}
		}

		cout << "[";
		for (auto& i : vres)
		{
			cout << i << ",";
		}
		cout << "]";
		return vres;

	}
	vector<int> inorderTraversal2(TreeNode* root)//�ݹ��
	{
		static vector<int> vres;
		if (root)
		{
			inorderTraversal2(root->left);
			vres.push_back(root->val);
			inorderTraversal2(root->right);
		}
		return vres;
	}

};





int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* rootl = new TreeNode(2);
	TreeNode* rootr = new TreeNode(3);
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
	Solution s;
	vector<int> iv;
	//s.preorderTraversal(root);
	//iv = preorderTraversal2(root);
	//iv = s.inorderTraversal(root);
	iv = s.inorderTraversal2(root);
	for (auto& i : iv)
	{
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}//


