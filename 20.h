#ifndef _20_H //ÓÐÐ§µÄÀ¨ºÅ
#define _20_H
#include "MyUtility.h"
#include <string>
#include <stack>
#include <cassert>

class Solution_20 {
public:
	bool isValid(std::string s) {
		std::stack<char> sk;

		for (const auto& c : s) {
			char match;
			if (c == '{' || c == '[' || c == '(')
				sk.push(c);
			else {
				if (c == '}')
					match = '{';
				else if (c == ']')
					match = '[';
				else { // c == ')'
					assert(c == ')');
					match = '(';
				}
				if (sk.empty() || sk.top() != match)
					return false;
				sk.pop();
			}
		}
		if (!sk.empty())
			return false;
		return true;
	}
};
#endif // !_20_H

