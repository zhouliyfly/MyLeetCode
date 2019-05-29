#ifndef _129_H //求根到叶子节点数字之和
#define _129_H
#include "MyUtility.h"
#include <string>
#include <numeric>

class Solution_129 {
public:
	int sumNumbers(TreeNode* root) {
		if (root == nullptr)
			return 0;

		auto res = pathNums(root);
		return std::accumulate(res.begin(), res.end(), 0,
			[](int x, std::string s) {return x + std::stoi(s); });
	}
private:
	std::vector<std::string> pathNums(TreeNode* root) {
		std::vector<std::string> vec;
		if (root->left == nullptr && root->right == nullptr) {
			vec.push_back(std::to_string(root->val));
			return vec;
		}
		if (root->left) {
			auto resLeft = pathNums(root->left);
			for (size_t i = 0; i != resLeft.size(); ++i) {
				vec.push_back(std::to_string(root->val) + resLeft[i]);
			}
		}
		if (root->right) {
			auto resRight = pathNums(root->right);
			for (size_t i = 0; i != resRight.size(); ++i) {
				vec.push_back(std::to_string(root->val) + resRight[i]);
			}
		}
		return vec;
	}
};
#endif // !_129_H
