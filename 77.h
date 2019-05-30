#ifndef _77_H //组合
#define _77_H
#include <vector>

class Solution_77 {
public:
	std::vector<std::vector<int>> combine(int n, int k) {
		if (n < 1 || k < 0 || k > n)
			return res;

		std::vector<int> vec;
		findcombine(n, k, 1, vec);
		return res;
	}
private:
	void findcombine(int n, int k, int index, std::vector<int>& vec) {
		if (vec.size() == k) {
			res.push_back(vec);
			return;
		}

		// 还剩n-i+1个数可以取
		// 还要取k-vec.size()个数
		// 因此k-vec.size() <= n-i+1 
		// i <= n+1-(k-vec.size())
		for (int i = index; i <= n + 1 - (k - (int)vec.size()); i++) {
			vec.push_back(i);
			findcombine(n, k, i + 1, vec);
			vec.pop_back();
		}
		return;
	}
private:
	std::vector< std::vector<int>> res;
};
#endif // !_77_H 

