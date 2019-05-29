#ifndef _437_H //Â·¾¶×ÜºÍ III
#define _437_H
#include "MyUtility.h"

class Solution_437 {
public:
	int pathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			return 0;

		int res = 0;
		res += findPath(root, sum);
		res += pathSum(root->left, sum);
		res += pathSum(root->right, sum);
			
		return res;
	}
private:
	int findPath(TreeNode* root, int sum) {
		if (root == nullptr)
			return 0;

		int res = 0;
		if (root->val == sum)
			res++;
		res += findPath(root->left, sum - root->val);
		res += findPath(root->right, sum - root->val);
		return res;
	}
};
#endif // !_437_H

