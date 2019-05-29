#ifndef _17_H //�绰�������ĸ���
#define _17_H
#include <string>
#include <vector>

#include <iostream>

// ���汣���˵�����Ϣ���ݹ���ݵĵ���ʾ����ֵ��ѧϰ
class Solution_17 {
public:
	std::vector<std::string> letterCombinations(std::string digits) {
		if (digits.empty())
			return {};

		findCombinations(digits, 0, "");
		return vec;
	}
private:
	void findCombinations(std::string digits, size_t index, std::string s) {
		std::cout << index << ": " << s << std::endl;
		if (index == digits.size()) {
			std::cout << "complete :" << s << std::endl;
			vec.push_back(s);
			return;
		}
		char c = digits[index];
		std::string str = words[c - '0'];
		for (size_t i = 0; i != str.size(); ++i) {
			std::cout << "digits["  << index << "]=" << c << ", use:" << str[i] << std::endl;
			findCombinations(digits, index + 1, s + str[i]);
		}

		std::cout << "digits[" << index << "] =" << c << " complete. return" << std::endl;
	}
private:
	const std::string words[10] = {
		" ",   //0
		"",    //1
		"abc", //2
		"def", //3
		"ghi", //4
		"jkl", //5
		"mno", //6
		"pqrs", //7
		"tuv", //8
		"wxyz" //9
	};

	std::vector<std::string> vec;
};
#endif // !_17_H
