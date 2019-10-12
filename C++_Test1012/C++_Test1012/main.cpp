#include<iostream>
#include<queue>
#include<vector>
using namespace std;


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
	vector<vector<int>> levelOrderBottom(TreeNode* root) 
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

		for (level = 0;!qu.empty(); level++)//��
		{
			int len = qu.size();
			for (int i = 0; i < len;i++)//lenΪÿһ��ĸ���
			{
				vres.push_back(vector<int>());
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
		for (int i = 0; i < level; i++)
		{
			cout << "[";
			for (int j = 0; j < vres[i].size(); j++)
			{
				cout << vres[i][j];
				if (j < vres[i].size() - 1)
				{
					cout << ",";
				}
			}
			cout << "]" << endl;
		}
		return vres;
	}

};
	
int main()
{
    TreeNode* root = new TreeNode(100);
	TreeNode* rootl = new TreeNode(1);
	TreeNode* rootr = new TreeNode(17);
	root->left = rootl;
	root->right = rootr;
	/*TreeNode* rootll = new TreeNode(39);
	TreeNode* rootlr = new TreeNode(48);
	rootl->left = rootll;
	rootl->right = rootlr;*/
	/*TreeNode* rootlrl = new TreeNode(12);
	TreeNode* rootlrll = new TreeNode(43);
	rootlr->left = rootlrl;
	rootlrl->left = rootlrll;*/
	TreeNode* rootrl = new TreeNode(9);
	TreeNode* rootrr = new TreeNode(90);
	rootr->left = rootrl;
	rootr->right = rootrr;
	Solution su;
	vector<vector<int>> iv;
	iv = su.levelOrderBottom(root);

	

    system("pause");
    return 0;
}