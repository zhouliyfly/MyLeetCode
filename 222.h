#ifndef _222_H
#define _222_H
#include "MyUtility.h"

class Solution_222 {
public:
	int countNodes(TreeNode* root) {
		if (root == nullptr)
			return 0;

		return countNodes(root->left) + countNodes(root->right) + 1;
	}
};
#endif // !_222_H

