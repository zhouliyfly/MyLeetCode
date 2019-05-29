#ifndef _108_H //将有序数组转换为二叉搜索树
#define _108_H
#include "MyUtility.h"
#include <vector>
class Solution_108 {
public:
	TreeNode* sortedArrayToBST(std::vector<int>& nums) {
		
		return insertNum(nums, 0, nums.size());
	}
private:
	TreeNode* insertNum(const std::vector<int>& nums, size_t l, size_t r) {
		if (l >= r)
			return nullptr;	
		if (l + 1 == r)
			return new TreeNode(nums[l]);

		size_t mid = l + (r - l) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = insertNum(nums, l, mid);
		root->right = insertNum(nums, mid + 1, r);

		return root;
	}
};
#endif // !_108_H

