#ifndef _27_H //�Ƴ�Ԫ��
#define _27_H
#include <vector>

class Solution_27 { 
public:
	// ʱ�临�Ӷȣ�o(n)�� �ռ临�Ӷ�O(1)
	int removeElement(std::vector<int>& nums, int val) {
		decltype(nums.size()) k = 0; //[0,k)���Ƴ���Ԫ��

		for (decltype(nums.size()) i = 0; i != nums.size(); ++i) {
			if (nums[i] != val) {
				if (i != k) //������������
					std::swap(nums[i], nums[k++]);
				else
					k++;
			}
		}
		// ɾ��vector�д��Ƴ���Ԫ��
		nums.erase(nums.begin() + k, nums.end());

		return k;
	}
};
#endif // !_27_H
