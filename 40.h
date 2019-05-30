#ifndef _40_H //组合总和 II
#define _40_H
#include <vector>
#include <algorithm>

class Solution_40 {
public:
	std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
		if (candidates.empty())
			return res;

		visited.resize(candidates.size(), false);
		std::sort(candidates.begin(), candidates.end());
		std::vector<int> vec;
		findcombinationSum2(candidates, target, 0, vec);

		return res;
	}
private:
	void findcombinationSum2(std::vector<int>& candidates, int target, int index, std::vector<int>& vec) {
		if (0 == target) {
			res.push_back(vec);
			return;
		}

		for (size_t i = index; i != candidates.size(); ++i) {
			if (target - candidates[i] < 0)
				break;
			if (i > 0 && candidates[i - 1] == candidates[i] && !visited[i - 1]) // 避免重复
				continue;

			visited[i] = true;
			vec.push_back(candidates[i]);
			findcombinationSum2(candidates, target - candidates[i], i + 1, vec);
			vec.pop_back();
			visited[i] = false;
		}
	}
private:
	std::vector<std::vector<int>> res;
	std::vector<bool> visited;
};
#endif // !_40_H

