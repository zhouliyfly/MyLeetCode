#ifndef _404_H
#define _404_H
#include "MyUtility.h"
#include <queue>

class Solution_404 {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == nullptr)
			return 0;

		if (root->left && root->left->left == nullptr && root->left->right == nullptr)
				return sumOfLeftLeaves(root->right) + root->left->val;
		return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
	}

	// �ǵݹ�ʵ��
	int sumOfLeftLeaves2(TreeNode* root) {
		if (root == nullptr)
			return 0;

		int sum = 0;
		std::queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop();
			
			if (node->left) {
				// node����Ҷ�ӽڵ�
				if (node->left->left == nullptr && node->left->right == nullptr)
					sum += node->left->val;
				else // ���Ӳ���Ҷ�ӽڵ�
					q.push(node->left);
			}
			if(node->right)
				q.push(node->right);
		}
		return sum;
	}
};
#endif // !_404_H
