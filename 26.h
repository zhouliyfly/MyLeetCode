#ifndef _26_H //删除排序数组中的重复项
#define _26_H
#include <vector>

class Solution_26 {
public:
	int removeDuplicates(std::vector<int>& nums) { //给定的是排序数组
		if (nums.empty())
			return 0;

		decltype(nums.size()) k = 1; //[0...k) 不含重复元素数组，初始有一个元素，满足不重复条件

		for (decltype(nums.size()) i = 1; i != nums.size(); ++i) {	
			if (nums[i] != nums[k-1]) {
				if (i != k) { 
					std::swap(nums[i], nums[k++]);
				}
				else { //i，k连续时不交换
					k++;
				}
				
			}
		}

		return k;
	}
};
#endif //!_26_H
