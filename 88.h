#ifndef _88_H //�ϲ�������������
#define _88_H
#include <vector>

class Solution_88 {
public:
	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
		std::vector<int> tmp(nums1.begin(), nums1.end()); //����nums1���㹻�ռ䣬���ﲻ���Ż�����
		int j = 0;
		int k = 0;
		for (decltype(nums1.size())i = 0; i != m + n; ++i) {
			if (j >= m) {
				nums1[i] = nums2[k++];
			}
			else if (k >= n) {
				nums1[i] = tmp[j++];
			}
			else if (tmp[j] <= nums2[k]) {
				nums1[i] = tmp[j++];
			}
			else {
				nums1[i] = nums2[k++];
			}
		}
	}
};
#endif // !_88_H