#ifndef _341_H //扁平化嵌套列表迭代器（设计问题）
#define _341_H
#include "MyUtility.h"
#include <vector>
#include <stack>

// LeetCode中只给出了NestedInteger类的定义，没有实现。下面简单的实现用于测试
class NestedInteger {
public:
	NestedInteger(bool isInt, int data, std::vector<NestedInteger> vec)
		:isInt_(isInt), data_(data), vec_(vec) {}

	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const { return isInt_; }

	// Return the single integer that this NestedInteger holds, if it holds a single integer
   // The result is undefined if this NestedInteger holds a nested list
	int getInteger() const { return data_; }

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const std::vector<NestedInteger> &getList() const { return vec_; }

private:
	bool isInt_;
	int data_;
	std::vector<NestedInteger> vec_;
};

// 本题的栈非常类似系统的函数调用栈，当有内层的vector时，记录外层的vector，进入内层vector
// 内层vector访问结束后回到外层vector，利用栈实现，如函数调用一般
class NestedIterator {
public:
	NestedIterator(std::vector<NestedInteger> &nestedList) {
		begins.push(nestedList.begin());
		ends.push(nestedList.end());
	}

	int next() {
		return (begins.top()++)->getInteger(); //操作栈顶元素
	}

	bool hasNext() {
#if 0
		while (!begins.empty()) {
			if (begins.top() == ends.top()) { //一个vector访问完成
				begins.pop();
				ends.pop();
			}
			else { // 访问当前vector
				if (begins.top()->isInteger()) // 当前节点是数值
					return true;

				/* 
				 * 这里隐藏了一个很大的错误
				 * v是一个vector，局部变量。begins.push将其成员入栈，
				 * 但是当前代码执行完之后v被释放，栈中的内容失效。
				 * 解决办法有两个，第一个是下面的示例代码，变量v保存迭代器；第二个
				 * 是使用引用类型auto& v;
				 */
				auto v = begins.top()->getList(); //? 当前节点是vector，获取vector
				begins.top()++; // 操作当前迭代器到下一个节点，之后进入内层
				begins.push(v.begin());  // 入栈新一层的迭代器
				ends.push(v.end());
			}
		}
		return false;
#else
		while (begins.size())
		{
			if (begins.top() == ends.top())
			{
				begins.pop();
				ends.pop();
	}
			else
			{
				auto val = begins.top();
				if (val->isInteger()) return true;
				begins.top()++;
				begins.push(val->getList().begin());
				ends.push(val->getList().end());
			}
}
		return false;
#endif
	}

private:
	// 每一层看成一个vector，每层用一个迭代器跟踪
	std::stack<std::vector<NestedInteger>::const_iterator> begins; // 记录每层的vector迭代器
	std::stack<std::vector<NestedInteger>::const_iterator> ends; // 记录每层vector的尾迭代器
};
#endif // !_341_H
