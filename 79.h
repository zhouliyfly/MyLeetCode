#ifndef _79_H //单词搜索
#define _79_H
#include <vector>
#include <string>
#include <array>


// 题设二维网格不知是否保证每行数据的个数相同
class Solution_79 {
public:
	bool exist(std::vector<std::vector<char>>& board, std::string word) {
		if (board.empty() || word.empty())
			return false;
		
		// 二维网格每行数量相同
		//visited = std::vector<std::vector<bool>>(board.size(), std::vector<bool>(board.size(), false));

		//二维网格每行数量不同
		visited = std::vector<std::vector<bool>>(board.size(), std::vector<bool>());
		for (size_t i = 0; i != board.size(); ++i) {
			visited[i] = std::vector<bool>(board[i].size(), false);
		}

		for (size_t i = 0; i != board.size(); ++i) {
			for (size_t j = 0; j != board[i].size(); ++j) {
				if (search(board, word, 0, i, j))
					return true;
			}
		}
		
		return false;
	}

private:
	// 调用者保证坐标x, y有效
	bool search(std::vector<std::vector<char>>& board, std::string word, size_t word_index, size_t x, size_t y) {
		if (word_index == word.size() - 1) {
			if (word[word_index] == board[x][y])
				return true;
			return false;
		}
	
		if (word[word_index] != board[x][y])
			return false;
		visited[x][y] = true;
		// 向上右下左四个方向前进
		for (size_t i = 0; i != direct.size(); ++i) {
			size_t nextX = x + direct[i][0];
			size_t nextY = y + direct[i][1];
			if (isAvalible(board, nextX, nextY) && !visited[nextX][nextY]) {
				if (search(board, word, word_index + 1, nextX, nextY)) {
					return true;
				}
			}
		}
		visited[x][y] = false;
		return false;
	}

	// 若二维网格不能保证每行个数相同，需用下面的函数验证坐标有效性
	// 否则，函数可以简化
	bool isAvalible(std::vector<std::vector<char>>& board, size_t x, size_t y) {
		if (x >= board.size())
			return false;
		if (y >= board[x].size())
			return false;
		return true;
	}
private:
	// array的多维数组定义有两种方式：一种是下面这种双大括号；
	//另外一种是只用一组大括号，如
	// std::array<std::array<int, 2>, 4> a{1,2,3,4,5,6,7,8};
	// 原因不详

	std::array<std::array<int, 2>, 4> direct = {{
		{-1, 0}, //上
		{0, 1},  //右
		{1, 0},  //下
		{0, -1}  //左
	}};

	// 标记网格的访问状态
	std::vector<std::vector<bool>> visited;
};
#endif // !_79_H
