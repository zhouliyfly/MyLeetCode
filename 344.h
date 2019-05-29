#ifndef _344_H
#define _344_H
#include <vector>

class Solution_344 {
public:
	void reverseString(std::vector<char>& s) {
		if (s.empty())
			return;
		decltype(s.size()) i = 0;
		decltype(s.size()) j = s.size() - 1;

		while (i < j) {
			std::swap(s[i++], s[j--]);
		}
	}
};
#endif // !_344_H

