#ifndef _451_H //根据字符出现频率排序
#define _451_H
#include <string>
#include <unordered_map>
#include <vector>

class Solution_451 {
public:
	std::string frequencySort(std::string s) {
		if (s.empty())
			return "";

		std::unordered_map<char, int> m;
		for (decltype(s.size()) i = 0; i != s.size(); ++i) {
			m[s[i]]++;
		}

		std::vector<char> v;
		for (auto item = m.begin(); item != m.end(); ++item)
			v.push_back(item->first);

		//稳定排序：归并排序 （类似排序索引）
		merge_sort(m, v);

		std::vector<char> res;
		for (decltype(v.size()) i = 0; i != v.size(); ++i) {
			res.insert(res.end(), m[v[i]], v[i]);
		}

		return std::string(res.begin(), res.end());
	}
private:
	void merge_sort(std::unordered_map<char, int>& m, std::vector<char>& v) {
		merge_sort(m, v, 0, v.size());
	}

	void merge_sort(std::unordered_map<char, int>& m, std::vector<char>& v, 
			std::vector<char>::size_type l,
			std::vector<char>::size_type r) {
		if (l + 1 >= r)
			return;

		merge_sort(m, v, l, l + (r - l) / 2);
		merge_sort(m, v, l + (r - l) / 2, r);
		if (m[v[l + (r - l) / 2 - 1]] < m[v[l + (r - l) / 2]])
			__merge(m, v, l, r);
	}

	void __merge(std::unordered_map<char, int>& m, 
			std::vector<char>& v, 
			std::vector<char>::size_type l,
			std::vector<char>::size_type r) {
		std::vector<char> tmp(v.begin() + l, v.begin() + r);

		// v: [l...(r-l)/2+l), [(r-l)/2+1...r)
		// tmp: [0, (r-l)/2), [(r-l)/2, r-l)
		std::vector<char>::size_type j = 0;
		std::vector<char>::size_type k = (r - l) / 2;
		for (std::vector<char>::size_type i = l; i < r; i++) {
			if (j >= (r - l) / 2) {
				v[i] = tmp[k++];
			}
			else if (k >= r - l) {
				v[i] = tmp[j++];
			}
			else if (m[tmp[j]] >= m[tmp[k]]) {
				v[i] = tmp[j++];
			}
			else { //tmp[j] < tmp[k]
				v[i] = tmp[k++];
			}
		}
	}
};
#endif // !_451_H

