#ifndef _76_H //��С�����Ӵ�
#define _76_H
#include <string>
#include <unordered_map>
#include <algorithm> //std:min
#include <vector>

/*
 * ���а���������ĸ���岻̫������������ƽ̨�������£�
 * ����: S = "ADOBECODEBANC", T = "AA"
 * ���: "ADOBECODEBA"
 * ��ˣ������ظ���ĸʱ����Ҫԭ�Ӵ���ͬ����������ĸ����
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
		decltype(s.size()) len = s.size() + 1; // ������С�����Ӵ���ֵ
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

	/*����ָ��t�а���������ĸ��������ֻ���ע26����ĸ��
	 *��������û����ȷָ��s�а������ַ����ͣ����ֻ��עӢ����ĸ����ʱ����٣�Ҳ����ͨ��������֤��
	 *
	 * ���Խ������ʱû��̫����ʵ����ֻ���ж�ƥ��Ĳ�ͬ��contain_map����������������ʹ�ù̶���С��128����
	 * vector���hash�����ռ����ķ���������
	*/
	std::string minWindow1(std::string s, std::string t) {
		if (s.empty() || s.size() < t.size())
			return "";

		//std::unordered_map<char, int> umap;
		std::vector<int> umap(128, 0); //ascii��
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
		decltype(s.size()) len = s.size() + 1; // ������С�����Ӵ���ֵ
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
