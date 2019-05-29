#ifndef _150_H //逆波兰表达式求值
#define _150_H
#include "MyUtility.h"
#include <vector>
#include <string>
#include <stack>

class Solution_150 {
public:
	int evalRPN(std::vector<std::string>& tokens) {
		std::stack<long long> sk;
		for (const auto& val : tokens) {
			if (val.size() == 1) {
				if (val[0] == '+') {
					long long data2 = sk.top();
					sk.pop();
					long long data1 = sk.top();
					sk.pop();
					sk.push(data1 + data2);
				}
				else if (val[0] == '-') {
					long long data2 = sk.top();
					sk.pop();
					long long data1 = sk.top();
					sk.pop();
					sk.push(data1 - data2);
				}
				else if (val[0] == '*') {
					long long data2 = sk.top();
					sk.pop();
					long long data1 = sk.top();
					sk.pop();
					sk.push(data1*data2);
				}
				else if (val[0] == '/') {
					long long data2 = sk.top();
					sk.pop();
					long long data1 = sk.top();
					sk.pop();
					sk.push(data1 / data2);
				}
				else {
					sk.push(val[0] - '0');
				}
			}
			else {
				sk.push(std::stoll(val));
			}
		}
		return static_cast<int>(sk.top());
	}
};
#endif // !_150_H

