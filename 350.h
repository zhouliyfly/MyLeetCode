#ifndef _350_H
#define _350_H
#include <vector>
#include <unordered_map>

class Solution_350 {
public:
	std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::unordered_map<int, int> map;
		for (decltype(nums1.size()) i = 0; i != nums1.size(); ++i) {
			map[nums1[i]]++;
		}

		std::vector<int> res;
		for (auto item = nums2.begin(); item != nums2.end(); ++item) {
			if (map[*item] > 0) { //key不存在时，会创建key-value，value值为0
				res.push_back(*item);
			}
			map[*item]--;
		}
		return res;
	}
};
#endif // !_350_H
