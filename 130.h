#ifndef _130_H //��Χ�Ƶ�����
#define _130_H
#include <vector>
#include <array>

class Solution_130 {
public:
	void solve(std::vector<std::vector<char>>& board) {
		if (board.size() <= 2 || board[0].size() <= 2)
			return;

		id = std::vector<std::vector<int>>(board.size(), std::vector<int>(board[0].size(), 0));
		visited = std::vector<std::vector<bool>>(board.size(), std::vector<bool>(board[0].size(), false));
		count = 0;

		for (size_t i = 1; i != board.size() - 1; ++i) { //�����߽�
			for (size_t j = 1; j != board[i].size() - 1; ++j) {
				//sign��־�����������Ƿ�����ڱ߽�
				bool sign = false; 
				if (board[i][j] == 'O' && !visited[i][j]) {
					count++;
					dfs(board, i, j, sign);
					if(!sign)
						fillArea(board, count);
				}
			}
		}
	}

private:
	void dfs(std::vector<std::vector<char>>& board, size_t x, size_t y, bool& sign) {
		id[x][y] = count;
		visited[x][y] = true;
		for (size_t i = 0; i != direct.size(); ++i) {
			size_t newX = x + direct[i][0];
			size_t newY = y + direct[i][1];
			if (isAvalible(board, newX, newY) && board[newX][newY] == 'O' && !visited[newX][newY]) {
				if (isEdge(board, newX, newY))
					sign = true;
				dfs(board, newX, newY, sign);
			}
		}
	}

	// ���ָ������
	void fillArea(std::vector<std::vector<char>>& board, int count) {
		for (size_t i = 1; i != board.size(); ++i) {
			for (size_t j = 1; j != board[i].size(); ++j) {
				if (id[i][j] == count)
					board[i][j] = 'X';
			}
		}
	}

	// ������Ч�Լ��
	bool isAvalible(std::vector<std::vector<char>>& board, size_t x, size_t y) {
		if (x >= board.size())
			return false;
		if (y >= board[0].size())
			return false;
		return true;
	}

	// �ж�������Ƿ��ڱ߽�
	bool isEdge(std::vector<std::vector<char>>& board, size_t x, size_t y) {
		if (0 == x || x == board.size() - 1 || 
			0 == y || y == board[0].size()-1)
			return true;
		return false;
	}

private:
	std::array<std::array<int, 2>, 4> direct = {
		-1,0, // ��
		0,1,  // ��
		1,0,  // ��
		0,-1  // ��
	};

	std::vector<std::vector<int>> id;
	std::vector<std::vector<bool>> visited;
	int count{ 0 };
};
#endif // !_130_H
