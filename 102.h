#ifndef _102_H //二叉树的层次遍历（注意层号）
#define _102_H
#include "MyUtility.h"
#include <vector>
#include <queue>

class Solution {
public:
	std::vector<std::vector<int>> levelOrder(TreeNode* root) {
		if (root == nullptr)
			return {};

		std::vector<std::vector<int>> res;
		std::queue<std::pair<TreeNode*, int>> q;
		q.push(std::make_pair(root, 0));

		while (!q.empty()) {
			TreeNode* node = q.front().first;
			int level = q.front().second;
			q.pop();
			if (level == res.size())
				res.push_back(std::vector<int>());

			res[level].push_back(node->val);
			if (node->left)
				q.push(std::make_pair(node->left, level + 1));
			if (node->right)
				q.push(std::make_pair(node->right, level + 1));
		}
		return res;
	}
};
#endif // !_102_H

