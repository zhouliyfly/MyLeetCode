#ifndef _76_H //最小覆盖子串
#define _76_H
#include <string>
#include <unordered_map>
#include <algorithm> //std:min
#include <vector>

/*
 * 题中包含所有字母含义不太不清晰。在线平台测试如下：
 * 输入: S = "ADOBECODEBANC", T = "AA"
 * 输出: "ADOBECODEBA"
 * 因此，当有重复字母时，需要原子串有同样数量的字母出现
*/
class Solution_76 {
public:
	std::string minWindow(std::string s, std::string t) {
		if (s.empty() || s.size() < t.size())
			return "";

		std::unordered_map<char, int> umap;
		for (decltype(t.size()) i = 0; i != t.size(); ++i) {
			umap[t[i]]++;
		}

		std::unordered_map<char, int> tmp_umap;
		for (decltype(t.size()) i = 0; i != t.size(); i++) {
			tmp_umap[s[i]]++;
		}
		if(contain_map(umap, tmp_umap))
			return s.substr(0, t.size());

		//[l...r)
		decltype(s.size()) l = 0;
		decltype(s.size()) r = l + t.size();
		decltype(s.size()) len = s.size() + 1; // 设置最小覆盖子串初值
		decltype(s.size()) index = s.size();
		while (r < s.size()) {
			while (r < s.size() && !contain_map(umap, tmp_umap)) {
				tmp_umap[s[r++]]++;
			}
			while (r - l >= t.size() && contain_map(umap, tmp_umap)) {
				if (r - l < len) {
					len = r - l;
					index = l;
				}
				tmp_umap[s[l++]]--;
			}
		}

		return (index != s.size()) ? s.substr(index, len) : "";
	}

	/*题设指定t中包含的是字母，理论上只需关注26个字母。
	 *不过题设没有明确指出s中包含的字符类型（如果只关注英文字母，耗时会更少，也可以通过在线验证）
	 *
	 * 测试结果，耗时没有太大差别！实际上只是判断匹配的不同（contain_map函数）。并且由于使用固定大小（128）的
	 * vector替代hash表，空间消耗反而增加了
	*/
	std::string minWindow1(std::string s, std::string t) {
		if (s.empty() || s.size() < t.size())
			return "";

		//std::unordered_map<char, int> umap;
		std::vector<int> umap(128, 0); //ascii码
		for (decltype(t.size()) i = 0; i != t.size(); ++i) {
			umap[t[i]]++;
		}

		//std::unordered_map<char, int> tmp_umap;
		std::vector<int> tmp_umap(128, 0);
		for (decltype(t.size()) i = 0; i != t.size(); i++) {
			tmp_umap[s[i]]++;
		}
		if (contain_map(umap, tmp_umap))
			return s.substr(0, t.size());

		//[l...r)
		decltype(s.size()) l = 0;
		decltype(s.size()) r = l + t.size();
		decltype(s.size()) len = s.size() + 1; // 设置最小覆盖子串初值
		decltype(s.size()) index = s.size();
		while (r < s.size()) {
			while (r < s.size() && !contain_map(umap, tmp_umap)) {
				tmp_umap[s[r++]]++;
			}
			while (r - l >= t.size() && contain_map(umap, tmp_umap)) {
				if (r - l < len) {
					len = r - l;
					index = l;
				}
				tmp_umap[s[l++]]--;
			}
		}

		return (index != s.size()) ? s.substr(index, len) : "";
	}

private:
	inline bool contain_map(const std::unordered_map<char, int>& umap, const std::unordered_map<char, int>& tmp_umap) {
		for (auto item = umap.begin(); item != umap.end(); ++item) {
			auto it = tmp_umap.find(item->first);
			if (it == tmp_umap.end() || it->second < item->second)
				return false;
		}
		return true;
	}

	inline bool contain_map(const std::vector<int>& umap, const std::vector<int>& tmp_umap) {
		for (decltype(umap.size()) i = 0; i != umap.size(); ++i) {
			if (tmp_umap[i] < umap[i])
				return false;
		}
		return true;
	}
};
#endif // !_76_H

