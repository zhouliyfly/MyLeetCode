#ifndef _11_H //盛最多水的容器
#define _11_H
#include <vector>
#include <algorithm> //std::max

class Solution_11 {
public:
	int maxArea(std::vector<int>& height) {
		//assert(height.size()>=2)

		//从两端向中间移动
		//移动较长的直线不会导致容积增加，因为高度由段的直线决定，而宽度只会变小
		//移动较短的直线可能导致容积增加，虽然宽度变小，但是高度可能更高

		decltype(height.size()) i = 0;
		decltype(height.size()) j = height.size() - 1;
		int maxA = 0;

		while (i < j) {
			maxA = std::max(int(std::min(height[i], height[j])*(j - i)), maxA);
			if (height[i] < height[j]) {
				i++;
			}
			else { //height[i] >= height[j]
				j--;
			}
		}
		return int(maxA);
	}
};
#endif // !_11_H

