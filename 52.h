#ifndef _52_H //N�ʺ� II
#define _52_H
#include <vector>
#include <cassert>

class Solution_52 {
public:
	int totalNQueens(int n) {
		if (n <= 2)
			return 0;

		//��ʼ��
		col = std::vector<bool>(n, false);
		diagonal_1 = std::vector<bool>(2 * n - 1, false); //�Խ��߹���2*n-1��
		diagonal_2 = std::vector<bool>(2 * n - 1, false);
		count = 0;

		putNQueens(n, 0);

		return count;
	}
private:
	// Ѱ�ҵ�index�лʺ������к�
	void putNQueens(int n, int index) {
		if (index == n) {
			count++;
			return;
		}
		for (size_t i = 0; i != n; ++i) {
			if (!col[i] && !diagonal_1[index + i] && !diagonal_2[index - i + (n - 1)]) {
				col[i] = true;
				diagonal_1[index + i] = true;
				diagonal_2[index - i + (n - 1)] = true;
				putNQueens(n, index + 1);
				col[i] = false;
				diagonal_1[index + i] = false;
				diagonal_2[index - i + (n - 1)] = false;
			}
		}
	}

	std::vector<std::string> vecToStr(int n, std::vector<int>& vec) {
		assert(int(vec.size()) == n);

		std::vector<std::string> res(n, std::string(n, '.'));
		for (size_t i = 0; i != vec.size(); ++i) {
			res[i][vec[i]] = 'Q';
		}
		return res;
	}

private:
	int count{ 0 };
	std::vector<bool> col; // ��Ǳ�ռ�õ���
	std::vector<bool> diagonal_1; //��Ǳ�ռ�õĶԽ���1
	std::vector<bool> diagonal_2; //��Ǳ�ռ�õĶԽ���2
};
#endif // !_52_H
