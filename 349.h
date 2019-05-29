#ifndef _349_H
#define _349_H
#include <vector>
#include <unordered_set>

class Solution_349 {
public:
	std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::unordered_set<int> set1(nums1.begin(), nums1.end());

		std::unordered_set<int> res;
		for (auto item = nums2.begin(); item != nums2.end(); ++item) {
			if (set1.find(*item) != set1.end())
				res.insert(*item);
		}
		return std::vector<int>(res.begin(), res.end());
	}
};
#endif // !_349_H

