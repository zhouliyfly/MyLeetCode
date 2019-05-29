#ifndef _111_H //二叉树的最小深度
#define _111_H
#include "MyUtility.h"
#include <algorithm>
#include <queue>

class Solution_111 {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;

		if (root->left == nullptr && root->right == nullptr)
			return 1;
		int res = INT_MAX;
		if (root->left != nullptr)
			res = std::min(minDepth(root->left) + 1, res);
		if (root->right != nullptr)
			res = std::min(minDepth(root->right) + 1, res);
		return res;

	}

	// 非递归实现
	int minDepth2(TreeNode* root) {
		if (root == nullptr)
			return 0;

		int res = 1;
		std::queue<std::pair<TreeNode*,int>> q;
		q.push(std::make_pair(root, 1));
		while (!q.empty()) {
			TreeNode* node = q.front().first;
			int step = q.front().second;
			q.pop();
			if (node->left == nullptr && node->right == nullptr) {
				res = step;
				break;
			}	
			if (node->left)
				q.push(std::make_pair(node->left, step + 1));
			if (node->right)
				q.push(std::make_pair(node->right, step + 1));
		}
		return res;
	}
};
#endif // !_111_H

