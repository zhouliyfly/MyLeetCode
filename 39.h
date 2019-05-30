#ifndef _39_H //����ܺ�
#define _39_H
#include <vector>

//�������֣����� target��������������������Ϊ�����鷳�ࣩܶ
class Solution_39 {
public:
	std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
		if (candidates.empty())
			return res;

		std::vector<int> vec;
		findcombinationSum(candidates, target, 0, vec);
		return res;
	}
private:
	void findcombinationSum(std::vector<int>& candidates, int target, int index, std::vector<int>& vec) {
		if (0 == target) {
			res.push_back(vec);
			return;
		}
		if (target < 0)
			return;
		for (size_t i = index; i != candidates.size(); ++i) {
			vec.push_back(candidates[i]);
			findcombinationSum(candidates, target - candidates[i], i, vec);
			vec.pop_back();
		}
	}

	// ���Լ�֦
	void findcombinationSum2(std::vector<int>& candidates, int target, int index, std::vector<int>& vec) {
		if (0 == target) {
			res.push_back(vec);
			return;
		}
		if (target < 0)
			return;
		for (size_t i = index; i != candidates.size(); ++i) {
			vec.push_back(candidates[i]);
			findcombinationSum(candidates, target - candidates[i], i, vec);
			vec.pop_back();
		}
	}
private:
	std::vector<std::vector<int>> res;
};

// ��֦
class Solution_39_2 {
public:
	std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
		if (candidates.empty())
			return res;
		
		std::sort(candidates.begin(), candidates.end());
		std::vector<int> vec;
		findcombinationSum(candidates, target, 0, vec);
		return res;
	}
private:
	
	void findcombinationSum(std::vector<int>& candidates, int target, int index, std::vector<int>& vec) {
		if (0 == target) {
			res.push_back(vec);
			return;
		}

		for (size_t i = index; i != candidates.size(); ++i) {
			if (target - candidates[i] < 0)
				break;
			vec.push_back(candidates[i]);
			findcombinationSum(candidates, target - candidates[i], i, vec);
			vec.pop_back();
		}
	}
private:
	std::vector<std::vector<int>> res;
};
#endif // !_39_H
