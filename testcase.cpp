#include "testcase.h"

#include <vector>

void TestCase::test27(std::ostream& os) {
	Solution_27 s27;
	std::vector<int> v27 = { 1,1 };

	size_t sz = s27.removeElement(v27, 1);

	os << sz << ":";
	for (auto v : v27)
		os << v << " ";
	os << std::endl;
}

void TestCase::test26(std::ostream & os)
{
	Solution_26 s26;
	std::vector<int> v26 = { 1,1,2,4,5,6,6,7,7,8,8,8,8,9,11 };

	size_t sz = s26.removeDuplicates(v26);

	os << sz << ":";
	for (auto v : v26)
		os << v << " ";
	os << std::endl;
}

void TestCase::test80(std::ostream & os)
{
	Solution_80 s80;
	std::vector<int> v80 = { 1,1,1,2,2,3 };

	size_t sz = s80.removeDuplicates(v80);

	os << sz << ":";
	for (auto v : v80)
		os << v << " ";
	os << std::endl;
}

void TestCase::test75(std::ostream & os)
{
	Solution_75 s75;
	std::vector<int> v75 = { 2,0,2,1,1,0 };

	s75.sortColors(v75);

	for (auto v : v75)
		os << v << " ";
	os << std::endl;
}

void TestCase::test88(std::ostream & os)
{
	Solution_88 s88;
	std::vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
	std::vector<int> nums2 = { 2, 5, 6 };
	int m = 3;
	int n = 3;
	s88.merge(nums1, m, nums2, n);

	for (auto v : nums1)
		os << v << " ";
	os << std::endl;
}

void TestCase::test215(std::ostream & os)
{
	Solution_215 s215;
	std::vector<int> nums1 = { 3,2,1,5,6,4 };
	int k1 = 2;
	std::vector<int> nums2 = { 3,2,3,1,2,4,5,5,6 };
	int k2 = 4;

	for (auto v : nums1)
		os << v << " ";
	os << ",k=" << k1 << "\n" << "out:" << s215.findKthLargest(nums1, k1) << std::endl;
	for (auto v : nums2)
		os << v << " ";
	os << ",k=" << k2 << "\n" << "out:" << s215.findKthLargest(nums2, k2) << std::endl;
}

void TestCase::test167(std::ostream & os)
{
	Solution_167 s167;
	std::vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;

	auto res = s167.twoSum(nums, target);
	for (auto v : nums)
		os << v << " ";
	os << ",target=" << target << "\n";
	os << "[" << res[0] << "," << res[1] << "]" << std::endl;
	
}

void TestCase::test125(std::ostream & os)
{
	Solution_125 s125;
	std::string s1 = "A man, a plan, a canal: Panama";
	std::string s2 = "race a car";

	os << s1 << "---> " << s125.isPalindrome(s1) << "\n";
	os << s2 << "--->" << s125.isPalindrome(s2) << std::endl;
}

void TestCase::test344(std::ostream & os)
{
	Solution_344 s344;
	std::vector<char> v344 = { 'h','e','l','l','o' };

	for (auto val : v344)
		os << val << " ";
	os << std::endl;

	s344.reverseString(v344);
	for (auto val : v344)
		os << val << " ";
	os << std::endl;
}

void TestCase::test345(std::ostream & os)
{
	std::string s = "leetcode";
	Solution_345 s345;

	os << s << "\n"
		<< s345.reverseVowels(s) << std::endl;
}

void TestCase::test11(std::ostream & os)
{
	Solution_11 s11;
	std::vector<int> v11 = { 1,8,6,2,5,4,8,3,7 };

	for (auto val : v11)
		os << val << " ";
	os << "\n" << s11.maxArea(v11) << std::endl;
}

void TestCase::test209(std::ostream & os)
{
	Solution_209 s209;
	std::vector<int> v209 = { 1,1 };
	int s = 3;

	for (auto val : v209)
		os << val << " ";

	os << "\n" << s209.minSubArrayLen(s, v209);
}

void TestCase::test3(std::ostream & os)
{
	Solution_3 s3;
	std::string str1 = "abcabcbb";
	std::string str2 = "bbbbb";
	std::string str3 = "pwwkew";

	os << str1 << ":" << s3.lengthOfLongestSubstring(str1) << std::endl;
	os << str2 << ":" << s3.lengthOfLongestSubstring(str2) << std::endl;
	os << str3 << ":" << s3.lengthOfLongestSubstring(str3) << std::endl;
}

void TestCase::test438(std::ostream & os)
{
	Solution_438 s438;
	std::string s = "cbaebabacd";
	std::string p = "abc";

	os << "s:" << s << " " << "p:" << p << "\n";
	os << "[";
	auto vec = s438.findAnagrams2(s, p);
	for (decltype(vec.size()) i = 0; i != vec.size() - 1; ++i) {
		os << vec[i] << ",";
	}
	os << *(vec.end()-1) << "]" << std::endl;
}

