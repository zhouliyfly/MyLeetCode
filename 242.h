#ifndef _242_H
#define _242_H
#include <string>
#include <unordered_map>

class Solution_242 { 
public:
	//Ö»°üº¬Ð¡Ð´×ÖÄ¸
	bool isAnagram(std::string s, std::string t) {
		if (s.size() != t.size())
			return false;

		int map1[26] = { 0 };
		int map2[26] = { 0 };
		for (decltype(s.size()) i = 0; i != s.size(); ++i) {
			map1[s[i] - 'a']++;
			map2[t[i] - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			if (map1[i] != map2[i])
				return false;
		}
		return true;
	}

	// °üº¬Unicode×Ö·û£¬½èÓÃunordered_map
	bool isAnagram2(std::string s, std::string t) {
		if (s.size() != t.size())
			return false;

		std::unordered_map<int, int> map1;
		for (decltype(s.size()) i = 0; i != s.size(); ++i) {
			map1[s[i]]++;
		}

		for (decltype(t.size()) i = 0; i != t.size(); ++i) {
			if (map1[t[i]] <= 0) {
				return false;
			}
			map1[t[i]]--;
		}
		return true;
	}
};
#endif // !_242_H

