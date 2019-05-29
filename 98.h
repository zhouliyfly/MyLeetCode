#ifndef _98_H //ÑéÖ¤¶þ²æËÑË÷Ê÷
#define _98_H
#include "MyUtility.h"
#include <functional>

class Solution_98 {
public:
	bool isValidBST(TreeNode* root) {
		if (root == nullptr)
			return true;

		std::vector<int> vec;
		inorder(root, vec);
		return std::is_sorted(vec.begin(), vec.end(), std::less_equal<int>());
	}
private:
	void inorder(TreeNode* root, std::vector<int>& vec) {
		if (root) {
			inorder(root->left, vec);
			vec.push_back(root->val);
			inorder(root->right, vec);
		}
	}
};
#endif // !_98_H