void TestCase::test76(std::ostream & os)
{
	Solution_76 s76;
	std::string s = "ADOBECODEBANC";
	std::string t = "AA";

	os << "s=" << s << ",t=" << t << "\n";
	os << "out:" << s76.minWindow1(s, t);
}

void TestCase::test349(std::ostream & os)
{
	Solution_349 s349;
	std::vector<int> nums1 = { 1,2,2,1 };
	std::vector<int> nums2 = { 2,2 };

	os << "[";
	for (const auto& val : nums1)
		os << val << ",";
	os << "\b], [";
	for (const auto& val : nums2)
		os << val << ",";
	os << "\b]" << "\n";
	os << "[";
	for (const auto& val : s349.intersection(nums1, nums2))
		os << val << ",";
	os << "\b]" << std::endl;

}

void TestCase::test350(std::ostream & os)
{
	Solution_350 s350;
	std::vector<int> nums1 = { 4,9,5 };
	std::vector<int> nums2 = { 9,4,9,8,4 };

	os << "[";
	for (const auto& val : nums1)
		os << val << ",";
	os << "\b], [";
	for (const auto& val : nums2)
		os << val << ",";
	os << "\b]" << "\n";
	os << "[";
	for (const auto& val : s350.intersect(nums1, nums2))
		os << val << ",";
	os << "\b]" << std::endl;
}

void TestCase::test242(std::ostream & os)
{
	Solution_242 s242;
	std::string s = "anagram";
	std::string t = "nagaram";

	os << "s=" << s << ",t=" << t << "\n";
	os << "out:" << s242.isAnagram2(s, t) << std::endl;
}

void TestCase::test202(std::ostream & os)
{
	Solution_202 s202;
	int n = 122;

	os << "n=" << n << "\n";
	os << s202.isHappy(n) << std::endl;
}

void TestCase::test290(std::ostream & os)
{
	Solution_290 s290;
	std::string pattern = "aa";
	std::string str = "aa aa aa aa";

	os << "input: pattern = " << pattern << ", str = " << str << "\n";
	os << "output: " << s290.wordPattern2(pattern, str) << std::endl;
}

void TestCase::test205(std::ostream & os)
{
	Solution_205 s205;
	std::string s = "paper";
	std::string t = "title";

	os << "input: s = " << s << ", t = " << t << "\n";
	os << "output: " << s205.isIsomorphic(s, t) << std::endl;
}

void TestCase::test451(std::ostream & os)
{
	Solution_451 s451;
	std::string s = "loveleetcode";

	os << "input: " << s << "\n";
	os << "output: " << s451.frequencySort(s) << std::endl;
}

void TestCase::test1(std::ostream & os)
{
	Solution_1 s1;
	std::vector<int> nums = { 2, 11, 7, 15 };
	int target = 9;
	std::vector<int> res = s1.twoSum2(nums, 9);

	os << "[";
	for (auto val : nums)
		os << val << ",";
	os << "\b], target = " << target << "\n";
	os << "[" << res[0] << ", " << res[1] << "]" << std::endl;
}

void TestCase::test15(std::ostream & os)
{
	Solution_15 s15;
	std::vector<int> nums = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	os << "[";
	for (auto val : nums)
		os << val << ",";
	os << "\b]" << std::endl;

	os << nums.size() << std::endl;
	clock_t start = clock();
	auto res = s15.threeSum(nums);
	os << double((clock() - start)) / CLOCKS_PER_SEC << std::endl;
	os << "[\n";
	for (const auto& vec : res) {
		os << "\t[";
		for (auto val : vec)
			os << val << ",";
		os << "\b],\n";
	}
	os << "]" << std::endl;
}

void TestCase::test18(std::ostream & os)
{
	Solution_18 s18;
	std::vector<int> nums = { 0,0,0,0 };
	int target = 0;
	os << "[";
	for (auto val : nums)
		os << val << ",";
	os << "\b]" << std::endl;

	clock_t start = clock();
	auto res = s18.fourSum(nums, target);
	os << double((clock() - start)) / CLOCKS_PER_SEC << std::endl;
	os << "[\n";
	for (const auto& vec : res) {
		os << "\t[";
		for (auto val : vec)
			os << val << ",";
		os << "\b],\n";
	}
	os << "]" << std::endl;
}

void TestCase::test16(std::ostream & os)
{
	Solution_16 s16;
	std::vector<int> nums = { -1,2,1, - 4 };
	int target = 1;

	os << "[";
	for (auto val : nums)
		os << val << ",";
	os << "\b], target = " <<  target << std::endl;
	os << "sum = " << s16.threeSumClosest(nums, target) << std::endl;
}

void TestCase::test454(std::ostream & os)
{
	Solution_454 s454;
	std::vector<int> nums1 = { 1,2 };
	std::vector<int> nums2 = { -2,-1 };
	std::vector<int> nums3 = { -1,2 };
	std::vector<int> nums4 = { 0,2 };

	os << s454.fourSumCount(nums1, nums2, nums3, nums4) << std::endl;
}

