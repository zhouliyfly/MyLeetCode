#ifndef _80_H //ɾ�����������е��ظ��� II
#define _80_H
#include <vector>

class Solution_80 {
public:
	int removeDuplicates(std::vector<int>& nums) {
		if (nums.empty())
			return 0;

		decltype(nums.size()) k = 1; //[0...k) �ظ������2�������飬��ʼ״̬��һ��Ԫ��
		size_t n = 1;

		for (decltype(nums.size()) i = 1; i != nums.size(); ++i) {
			if (nums[i] != nums[k-1]) {
				if (i != k) {
					std::swap(nums[i], nums[k++]);
				}
				else {
					k++;
				}
				n = 1; //�ظ������ָ�Ϊ1
			}
			else {
				if (n < 2) { //�ظ�����������2���˴����趨�����ظ�����
					if (i != k) {
						std::swap(nums[i], nums[k++]);
					}
					else {
						k++;
					}
				}
				n++;
			}
		}

		return k;
	}
};
#endif // !_80_H
