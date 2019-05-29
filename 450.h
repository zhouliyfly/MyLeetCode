#ifndef _450_H //删除二叉搜索树中的节点
#define _450_H
#include "MyUtility.h"
class Solution_450 {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr)
			return root;

		if (root->val == key) {
			TreeNode* delNode = root;
			if (root->left == nullptr) {
				root = root->right;
				delete delNode;
				return root;
			}			
			if (root->right == nullptr) {
				root = root->left;
				delete delNode;
				return root;
			}

			TreeNode* rightMin = getMin(root->right);
			TreeNode* min = new TreeNode(rightMin->val);
			root->right = delMin(root->right);
			min->left = root->left;
			min->right = root->right;		
			delete delNode;

			return min;
		}

		else if (root->val > key)
			root->left = deleteNode(root->left, key);
		else // root->val < key
			root->right = deleteNode(root->right, key);

		return root;
	}
//private:
	TreeNode* delMin(TreeNode* root) {
		if (root == nullptr)
			return root;
		
		if (root->left == nullptr) {
			TreeNode* rightNode = root->right;
			delete root;
			return rightNode;
		}
		root->left = delMin(root->left);
		return root;
	}

	TreeNode* getMin(TreeNode* root) {
		if (root == nullptr)
			return root;

		while (root->left) {
			root = root->left;
		}
		return root;
	}
};
#endif // !_450_H

