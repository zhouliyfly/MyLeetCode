#ifndef _209_H //长度最小的子数组
#define _209_H
#include <vector>
#include <algorithm> //std::min

class Solution_209 { //滑动窗口（双指针）
public:
	int minSubArrayLen(int s, std::vector<int>& nums) {
#if 0
		//滑动窗口[i...j)
		decltype(nums.size()) i = 0;
		decltype(nums.size()) j = 0;

		int sz = nums.size() + 1; //子数组最小个数
		int sum = 0;

		while (i < nums.size()) {
			while (j < nums.size() && sum < s) {
				sum += nums[j++];
			}
			if (sum < s)
				break;

			if (sum >= s) {
				sz = std::min(sz, int(j - i));
				sum -= nums[i++];
			}
		}
		return sz == nums.size() + 1 ? 0 : sz;
#endif // 一种写法
		//滑动窗口[i...j)
		decltype(nums.size()) i = 0;
		decltype(nums.size()) j = 0;

		int sz = nums.size() + 1; //子数组最小个数
		int sum = 0;

		while (i < nums.size()) {
			if (j < nums.size() && sum < s) {
				sum += nums[j++];
			}
			else {
				sum -= nums[i++];
			}
			if (sum >= s) {
				sz = std::min(sz, int(j - i));
			}
		}
		return sz == nums.size() + 1 ? 0 : sz;
	}
};
#endif // !_209_H

