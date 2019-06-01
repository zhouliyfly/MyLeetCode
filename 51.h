#ifndef _51_H //N�ʺ�
#define _51_H
#include <vector>
#include <string>
#include <cassert>

// N�ʺ�����ؼ��ǻʺ�֮��λ�ó�ͻ���ж�
// ��������
// 1. ����һ��ֻ����һ���ʺ� ��������ܼ򵥣�ÿ��ֻѰ��һ��λ��
// 2. ����ÿ��ֻ����һ���ʺ󡣴���һ�����飬��¼�Ѿ���ռ�ݵ��кţ�col��
// 3. �Խ��ߣ��Խ�������������
//    ��һ���������ϵ����£��Ĺ�����ͬһ���Խ����ϵ�λ������֮����ͬ
//    �ڶ����������ϵ����£��Ĺ�����ͬһ���Խ����ϵĺ�������������֮�����
//    �����ѧ���ɣ�n������ʽ�Խ�����2*n-1��
//    Ϊ��ʹ�±��0��ʼ���Խ�����Ҫ��΢��������һ������ i+j���ڶ�������i-j+n-1;

class Solution_51 {
public:
	std::vector<std::vector<std::string>> solveNQueens(int n) {
		if (n <= 0)
			return res;
		
		//��ʼ��
		col = std::vector<bool>(n, false);
		diagonal_1 = std::vector<bool>(2 * n - 1, false); //�Խ��߹���2*n-1��
		diagonal_2 = std::vector<bool>(2 * n - 1, false);

		std::vector<int> vec;
		vec.reserve(n);
		putNQueens(n, 0, vec);
		
		return res;
	}

private:
	// Ѱ�ҵ�index�лʺ������к�
	void putNQueens(int n, int index, std::vector<int>& vec) {
		if (index == n) {
			res.push_back(vecToStr(n, vec));
			return;
		}
		for (size_t i = 0; i != n; ++i) {
			if (!col[i] && !diagonal_1[index + i] && !diagonal_2[index - i + (n - 1)]) {
				col[i] = true;
				diagonal_1[index + i] = true;
				diagonal_2[index - i + (n - 1)] = true;
				vec.push_back(i);
				putNQueens(n, index + 1, vec);
				col[i] = false;
				diagonal_1[index + i] = false;
				diagonal_2[index - i + (n - 1)] = false;
				vec.pop_back();
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
	std::vector<std::vector<std::string>> res;
	std::vector<bool> col; // ��Ǳ�ռ�õ���
	std::vector<bool> diagonal_1; //��Ǳ�ռ�õĶԽ���1
	std::vector<bool> diagonal_2; //��Ǳ�ռ�õĶԽ���2
};
#endif // !_51_H