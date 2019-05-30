#ifndef _200_H //岛屿数量
#define _200_H
#include <vector>

// 可能只是递归(DFS)，不算标准回溯
class Solution_200 {
public:
	int numIslands(std::vector<std::vector<char>>& grid) {
		if (grid.empty())
			return 0;

		visited = std::vector<std::vector<bool>>(grid.size(), std::vector<bool>(grid[0].size(), false));
		count = 0;

		for (size_t i = 0; i != grid.size(); ++i) {
			for (size_t j = 0; j != grid[i].size(); ++j) {
				if (grid[i][j] == '1' && !visited[i][j]) {
					dfs(grid, i, j);
					count++;
				}		
			}
		}
		return count;
	}

private:
	void dfs(std::vector<std::vector<char>>& grid, size_t x, size_t y) {
		visited[x][y] = true;
		for (size_t i = 0; i != direct.size(); ++i) {
			size_t newX = x + direct[i][0];
			size_t newY = y + direct[i][1];
			if (isAvalible(grid, newX, newY) && !visited[newX][newY]
					&& grid[newX][newY] == '1') {
				dfs(grid, newX, newY);
			}
		}
	}

	bool isAvalible(std::vector<std::vector<char>>& grid, size_t x, size_t y) {
		if (x >= grid.size())
			return false;
		if (y >= grid[0].size())
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

	std::vector<std::vector<bool>> visited;
	int count{0};
};
#endif // !_200_H

