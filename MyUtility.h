#ifndef _MY_UTILITY_H
#define _MY_UTILITY_H
#include <vector>
#include <ostream>
#include <string>
#include <sstream>

// 用于测试链表问题的辅助函数

struct ListNode {
	ListNode(int x) :val(x), next(nullptr) {}
	int val;
	ListNode* next;
};

// 用于测试二叉树问题的辅助函数
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class MyUtility {
public:
	ListNode* createLinkedList(int[], int);
	ListNode* createLinkedList(std::vector<int>);
	void delLinkedList(ListNode*);
	void printLinkedList(std::ostream&, ListNode*);

	TreeNode* createTree(const std::vector<std::string>&);
	TreeNode* findNode(TreeNode*, int);
	void delTree(TreeNode*);
	void printTree(std::ostream&, TreeNode*);

	std::vector<std::string> getStringToVec(const std::string&);
	std::vector<char> getStringToVecChar(const std::string & s);
};

enum class CommandType { Go, Print };
struct Command {
	//std::string _s;
	CommandType _commandtype;
	TreeNode* _node;
	Command(CommandType t, TreeNode* node) :_commandtype(t), _node(node) {}
};
#endif // !_MY_UTILITY_H

