#ifndef _149_H // 直线上最多的点数
#define _149_H
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <cassert>
#include <ostream>

class Fraction {
	// 友元函数实现不能放在当前文件Solution_149类外部，只能放在cpp文件中
	// 这里直接在类中实现
	friend std::ostream& operator << (std::ostream& os, const /*Solution_149::*/Fraction f) {
		os << f._num << "/" << f._den;
		return os;
	}
	friend class Hasher;
	friend size_t myhasher(const std::vector<Fraction>& v);
public:
	Fraction(long long num, long long den) { // 保证分母为正
		assert(den != 0);
		if (den < 0) {
			_num = -num;
			_den = -den;
		}
		else { // den>0
			_num = num;
			_den = den;
		}
		// 约分
		long long tmp_gcd = gcd(_num, _den);
		_num /= tmp_gcd;
		_den /= tmp_gcd;
	}

	Fraction operator+(const Fraction& rh) const {
		//分母最小公倍数
		long long den_lcm = lcm(this->_den, rh._den);
		long long num = this->_num * (den_lcm / this->_den) + rh._num * (den_lcm / rh._den);
		long long tmp_gcd = gcd(den_lcm, num);

		return Fraction(num / tmp_gcd, den_lcm / tmp_gcd);
	}

	Fraction operator-(const Fraction& rh) const {
		//分母最小公倍数
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
		//分母最小公倍数
		auto tmp = *this - rh;

		return tmp._num < 0;
	}

	bool operator==(const Fraction& rh) const {
		return (((*this)._num == 0 && rh._num == 0) ||
			((*this)._num == rh._num && (*this)._den == rh._den));
	}

	static size_t hasher(const std::vector<Fraction> v) {
		size_t res = 0;

		// 保证相等的数映射之后也相等，如0/3, 0/7 都是0，应该有相同的映射结果
		for (int i = 0; i < 3; ++i) {
			if (v[i]._num)
				res ^= std::hash<long long>()(v[i]._den) ^ std::hash<long long>()(v[i]._num);
			else
				res ^= std::hash<long long>()(0);
		}

		return res;
	}
private:
	// 求解方法不能直接使用暴力循环，在线超时
	long long gcd(long long x, long long y) const { //greatest common divisor 最大公约数
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

	long long lcm(long long x, long long y) const { //least common multiple 最小公倍数
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

		// 保证相等的数映射之后也相等，如0/3, 0/7 都是0，应该有相同的映射结果
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

		// 使用hash map，hash函数的三种实现：
		// 1. 仿函数
		// 2. 函数 ----》 由于main.cpp和testcase.cpp都包含当前头文件，导致链接时重定义！
		//    只能在头文件中声明，在cpp中实现
		// 3. 静态成员函数

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
	// 计算斜率和截距
	// 返回值：{k, b, sign}
	// k斜率, b截距, 
    // sign：标识斜率是否有效
	std::vector<Fraction> linear_parameters(const std::vector<int>& p1, const std::vector<int>& p2) {
		long long  num = p2[1] - p1[1];
		long long den = p2[0] - p1[0];
		

		//int k = (p2[1] - p1[1]) / (p2[0] - p1[0]);
		//int b = p2[1] - k * p2[0];

		// 平行于y轴直线（k无穷时）
		if (0 == p2[0] - p1[0]) {
			return std::vector< Fraction>{Fraction(1, 1), Fraction(p2[0], 1), Fraction(1, 1)};
		}

		Fraction k(p2[1] - p1[1], p2[0] - p1[0]);
		Fraction b(Fraction(p2[1], 1) - k * Fraction(p2[0], 1));
		
		return std::vector<Fraction>{ k, b, Fraction(0, 1) };
	}
};

#endif // !_149_H 

