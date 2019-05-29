#ifndef _107_H //二叉树的层次遍历 II（vector的reverse_iterator迭代器）
#define _107_H
#include "MyUtility.h"
#include <vector>
#include <queue>

class Solution {
public:
	std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
		if (root == nullptr)
			return {};

		std::vector<std::vector<int>> res;
		std::queue<std::pair<TreeNode*, int>> q;
		q.push(std::make_pair(root, 0));

		while (!q.empty()) {
			TreeNode* node = q.front().first;
			int level = q.front().second;
			if (level == res.size())
				res.push_back(std::vector<int>());
			q.pop();
			res[level].push_back(node->val);
			if (node->left)
				q.push(std::make_pair(node->left, level + 1));
			if (node->right)
				q.push(std::make_pair(node->right, level + 1));
		}
		return std::vector<std::vector<int>>(res.crbegin(), res.crend());
	}
};
#endif // !_107_H

