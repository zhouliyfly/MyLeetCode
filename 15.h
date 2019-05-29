#ifndef _15_H //三数之和
#define _15_H
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <cassert>

class Solution_15 {
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		if (nums.size() < 3)
			return{};

		std::sort(nums.begin(), nums.end());
		std::set<std::vector<int>> set;
		for (decltype(nums.size()) i = 0; i != nums.size() - 2; ++i) {
			auto res = twoSum(nums, i + 1, nums.size(), 0 - nums[i]);
			if (!res.empty()) {
				set.insert(res.begin(), res.end());
			}
		}
		return std::vector<std::vector<int>>(set.begin(), set.end());
	}
private:
	// 要注意处理大量重复数据的情形，不然在线提交超时
	// 原因是当前算法的时间复杂度是O(n^2)，n过大时算法不可行
	std::vector<std::vector<int>> twoSum(const std::vector<int>& nums,
			std::vector<int>::size_type l, 
			std::vector<int>::size_type r, int target) {
		assert(l + 1 < r && nums.size() >= r);

		/*std::vector<std::vector<int>> res;
		std::unordered_set<int> set;
		for (decltype(nums.size()) i = l; i != r; ++i) {
			auto item = set.find(target - nums[i]);
			if (item != set.end()) {
				std::vector<int> tmp = { -target, *item, nums[i] };
				res.push_back(tmp);	
			}
			set.insert(nums[i]);
		}
		return res;*/

		std::vector<std::vector<int>> res;
		r--;
		while (l < r) {
			if (nums[l] + nums[r] == target) {
				res.push_back({ -target, nums[l++], nums[r--] });
				// 跳过重复数据
				while (l < r && nums[l] == nums[l - 1])
					l++;
				while (l < r && nums[r] == nums[r + 1])
					r--;
			}
				
			else if (nums[l] + nums[r] < target)
				l++;
			else //nums[l] + nums[r] > target
				r--;
		}
		return res;
	}
};
#endif // !_15_H