void TestCase::test49(std::ostream & os)
{
	Solution_49 s49;
	std::vector<std::string> nums = { "eat", "tea", "tan", "ate", "nat", "bat" };

	s49.groupAnagrams1(nums);
	auto res = s49.groupAnagrams(nums);
	os << "[\n";
	for (const auto& vec : res) {
		os << "\t[";
		for (auto val : vec)
			os << val << ",";
		os << "\b],\n";
	}
	os << "]" << std::endl;
}

void TestCase::test447(std::ostream & os)
{
	Solution_447 s447;
	std::vector<std::pair<int, int>> vec;
	//[0, 0], [1, 0], [2, 0]
	vec.push_back(std::make_pair(0, 0));
	vec.push_back(std::make_pair(1, 0));
	vec.push_back(std::make_pair(2, 0));

	os << s447.numberOfBoomerangs(vec) << std::endl;
}

void TestCase::test149(std::ostream & os)
{
	Solution_149 s149;
	/*auto p = s149.linear_parameters({ 0,1 }, { 2,4 });
	os << "k = " << p.first << "\n";
	os << "b = " << p.second << std::endl;*/
	//std::vector<std::vector<int>> vec{ {0,0}, {94911151,94911150}, {94911152,94911151} };
	std::vector<std::vector<int>> vec{ {2,3}, {3,3}, {-5,3} };
	os << s149.maxPoints(vec) << std::endl;
	/*Fraction f1(2, 3);
	Fraction f2(-2, 3);
	Fraction f3(0, 3);
	Fraction f4(0, 9);

	os << (f1 == f2) << std::endl;
	os << (f3 == f4) << std::endl;
	os << (f1 == f3) << std::endl;

	std::vector< Fraction> vec1{ Fraction(0,3), Fraction(1,3) };
	std::vector< Fraction> vec2{ Fraction(0,7), Fraction(1,3) };
	os << (vec1 == vec2) << std::endl;*/
}

void TestCase::test206(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* head = my_utility.createLinkedList({ 1,2,3,4,5 });
	my_utility.printLinkedList(os, head);
	head = Solution_206().reverseList(head);
	my_utility.printLinkedList(os, head);
}

void TestCase::test92(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* head = my_utility.createLinkedList({ 1,2,3,4,5 });
	int m = 2;
	int n = 4;
	my_utility.printLinkedList(os, head);
	head = Solution_92().reverseBetween(head, m, n);
	my_utility.printLinkedList(os, head);
}

void TestCase::test83(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* head = my_utility.createLinkedList({ 1,1,2,3,3 });
	my_utility.printLinkedList(os, head);
	head = Solution_83().deleteDuplicates(head);
	my_utility.printLinkedList(os, head);
}

void TestCase::test86(std::ostream & os)
{
	MyUtility my_utility;
	int x = 3;
	ListNode* head = my_utility.createLinkedList({ 1,4,3,2,5,2 });
	my_utility.printLinkedList(os, head);
	head = Solution_86().partition(head, x);
	my_utility.printLinkedList(os, head);
}

void TestCase::test328(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* head = my_utility.createLinkedList({ 2,1,3,5,6,4,7 });
	my_utility.printLinkedList(os, head);
	head = Solution_328().oddEvenList(head);
	my_utility.printLinkedList(os, head);
}

void TestCase::test2(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* l1 = my_utility.createLinkedList({ 9,1,6 });
	ListNode* l2 = my_utility.createLinkedList({ 0 });
	my_utility.printLinkedList(os, l1);
	my_utility.printLinkedList(os, l2);
	ListNode* res = Solution_2().addTwoNumbers(l1, l2);
	my_utility.printLinkedList(os, res);
}

void TestCase::test445(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* l1 = my_utility.createLinkedList({ 7,2,4,3 });
	ListNode* l2 = my_utility.createLinkedList({ 5,6,4 });
	my_utility.printLinkedList(os, l1);
	my_utility.printLinkedList(os, l2);
	ListNode* res = Solution_445().addTwoNumbers(l1, l2);
	my_utility.printLinkedList(os, res);
}

void TestCase::test203(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* l1 = my_utility.createLinkedList({ 1,2,6,3,4,5,6 });
	int val = 6;
	my_utility.printLinkedList(os, l1);
	ListNode* res = Solution_203().removeElements(l1, val);
	my_utility.printLinkedList(os, res);
}

void TestCase::test82(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* l1 = my_utility.createLinkedList({ 1,1});
	my_utility.printLinkedList(os, l1);
	ListNode* res = Solution_82().deleteDuplicates(l1);
	my_utility.printLinkedList(os, res);
}

void TestCase::test21(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* l1 = my_utility.createLinkedList({ 1,2,4 });
	ListNode* l2 = my_utility.createLinkedList({ 1,3,4 });
	my_utility.printLinkedList(os, l1);
	my_utility.printLinkedList(os, l2);
	ListNode* res = Solution_21().mergeTwoLists(l1, l2);
	my_utility.printLinkedList(os, res);
}

