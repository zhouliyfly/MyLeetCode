#ifndef _90_H //子集 II
#define _90_H
#include <vector>
#include <algorithm>

class Solution_90 {
public:
	std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
		res.push_back({});
		if (nums.empty())
			return res;

		visited.resize(nums.size(), false);
		std::sort(nums.begin(), nums.end());
		std::vector<int> vec;
		findsubsetsWithDup(nums, 0, vec);

		return res;
	}
private:
	void findsubsetsWithDup(std::vector<int>& nums, int index, std::vector<int>& vec) {
		for (size_t i = index; i != nums.size(); ++i) {
			if (i > 0 && nums[i - 1] == nums[i] && !visited[i-1]) //去除重复元素
				continue;

			visited[i] = true;
			vec.push_back(nums[i]);
			res.push_back(vec);
			findsubsetsWithDup(nums, i + 1, vec);
			vec.pop_back();
			visited[i] = false;
		}
	}
private:
	std::vector<std::vector<int>> res;
	std::vector<bool> visited;
};
#endif // !_90_H

