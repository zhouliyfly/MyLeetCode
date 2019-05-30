#ifndef _79_H //��������
#define _79_H
#include <vector>
#include <string>
#include <array>


// �����ά����֪�Ƿ�֤ÿ�����ݵĸ�����ͬ
class Solution_79 {
public:
	bool exist(std::vector<std::vector<char>>& board, std::string word) {
		if (board.empty() || word.empty())
			return false;
		
		// ��ά����ÿ��������ͬ
		//visited = std::vector<std::vector<bool>>(board.size(), std::vector<bool>(board.size(), false));

		//��ά����ÿ��������ͬ
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
	// �����߱�֤����x, y��Ч
	bool search(std::vector<std::vector<char>>& board, std::string word, size_t word_index, size_t x, size_t y) {
		if (word_index == word.size() - 1) {
			if (word[word_index] == board[x][y])
				return true;
			return false;
		}
	
		if (word[word_index] != board[x][y])
			return false;
		visited[x][y] = true;
		// �����������ĸ�����ǰ��
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

	// ����ά�����ܱ�֤ÿ�и�����ͬ����������ĺ�����֤������Ч��
	// ���򣬺������Լ�
	bool isAvalible(std::vector<std::vector<char>>& board, size_t x, size_t y) {
		if (x >= board.size())
			return false;
		if (y >= board[x].size())
			return false;
		return true;
	}
private:
	// array�Ķ�ά���鶨�������ַ�ʽ��һ������������˫�����ţ�
	//����һ����ֻ��һ������ţ���
	// std::array<std::array<int, 2>, 4> a{1,2,3,4,5,6,7,8};
	// ԭ����

	std::array<std::array<int, 2>, 4> direct = {{
		{-1, 0}, //��
		{0, 1},  //��
		{1, 0},  //��
		{0, -1}  //��
	}};

	// �������ķ���״̬
	std::vector<std::vector<bool>> visited;
};
#endif // !_79_H