void TestCase::test24(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* l1 = my_utility.createLinkedList({ 1,2,3,4,5 });
	my_utility.printLinkedList(os, l1);
	ListNode* res = Solution_24().swapPairs(l1);
	my_utility.printLinkedList(os, res);
}

void TestCase::test25(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* l1 = my_utility.createLinkedList({ 1,2,3,4,5 });
	int k = 3;
	my_utility.printLinkedList(os, l1);
	ListNode* res = Solution_25().reverseKGroup(l1, k);
	my_utility.printLinkedList(os, res);
}

void TestCase::test147(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* l1 = my_utility.createLinkedList({ 4,2,1,3 });
	my_utility.printLinkedList(os, l1);
	ListNode* res = Solution_147().insertionSortList(l1);
	my_utility.printLinkedList(os, res);
}

void TestCase::test148(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* l1 = my_utility.createLinkedList({ 4,3,2,1 });
	my_utility.printLinkedList(os, l1);
	clock_t start = clock();
	//ListNode* res = Solution_148().sortList(l1);
	ListNode* res = Solution_148().sortList_no_rec(l1);
	clock_t end = clock();
	my_utility.printLinkedList(os, res);
	os << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s" << std::endl;
}

void TestCase::test237(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* l1 = my_utility.createLinkedList({ 4,5,1,9 });
	my_utility.printLinkedList(os, l1);
	ListNode* node = l1->next;
	Solution_237().deleteNode(node);
	my_utility.printLinkedList(os, l1);
}

void TestCase::test19(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* l1 = my_utility.createLinkedList({ 1,2,3,4,5 });
	int n = 2;
	my_utility.printLinkedList(os, l1);
	ListNode* res = Solution_19().removeNthFromEnd(l1, n);
	my_utility.printLinkedList(os, res);
}

void TestCase::test61(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* l1 = my_utility.createLinkedList({ 0,1,2 });
	int k = 4;
	my_utility.printLinkedList(os, l1);
	ListNode* res = Solution_61().rotateRight(l1, k);
	my_utility.printLinkedList(os, res);
}

void TestCase::test143(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* l1 = my_utility.createLinkedList({ 1,2 });
	my_utility.printLinkedList(os, l1);
	Solution_143().reorderList(l1);
	my_utility.printLinkedList(os, l1);
}

void TestCase::test234(std::ostream & os)
{
	MyUtility my_utility;
	ListNode* l1 = my_utility.createLinkedList({ 1,2,2 });
	my_utility.printLinkedList(os, l1);
	os << Solution_234().isPalindrome(l1) << std::endl;
}

void TestCase::test20(std::ostream & os)
{
	std::string s = "{[]}";
	os << Solution_20().isValid(s) << std::endl;
}

void TestCase::test150(std::ostream & os)
{
	std::vector<std::string> vec = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	os << Solution_150().evalRPN(vec) << std::endl;
}

void TestCase::test71(std::ostream & os)
{
	std::string path = "/a/../../b/../c//.//";
	os << Solution_71().simplifyPath(path) << std::endl;
}

void TestCase::test144(std::ostream & os)
{

}

void TestCase::test94(std::ostream & os)
{
}

void TestCase::test341(std::ostream & os)
{
	NestedInteger n1(false, 0, { NestedInteger(true, 1, {}), NestedInteger(true, 2, {}) });
	NestedInteger n2(false, 0, { NestedInteger(true, 3, {}),  NestedInteger(false, 0, {NestedInteger(true, 4, {})}) });
	std::vector<NestedInteger> v = { n1,n2 };
	NestedIterator iter(v);
	while (iter.hasNext()) {
		os << iter.next() << ",";
	}
	os << std::endl;
}

void TestCase::test279(std::ostream & os)
{
	int n = 13;
	os << "input:" << "n=" << n << "\n";
	os << "output:" << Solution_279().numSquares(n) << std::endl;
}

