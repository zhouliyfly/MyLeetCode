#ifndef _209_H //������С��������
#define _209_H
#include <vector>
#include <algorithm> //std::min

class Solution_209 { //�������ڣ�˫ָ�룩
public:
	int minSubArrayLen(int s, std::vector<int>& nums) {
#if 0
		//��������[i...j)
		decltype(nums.size()) i = 0;
		decltype(nums.size()) j = 0;

		int sz = nums.size() + 1; //��������С����
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
#endif // һ��д��
		//��������[i...j)
		decltype(nums.size()) i = 0;
		decltype(nums.size()) j = 0;

		int sz = nums.size() + 1; //��������С����
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
