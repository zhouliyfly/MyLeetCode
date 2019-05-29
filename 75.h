#ifndef _75_H //颜色分类
#define _75_H
#include <vector>

class Solution_75 {
public:
	void sortColors(std::vector<int>& nums) {
		// 借鉴3路快排
		// [0...j)==0, [j...k)==1, [k,n)==2
		decltype(nums.size()) j = 0;
		decltype(nums.size()) k = nums.size();

		for (decltype(nums.size()) i = 0; i != k; ) {
			if (nums[i] == 0) {
				if (i != k)
					std::swap(nums[i++], nums[j++]);
				else {
					j++;
					i++;
				}

			}
			else if (nums[i] == 2) {
				std::swap(nums[i], nums[--k]);
			}
			else //nums[i] == 1
				i++;
		}
	}
};
#endif // !_75_H