void TestCase::test127(std::ostream & os)
{
	std::string beginWord = "zings";
	std::string	endWord = "brown";
	std::vector<std::string> wordList = { "chump","sours","mcgee","piers","match","folds","rinse","films","small","umbel","assad","morin","plied","basin","moots","blurb","suits","solve","sooty","fluky","bombs","nurse","ceres","lopes","yucky","ricks","goads","loses","coyly","marcy","bonds","niece","cures","sonic","crows","dicey","gaped","buggy","riles","homer","fakir","hello","riper","makes","laked","sinus","fangs","acton","spiky","salts","boots","skiff","maker","pence","fells","cedar","kited","raved","flake","jiffy","tanks","barns","sized","gluts","amman","jumps","cavil","quaff","rents","looms","toner","gibes","aside","drawn","karin","torte","haded","psych","hacks","jesus","fumed","lisle","spays","sumps","beats","tunas","naked","bathe","gulfs","karma","snuff","boast","grins","turds","plant","spicy","risen","tints","tomas","stand","noses","toxin","sheep","paddy","abase","jeeps","dated","tough","timid","forty","kusch","pones","smack","token","havel","vanes","repay","chums","paved","chimp","spinx","smirk","pupas","bares","mites","egged","palsy","gyros","wolfe","chips","pouts","johns","barbs","slunk","hires","seals","rally","tromp","roads","writs","aches","corny","fiats","hench","gilts","blake","phony","drams","skimp","suing","horus","hewer","barfs","hewed","needs","epsom","knots","tided","befit","eager","melva","coves","plush","pawed","zebra","gales","blots","foggy","rooks","comas","laxly","cries","kirks","monks","magic","fugue","apter","limos","congo","rosin","seder","bones","holes","fated","gamay","snags","wimpy","rites","gilds","slink","staph","sioux","bends","wilma","warts","reeds","yolks","lover","demon","salve","hulas","shard","worst","leach","omits","flint","tines","julio","trots","silly","cocks","gleam","react","camps","nicks","bored","coded","swine","scope","aloes","south","hands","rainy","david","newer","ferns","jelly","index","gibbs","truly","tubes","opera","raven","noyce","whims","titus","hared","vined","dealt","slats","erick","rolls","breed","udder","oozed","prays","tsars","harry","shelf","norms","larks","hazes","brice","gifts","units","veeps","dumas","mommy","spock","dotty","molls","slobs","diane","buddy","boost","ginny","rends","marks","timur","bands","genes","slews","leeds","karyn","mobil","mixes","ronny","sadly","rinks","smash","baled","pulpy","toils","yards","piing","dried","veils","spook","snaky","sizer","spout","percy","sheol","blank","waxes","herod","attar","doped","polls","banes","penny","knelt","laded","manic","acids","squat","jerry","stony","woofs","idles","bruin","carla","sheik","hodge","goody","merge","nicer","scums","evens","lames","wends","midge","jives","tuner","reins","boars","fryer","realm","dyson","narks","torts","yawed","waked","cress","curvy","bongs","fared","jilts","liens","ducat","shaft","pesos","dulls","donna","potty","winks","marsh","giddy","tiffs","scoot","nifty","daisy","slots","stacy","colby","skims","malls","sifts","jinns","flank","molar","hatch","wiped","taped","clink","brims","credo","fezes","molds","finds","quids","terra","damns","dusky","wanes","musty","barer","snare","honey","piked","wiser","elvin","dolly","fetal","ships","reign","cause","caved","mecca","blink","close","birth","pints","reefs","amado","comae","waite","willy","lorry","nixed","quire","napes","voted","eldon","nappy","myles","laser","pesky","leant","septa","mucks","agree","sworn","lofty","slush","holst","tevet","wases","cheer","torah","treks","purge","class","popes","roans","curve","quads","magma","drier","hales","chess","prigs","sivan","romes","finch","peels","mousy","atria","offer","coals","crash","tauts","oinks","dazed","flaps","truck","treed","colas","petty","marty","cadet","clips","zones","wooed","haves","grays","gongs","minis","macaw","horde","witch","flows","heady","fuels","conks","lifts","tumid","husks","irony","pines","glops","fonds","covey","chino","riggs","tonya","slavs","caddy","poled","blent","mired","whose","scows","forte","hikes","riped","knobs","wroth","bagel","basks","nines","scams","males","holed","solid","farms","glaxo","poise","drays","ryder","slash","rajas","goons","bowed","shirt","blurs","fussy","rills","loren","helps","feels","fiefs","hines","balms","blobs","fiord","light","dinky","maids","sagas","joked","pyxed","lilly","leers","galls","malts","minos","ionic","lower","peale","ratty","tuber","newed","whirl","eases","wests","herds","clods","floes","skate","weeds","tones","rangy","kings","adder","pitts","smith","coats","lenny","sorta","floss","looks","angie","peppy","upper","darin","white","lofts","clint","jared","heros","ruler","tonia","sexed","grail","villa","topic","kenny","dopes","hoots","boobs","gerry","eries","lyres","lunch","glove","cumin","harms","races","today","crust","track","mends","snout","shark","iliad","shrew","dorky","monty","dodge","toted","worse","dream","weird","gaunt","damon","rimes","layer","salem","bards","dills","hobby","gives","shall","crazy","brace","faxed","pools","foamy","viral","strop","liver","ceded","jolts","jonah","tight","lilia","hussy","mutts","crate","girls","marge","hypos","mewls","bulls","gazes","wands","avior","sonya","slick","clump","cater","aural","agave","grief","shana","fices","moans","grape","fetid","jenna","humus","poesy","cooks","still","lease","wanda","oddly","areas","frats","imply","files","ramon","seuss","hubby","wakes","rural","nodal","doric","carry","chefs","fails","klaus","shine","filly","yawls","brows","cabby","favor","styli","filed","jinni","ferry","balls","lakes","voled","drone","lusty","tansy","among","trail","liven","slake","madge","steps","donne","sties","picks","lacks","jumpy","meade","bogie","bauer","scene","lubes","brigs","label","fines","grebe","limns","mouse","ensue","swags","bunch","kayla","micky","sneak","bulbs","camus","yours","aisha","dunne","volta","cores","dweeb","libby","flees","shops","bided","satan","socks","draws","golfs","taunt","genus","belts","orbit","taxis","hinds","fakes","chart","wings","words","digit","copse","deena","perry","sanes","huffy","chung","lucks","fills","selma","wafts","pecks","trite","combs","sooth","weary","salty","brews","kooky","robby","loans","props","huang","marry","swabs","tinny","mince","japed","ellis","lowed","newly","loath","drown","loved","joker","lints","kinky","skits","feats","hiker","doles","every","dolby","stirs","lobed","fusty","cozen","vader","byron","dozes","slows","bethe","ploys","misty","binds","bumpy","spurs","wolfs","ernie","nails","prows","seeds","visas","dowse","pores","jocks","cower","hoofs","mined","marat","gorge","souse","clack","liter","jewel","hates","boats","stark","blabs","murks","woken","stomp","peeks","perky","pasta","goats","hocks","kinks","gushy","outdo","gelds","foxes","fives","sybil","upton","taine","helga","mauls","gills","grows","bauds","aloft","cline","payer","pinch","thorn","slits","thumb","biked","cowls","grams","disks","belly","randy","hunts","prize","minty","river","chevy","gages","cysts","years","scoff","becky","inert","abler","bevel","dyers","tonne","glows","ocean","spits","bowen","tings","baths","goals","whiny","merry","fares","leila","cairo","honor","verge","teary","pimps","sarah","meets","tamed","bumps","alias","pings","wears","dante","snore","ruled","savor","gapes","loony","chaps","froth","fancy","herbs","cutes","crowd","ghana","teddy","abate","scalp","mules","patsy","minks","shuck","billy","helen","stain","moles","jodie","homed","stack","niger","denny","kinds","elves","waled","rover","medan","churn","whizz","green","reach","lajos","mates","ditch","grads","start","press","rimed","hells","vised","slums","notes","canes","taper","camry","weans","sinks","arise","crown","prier","ramps","wotan","chars","mussy","rodes","sonar","cheri","sired","snell","basel","eider","sades","times","ovule","gusto","myrna","gabby","dully","spake","beast","towns","allay","gaged","smell","skids","clone","slack","pooch","vulva","arson","blown","kongo","maize","thick","brags","spore","soles","trial","snort","price","bowel","stoke","pents","hutch","flack","arced","cubic","hiram","tongs","lades","coons","finer","games","unpin","vests","slabs","santa","tamer","asian","tease","miked","lodes","vents","leafy","stats","shuts","bully","edith","bloch","corps","bloom","doses","coins","skips","gains","hided","coops","ninja","pills","raves","hanks","seres","ewing","bests","wrath","burgs","thrum","cabin","daren","imams","junks","brood","bacon","creel","gazed","teats","halos","gypsy","ether","train","tiles","bulks","bolls","added","roger","sites","balmy","tilts","swoop","jules","bawdy","mango","stoop","girts","costs","lemur","yucks","swazi","okays","piped","ticks","tomes","filch","depth","meals","coots","bites","pansy","spelt","leeks","hills","drops","verde","japes","holds","bangs","maxed","plume","frets","lymph","modes","twits","devon","cawed","putty","sowed","likes","quips","board","loxed","slags","dilly","refit","saved","takes","meter","prove","spacy","poach","cilia","pears","lists","gated","verdi","shave","notch","culls","shams","weedy","gaols","hoops","kraft","burro","roles","rummy","click","plots","mitty","yanks","drool","papal","rearm","prose","fucks","berra","salas","tents","flues","loves","poker","parry","polyp","agent","flown","walls","studs","troll","baron","earle","panda","wiley","raged","sexes","berne","vista","rojas","cones","byway","vases","wines","forth","freya","gully","fires","sails","dusts","terse","booed","stung","basic","saver","basis","hmong","brawn","pured","locks","downs","punts","rhine","metes","title","shims","bents","blows","harte","boyle","peach","posts","olson","might","flier","rubes","lingo","tarts","nexus","woman","mains","finis","mikes","pleas","trams","shawl","gunny","sleds","ruder","aries","usher","refed","toady","caper","tries","gimpy","doors","thieu","deere","mucky","rests","mares","cards","bouts","dines","rants","giles","flunk","enact","derek","dover","conan","mooed","fiver","kaput","enrol","payed","feint","miner","shyer","whelk","perch","furor","hayes","tammy","caves","maims","cairn","tract","legal","adler","veldt","basal","spiny","surer","bolds","grove","heaps","noway","pokes","tubed","beaks","loots","drawl","jones","typed","funny","cells","beaus","bayed","rears","seats","hazed","flubs","maura","goths","rumba","morse","fumes","slide","snoot","music","sully","perth","pocks","mills","lopez","sacks","stine","gawks","gavel","rains","wound","hares","guild","leger","foxed","craws","rinds","faced","groom","lully","boded","lends","serge","sword","faked","envoy","stick","tumor","riser","bolts","trued","gasps","thoth","veers","verbs","boles","lunar","taxes","vexes","pucks","welsh","pelts","shift","booth","smote","spied","gnawn","crete","dough","tasha","timed","wired","state","hears","lauds","wills","dummy","basil","belie","calls","crams","matts","gybes","limed","snots","moder","faces","sibyl","spare","crops","drips","frown","doggy","pearl","reese","curls","earns","poles","tiara","risks","lethe","titan","tucks","trace","vises","prick","sears","ogled","preps","livid","kicky","candy","weeps","tapes","cokes","foods","wards","coifs","shirk","elsie","ketch","trunk","goofs","kodak","toyed","lance","whale","soups","roars","poxed","tombs","noons","hindi","basie","hoffa","bayou","tests","roots","shove","hoses","doled","tempt","kilos","velma","avers","dorks","comic","fanny","poops","sicks","leary","merer","finks","garbo","cains","mimed","sates","celli","flats","grown","broth","augur","chaos","sangs","chide","barks","guide","mewed","synch","rings","scrap","zings","howls","duded","noemi","geeks","nexis","comte","helot","whams","brand","hogan","moira","trips","loges","baits","winds","marla","never","louis","anted","helix","morns","heeds","crags","rowdy","becks","venue","diary","stoat","feeds","kiths","riled","drags","lucia","deeps","sends","fonts","swing","fence","stout","trice","taker","drugs","babel","plows","pends","sloes","gents","brawl","arabs","leaps","flied","fulls","meats","megan","burch","oscar","evict","betsy","lasts","ethos","mavis","petal","fever","alone","snips","assay","rocks","talon","grass","clive","discs","wrapt","calfs","razed","learn","bruce","midst","swear","merck","meyer","funks","lobby","fears","decay","sedge","alien","reaps","koran","range","enter","lepke","honed","gallo","staid","joist","lines","paler","fined","sorts","piper","highs","busch","dario","north","ashed","sands","songs","rakes","garza","pinks","rival","leann","allow","golds","hilts","berry","hicks","idler","weiss","cider","desks","skies","hulls","warns","datum","brown","leapt","dregs","dozed","stump","reply","finny","clues","diode","dicks","rabid","moors","limbs","gulls","scary","dungs","liege","vicky","nigel","peeps","dolls","blame","sings","wants","fuzes","proud","bungs","seams","bingo","buffs","shire","decks","hosed","scots","pumas","jazzy","books","ellie","hayed","snowy","twill","links","coped","spats","reyes","piles","hovel","reads","wryer","patty","sling","oneal","waves","gorse","ofter","teams","strep","mores","daily","spoil","limes","foots","dells","hakes","danny","furls","flaws","tarot","dusty","potts","tells","pager","claps","serra","josie","award","pewee","snack","lobes","damps","tanya","lures","mushy","hertz","caret","marco","parks","pithy","synge","spoon","troth","drama","bleak","lidia","banns","forms","iambs","crick","patel","mercy","waded" };

	/*std::string beginWord = "lost";
	std::string	endWord = "cost";
	std::vector<std::string> wordList = { "most","fist","lost","cost","fish" };*/
	os << Solution_127().ladderLength(beginWord, endWord, wordList) << std::endl;
}

