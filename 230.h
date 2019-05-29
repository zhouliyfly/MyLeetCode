#ifndef _230_H //二叉搜索树中第K小的元素
#define _230_H
#include "MyUtility.h"
#include <iostream>
class Solution_230 {
public:
	// k有效
	int kthSmallest(TreeNode* root, int k) {
		int num = 1;
		int res = INT_MAX;
		inOrder(root, k, num, res);
		return res;
	}

private:
	void inOrder(TreeNode* root, int k, int& num, int& res) {
		if (root) {
			inOrder(root->left, k, num, res);
			if (num++ == k) {
				res = root->val;
				return;
			}
			inOrder(root->right, k, num, res);
		}
	}
};
#endif // !_230_H 
