#ifndef _345_H //反转字符串中的元音字母
#define _345_H
#include <string>

class Solution_345 {
public:
	std::string reverseVowels(std::string s) {
		if (s.empty())
			return s;

		decltype(s.size()) i = 0;
		decltype(s.size()) j = s.size() - 1;

		while (i < j) {
			while (i < j && !isvowel(s[i]))
				i++;
			while (i < j && !isvowel(s[j]))
				j--;
			if (i < j) {
				if (s[i] != s[j])
					std::swap(s[i++], s[j--]);
				else {
					i++;
					j--;
				}
			}
		}
		return s;
	}
private:
	inline bool isvowel(char c) {
		char ch = tolower(c);

		if (ch == 'a' || ch == 'e' || ch == 'i' 
			|| ch == 'o' || ch == 'u')
			return true;
		return false;
	}
};
#endif // !_345_H

