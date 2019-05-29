#ifndef _112_H //Â·¾¶×ÜºÍ
#define _112_H
#include "MyUtility.h"

class Solution_112 {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			return false;

		if (root->left == nullptr && root->right == nullptr)
			return sum == root->val;

		/*if (hasPathSum(root->left, sum - root->val))
			return true;
		if (hasPathSum(root->right, sum - root->val))
			return true;*/
		return hasPathSum(root->left, sum - root->val) ||
			hasPathSum(root->right, sum - root->val);
	}
};
#endif // !_112_H

