#ifndef _26_H //ɾ�����������е��ظ���
#define _26_H
#include <vector>

class Solution_26 {
public:
	int removeDuplicates(std::vector<int>& nums) { //����������������
		if (nums.empty())
			return 0;

		decltype(nums.size()) k = 1; //[0...k) �����ظ�Ԫ�����飬��ʼ��һ��Ԫ�أ����㲻�ظ�����

		for (decltype(nums.size()) i = 1; i != nums.size(); ++i) {	
			if (nums[i] != nums[k-1]) {
				if (i != k) { 
					std::swap(nums[i], nums[k++]);
				}
				else { //i��k����ʱ������
					k++;
				}
				
			}
		}

		return k;
	}
};
#endif //!_26_H