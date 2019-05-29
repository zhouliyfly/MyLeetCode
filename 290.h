#ifndef _290_H //单词模式
#define _290_H
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

class Solution_290 { 
public:
	bool wordPattern(std::string pattern, std::string str) {
		if (str.empty()) //只关注str中非空单词, pattern只包含小写字母（非空）
			return false;

		std::string map[26];
		std::unordered_set<std::string> set;
		decltype(pattern.size()) start = 0;
		decltype(pattern.size()) end = std::string::npos;
		std::string substr;

		for (decltype(pattern.size()) i = 0; i != pattern.size(); ++i) {
			// 获取str中第一个非空单词
			if ((start = str.find_first_not_of(' ', start)) != std::string::npos) {
				if ((end = str.find_first_of(' ', start)) == std::string::npos) {
					end = str.size();
				}
				substr = str.substr(start, end - start);
				start = end;
			}
			else { //非空单词获取失败
				return false;
			}

			if (map[pattern[i] - 'a'] == "") { //pattern中未出现过
				if (set.find(substr) != set.end()) { //set中不能出现
					return false;
				}
				map[pattern[i] - 'a'] = substr;
				set.insert(substr);
			}
			else { //pattern中出现过，必须与之前的映射相同
				if (map[pattern[i] - 'a'] != substr) {
					return false;
				}
			}
		}

		return true;
	}

	bool wordPattern2(std::string pattern, std::string str) {
		if (str.empty()) //只关注str中非空单词, pattern只包含小写字母（非空）
			return false;

		std::string map[26];
		std::unordered_set<std::string> set;
		std::istringstream in(str);

		for (decltype(pattern.size()) i = 0; i != pattern.size(); ++i) {
			// 获取str中第一个非空单词
			std::string substr;
			if (!(in >> substr))
				return false;

			if (map[pattern[i] - 'a'] == "") { //pattern中未出现过
				if (set.find(substr) != set.end()) { //set中不能出现
					return false;
				}
				map[pattern[i] - 'a'] = substr;
				set.insert(substr);
			}
			else { //pattern中出现过，必须与之前的映射相同
				if (map[pattern[i] - 'a'] != substr) {
					return false;
				}
			}
		}
		if (!(in.eof())) {
			return false;
		}

		return true;
	}

	//pattern只包含小写字母，只关注str中非空单词
#if 0
	bool wordPattern_c(std::string pattern, std::string str) {
		if (str.empty())
			return false;

		std::vector<std::string> vstr;
		char* cstr = new char[str.size() + 1];
		std::copy(str.begin(), str.end(), cstr); //strcpy
		char* p = strtok(cstr, " ");
		while (p) {
			vstr.push_back(p);
			p = strtok(nullptr, " ");
		}
		if (pattern.size() != vstr.size())
			return false;

		std::unordered_map<char, std::string> map;
		std::unordered_set<std::string> set;
		for (decltype(pattern.size()) i = 0; i != pattern.size(); ++i) {
			if (map.find(pattern[i]) != map.end()) { //pattern出现过
				if(map[pattern[i]] != vstr[i]) // str与之前不同
					return false;
			}
				
			else //map.find(pattern[i]) == map.end()， pattern没有出现过
			{	
				if(set.find(vstr[i]) != set.end()) // str之前出现过
					return false;
				map[pattern[i]] = vstr[i];
				set.insert(vstr[i]);
			}
		}
		return true;
	}
#endif
};
#endif // !_290_H

