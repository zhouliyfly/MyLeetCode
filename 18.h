#ifndef _18_H
#define _18_H
#include <vector>
#include <algorithm>
#include <cassert>

class Solution_18 {
public:
	std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
		if (nums.size() < 4)
			return {};

		std::vector<std::vector<int>> res;
		std::sort(nums.begin(), nums.end());
		for (decltype(nums.size()) i = 0; i != nums.size() - 3; ++i) {
			if (i != 0 && nums[i] == nums[i - 1])
				continue;
			auto tmp = __threeSum(nums, i + 1, nums.size(), target - nums[i]);
			for (auto& v : tmp)
				v.insert(v.begin(), nums[i]);
			res.insert(res.end(), tmp.begin(), tmp.end());
		}
		return res;
	}
private:
	std::vector<std::vector<int>> __threeSum(const std::vector<int>& nums, 
			std::vector<int>::size_type l, 
			std::vector<int>::size_type r, 
			int target) 
	{
		assert(l + 2 < r && nums.size() >= r);

		std::vector<std::vector<int>> res;
		for (decltype(nums.size()) i = l; i != r - 2; ++i) {
			if (i != l && nums[i] == nums[i - 1])
				continue;
			auto tmp = __twoSum(nums, i + 1, r, target - nums[i]);
			for (auto& v : tmp)
				v.insert(v.begin(), nums[i]);
			res.insert(res.end(), tmp.begin(), tmp.end());
		}
		return res;
	}

	std::vector<std::vector<int>> __twoSum(const std::vector<int>& nums,
		std::vector<int>::size_type l,
		std::vector<int>::size_type r, int target) {
		assert(l + 1 < r && nums.size() >= r);

		std::vector<std::vector<int>> res;
		r--;
		while (l < r) {
			if (nums[l] + nums[r] == target) {
				res.push_back({ nums[l++], nums[r--] });
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
#endif //!_18_H
