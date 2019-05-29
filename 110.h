#ifndef _110_H //Æ½ºâ¶þ²æÊ÷
#define _110_H
#include "MyUtility.h"

#include <algorithm>

class Solution_110 {
public:
	bool isBalanced(TreeNode* root) {
		if (root == nullptr)
			return true;

		if (std::abs(nodeHeight(root->left) - nodeHeight(root->right)) > 1)
			return false;
		else {
			return isBalanced(root->left) && isBalanced(root->right);
		}
	}
private:

	int nodeHeight(TreeNode* root) {
		if (root == nullptr)
			return 0;

		return std::max(nodeHeight(root->left), nodeHeight(root->right)) + 1;
	}
};
#endif // !_110_H

