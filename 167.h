#ifndef _167_H //两数之和 II - 输入有序数组
#define _167_H
#include <vector>
#include <stdexcept> //std::invalid_argument

class Solution_167 {
public:
	// 使用二分查找
	std::vector<int> twoSum1(std::vector<int>& numbers, int target) {
		for (decltype(numbers.size()) i = 0; i != numbers.size(); ++i) {
			int res = binary_search(numbers, i + 1, numbers.size(), target - numbers[i]);
			if (res != -1) {
				return { int(i + 1), int(res + 1) };
			}
		}
		throw std::invalid_argument("invalid argument");
	}

	// 对撞指针
	std::vector<int> twoSum(std::vector<int>& numbers, int target) {
		decltype(numbers.size()) i = 0;
		decltype(numbers.size()) j = numbers.size() - 1;
		
		while (i < j) {
			if (numbers[i] + numbers[j] == target)
				return { int(i + 1), int(j + 1) };
			else if (numbers[i] + numbers[j] < target)
				i++;
			else //numbers[i] + numbers[j] > target
				j--;
		}
		throw std::invalid_argument("invalid argument");
	}

private:
	int binary_search(std::vector<int>& numbers, size_t l, size_t r, int target) {
		if (l >= r)
			return -1;

		if (numbers[l + (r - l) / 2] < target) {
			return binary_search(numbers, l + (r - l) / 2 + 1, r, target);
		}
		else if (numbers[l + (r - l) / 2] > target) {
			return binary_search(numbers, l, l + (r - l) / 2, target);
		}
		else { //numbers[l + (r - l) / 2] == target
			return l + (r - l) / 2;
		}
	}
};
#endif // !_167_H

