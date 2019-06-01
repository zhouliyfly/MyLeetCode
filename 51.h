#ifndef _51_H //N皇后
#define _51_H
#include <vector>
#include <string>
#include <cassert>

// N皇后问题关键是皇后之间位置冲突的判断
// 三个方向：
// 1. 横向：一行只能有一个皇后。 这个条件很简单，每行只寻找一个位置
// 2. 纵向：每列只能有一个皇后。创建一个数组，记录已经被占据的列号（col）
// 3. 对角线：对角线有两个方向
//    第一个方向（右上到左下）的规律是同一条对角线上的位置坐标之和相同
//    第二个方向（左上到右下）的规律是同一条对角线上的横坐标与纵坐标之差相等
//    结合数学规律：n阶行列式对角线有2*n-1条
//    为了使下标从0开始，对角线需要略微调整。第一个方向 i+j，第二个方向i-j+n-1;

class Solution_51 {
public:
	std::vector<std::vector<std::string>> solveNQueens(int n) {
		if (n <= 0)
			return res;
		
		//初始化
		col = std::vector<bool>(n, false);
		diagonal_1 = std::vector<bool>(2 * n - 1, false); //对角线共有2*n-1条
		diagonal_2 = std::vector<bool>(2 * n - 1, false);

		std::vector<int> vec;
		vec.reserve(n);
		putNQueens(n, 0, vec);
		
		return res;
	}

private:
	// 寻找第index行皇后所在列号
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
	std::vector<bool> col; // 标记被占用的列
	std::vector<bool> diagonal_1; //标记被占用的对角线1
	std::vector<bool> diagonal_2; //标记被占用的对角线2
};
#endif // !_51_H