void TestCase::test347(std::ostream & os)
{
	std::vector<int> nums = { 1 };
	int k = 1;
	os << "output:";
	
	auto vec = Solution_347().topKFrequent(nums, k);
	os << "[";
	for (decltype(vec.size()) i = 0; i != vec.size(); ++i) {
		if (i != vec.size() - 1)
			os << vec[i] << ",";
		else
			os << vec[i];
	}
	os << "]" << std::endl;
}

void TestCase::test23(std::ostream & os)
{
	MyUtility mu;
	ListNode* l1 = mu.createLinkedList({ 1,4,5 });
	ListNode* l2 = mu.createLinkedList({ 1,3,4 });
	ListNode* l3 = mu.createLinkedList({ 2 });
	std::vector<ListNode*> lists = { l1,l2,l3 };
	ListNode* res = Solution_23().mergeKLists(lists);
	mu.printLinkedList(os, res);
	mu.delLinkedList(res);
}

void TestCase::test104(std::ostream & os)
{
	MyUtility mu; 
	auto res = mu.createTree({ "3","9","20","null","null","15","7" });
	os << Solution_104().maxDepth2(res) << std::endl;
	mu.delTree(res);
}

void TestCase::test111(std::ostream & os)
{
	MyUtility mu;
	auto res = mu.createTree({ "3","9","20","null","null","15","7" });
	//auto res = mu.createTree({ "1", "2", "3","4" ,"5" });
	os << Solution_111().minDepth2(res) << std::endl;
	mu.delTree(res);
}

