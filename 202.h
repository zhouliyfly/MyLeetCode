#ifndef _202_H
#define _202_H
#include <unordered_set>

class Solution_202 {
public:
	bool isHappy(int n) {
		std::unordered_set<long long> record;
		long long num = n;
		while (true) {
			long long sum = 0;
			int i;
			while (num) {
				i = num % 10;
				num = num / 10;
				sum += i * i;
			}
			if (sum == 1)
				return true;
			if (record.find(sum) != record.end())
				return false;
			record.insert(sum);
			num = sum;
		}
	}
};
#endif // !_202_H

