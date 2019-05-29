#ifndef _11_H //ʢ���ˮ������
#define _11_H
#include <vector>
#include <algorithm> //std::max

class Solution_11 {
public:
	int maxArea(std::vector<int>& height) {
		//assert(height.size()>=2)

		//���������м��ƶ�
		//�ƶ��ϳ���ֱ�߲��ᵼ���ݻ����ӣ���Ϊ�߶��ɶε�ֱ�߾�����������ֻ���С
		//�ƶ��϶̵�ֱ�߿��ܵ����ݻ����ӣ���Ȼ���ȱ�С�����Ǹ߶ȿ��ܸ���

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
