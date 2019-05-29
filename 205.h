#ifndef _205_H //同构字符串（假设 s 和 t 具有相同的长度）
#define _205_H
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution_205 {
public:
	//
	bool isIsomorphic(std::string s, std::string t) {
		if (s.empty() && t.empty())
			return true;

		std::unordered_map<char, char> map;
		std::unordered_set<char> set;

		for (decltype(s.size()) i = 0; i != s.size(); ++i) {
			if (map.find(s[i]) != map.end()) {
				if (map[s[i]] != t[i])
					return false;
				else
					continue;
			}
			else {
				if (set.find(t[i]) != set.end())
					return false;
				else {
					map[s[i]] = t[i];
					set.insert(t[i]);
				}	
			}
		}
		return true;
	}
};
#endif // !_205_H
