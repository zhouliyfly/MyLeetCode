#ifndef _347_H //前K个高频元素
#define _347_H
#include <vector>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <stack>

class Solution_347 {
public:
	std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
		assert(k >= 1);

		std::unordered_map<int, int> um;
		for (decltype(nums.size()) i = 0; i != nums.size(); ++i) {
			um[nums[i]]++;
		}

		assert((size_t)k <= um.size());

		std::priority_queue<std::pair<int,int>, std::vector<std::pair<int, int>>, 
			std::greater<std::pair<int, int>>> pq;
		for (const auto& p : um) {
			if(pq.size() < (size_t)k)
				pq.push(std::make_pair(p.second, p.first));
			else {
				int minfreq = pq.top().first;
				if (p.second > minfreq) {
					pq.pop();
					pq.push(std::make_pair(p.second, p.first));
				}
			}
		}
		
		std::vector<int> vec;
		std::stack<int> s;
		while (!pq.empty()) {
			s.push(pq.top().second);
			pq.pop();
		}
		while (!s.empty()) {
			vec.push_back(s.top());
			s.pop();
		}
		return vec;
	}
};
#endif // !_347_H 

