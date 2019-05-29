#ifndef _215_H //�����еĵ�K�����Ԫ��
#define _215_H
#include <vector>
#include <random> //std::default_random_engine
#include <ctime> //std::time

// ����Ҫ�󷵻ص�k�����Ԫ�أ����ǵ�k����ͬ��Ԫ�أ����ÿ���Ԫ���ظ����Լ�
class Solution_215 {
public:
	int findKthLargest(std::vector<int>& nums, int k) {
		// ���ÿ���˼·
		//assert(k <= nums.size() && k > 0); //�������k��Ч

		std::vector<int> v(nums.begin(), nums.end());
		int p = __findKthLargest(v, k, 0, nums.size());
		return v[p];
	}
private:
	int __findKthLargest(std::vector<int>& nums, int k, int l, int r) {
		int p = partition(nums, k, l, r);
		if (p < (int)nums.size() - k) {
			p = __findKthLargest(nums, k, p + 1, r);
		}
		else if (p > (int)nums.size() - k) {
			p = __findKthLargest(nums, k, l, p);
		}

		return p;
	}

	int partition(std::vector<int>& nums, int k, int l, int r) {
		//[l+1...j)<nums[p], [j...t)==p, [t...r)>nums[p]
		// 3·����
		int j = l + 1;
		int t = r;
		//int v = nums[l]; 
		//���ѡȡ
		std::default_random_engine e;
		std::uniform_int_distribution<int> u(l, r - 1);
		e.seed(static_cast<unsigned int>(std::time(0)));
		std::swap(nums[l], nums[u(e)]);
		int v = nums[l];

		for (int i = l + 1; i < t; /**/) {
			if (nums[i] < v) {
				std::swap(nums[i++], nums[j++]);
			}
			else if (nums[i] > v) {
				std::swap(nums[i], nums[--t]);
			}
			else { //nums[i] == v
				i++;
			}
		}
		std::swap(nums[l], nums[j - 1]);
		return j - 1;
	}
};
#endif // !_215_H
