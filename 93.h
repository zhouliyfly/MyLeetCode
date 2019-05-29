#ifndef _93_H //复原IP地址
#define _93_H
#include <string>
#include <vector>

#include <iostream>

// ip地址有4部分组成，每部分的数字在0~255之间
// 用回溯法，每部分可以选择1位数，2位数和3位数
// 注意：当选择2位数和3位数时，开头不能为0.如"012"

class Solution_93 {
public:
	std::vector<std::string> restoreIpAddresses(std::string s) {
		if (s.size() < 4)
			return {};

		findIpAddresses(s, 0, "");
		return vec;
	}

private:
	void findIpAddresses(std::string s, int index, std::string ip) {
		//std::cout << index << ":" << ip << std::endl;
		// ip地址4个部分组成，每个部分都有1/2/3种位数可选
		if (index == 3) {
			if (s.size() > 0 && s.size() <= 3) {
				if (s.size() > 1 && s[0] == '0')
					return;
				int ip3 = std::stoi(s);
				if (ip3 >= 0 && ip3 <= 255) {
					//std::cout << "get " << ip + "," + s << std::endl;
					vec.push_back(ip + "." + s);
				}
			}
			return;
		}
		// index < 3
		for (int i = 0; i < 3; i++) { //选取i+1位
			if (s.size() < i + 1)
				break;
			std::string sip0(s.begin(), s.begin() + i + 1);
			if (i > 0 && sip0[0] == '0')
				break;
			//std::cout << "index[" << index << "], use " << i << std::endl;
			int ip0 = std::stoi(sip0);
			if (ip0 >= 0 && ip0 <= 255) {
				if(index == 0)
					findIpAddresses(std::string(s.begin() + i + 1, s.end()), index + 1, ip + sip0);
				else
					findIpAddresses(std::string(s.begin() + i + 1, s.end()), index + 1, ip + "." + sip0);
			}
		}
	}
private:
	std::vector<std::string> vec;
};
#endif // !_93_H

