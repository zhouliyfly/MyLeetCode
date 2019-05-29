#ifndef _341_H //��ƽ��Ƕ���б���������������⣩
#define _341_H
#include "MyUtility.h"
#include <vector>
#include <stack>

// LeetCode��ֻ������NestedInteger��Ķ��壬û��ʵ�֡�����򵥵�ʵ�����ڲ���
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

// �����ջ�ǳ�����ϵͳ�ĺ�������ջ�������ڲ��vectorʱ����¼����vector�������ڲ�vector
// �ڲ�vector���ʽ�����ص����vector������ջʵ�֣��纯������һ��
class NestedIterator {
public:
	NestedIterator(std::vector<NestedInteger> &nestedList) {
		begins.push(nestedList.begin());
		ends.push(nestedList.end());
	}

	int next() {
		return (begins.top()++)->getInteger(); //����ջ��Ԫ��
	}

	bool hasNext() {
#if 0
		while (!begins.empty()) {
			if (begins.top() == ends.top()) { //һ��vector�������
				begins.pop();
				ends.pop();
			}
			else { // ���ʵ�ǰvector
				if (begins.top()->isInteger()) // ��ǰ�ڵ�����ֵ
					return true;

				/* 
				 * ����������һ���ܴ�Ĵ���
				 * v��һ��vector���ֲ�������begins.push�����Ա��ջ��
				 * ���ǵ�ǰ����ִ����֮��v���ͷţ�ջ�е�����ʧЧ��
				 * ����취����������һ���������ʾ�����룬����v������������ڶ���
				 * ��ʹ����������auto& v;
				 */
				auto v = begins.top()->getList(); //? ��ǰ�ڵ���vector����ȡvector
				begins.top()++; // ������ǰ����������һ���ڵ㣬֮������ڲ�
				begins.push(v.begin());  // ��ջ��һ��ĵ�����
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
	// ÿһ�㿴��һ��vector��ÿ����һ������������
	std::stack<std::vector<NestedInteger>::const_iterator> begins; // ��¼ÿ���vector������
	std::stack<std::vector<NestedInteger>::const_iterator> ends; // ��¼ÿ��vector��β������
};
#endif // !_341_H