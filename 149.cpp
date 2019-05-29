#include "149.h"

size_t myhasher(const std::vector<Fraction>& v)
{
	size_t res = 0;

	// ��֤��ȵ���ӳ��֮��Ҳ��ȣ���0/3, 0/7 ����0��Ӧ������ͬ��ӳ����
	for (int i = 0; i < 3; ++i) {
		if (v[i]._num)
			res ^= std::hash<long long>()(v[i]._den) ^ std::hash<long long>()(v[i]._num);
		else
			res ^= std::hash<long long>()(0);
	}

	return res;
}