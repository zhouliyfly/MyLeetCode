#ifndef _199_H //¶þ²æÊ÷µÄÓÒÊÓÍ¼
#define _199_H
#include "MyUtility.h"
#include <vector>
#include <queue>

class Solution {
public:
	std::vector<int> rightSideView(TreeNode* root) {
		if (root == nullptr)
			return {};

		std::vector<int> res;
		std::vector<std::vector<int>> vec;
		std::queue<std::pair<TreeNode*, int>> q;
		
		q.push(std::make_pair(root, 0));
		while (!q.empty()) {
			TreeNode* node = q.front().first;
			int level = q.front().second;
			q.pop();
			if (level == vec.size())
				vec.push_back(std::vector<int>());
			vec[level].push_back(node->val);
			if (node->left)
				q.push(std::make_pair(node->left, level + 1));
			if (node->right)
				q.push(std::make_pair(node->right, level + 1));
		}
		for (const auto& v : vec)
			res.push_back(*(v.end() - 1));

		return res;
	}
};
#endif // !_199_H 
