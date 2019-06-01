#include "MyUtility.h"

ListNode* MyUtility::createLinkedList(std::vector<int> vec) {
	if (vec.empty())
		return nullptr;

	ListNode* head = new ListNode(vec[0]);
	ListNode* cur = head;
	for (decltype(vec.size()) i = 1; i != vec.size(); ++i) {
		cur->next = new ListNode(vec[i]);
		cur = cur->next;
	}
	return head;
}

ListNode* MyUtility::createLinkedList(int arr[], int n) {
	if (0 == n)
		return nullptr;

	ListNode* head = new ListNode(arr[0]);
	ListNode* cur = head;
	for (int i = 1; i < n; i++) {
		cur->next = new ListNode(arr[i]);
		cur = cur->next;
	}
	return head;
}

void MyUtility::delLinkedList(ListNode* head) {
	while (head != nullptr) {
		ListNode* delNode = head;
		head = head->next;
		delete delNode;
	}
}

void MyUtility::printLinkedList(std::ostream& os, ListNode* head) {
	ListNode* cur = head;
	while (cur != nullptr) {
		os << cur->val << "-->";
		cur = cur->next;
	}
	os << "nullptr" << std::endl;
}

#include <queue>
#include <string>
TreeNode * MyUtility::createTree(const std::vector<std::string>& nums)
{
	if (nums.empty() || nums[0] == "null")
		return nullptr;

	std::queue<TreeNode*> q;
	TreeNode* head = new TreeNode(std::stoi(nums[0]));
	q.push(head);
	size_t i = 1;
	while(i < nums.size()){
		TreeNode* cur = q.front();
		q.pop();
		if (i != nums.size() && nums[i] != "null") {
			cur->left = new TreeNode(std::stoi(nums[i]));
			q.push(cur->left);
		}	
		i++;
		if (i != nums.size() && nums[i] != "null") {
			cur->right = new TreeNode(std::stoi(nums[i]));
			q.push(cur->right);
		}	
		i++;
	}

	return head;
}

TreeNode * MyUtility::findNode(TreeNode* root, int key)
{
	if (root == nullptr)
		return root;

	if (root->val == key)
		return root;

	auto node = findNode(root->left, key);
	if(node == nullptr)
		node = findNode(root->right, key);
	return node;
}

void MyUtility::delTree(TreeNode* node)
{
	if (node) {
		delTree(node->left);
		delTree(node->right);
		delete node;
	}
}

void MyUtility::printTree(std::ostream& os, TreeNode * node)
{
	if (node == nullptr)
		return;

	std::queue<TreeNode*> q;
	q.push(node);
	while (!q.empty()) {
		TreeNode* cur = q.front();
		os << cur->val << " ";
		q.pop();
		if(cur->left)
			q.push(cur->left);
		if(cur->right)
			q.push(cur->right);
	}
}

std::vector<std::string> MyUtility::getStringToVec(const std::string & s)
{
	std::vector<std::string> vec;
	if (s.empty())
		return vec;

	std::string str;
	if (s[0] == '[' && s[s.size() - 1] == ']') {
		std::copy(s.begin() + 1, s.end() - 1, std::back_inserter(str));
	}
	else
		str = s;

	std::istringstream iss(str);
	for (std::string str; std::getline(iss, str, ',');) {
		vec.push_back(str);
	}
	return vec;
}

std::vector<char> MyUtility::getStringToVecChar(const std::string & s)
{
	std::vector<char> vec;
	if (s.empty())
		return vec;

	std::string str;
	if (s[0] == '[' && s[s.size() - 1] == ']') {
		std::copy(s.begin() + 1, s.end() - 1, std::back_inserter(str));
	}
	else
		str = s;

	std::istringstream iss(str);
	for (std::string str; std::getline(iss, str, ',');) {
		vec.push_back(str[0]);
	}
	return vec;
}
