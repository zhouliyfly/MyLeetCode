#ifndef _49_H //��ĸ��λ�ʷ���
#define _49_H
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class Solution_49 {
public:
	std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
		if (strs.empty())
			return {};

		std::vector<std::vector<std::string>> res;
		std::unordered_map<std::string, std::vector<std::string>> m;
		for (decltype(strs.size()) i = 0; i != strs.size(); i++) {
			std::string tmp = strs[i];
			std::sort(tmp.begin(), tmp.end());
			m[tmp].push_back(strs[i]);
		}

		for (auto v : m) {
			res.push_back(v.second);
		}
		return res;
	}

	// ʹ��������ʾСд��ĸ���ַ����������������˻�Ψһ��ʶ
	// ��ǰһ�ֽⷨ��ȣ�����Ҫ����ʱ�临�Ӷ�O(n)
	// ������֤ʱ����
	std::vector<std::vector<std::string>> groupAnagrams1(std::vector<std::string>& strs) {
		if (strs.empty())
			return {};

		// ����--Сд��ĸӳ�����ֱ��ʹ�ó������������죩
		std::unordered_map<char, int> record;
		int prime = 2;
		char c = 'a';
		while (record.size() != 26) {
			int j = 2;
			for (; j < prime; j++) {
				if (!(prime%j))
					break;	
			}
			if(j == prime)
				record[c++] = j;
			prime++;
		}

		std::vector<std::vector<std::string>> res;
		std::unordered_map<long long, std::vector<std::string>> m;
		for (decltype(strs.size()) i = 0; i != strs.size(); i++) {
			unsigned long long tmp = 1;  // ������long long�������
			for (const auto& c : strs[i])
				tmp *= record[c];
			m[tmp].push_back(strs[i]);
		}

		for (auto v : m) {
			res.push_back(v.second);
		}
		return res;
	}
};
#endif // !_49_H
