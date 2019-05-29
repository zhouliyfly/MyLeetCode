#ifndef _71_H //��·��
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
					if (s.top() == '/') { // "//" ����
						continue;
					}
					else if (s.top() == '.') { // "../" "./" ����
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

						if (!s.empty() && s.top() == '.') { // "../"����
							s.pop(); //���� '.'
							if (s.size() <= 1)
								continue;
							else
								s.pop(); //���� '/'
							while (!s.empty() && s.top() != '/') { // ���˵��ϼ�Ŀ¼
								s.pop();
							}
						}
						// "./"ֱ��ɾ��
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
		// ������β�� '.' '..'
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
						s.pop(); //���� '.'
						if (s.size() > 1)
							s.pop(); //���� '/'
						while (!s.empty() && s.top() != '/') { // ���˵��ϼ�Ŀ¼
							s.pop();
						}
					}
				}	
			}
		}

		// ���һ��'/'Ҫɾ��
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
