#ifndef _125_H
#define _125_H
#include <string>
#include <cctype> //isalnum,tolower

class Solution_125 {
public:
	bool isPalindrome(std::string s) {
		if (s.empty())
			return true;

		std::string::size_type i = 0;
		std::string::size_type j = s.size() - 1;

		while (i < j) {
			if (!isalnum(s[i])) { // Ö»¿¼ÂÇÊý×ÖºÍ×ÖÄ¸
				i++;
				continue;
			}
			if (!isalnum(s[j])) {
				j--;
				continue;
			}
			if (tolower(s[i]) != tolower(s[j])) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
};
#endif // !_125_H

