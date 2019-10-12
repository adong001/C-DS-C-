#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//����һ����������������ڵ�ֵ�Ե����ϵĲ�α����� 
//��������Ҷ�ӽڵ����ڲ㵽���ڵ����ڵĲ㣬���������ұ�����
//
//���磺
//����������[3, 9, 20, null, null, 15, 7],
//
//3
/// \
//9  20
/// \
//15   7
//
//
//�������Ե����ϵĲ�α���Ϊ��
//
//[
//	[15, 7],
//	[9, 20],
//	[3]
//]
//


struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
		val(x),
		left(NULL),
		right(NULL)
	{}
};
//1.�������������
class Solution {
public:
	vector<vector<int>> levelOrderBottom1(TreeNode* root)
	{
		vector<vector<int>> vres;
		queue<TreeNode*> qu;
		TreeNode* cur = root;

		int level;//����
		if (!root)
		{
			return vres;
		}

		qu.push(cur);

		for (level = 0; !qu.empty(); level++)//��
		{
			int len = qu.size();
			vres.push_back(vector<int>());
			for (int i = 0; i < len; i++)//lenΪÿһ��ĸ���
			{
				
				vres[level].push_back(cur->val);
				if (cur->left)//�ȿ����Ӵ���->���
				{
					qu.push(cur->left);
				}

				if (cur->right)//�ٿ��Һ��Ӵ���->���
				{
					qu.push(cur->right);
				}
				qu.pop();//pop�����´η��ʺ����Ԫ��
				if (!qu.empty())
				{
					cur = qu.front();//ȡ����
				}
			}
		}

		vector<vector<int>> vtmp;//���������������һ�����ϸ�ֵ��vtmp
		for (int i = level - 1; i >= 0; i--)
		{
			vtmp.push_back(vector<int>());
			for (int j = 0; j < vres[i].size(); j++)
			{
			
				vtmp[vres.size() - i - 1].push_back(vres[i][j]);
			}
		}

		for (int i = 0; i < level; i++)
		{
			cout << "[";
			for (int j = 0; j < vtmp[i].size(); j++)
			{
				cout << vtmp[i][j];
				if (j < vtmp[i].size() - 1)
				{
					cout << ",";
				}
			}
			cout << "]" << endl;
		}
		return vtmp;//���ؾ���Ķ�����
	}
};

int main1()
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
	Solution su;
	vector<vector<int>> iv;
	iv = su.levelOrderBottom1(root);
	system("pause");
	return 0;
}