#ifndef _37_H //解数独
#define _37_H
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

#include <iostream>

class Solution_37 {
public:
	void solveSudoku(std::vector<std::vector<char>>& board) {
		assert(board.size() == 9);

		// 初始化
		line.resize(9);
		col.resize(9);
		area = std::vector<std::vector<std::unordered_set<char>>>(3, 
			std::vector<std::unordered_set<char>>(3, std::unordered_set<char>()));

		for (size_t i = 0; i != board.size(); ++i) {
			for (size_t j = 0; j != board[i].size(); ++j) {
				if (board[i][j] != '.') {
					line[i].insert(board[i][j]);
					col[j].insert(board[i][j]);
					area[i / 3][j / 3].insert(board[i][j]);
				}
			}
		}

		for (size_t i = 0; i != board.size(); ++i) {
			for (size_t j = 0; j != board[i].size(); ++j) {
				if (board[i][j] == '.') {
					fillNums(board, i, j);
					return;
				}
			}
		}
	}

private:
	bool fillNums(std::vector<std::vector<char>>& board, size_t x, size_t y) {
		//std::cout << "(" << x << "," << y << "): " << std::endl;
		if (x == 9)
			return true;

		for (size_t i = 1; i != 10; ++i) {
			auto iter_line = line[x].find('0' + i);
			if (iter_line != line[x].end())
				continue;
			auto iter_col = col[y].find('0' + i);
			if (iter_col != col[y].end())
				continue;
			auto iter_area = area[x / 3][y / 3].find('0' + i);
			if (iter_area != area[x / 3][y / 3].end())
				continue;

			//std::cout << i << std::endl;
			board[x][y] = '0' + i;
			line[x].insert('0' + i);
			col[y].insert('0' + i);
			area[x / 3][y / 3].insert('0' + i);
			auto newXY = getNext(board, x, y);
			size_t newX = newXY.first;
			size_t newY = newXY.second;
			
			if (fillNums(board, newXY.first, newXY.second))
				return true;

			//std::cout << "-" << i << std::endl;
			board[x][y] = '.';
			line[x].erase('0' + i);
			col[y].erase('0' + i);
			area[x / 3][y / 3].erase('0' + i);

		}
		return false;
	}

	std::pair<size_t, size_t> getNext(std::vector<std::vector<char>>& board, size_t x, size_t y) {
		if (x == 9)
			return { 9,0 };

		if (y == 8) {
			y = 0;
			x += 1;
		}
		else
			y += 1;

		if (x < 9 && board[x][y] != '.')
			return getNext(board, x, y);

		return { x,y };
	}

private:
	std::vector<std::unordered_set<char>> line;
	std::vector<std::unordered_set<char>> col;
	std::vector<std::vector<std::unordered_set<char>>> area;
};

class Solution_37_2 {
public:
	void solveSudoku(std::vector<std::vector<char>>& board) {
		assert(board.size() == 9);

		line = std::vector<std::vector<bool>>(9, std::vector<bool>(10, false));
		rol = std::vector<std::vector<bool>>(9, std::vector<bool>(10, false));
		block = std::vector<std::vector<bool>>(9, std::vector<bool>(10, false));

		// 初始化
		for (size_t i = 0; i != board.size(); ++i) {
			for (size_t j = 0; j != board[i].size(); ++j) {
				if (board[i][j] != '.') {
					line[i][board[i][j] - '0'] = true;
					rol[j][board[i][j] - '0'] = true;
					block[i / 3 * 3 + j / 3][board[i][j] - '0'] = true;
				}
			}
		}

		for (size_t i = 0; i != board.size(); ++i) {
			for (size_t j = 0; j != board[i].size(); ++j) {
				if (board[i][j] == '.') {
					fillNums(board, i * 9 + j % 9);
					return;
				}
			}
		}
	}

private:
	bool fillNums(std::vector<std::vector<char>>& board, size_t index) {
		//std::cout << "index " << index << std::endl;
		if (index == 81)
			return true;

		size_t next = index + 1;
		for (; next < 81; next++) {
			if (board[next / 9][next % 9] == '.')
				break;
		}

		for (size_t i = 1; i != 10; ++i) {
			if (!line[index / 9][i] && !rol[index % 9][i] && !block[index / 9 / 3 * 3 + index % 9 / 3][i]) {
				//std::cout << "fill " << i << std::endl;
				board[index / 9][index % 9] = '0' + i;
				line[index / 9][i] = true;
				rol[index % 9][i] = true;
				block[index / 9 / 3 * 3 + index % 9 / 3][i] = true;
				if (fillNums(board, next))
					return true;
				line[index / 9][i] = false;
				rol[index % 9][i] = false;
				block[index / 9 / 3 * 3 + index % 9 / 3][i] = false;
				board[index / 9][index % 9] = '.';
			}
		}
		return false;
	}

private:
	std::vector<std::vector<bool>> line;
	std::vector<std::vector<bool>> rol;
	std::vector<std::vector<bool>> block;
};
#endif // !_37_H