void TestCase::test226(std::ostream & os)
{
	MyUtility mu;
	auto res = mu.createTree({ "1", "2", "3","4" ,"5" });
	auto root = Solution_226().invertTree2(res);
	mu.printTree(os, root);
}

void TestCase::test100(std::ostream & os)
{
	MyUtility mu;
	auto t1 = mu.createTree({ "1", "2"});
	auto t2 = mu.createTree({ "1", "null","2" });
	os << Solution_100().isSameTree(t1, t2) << std::endl;
}

void TestCase::test101(std::ostream & os)
{
	MyUtility mu;
	auto res = mu.createTree({ "1", "2","2", "null" ,"3","null", "3" });
	os << Solution_101().isSymmetric2(res) << std::endl;
}

void TestCase::test222(std::ostream & os)
{
	MyUtility mu;
	auto res = mu.createTree({ "1", "2","3", "4" ,"5","6"});
	os << Solution_222().countNodes(res);
}

void TestCase::test110(std::ostream & os)
{
	MyUtility mu;
	//auto res = mu.createTree({ "1", "2","2","3","3", "null" ,"null" ,"4","4" });
	auto res = mu.createTree({ "3", "9","20", "null" ,"null" ,"15","7" });

	os << Solution_110().isBalanced(res) << std::endl;
}

