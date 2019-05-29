#ifndef _71_H //简化路径
#define _71_H
#include "MyUtility.h"
#include <string>
#include <stack>

class Solution_71 {
public:
	std::string simplifyPath(std::string path) {
		std::stack<char> s;
		for (const auto& c : path) {
			if (c == '/') {
				if (!s.empty()) {
					if (s.top() == '/') { // "//" 情形
						continue;
					}
					else if (s.top() == '.') { // "../" "./" 情形
						s.pop();
						char temp = s.top();
						s.pop();
						if (temp == '.' && s.top() == '.') {
							s.push('.');
							s.push('.');
							s.push(c);
							continue;
						}
						s.push(temp);

						if (!s.empty() && s.top() == '.') { // "../"情形
							s.pop(); //弹出 '.'
							if (s.size() <= 1)
								continue;
							else
								s.pop(); //弹出 '/'
							while (!s.empty() && s.top() != '/') { // 回退到上级目录
								s.pop();
							}
						}
						// "./"直接删除
					}
					else {
						s.push(c);
					}
				}
				else {
					s.push(c);
				}
			}
			else {
				s.push(c);
			}
		}
		// 处理结尾的 '.' '..'
		if (s.size() >= 2) {
			if (s.top() == '.') {
				s.pop();
				char temp = s.top();
				s.pop();
				if (temp == '.' && !s.empty() && s.top() == '.') {
					s.push('.');
					s.push('.');
				}
				else {
					s.push(temp);
					//s.push('.');
					if (s.top() == '.') {
						s.pop(); //弹出 '.'
						if (s.size() > 1)
							s.pop(); //弹出 '/'
						while (!s.empty() && s.top() != '/') { // 回退到上级目录
							s.pop();
						}
					}
				}	
			}
		}

		// 最后一个'/'要删除
		if (s.size() >= 2 && s.top() == '/')
			s.pop();
		std::string res;
		while (!s.empty()) {
			res.insert(res.begin(), s.top());
			s.pop();
		}
		return res;
	}
};
#endif // !_71_H

