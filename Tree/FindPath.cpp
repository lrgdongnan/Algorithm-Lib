//ʱ�䣺2016-08-29
//��Ŀ���������ɫ·��
//��Ŀ��Դ��ţ����
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
	int maxLen = 0;					//��¼�·��ֵ��һ��Ҫ����ֵ��

	//��ȡ·������
	int getPath(TreeNode *root){

		if (root == NULL){
			return 0;
		}

		//��¼����������󳤶�
		int left = 0;
		int right = 0;

		//����������
		if (root->left != NULL){
			int ret = getPath(root->left);			//����������󳤶�

			//�������ڵ����������ɫһ��
			if (root->val == root->left->val){
				left = ret;							//���գ�����û�н���
			}
		}

		//����������
		if (root->right != NULL){
			int ret = getPath(root->right);

			if (root->val == root->right->val){
				right = ret;
			}
		}

		//��¼��󳤶�ֵ���������������·��+���ڵ�+������
		maxLen = max(maxLen, (left + right + 1));

		//���ص�ǰ����������ڵ���ɫ��ͬ�������Ը�Ϊ�����·������
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
