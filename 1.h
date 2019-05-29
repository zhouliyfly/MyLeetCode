#ifndef _1_H
#define _1_H
#include <vector>
#include <random> //std::default_random_engine, std::uniform_int_distribution
#include <ctime> //std::time
#include <unordered_map>

/*
 ��������˼·��һ����������Ȼ��ʹ�ö�ײָ�룻�ڶ�����ʹ��hash����ǰһ�ָ��򵥣�ʱ�临�Ӷ�
 O(nlgn)����һ��˼·�����ӣ�ʱ�临�Ӷ�O(n)
 */
class Solution_1 {
public:
	std::vector<int> twoSum1(std::vector<int>& nums, int target) {
		if (nums.empty())
			return {};

		std::vector<decltype(nums.size())> index;
		for (decltype(nums.size()) i = 0; i != nums.size(); ++i)
			index.push_back(i);

		__quick_sort(nums, index);

		decltype(index.size()) j = 0;
		decltype(index.size()) k = index.size() - 1;
		while (j < k) {
			if (nums[index[j]] + nums[index[k]] == target) {
				return { int(index[j]), int(index[k]) };
			}
			else if (nums[index[j]] + nums[index[k]] < target) {
				j++;
			}
			else { //nums[index[j]] + nums[index[k]] > target
				k--;
			}
		}
		return {};
	}

	// ʱ�临�Ӷ�O(n)
	std::vector<int> twoSum2(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> m;
		for (decltype(nums.size()) i = 0; i < nums.size(); ++i) {
			auto item = m.find(target - nums[i]);
			if (item != m.end()) {
				return { item->second, int(i) };
			}
			m[nums[i]] = i;
		}
		return {};
	}

private:
	void __quick_sort(std::vector<int>& nums, std::vector<decltype(nums.size())>& index) {
		
		__quick_sort(nums, index, 0, nums.size());
	}

	void __quick_sort(std::vector<int>& nums, std::vector<decltype(nums.size())>& index,
			std::vector<int>::size_type l,
			std::vector<int>::size_type r) {
		if (l + 1 >= r)
			return;

		//���ѡȡ
		std::default_random_engine e;
		std::uniform_int_distribution<unsigned int> u(l, r - 1);
		e.seed(static_cast<unsigned int>(time(0)));
		std::swap(index[l], index[u(e)]);

		//partition
		// [l+1...j)<p, [j,k)=p, [k, r)>p
		int v = nums[index[l]];
		decltype(index.size()) j = l + 1;
		decltype(index.size()) k = r;

		for (decltype(index.size()) i = l + 1; i < k; /**/) {
			if (nums[index[i]] < v) {
				if (i != j)
					std::swap(index[i], index[j]);
				i++;
				j++;
			}
			else if (nums[index[i]] > v) {
				std::swap(index[i], index[--k]);
			}
			else { //nums[index[i]] == v
				i++;
			}
		}
		std::swap(index[l], index[j - 1]);

		__quick_sort(nums, index, l, j - 1);
		__quick_sort(nums, index, k, r);
	}
};
#endif // !_1_H
