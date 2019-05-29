#ifndef _104_H //二叉树的最大深度
#define _104_H
#include "MyUtility.h"

#include <algorithm>
#include <queue>

class Solution_104 {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;

		return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}

	// 非递归实现
	int maxDepth2(TreeNode* root) {
		if (root == nullptr)
			return 0;

		int step = 1;
		std::queue<std::pair<TreeNode*, int>> q;
		q.push(std::make_pair(root, 1));
		while (!q.empty()) {
			TreeNode* node = q.front().first;
			step = q.front().second;
			q.pop();
			if (node->left)
				q.push(std::make_pair(node->left, step + 1));
			if (node->right)
				q.push(std::make_pair(node->right, step + 1));
		}
		return step;
	}
};
#endif // !_104_H

