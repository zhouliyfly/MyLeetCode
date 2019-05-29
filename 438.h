#ifndef _438_H //�ҵ��ַ�����������ĸ��λ��
#define _438_H
#include <vector>
#include <string>
#include <unordered_map>

class Solution_438 {
public:
	std::vector<int> findAnagrams(std::string s, std::string p) {
		if (s.empty() || p.empty())
			return {};

		int map[256] = { 0 }; //ֻ����СдӢ����ĸ
		for (decltype(p.size()) i = 0; i != p.size(); ++i) {
			map[p[i]]++;
		}
		std::vector<int> res;
		
		int tmp_map[256] = { 0 };
		for (decltype(p.size()) j = 0; j != p.size(); ++j) {
			tmp_map[s[j]]++;
		}
		if (compare_nums(map, tmp_map, 256))
			res.push_back(0);

		for (decltype(s.size()) i = 1; i + p.size() <= s.size(); ++i) {
			tmp_map[s[i-1]]--;
			tmp_map[s[i - 1 + p.size()]]++;
			if (compare_nums(map, tmp_map, 256))
				res.push_back(i);
		}
		return res;
	}

	// ��findAnagrams��ȣ�ʹ���˱�׼��hash�����ռ�ռ�û���hash���Ƚ�ʱ���֮������С
	std::vector<int> findAnagrams1(std::string s, std::string p) {
		if (s.empty() || p.empty())
			return {};

		std::unordered_map<char, int> umap; 
		for (decltype(p.size()) i = 0; i != p.size(); ++i) {
			umap[p[i]]++;
		}
		std::vector<int> res;

		std::unordered_map<char, int> tmp_umap;
		for (decltype(p.size()) j = 0; j != p.size(); ++j) {
			tmp_umap[s[j]]++;
		}
		if (compare_umap(umap, tmp_umap))
			res.push_back(0);

		for (decltype(s.size()) i = 1; i + p.size() <= s.size(); ++i) {
			tmp_umap[s[i - 1]]--;
			tmp_umap[s[i - 1 + p.size()]]++;
			if (compare_umap(umap, tmp_umap))
				res.push_back(i);
		}
		return res;
	}

	// �Ż�hash����ʱ������
	std::vector<int> findAnagrams2(std::string s, std::string p) {
		if (s.empty() || p.empty() || s.size() < p.size())
			return {};

		std::vector<int> map(26, 0); //ֻ����СдӢ����ĸ
		for (decltype(p.size()) i = 0; i != p.size(); ++i) {
			map[p[i] - 'a']++; //map[0...26]�ֱ��Ӧ26��Сд��ĸ
		}
		std::vector<int> res;

		std::vector<int> tmp_map(26, 0);
		for (decltype(p.size()) j = 0; j != p.size(); ++j) {
			tmp_map[s[j] - 'a']++;
		}
		if (map == tmp_map) //vector֮��ıȽϸ��򵥿���
			res.push_back(0);

		for (decltype(s.size()) i = 1; i + p.size() <= s.size(); ++i) {
			tmp_map[s[i - 1] - 'a']--;
			tmp_map[s[i - 1 + p.size()] - 'a']++;
			if (map == tmp_map)
				res.push_back(i);
		}
		return res;
	}

private:
	inline bool compare_umap(std::unordered_map<char, int>& m1, std::unordered_map<char, int>& m2) {
		for (auto item = m1.begin(); item != m1.end(); ++item) {
			char c = item->first;
			auto it = m2.find(c);
			if (it == m2.end() || item->second != it->second)
				return false;
		}
		return true;
	}

	inline bool compare_nums(int nums1[], int nums2[], int n) {
		for (int i = 0; i < n; i++) {
			if (nums1[i] != nums2[i])
				return false;
		}
		return true;
	}
};
#endif // !_438_H
