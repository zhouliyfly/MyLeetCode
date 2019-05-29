#ifndef _454_H
#define _454_H
#include <vector>
#include <unordered_map>

class Solution_454 {
public:
	int fourSumCount(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, std::vector<int>& D) {
		if (A.empty())
			return 0;

		// B+C--->map
		std::unordered_map<int, int> m;
		for (decltype(C.size()) i = 0; i != C.size(); ++i) {
			for (decltype(D.size()) j = 0; j != D.size(); ++j) {
				m[C[i] + D[j]]++;
			}
		}
		int res = 0;
		for (decltype(A.size()) i = 0; i != A.size(); ++i) {
			for (decltype(B.size()) j = 0; j != A.size(); ++j) {
				auto item = m.find(0 - A[i] - B[j]);
				if (item != m.end()) {
					res += item->second;
				}
			}
		}
		return res;
	}
};
#endif // !_454_H

