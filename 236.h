#ifndef _236_H //�������������������
#define _236_H
#include "MyUtility.h"
#include <algorithm>

class Solution_236 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p == q)
			return p;

		std::vector<TreeNode*> vec;
		int count = 0;
		preOrder(root, p, q, vec, count);
		int i = std::find(vec.begin(), vec.end(), p) - vec.begin();
		int j = std::find(vec.begin(), vec.end(), q) - vec.begin();
		int index = std::min(i, j);
		for (int k = index; k >= 0; k--) {
			if (search(vec[k], vec[vec.size()-1])) {
				return vec[k];
			}
		}
		throw std::invalid_argument("error");
	}

private:
	void preOrder(TreeNode* root, TreeNode* p, TreeNode* q, std::vector<TreeNode*>& vec, int& count) {
		if (root && count < 2) {
			if (root->val == p->val || root->val == q->val)
				count++;
			vec.push_back(root);
			if (count == 2)
				return;
			preOrder(root->left, p, q, vec, count);
			preOrder(root->right, p, q, vec, count);
		}
	}

	bool search(TreeNode* root, TreeNode* node) {
		if (root == nullptr)
			return false;
		if (root == node)
			return true;

		return search(root->left, node) ||
			search(root->right, node);
	}

public:
	// ��root��Ѱ��p��q
	// ���p��q����root���ڵĶ�������, �򷵻�LCA
	// ���p��qֻ��һ����root���ڵĶ�������, �򷵻�p����q
	// ���p��q������root���ڵĶ�������, �򷵻�NULL
	TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
		// �ݹ��������
		if (root == nullptr)
			return root;
		if (root == p || root == q)
			return root;
		
	    // �ݹ����
		TreeNode* left = lowestCommonAncestor2(root->left, p, q);
		TreeNode* right = lowestCommonAncestor2(root->right, p, q);

		// �ж��������������ǰע��
		if (left != nullptr && right != nullptr)
			return root;
		if (left != nullptr)
			return left;
		if (right != nullptr)
			return right;

		return nullptr;
	}
};
#endif // !_236_H
