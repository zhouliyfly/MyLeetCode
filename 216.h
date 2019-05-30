#ifndef _216_H //组合总和 III
#define _216_H
#include <vector>
#include <numeric>

// 回溯算法，注意剪枝
class Solution_216 {
public:
	std::vector<std::vector<int>> combinationSum3(int k, int n) {
		if (k > 9)
			return res;

		int minsum = 0;
		for (int i = 1; i <= k; i++) {
			minsum += i;
		}
		if (n < minsum)
			return res;

		int maxsum = 0;
		int j = 9;
		for (int i = 1; i <= k; i++, j--) {
			maxsum += j;
		}
		if (n > maxsum)
			return res;

		std::vector<int> vec;
		findcombinationSum3(1, 0, k,n, vec);

		return res;
	}
private:
	void findcombinationSum3(int m, int index, int k, int target, std::vector<int>& vec) {
		if (k == index && 0 == target) {
			res.push_back(vec);
			return;
		}
		if (index >= k)
			return;

		for (int i = m; i <= 9; i++) {
			if (target - i < 0) //剪枝1
				break;
			if (k == index && 0 == target - i) { //剪枝2
				vec.push_back(i);
				res.push_back(vec);
				vec.pop_back();
				break;
			}
			vec.push_back(i);
			findcombinationSum3(i + 1, index + 1, k, target - i, vec);
			vec.pop_back();
		}
	}
private:
	std::vector<std::vector<int>> res;
};
#endif // !_216_H

