#ifndef _149_H // ֱ�������ĵ���
#define _149_H
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <cassert>
#include <ostream>

class Fraction {
	// ��Ԫ����ʵ�ֲ��ܷ��ڵ�ǰ�ļ�Solution_149���ⲿ��ֻ�ܷ���cpp�ļ���
	// ����ֱ��������ʵ��
	friend std::ostream& operator << (std::ostream& os, const /*Solution_149::*/Fraction f) {
		os << f._num << "/" << f._den;
		return os;
	}
	friend class Hasher;
	friend size_t myhasher(const std::vector<Fraction>& v);
public:
	Fraction(long long num, long long den) { // ��֤��ĸΪ��
		assert(den != 0);
		if (den < 0) {
			_num = -num;
			_den = -den;
		}
		else { // den>0
			_num = num;
			_den = den;
		}
		// Լ��
		long long tmp_gcd = gcd(_num, _den);
		_num /= tmp_gcd;
		_den /= tmp_gcd;
	}

	Fraction operator+(const Fraction& rh) const {
		//��ĸ��С������
		long long den_lcm = lcm(this->_den, rh._den);
		long long num = this->_num * (den_lcm / this->_den) + rh._num * (den_lcm / rh._den);
		long long tmp_gcd = gcd(den_lcm, num);

		return Fraction(num / tmp_gcd, den_lcm / tmp_gcd);
	}

	Fraction operator-(const Fraction& rh) const {
		//��ĸ��С������
		long long den_lcm = lcm(this->_den, rh._den);
		long long num = this->_num * (den_lcm / this->_den) - rh._num * (den_lcm / rh._den);
		long long tmp_gcd = gcd(den_lcm, num);

		return Fraction(num / tmp_gcd, den_lcm / tmp_gcd);
	}

	Fraction operator*(const Fraction& rh) const {
		long long num = this->_num * rh._num;
		long long den = this->_den * rh._den;
		long long tmp_gcd = gcd(num, den);

		return Fraction(num / tmp_gcd, den / tmp_gcd);
	}

	Fraction operator/(const Fraction& rh) const {
		assert(rh._num != 0);
		long long num = this->_num * rh._den;
		long long den = this->_den * rh._num;
		long long tmp_gcd = gcd(num, den);

		return Fraction(num / tmp_gcd, den / tmp_gcd);
	}

	bool operator<(const Fraction& rh) const {
		//��ĸ��С������
		auto tmp = *this - rh;

		return tmp._num < 0;
	}

	bool operator==(const Fraction& rh) const {
		return (((*this)._num == 0 && rh._num == 0) ||
			((*this)._num == rh._num && (*this)._den == rh._den));
	}

	static size_t hasher(const std::vector<Fraction> v) {
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
private:
	// ��ⷽ������ֱ��ʹ�ñ���ѭ�������߳�ʱ
	long long gcd(long long x, long long y) const { //greatest common divisor ���Լ��
		if (x == 0 || y == 0)
			return 1;

		long long a = std::abs(x);
		long long b = std::abs(y);

		long long z = b;
		while (a%b != 0)
		{
			z = a % b;
			a = b;
			b = z;
		}
		return z;
	}

	long long lcm(long long x, long long y) const { //least common multiple ��С������
		long long a = std::abs(x);
		long long b = std::abs(y);

		return a * b / gcd(a, b);
	}

private:
	long long _num;
	long long _den;
};

extern size_t myhasher(const std::vector<Fraction>& v);

class Hasher {
public:
	size_t operator()(const std::vector<Fraction>& v) const{
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
};

class Solution_149 {
public:
	int maxPoints(std::vector<std::vector<int>>& points) {
		if (points.size() <= 1)
			return points.size();

		std::unordered_set<int>::size_type res = 0;
		//std::map<std::vector<Fraction>, std::unordered_set<int>> record;

		// ʹ��hash map��hash����������ʵ�֣�
		// 1. �º���
		// 2. ���� ----�� ����main.cpp��testcase.cpp��������ǰͷ�ļ�����������ʱ�ض��壡
		//    ֻ����ͷ�ļ�����������cpp��ʵ��
		// 3. ��̬��Ա����

		/*std::unordered_map<std::vector<Fraction>, std::unordered_set<int>,
			Hasher> record(0, Hasher());*/

		std::unordered_map<std::vector<Fraction>, std::unordered_set<int>,
			decltype(myhasher)*> record(0, myhasher);

		/*std::unordered_map<std::vector<Fraction>, std::unordered_set<int>,
			decltype(Fraction::hasher)*> record(0, Fraction::hasher);*/

		for (decltype(points.size()) i = 0; i != points.size(); ++i) {
			for (decltype(points.size()) j = i + 1; j != points.size(); ++j) {
				record[linear_parameters(points[i], points[j])].insert(i);
				record[linear_parameters(points[i], points[j])].insert(j);
			}
		}
		for (const auto& p : record) {
			if (p.second.size() > res)
				res = p.second.size();
		}

		return int(res);
	}

private:
	// ����б�ʺͽؾ�
	// ����ֵ��{k, b, sign}
	// kб��, b�ؾ�, 
    // sign����ʶб���Ƿ���Ч
	std::vector<Fraction> linear_parameters(const std::vector<int>& p1, const std::vector<int>& p2) {
		long long  num = p2[1] - p1[1];
		long long den = p2[0] - p1[0];
		

		//int k = (p2[1] - p1[1]) / (p2[0] - p1[0]);
		//int b = p2[1] - k * p2[0];

		// ƽ����y��ֱ�ߣ�k����ʱ��
		if (0 == p2[0] - p1[0]) {
			return std::vector< Fraction>{Fraction(1, 1), Fraction(p2[0], 1), Fraction(1, 1)};
		}

		Fraction k(p2[1] - p1[1], p2[0] - p1[0]);
		Fraction b(Fraction(p2[1], 1) - k * Fraction(p2[0], 1));
		
		return std::vector<Fraction>{ k, b, Fraction(0, 1) };
	}
};

#endif // !_149_H 
