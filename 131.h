#ifndef _131_H //分割回文串
#define _131_H
#include <string>
#include <vector>
#include <cassert>

// 回溯算法
// D = d[1] + d[n-1] = d[1] + d[2] + d[n-2] =...
// 首先查找最短回文串，为d[1]。然后在剩下的字符串中查找d[2],依次类推。
// 当最后剩下的子串d[n]为回文串时，字符串序列D即为一个正确分割；否则此分割无效
// 第二次分割d[1]'寻找比d[1]长度更长的回文串，之后延续分割。
// 第m次分割，找不到d[1]''的回文串，整个算法结束
class Solution_131 {
public:
	std::vector<std::vector<std::string>> partition(std::string s) {
		if (s.empty())
			return {};

		findStr(s, std::vector<std::string>());
		return vec;
	}

private:
	void findStr(std::string s, std::vector<std::string> ps) {
		if (s.empty()) {
			vec.push_back(ps);
			return;
		}
		for (size_t i = 0; i != s.size(); ) {
			i = find(s, i + 1);
			//std::string str(s.begin(), s.begin() + i);
			if (i == s.size() + 1)
				break;
			std::string str = s.substr(0, i);
			ps.push_back(str);
			findStr(std::string(s.begin() + i, s.end()), ps);
			ps.pop_back();
		}
	}

	// 找出字符串中的回文串
	// 从字符串开头开始查找，遇到回文串即返回，返回值为回文串的长度
	// 要求回文串长度至少大于等于参数i
	size_t find(std::string s, size_t i) {
		for (int j = i; j <= (int)s.size(); ++j) {
			std::string substr = s.substr(0, j);
			if (check(substr)) {
				return j;
			}
		}
		return s.size() + 1;
	}

	// 检测字符串是否为回文串
	bool check(std::string s) {
		assert(!s.empty());
		for (size_t i = 0, j = s.size() - 1; i != s.size() / 2; ++i, --j) {
			if (s[i] != s[j])
				return false;
		}
		return true;
	}

private:
	std::vector<std::vector<std::string>> vec;
};
#endif // !_131_H

