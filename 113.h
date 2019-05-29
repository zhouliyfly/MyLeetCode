#ifndef _113_H
#define _113_H
#include "MyUtility.h"
#include <vector>

class Solution_113 {
public:
	std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			return {};

		std::vector<std::vector<int>> res;
		std::vector<int> vec;
		pathSum(root, sum, vec, res);
		return res;
	}
private:
	void pathSum(TreeNode* root, int sum, std::vector<int> vec, std::vector<std::vector<int>>& res) {
		if (root->left == nullptr && root->right == nullptr) {
			if (root->val == sum) {
				vec.push_back(root->val);
				res.push_back(vec);
			}	
			return;
		}

		vec.push_back(root->val);
		if (root->left) {
			pathSum(root->left, sum - root->val, vec, res);
		}
		if (root->right) {
			pathSum(root->right, sum - root->val, vec, res);
		}
	}
};
#endif // !_113_H

