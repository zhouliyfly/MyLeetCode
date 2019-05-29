#ifndef _47_H //全排列 II
#define _47_H
#include <vector>

class Solution_47 {
public:
	std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
		if (nums.empty())
			return {};

		visited.resize(nums.size(), false);
		std::sort(nums.begin(), nums.end()); // 先排序，同下面的条件匹配
		std::vector<int> v;
		findPermute(nums, 0, v);
		return vec;
	}
private:
	void findPermute(std::vector<int>& nums, int index, std::vector<int>& v) {
		if (index == nums.size()) {
			vec.push_back(v);
			return;
		}

		for (size_t i = 0; i != nums.size(); ++i) {
			if (!visited[i]) {
				if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) // 防止重复的条件
					continue;
				v.push_back(nums[i]);
				visited[i] = true;
				findPermute(nums, index + 1, v);
				v.pop_back();
				visited[i] = false;
			}
		}
	}
private:
	std::vector<std::vector<int>> vec;
	std::vector<bool> visited;
};
#endif // !_47_H

