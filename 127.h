#ifndef _127_H
#define _127_H
#include <string>
#include <vector>
#include <cassert>
#include <queue>

class Solution_127 {
public:
	int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
		assert(!beginWord.empty() && !endWord.empty() && beginWord != endWord);
		
		size_t iend = std::find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
		if (iend == wordList.size())
			return 0;

		size_t ibegin = std::find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
		if (ibegin == wordList.size()) {
			wordList.push_back(beginWord);
		}	

		// 创建图
		std::vector<std::vector<bool>> g(wordList.size(), std::vector<bool>(wordList.size(), false));
		for (size_t i = 0; i != wordList.size(); ++i) {
			for (size_t j = 0; j != i; ++j) {
				g[i][j] = g[j][i] = neighbour(wordList[i], wordList[j]);
			}
		}

		// BFS
		// 双向BFS，否则在线超时
		std::vector<size_t> step1(wordList.size(), 0);
		std::vector<size_t> step2(wordList.size(), 0);
		std::queue<size_t> q1;
		std::queue<size_t> q2;
		q1.push(ibegin);
		q2.push(iend);
		step1[ibegin] = 1;
		step2[iend] = 1;

		while (!q1.empty() && !q2.empty()) {
			size_t s = q1.front();
			q1.pop();
			for (size_t i = 0; i != wordList.size(); ++i) {
				if (step1[i] == 0 && g[s][i]) {
					q1.push(i);
					step1[i] = step1[s] + 1;
				}

			}	

			size_t k = q2.front();
			q2.pop();
			for (size_t i = 0; i != wordList.size(); ++i) {
				if (step2[i] == 0 && g[k][i]) {
					q2.push(i);
					step2[i] = step2[k] + 1;
				}
			}

			size_t res = SIZE_MAX;
			for (size_t i = 0; i != wordList.size(); ++i) {
				if (step1[i] != 0 && step2[i] != 0) {
					res = std::min(res, step1[i] + step2[i] - 1);
				}
			}
			if (res != SIZE_MAX)
				return res;
		}
		return 0;
	}
private:
	// 判断两个单词是否相邻（只有一个字母不同）
	bool neighbour(const std::string& s1, const std::string& s2)const {
		assert(s1.size() == s2.size());

		int count = 0;
		for (decltype(s1.size()) i = 0; i != s1.size(); ++i) {
			if (s1[i] != s2[i]) {
				count++;
				if (count >= 2)
					break;
			}
		}
		return count == 1;
	}
};
#endif // !_127_H

