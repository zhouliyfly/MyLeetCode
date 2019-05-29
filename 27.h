#ifndef _27_H //移除元素
#define _27_H
#include <vector>

class Solution_27 { 
public:
	// 时间复杂度：o(n)， 空间复杂度O(1)
	int removeElement(std::vector<int>& nums, int val) {
		decltype(nums.size()) k = 0; //[0,k)非移除的元素

		for (decltype(nums.size()) i = 0; i != nums.size(); ++i) {
			if (nums[i] != val) {
				if (i != k) //不和自身交换
					std::swap(nums[i], nums[k++]);
				else
					k++;
			}
		}
		// 删除vector中待移除的元素
		nums.erase(nums.begin() + k, nums.end());

		return k;
	}
};
#endif // !_27_H

