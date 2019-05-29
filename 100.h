#ifndef _100_H
#define _100_H
#include "MyUtility.h"

class Solution_100 {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr)
			return true;
		if (p == nullptr && q != nullptr)
			return false;
		if (p != nullptr && q == nullptr)
			return false;
		if (p->val != q->val)
			return false;

		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};
#endif // !_100_H

