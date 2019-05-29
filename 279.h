#ifndef _279_H //��ȫƽ����
#define _279_H
#include <cassert>
#include <queue>
#include <stdexcept>
#include <iostream>

/* ���⽨ģʹ����Ȩͼ�����·������⣨BFS������Щ����

*   ˼·��һ���������ֽ�Ϊ�����ȫƽ�����ĺͿ����ж��ֽⷨ��Ҫ�����и������ٵĽ⡣���Կ���һ����
*      ��0�ж����ͬ��·��������̵�·������ģ�ؼ�����ͼ�Ľڵ�ͱ���ζ��壬һ�ֺ���Ȼ���뷨�ǽڵ㶨��Ϊ��ȫƽ������
       ��ʱ��û���ر�����壬���Ҵ��ֽ��nֵ���ܲ�����Ϊ�ڵ㣬��Ϊ��δ������ȫƽ����������˼·����Ȼ����ȷ��
	   ��һ��˼·�Ǳ߶���Ϊ��ȫƽ�������ڵ������������໥��ϵ������������ɸ���ȫƽ������
*/

// ������������һ���н⡣��Ϊ1����ȫƽ���������������������Էֽ�Ϊ���1���
class Solution_279 {
public:
	// from������getNums�����������n������ƽ������ԭ��û��Ҫ��
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
		// ���������ƽ����
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
