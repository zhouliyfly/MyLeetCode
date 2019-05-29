#ifndef _131_H //�ָ���Ĵ�
#define _131_H
#include <string>
#include <vector>
#include <cassert>

// �����㷨
// D = d[1] + d[n-1] = d[1] + d[2] + d[n-2] =...
// ���Ȳ�����̻��Ĵ���Ϊd[1]��Ȼ����ʣ�µ��ַ����в���d[2],�������ơ�
// �����ʣ�µ��Ӵ�d[n]Ϊ���Ĵ�ʱ���ַ�������D��Ϊһ����ȷ�ָ����˷ָ���Ч
// �ڶ��ηָ�d[1]'Ѱ�ұ�d[1]���ȸ����Ļ��Ĵ���֮�������ָ
// ��m�ηָ�Ҳ���d[1]''�Ļ��Ĵ��������㷨����
class Solution_131 {
public:
	std::vector<std::vector<std::string>> partition(std::string s) {
		if (s.empty())
			return {};

		findStr(s, std::vector<std::string>());
		return vec;
	}

private:
	void findStr(std::string s, std::vector<std::string> ps) {
		if (s.empty()) {
			vec.push_back(ps);
			return;
		}
		for (size_t i = 0; i != s.size(); ) {
			i = find(s, i + 1);
			//std::string str(s.begin(), s.begin() + i);
			if (i == s.size() + 1)
				break;
			std::string str = s.substr(0, i);
			ps.push_back(str);
			findStr(std::string(s.begin() + i, s.end()), ps);
			ps.pop_back();
		}
	}

	// �ҳ��ַ����еĻ��Ĵ�
	// ���ַ�����ͷ��ʼ���ң��������Ĵ������أ�����ֵΪ���Ĵ��ĳ���
	// Ҫ����Ĵ��������ٴ��ڵ��ڲ���i
	size_t find(std::string s, size_t i) {
		for (int j = i; j <= (int)s.size(); ++j) {
			std::string substr = s.substr(0, j);
			if (check(substr)) {
				return j;
			}
		}
		return s.size() + 1;
	}

	// ����ַ����Ƿ�Ϊ���Ĵ�
	bool check(std::string s) {
		assert(!s.empty());
		for (size_t i = 0, j = s.size() - 1; i != s.size() / 2; ++i, --j) {
			if (s[i] != s[j])
				return false;
		}
		return true;
	}

private:
	std::vector<std::vector<std::string>> vec;
};
#endif // !_131_H
