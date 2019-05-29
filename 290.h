#ifndef _290_H //����ģʽ
#define _290_H
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

class Solution_290 { 
public:
	bool wordPattern(std::string pattern, std::string str) {
		if (str.empty()) //ֻ��עstr�зǿյ���, patternֻ����Сд��ĸ���ǿգ�
			return false;

		std::string map[26];
		std::unordered_set<std::string> set;
		decltype(pattern.size()) start = 0;
		decltype(pattern.size()) end = std::string::npos;
		std::string substr;

		for (decltype(pattern.size()) i = 0; i != pattern.size(); ++i) {
			// ��ȡstr�е�һ���ǿյ���
			if ((start = str.find_first_not_of(' ', start)) != std::string::npos) {
				if ((end = str.find_first_of(' ', start)) == std::string::npos) {
					end = str.size();
				}
				substr = str.substr(start, end - start);
				start = end;
			}
			else { //�ǿյ��ʻ�ȡʧ��
				return false;
			}

			if (map[pattern[i] - 'a'] == "") { //pattern��δ���ֹ�
				if (set.find(substr) != set.end()) { //set�в��ܳ���
					return false;
				}
				map[pattern[i] - 'a'] = substr;
				set.insert(substr);
			}
			else { //pattern�г��ֹ���������֮ǰ��ӳ����ͬ
				if (map[pattern[i] - 'a'] != substr) {
					return false;
				}
			}
		}

		return true;
	}

	bool wordPattern2(std::string pattern, std::string str) {
		if (str.empty()) //ֻ��עstr�зǿյ���, patternֻ����Сд��ĸ���ǿգ�
			return false;

		std::string map[26];
		std::unordered_set<std::string> set;
		std::istringstream in(str);

		for (decltype(pattern.size()) i = 0; i != pattern.size(); ++i) {
			// ��ȡstr�е�һ���ǿյ���
			std::string substr;
			if (!(in >> substr))
				return false;

			if (map[pattern[i] - 'a'] == "") { //pattern��δ���ֹ�
				if (set.find(substr) != set.end()) { //set�в��ܳ���
					return false;
				}
				map[pattern[i] - 'a'] = substr;
				set.insert(substr);
			}
			else { //pattern�г��ֹ���������֮ǰ��ӳ����ͬ
				if (map[pattern[i] - 'a'] != substr) {
					return false;
				}
			}
		}
		if (!(in.eof())) {
			return false;
		}

		return true;
	}

	//patternֻ����Сд��ĸ��ֻ��עstr�зǿյ���
#if 0
	bool wordPattern_c(std::string pattern, std::string str) {
		if (str.empty())
			return false;

		std::vector<std::string> vstr;
		char* cstr = new char[str.size() + 1];
		std::copy(str.begin(), str.end(), cstr); //strcpy
		char* p = strtok(cstr, " ");
		while (p) {
			vstr.push_back(p);
			p = strtok(nullptr, " ");
		}
		if (pattern.size() != vstr.size())
			return false;

		std::unordered_map<char, std::string> map;
		std::unordered_set<std::string> set;
		for (decltype(pattern.size()) i = 0; i != pattern.size(); ++i) {
			if (map.find(pattern[i]) != map.end()) { //pattern���ֹ�
				if(map[pattern[i]] != vstr[i]) // str��֮ǰ��ͬ
					return false;
			}
				
			else //map.find(pattern[i]) == map.end()�� patternû�г��ֹ�
			{	
				if(set.find(vstr[i]) != set.end()) // str֮ǰ���ֹ�
					return false;
				map[pattern[i]] = vstr[i];
				set.insert(vstr[i]);
			}
		}
		return true;
	}
#endif
};
#endif // !_290_H
