#ifndef _145_H
#define _145_H
#include "MyUtility.h"
#include <vector>
#include <stack>
#include <cassert>
#include <deque>

class Solution_145 {
public:
	std::vector<int> postorderTraversal(TreeNode* root) {
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
				sk.push(Command(CommandType::Print, command._node));
				if (command._node->right)
					sk.push(Command(CommandType::Go, command._node->right));
				if (command._node->left)
					sk.push(Command(CommandType::Go, command._node->left));
			}
		}
		return res;
	}

	std::vector<int> postorderTraversal_no_rec_1(TreeNode* root) {
		if (root == nullptr)
			return {};

		std::vector<int> res;
		std::stack<TreeNode*> s;
		std::stack<TreeNode*> tmp;
		s.push(root);
		while (!s.empty()) {
			TreeNode* node = s.top();
			s.pop();
			//res.push_back(node->val);
			tmp.push(node);
			if (node->left)
				s.push(node->left);
			if (node->right)
				s.push(node->right);
			
		}
		while (!tmp.empty()) {
			res.push_back(tmp.top()->val);
			tmp.pop();
		}
		return res;
	}

	std::vector<int> postorderTraversal_no_rec_2(TreeNode* root) {
		std::deque<int> res;
		std::stack<TreeNode*> s;
		TreeNode* node = root;
		while (true) {
			visitAlongLeft(node, res, s);
			if (s.empty()) break;
			node = s.top();
			s.pop();
		}
		return std::vector<int>(res.crbegin(), res.crend());
	}

	void visitAlongLeft(TreeNode* node, std::deque<int>& res, std::stack<TreeNode*>& s) {
		while (node) {
			res.push_front(node->val);
			s.push(node->left);
			node = node->right;
		}
	}
};
#endif // !_145_H

