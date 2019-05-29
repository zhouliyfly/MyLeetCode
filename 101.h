#ifndef _101_H
#define _101_H
#include "MyUtility.h"

#include <queue>

// 本题主要是找规律，何为对称，对称具体怎么描述？
class Solution_101 {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
			return true;

		return isSymmetric(root->left, root->right);

	}
private:
	bool isSymmetric(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr && root2 == nullptr)
			return true;
		if (root1 == nullptr || root2 == nullptr)
			return false;
		if (root1->val != root2->val)
			return false;

		return isSymmetric(root1->left, root2->right) &&
			isSymmetric(root1->right, root2->left);
	}

public:
	// 非递归实现
	bool isSymmetric2(TreeNode* root) {
		if (root == nullptr)
			return true;

		std::queue<TreeNode*> q1;
		std::queue<TreeNode*> q2;
		q1.push(root->left);
		q2.push(root->right);
		while (!q1.empty() && !q2.empty()) {
			TreeNode* note1 = q1.front();
			TreeNode* note2 = q2.front();
			q1.pop();
			q2.pop();

			if (note1 == nullptr && note2 == nullptr)
				continue;
			if (note1 == nullptr || note2 == nullptr)
				return false;
			if (note1->val != note2->val)
				return false;
			q1.push(note1->left);
			q1.push(note1->right);
			q2.push(note2->right);
			q2.push(note2->left);
		}
		return true;
	}
};
#endif // !_101_H

