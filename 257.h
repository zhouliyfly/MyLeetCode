#ifndef _257_H
#define _257_H
#include "MyUtility.h"
#include <vector>
#include <string>

class Solution_257 {
public:
	std::vector<std::string> binaryTreePaths(TreeNode* root) {
		if (root == nullptr)
			return {};

		std::vector<std::string> v;
		if (root->left == nullptr && root->right == nullptr)
			v.push_back(std::to_string(root->val));

		if (root->left) {
			std::vector<std::string> left = binaryTreePaths(root->left);
			for (size_t i = 0; i != left.size(); ++i) {
				v.push_back(std::to_string(root->val) + "->" + left[i]);
			}
		}
		if (root->right) {
			std::vector<std::string> right = binaryTreePaths(root->right);
			for (size_t i = 0; i != right.size(); ++i) {
				v.push_back(std::to_string(root->val) + "->" + right[i]);
			}
		}
		return v;
	}
};
#endif // !_257_H
