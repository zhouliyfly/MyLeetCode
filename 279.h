#ifndef _279_H //完全平方数
#define _279_H
#include <cassert>
#include <queue>
#include <stdexcept>
#include <iostream>

/* 本题建模使用无权图的最短路径法求解（BFS），有些复杂

*   思路：一个正整数分解为多个完全平方数的和可以有多种解法，要求其中个数最少的解。可以看成一个数
*      到0有多个不同的路径，求最短的路径。建模关键在于图的节点和边如何定义，一种很自然的想法是节点定义为完全平方数，
       此时边没有特别的意义，而且待分解的n值可能不能作为节点，因为其未必是完全平方数，这种思路很显然不正确；
	   另一种思路是边定义为完全平方数，节点的数由特殊的相互关系，都是相差若干个完全平方数。
*/

// 给定正整数，一定有解。因为1是完全平方数，所有正整数都可以分解为多个1相加
class Solution_279 {
public:
	// from变量和getNums函数用于输出n包含的平方数，原题没有要求
	int numSquares(int n) {
		assert(n > 0);

		std::queue<std::pair<int, int>> q;
		std::vector<bool> visited(n + 1, false);
		//std::vector<int> from(n + 1, 0);
		visited[n] = true;
		q.push(std::make_pair(n, 0));
		while (!q.empty()) {
			int num = q.front().first;
			int step = q.front().second;
			q.pop();

			for (int i = 1;/**/; i++) {
				int a = num - i * i;
				if (a == 0) {
					//from[0] = num;
					//getNums(n, from);
					return step + 1;
				}
					
				if (a < 0)
					break;
				if (!visited[a]) {
					q.push(std::make_pair(a, step + 1));
					//from[a] = num;
					visited[a] = true;
				}
			}
		}
		throw std::invalid_argument("error");
	}

	void getNums(int n, std::vector<int>& from) {
		// 输出包含的平方数
		std::vector<int> vec;
		int i = 0;
		while (n != from[i]) {
			vec.push_back(from[i] - i);
			i = from[i];
		}
		vec.push_back(n - i);
		std::cout << "explain:";
		for (size_t j = 0; j != vec.size(); ++j) {
			if (j != vec.size() - 1)
				std::cout << vec[j] << "+";
			else
				std::cout << vec[j];
		}
			
		std::cout << std::endl;
	}
};

#endif // !_279_H

