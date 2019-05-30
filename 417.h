#ifndef _417_H //太平洋大西洋水流问题
#define _417_H
#include <vector>
#include <array>

#if 0
class Solution_417 {
public:
	std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& matrix) {
		if (matrix.empty())
			return res;

		if (matrix.size() == 1) {
			for (size_t i = 0; i != matrix[0].size(); ++i) {
				res.push_back(std::vector<int>({ 0, (int)i }));
			}
			return res;
		}
		if (matrix[0].size() == 1) {
			for (size_t i = 0; i != matrix.size(); ++i) {
				res.push_back(std::vector<int>({ (int)i,0 }));
			}
			return res;
		}

		for (size_t i = 0; i != matrix.size(); ++i) {
			for (size_t j = 0; j != matrix[i].size(); ++j) {
				bool water1 = false; //太平洋
				bool water2 = false; //大西洋
				std::vector<std::vector<bool>> visited(matrix.size(), std::vector<bool>(matrix[0].size(), false));
				dfs(matrix, i, j, water1, water2, visited);
				if (water1 && water2)
					res.push_back({ int(i), int(j) });
			}
		}
		return res;
	}

private:
	void dfs(std::vector<std::vector<int>>& matrix, size_t x, size_t y, 
			bool& water1, bool& water2, 
			std::vector<std::vector<bool>>& visited) {

		visited[x][y] = true;
		for (size_t i = 0; i != direct.size(); ++i) {
			size_t newX = x + direct[i][0];
			size_t newY = y + direct[i][1];
			if (isAvalible(matrix, newX, newY, water1, water2) 
					&& !visited[newX][newY]
					&& matrix[newX][newY] <= matrix[x][y]) {

				dfs(matrix, newX, newY, water1, water2, visited);
				if (water1 && water2)
					return;
			}
		}
	}

	bool isAvalible(std::vector<std::vector<int>>& matrix, size_t x, size_t y, bool& water1, bool& water2) {
		bool ret = false;
		if (x == -1 || y == -1) {
			water1 = true;
			ret = false;
		}
		else if (x == matrix.size() || y == matrix[0].size()) {
			water2 = true;
			ret = false;
		}
		else
			ret = true;

		return ret;
	}

private:
	std::array<std::array<int, 2>, 4> direct = {
		-1,0, // 上
		0,1,  // 右
		1,0,  // 下
		0,-1  // 左
	};
	std::vector<std::vector<int>> res;
};
#endif

class Solution_417_2 {
public:
	std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& matrix) {
		if (matrix.empty())
			return res;

		if (matrix.size() == 1) {
			for (size_t i = 0; i != matrix[0].size(); ++i) {
				res.push_back(std::vector<int>({ 0, (int)i }));
			}
			return res;
		}
		if (matrix[0].size() == 1) {
			for (size_t i = 0; i != matrix.size(); ++i) {
				res.push_back(std::vector<int>({ (int)i,0 }));
			}
			return res;
		}

		size_t m = matrix.size();
		size_t n = matrix[0].size();

		std::vector<std::vector<bool>> pacific(m, std::vector<bool>(n, false));
		std::vector<std::vector<bool>> atlantic(m, std::vector<bool>(n, false));

		for (size_t i = 0; i != n; ++i) {
			dfs(matrix, pacific, 0, i);
			dfs(matrix, atlantic, m - 1, i);
		}

		for (size_t i = 0; i != m; ++i) {
			dfs(matrix, pacific, i, 0);
			dfs(matrix, atlantic, i, n - 1);
		}

		for (size_t i = 0; i != m; ++i) {
			for (size_t j = 0; j != n; ++j) {
				if (pacific[i][j] == true && true == atlantic[i][j])
					res.push_back({ int(i), int(j) });
			}
		}
		return res;
	}

private:
	void dfs(std::vector<std::vector<int>>& matrix, std::vector<std::vector<bool>>& visited, size_t x, size_t y) {
		visited[x][y] = true;
		for (size_t i = 0; i != direct.size(); ++i) {
			size_t newX = x + direct[i][0];
			size_t newY = y + direct[i][1];
			if (isAvalible(matrix, newX, newY) &&
					!visited[newX][newY] && 
					matrix[newX][newY] >= matrix[x][y]) {
				dfs(matrix, visited, newX, newY);
			}
		}
	}

	bool isAvalible(std::vector<std::vector<int>>& matrix, size_t x, size_t y) {
		size_t m = matrix.size();
		size_t n = matrix[0].size();

		if (x >= m || y >= n)
			return false;
		return true;
	}

private:
	std::array<std::array<int, 2>, 4> direct = {
		-1,0, // 上
		0,1,  // 右
		1,0,  // 下
		0,-1  // 左
	};
	std::vector<std::vector<int>> res;
};
#endif // !_417_H

