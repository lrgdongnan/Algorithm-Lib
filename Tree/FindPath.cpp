//时间：2016-08-29
//题目：树上最长单色路径
//题目来源：牛客网
//*******************************************************************************************

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class LongestPath {
public:
	int maxLen = 0;					//记录最长路径值（一定要赋初值）

	//获取路径长度
	int getPath(TreeNode *root){

		if (root == NULL){
			return 0;
		}

		//记录左右子树最大长度
		int left = 0;
		int right = 0;

		//处理左子树
		if (root->left != NULL){
			int ret = getPath(root->left);			//左子树的最大长度

			//如果这个节点和左子树颜色一样
			if (root->val == root->left->val){
				left = ret;							//接收，否则没有接收
			}
		}

		//处理右子树
		if (root->right != NULL){
			int ret = getPath(root->right);

			if (root->val == root->right->val){
				right = ret;
			}
		}

		//记录最大长度值，包含左子树最大路径+根节点+右子树
		maxLen = max(maxLen, (left + right + 1));

		//返回当前子树中与根节点颜色相同，并且以跟为起点的最长路径长度
		int t = max(left, right) + 1;
		return t;
	}


	int findPath(TreeNode *root){

		if (root == NULL){
			return 0;
		}

		getPath(root);

		return maxLen;
	}
};