void TestCase::test112(std::ostream & os)
{
	MyUtility mu;
	auto res = mu.createTree({ "5", "4","8", "11" ,"13" ,"4","7","2","1" });
	int sum = 22;
	os << Solution_112().hasPathSum(res, sum) << std::endl;
}

void TestCase::test404(std::ostream & os)
{
	MyUtility mu;
	//auto res = mu.createTree({ "9","null" ,"2","0","null" ,"-7","null","-1" });
	auto res = mu.createTree({ "1", "2","3", "4" ,"5" });

	os << Solution_404().sumOfLeftLeaves2(res) << std::endl;
}

void TestCase::test257(std::ostream & os)
{
	MyUtility mu;
	auto res = mu.createTree({ "1", "2","3", "null" ,"5" });
	auto v = Solution_257().binaryTreePaths(res);
	for (auto s : v)
		os << s << ",";
}

void TestCase::test113(std::ostream & os)
{
	MyUtility mu;
	auto root = mu.createTree({ "5","4" ,"8","11","null","13" ,"4","7","2","null","null","5","1" });
	int sum = 22;
	auto res = Solution_113().pathSum(root, sum);
	for (size_t i = 0; i != res.size(); ++i) {
		for (size_t j = 0; j != res[i].size(); ++j)
			os << res[i][j] << ",";
		os << std::endl;
	}
}

void TestCase::test129(std::ostream & os)
{
	MyUtility mu;
	auto root = mu.createTree({ "4", "9","0","5", "1"});
	os << Solution_129().sumNumbers(root) << std::endl;
}

void TestCase::test437(std::ostream & os)
{
	MyUtility mu;
	auto root = mu.createTree({ "10", "5","-3","3", "2","null","11","3","-2","null","1" });
	int sum = 8;
	os << Solution_437().pathSum(root, sum) << std::endl;
}

void TestCase::test235(std::ostream & os)
{
	MyUtility mu;
	auto root = mu.createTree({ "6", "2","8","0", "4","7","9","null","null","3","5" });
	//auto res = Solution_235().lowestCommonAncestor(root, p, q);

}

void TestCase::test98(std::ostream & os)
{
	MyUtility mu;
	auto root = mu.createTree({ "5", "3","6","2","4","null","7" });
	
	os << Solution_98().isValidBST(root) << std::endl;
}

void TestCase::test450(std::ostream & os)
{
	MyUtility mu;
	int key = 3;
	
	auto root = mu.createTree(mu.getStringToVec("[5,3,6,2,4,null,7]"));
	/*root = Solution_450().deleteNode(root, key);
	mu.printTree(os, root);*/
	Solution_450().delMin(root);
	os << std::endl;
}

void TestCase::test108(std::ostream & os)
{
	std::vector<int> nums = { -10,-3,0,5,9 };
	auto root = Solution_108().sortedArrayToBST(nums);
	MyUtility mu;
	mu.printTree(os, root);
}

void TestCase::test230(std::ostream & os)
{
	MyUtility mu;
	int k = 3;
	auto root = mu.createTree(mu.getStringToVec("[5,3,6,2,4,null,null,1]"));
	os << Solution_230().kthSmallest(root, k) << std::endl;
}

void TestCase::test236(std::ostream & os)
{
	MyUtility mu;
	auto root = mu.createTree(mu.getStringToVec("[3,5,1,6,2,0,8,null,null,7,4]"));
	TreeNode* p = mu.findNode(root, 8);
	TreeNode* q = mu.findNode(root, 4);
	os << Solution_236().lowestCommonAncestor(root, p, q)->val << std::endl;
}

void TestCase::test17(std::ostream & os)
{
	std::string digits = "23";
	auto res = Solution_17().letterCombinations(digits);
	for (const auto& s : res)
		os << s << std::endl;
}

void TestCase::test93(std::ostream & os)
{
	std::string s = "010010";
	auto res = Solution_93().restoreIpAddresses(s);
	for (const auto& str : res)
		os << str << std::endl;
}

