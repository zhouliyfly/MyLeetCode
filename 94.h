#ifndef _94_H //二叉树的中序遍历
#define _94_H
#include <vector>
#include <stack>
#include <cassert>
#include "MyUtility.h"

class Solution_94 {
public:
	std::vector<int> inorderTraversal(TreeNode* root) {
		if (!root)
			return {};

		std::vector<int> res;
		std::stack<Command> sk;

		sk.push(Command(CommandType::Go, root));
		while (!sk.empty()) {
			Command command = sk.top();
			sk.pop();
			if (command._commandtype == CommandType::Print)
				res.push_back(command._node->val);
			else {
				assert(command._commandtype == CommandType::Go);
				if (command._node->right)
					sk.push(Command(CommandType::Go, command._node->right));
				sk.push(Command(CommandType::Print, command._node));
				if (command._node->left)
					sk.push(Command(CommandType::Go, command._node->left));
			}
		}
		return res;
	}

	std::vector<int> inorderTraversal_2(TreeNode* root) {
		if (root == nullptr)
			return {};

		std::vector<int> res;
		std::stack<TreeNode*> s;

		TreeNode* node = root;
		while (true) {
			visitAlong(node, s);
			if (s.empty())
				break;
			
			node = s.top();
			s.pop();
			res.push_back(node->val);
			node = node->right;
		}
		return res;
	}
	void visitAlong(TreeNode* node, std::stack<TreeNode*>& s) {
		while (node) {
			s.push(node);
			node = node->left;
		}
	}
};
#endif // !_94_H

