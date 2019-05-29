#ifndef _144_H // 二叉树的前序遍历
#define _144_H
#include "MyUtility.h"
#include <vector>
#include <cassert>

class Solution {
public:
	std::vector<int> preorderTraversal(TreeNode* root) {
		if (!root)
			return {};

		std::vector<int> res;
		preorder(root, res);
		return res;
	}

	std::vector<int> preorderTraversal_no_rec(TreeNode* root) {
		if (!root)
			return {};

		std::vector<int> res;
		std::stack<Command> sk;
		
		sk.push(Command(CommandType::Go, root));
		while (!sk.empty()) {
			Command c = sk.top();
			sk.pop();
			if (c._commandtype == CommandType::Print) {
				res.push_back(c._node->val);
			}
			else {
				assert(c._commandtype == CommandType::Go);
				if(c._node->right)
					sk.push(Command(CommandType::Go, c._node->right));
				if(c._node->left)
					sk.push(Command(CommandType::Go, c._node->left));
				sk.push(Command(CommandType::Print, c._node));
			}
		}

		return res;
	}

	std::vector<int> preorderTraversal_no_rec_2(TreeNode* root) {
		if (root == nullptr)
			return {};

		std::vector<int> res;
		std::stack<TreeNode*> s;
		s.push(root);

		while (!s.empty()) {
			TreeNode* node = s.top();
			s.pop();
			res.push_back(node->val);
			if (node->right)
				s.push(node->right);
			if (node->left)
				s.push(node->left);
		}
		return res;
	}

	std::vector<int> preorderTraversal_no_rec_3(TreeNode* root) {
		std::vector<int> res;
		std::stack<TreeNode*> s;

		TreeNode* node = root;
		while (true) {
			visitAlong(node, s, res);
			if (s.empty()) break;
			node = s.top();
			s.pop();
		}
		return res;
	}

	void visitAlong(TreeNode* node, std::stack<TreeNode*>& s, std::vector<int>& v) {
		while (node) {
			v.push_back(node->val);
			s.push(node->right);
			node = node->left;
		}
	}

private:
	void preorder(TreeNode* root, std::vector<int>& vec) {
		if (!root)
			return;

		vec.push_back(root->val);
		preorder(root->left, vec);
		preorder(root->right, vec);
	}
};
#endif // !_144_H

