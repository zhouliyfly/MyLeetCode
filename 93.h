#ifndef _93_H //��ԭIP��ַ
#define _93_H
#include <string>
#include <vector>

#include <iostream>

// ip��ַ��4������ɣ�ÿ���ֵ�������0~255֮��
// �û��ݷ���ÿ���ֿ���ѡ��1λ����2λ����3λ��
// ע�⣺��ѡ��2λ����3λ��ʱ����ͷ����Ϊ0.��"012"

class Solution_93 {
public:
	std::vector<std::string> restoreIpAddresses(std::string s) {
		if (s.size() < 4)
			return {};

		findIpAddresses(s, 0, "");
		return vec;
	}

private:
	void findIpAddresses(std::string s, int index, std::string ip) {
		//std::cout << index << ":" << ip << std::endl;
		// ip��ַ4��������ɣ�ÿ�����ֶ���1/2/3��λ����ѡ
		if (index == 3) {
			if (s.size() > 0 && s.size() <= 3) {
				if (s.size() > 1 && s[0] == '0')
					return;
				int ip3 = std::stoi(s);
				if (ip3 >= 0 && ip3 <= 255) {
					//std::cout << "get " << ip + "," + s << std::endl;
					vec.push_back(ip + "." + s);
				}
			}
			return;
		}
		// index < 3
		for (int i = 0; i < 3; i++) { //ѡȡi+1λ
			if (s.size() < i + 1)
				break;
			std::string sip0(s.begin(), s.begin() + i + 1);
			if (i > 0 && sip0[0] == '0')
				break;
			//std::cout << "index[" << index << "], use " << i << std::endl;
			int ip0 = std::stoi(sip0);
			if (ip0 >= 0 && ip0 <= 255) {
				if(index == 0)
					findIpAddresses(std::string(s.begin() + i + 1, s.end()), index + 1, ip + sip0);
				else
					findIpAddresses(std::string(s.begin() + i + 1, s.end()), index + 1, ip + "." + sip0);
			}
		}
	}
private:
	std::vector<std::string> vec;
};
#endif // !_93_H
