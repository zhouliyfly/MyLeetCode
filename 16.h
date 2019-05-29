#ifndef _16_H //最接近的三数之和
#define _16_H
#include <vector>
#include <algorithm>

class Solution_16 {
public:
	int threeSumClosest(std::vector<int>& nums, int target) {
		if (nums.size() < 3)
			return 0;

		std::sort(nums.begin(), nums.end());
		int res = nums[0] + nums[1] + nums[2];
		for (decltype(nums.size()) i = 0; i != nums.size() - 2; ++i) {
			// twoSum
			decltype(nums.size()) j = i + 1;
			decltype(nums.size()) k = nums.size() - 1;
			while (j < k) {
				int tmp_sum = nums[i] + nums[j] + nums[k];
				if (std::abs(tmp_sum - target) < std::abs(res - target)) {
					res = tmp_sum;
				}
				if (tmp_sum < target) {
					j++;
				}
				else if (tmp_sum > target) {
					k--;
				}
				else { //tmp_sum == target
					return res;
				}
			}
		}
		return res;
	}
};
#endif // !_16_H

