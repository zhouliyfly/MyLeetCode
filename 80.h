#ifndef _80_H //删除排序数组中的重复项 II
#define _80_H
#include <vector>

class Solution_80 {
public:
	int removeDuplicates(std::vector<int>& nums) {
		if (nums.empty())
			return 0;

		decltype(nums.size()) k = 1; //[0...k) 重复项不超过2个的数组，初始状态有一个元素
		size_t n = 1;

		for (decltype(nums.size()) i = 1; i != nums.size(); ++i) {
			if (nums[i] != nums[k-1]) {
				if (i != k) {
					std::swap(nums[i], nums[k++]);
				}
				else {
					k++;
				}
				n = 1; //重复计数恢复为1
			}
			else {
				if (n < 2) { //重复次数不超过2，此处可设定允许重复次数
					if (i != k) {
						std::swap(nums[i], nums[k++]);
					}
					else {
						k++;
					}
				}
				n++;
			}
		}

		return k;
	}
};
#endif // !_80_H

