#ifndef _226_H
#define _226_H
#include "MyUtility.h"
#include <stack>

class Solution_226 {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr)
			return root;

		root->left = invertTree(root->left);
		root->right = invertTree(root->right);
		std::swap(root->left, root->right);
		return root;
	}

	// ·ÇµÝ¹é½â·¨
	TreeNode* invertTree2(TreeNode* root) {
		if (root == nullptr)
			return root;
		
		std::stack<TreeNode*> s;
		s.push(root);
		while (true) {
			TreeNode* node = s.top();
			s.pop();
			visistAlongLeft(node, s);
			if (s.empty())
				break;
		}
		return root;
	}
private:
	void visistAlongLeft(TreeNode* node, std::stack<TreeNode*>& s) {
		while (node) {
			std::swap(node->left, node->right);
			s.push(node->right);
			node = node->left;
		}
		

	}
};
#endif // !_226_H
