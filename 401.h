#ifndef _401_H //二进制手表
#define _401_H
#include <vector>
#include <string>
#include <cassert>

class Solution_401 {
public:
	std::vector<std::string> readBinaryWatch(int num) {
		if (0 == num) {
			return std::vector<std::string>(1, "0:00");
		}

		std::vector<int> vec;
		getBinaryWatch(num, 0, vec);

		return res;
	}
private:
	void getBinaryWatch(int num, int index, std::vector<int>& vec) {
		if (vec.size() == num) {
			if (available(vec)) {
				res.push_back(vecToStr(vec));
			}
			return;
		}

		for (size_t i = index; i != times.size(); ++i) {
			if (!available(vec))
				break;
			vec.push_back(i);
			getBinaryWatch(num, i + 1, vec);
			vec.pop_back();
		}
	}

	bool available(std::vector<int>& vec) {
		int hours = 0;
		int minits = 0;
		for (size_t i = 0; i != vec.size(); ++i) {
			if (vec[i] < 4) {
				hours += times[vec[i]];
			}
			else
				minits += times[vec[i]];
		}
		if(hours > 11 || minits > 59)
			return false;
		return true;
	}

	std::string vecToStr(std::vector<int>& vec) {
		assert(!vec.empty());

		int hours = 0;
		int minits = 0;
		for (size_t i = 0; i != vec.size(); ++i) {
			if (vec[i] < 4) {
				hours += times[vec[i]];
			}
			else
				minits += times[vec[i]];
		}
		std::string h;
		std::string m;

		h = std::to_string(hours);
		if (minits < 10)
			m = "0" + std::to_string(minits);
		else
			m = std::to_string(minits);
		return h + ":" + m;
	}

private:
	std::vector<std::string> res;
	std::vector<int> times = { 1,2,4,8 ,1,2,4,8,16,32 };
	//const int minits[] = { 1,2,4,8,16,32 };
};
#endif // !_401_H

