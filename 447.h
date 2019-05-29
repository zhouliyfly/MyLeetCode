#ifndef _447_H //�����ڵ�����
#define _447_H
#include <vector>
#include <unordered_map>

// ʱ�临�Ӷ�O(n^2), n<=500
// �ռ临�Ӷ�O(n)
class Solution_447 {
public:
	int numberOfBoomerangs(std::vector<std::pair<int, int>>& points) {
		if (points.size() < 3)
			return 0;

		int res = 0;
		for (decltype(points.size()) i = 0; i != points.size(); ++i) {
			std::unordered_map<int, int> record;
			for (decltype(points.size()) j = 0; j != points.size(); ++j) {
				if (i != j) {
					record[dis_square(points[i], points[j])]++;
				}
			}
			for (const auto& val : record) {
				res += val.second*(val.second - 1);
			}
		}
		return res;
	}
private:
	// ����㷶Χ[-10000, 10000]������ƽ�����ֵΪ 20000*20000�����Ͳ������
	int dis_square(const std::pair<int, int> x, const std::pair<int, int> y) {
		return (x.first - y.first)*(x.first - y.first) +
			(x.second - y.second)*(x.second - y.second);
	}
};
#endif // !_447_H
