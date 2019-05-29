#ifndef _3_H //���ظ��ַ�����Ӵ�
#define _3_H
#include <string>
#include <algorithm> //std::max

class Solution_3 {
public:
	int lengthOfLongestSubstring(std::string s) {
		int map[256] = { 0 };
		std::string::size_type i = 0;
		std::string::size_type j = 0;
		int res = 0;
		
		while (j < s.size()) {
			if (!map[s[j]]) {
				map[s[j]]++;
				j++;
			}
			else {
				map[s[i++]]--;
			}
			res = std::max(res, int(j - i));
		}
		return res;
	}
};
#endif // !_3_H
