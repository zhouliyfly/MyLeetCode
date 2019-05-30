#ifndef _78_H //×Ó¼¯
#define _78_H
#include <vector>
class Solution_78 {
public:
	std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
		res.push_back({});
		if (nums.empty())
			return res;

		std::vector<int> vec;
		findsubsets(nums, 0, vec);
		return res;
	}

private:
	void findsubsets(std::vector<int>& nums, int index, std::vector<int>& vec) {
		for (size_t i = index; i != nums.size(); ++i) {
			vec.push_back(nums[i]);
			res.push_back(vec);
			findsubsets(nums, i + 1, vec);
			vec.pop_back();
		}
		return;
	}
private:
	std::vector<std::vector<int>> res;
};
#endif // !_78_H

