#ifndef _TESTCASE_H
#define _TESTCASE_H
#include <ostream>

#include "27.h"
#include "26.h"
#include "80.h"
#include "75.h"
#include "88.h"
#include "215.h"
#include "167.h"
#include "125.h"
#include "344.h"
#include "345.h"
#include "11.h"
#include "209.h"
#include "3.h"
#include "438.h"
#include "76.h"
#include "349.h"
#include "350.h"
#include "242.h"
#include "202.h"
#include "290.h"
#include "205.h"
#include "451.h"
#include "1.h"
#include "15.h"
#include "18.h"
#include "16.h"
#include "454.h"
#include "49.h"
#include "447.h"
#include "149.h"
#include "206.h"
#include "92.h"
#include "83.h"
#include "86.h"
#include "328.h"
#include "2.h"
#include "445.h"
#include "203.h"
#include "82.h"
#include "21.h"
#include "24.h"
#include "25.h"
#include "147.h"
#include "148.h"
#include "237.h"
#include "19.h"
#include "61.h"
#include "143.h"
#include "234.h"
#include "20.h"
#include "150.h"
#include "71.h"
#include "144.h"
#include "94.h"
#include "341.h"
#include "279.h"
#include "127.h"
#include "347.h"
#include "23.h"
#include "104.h"
#include "111.h"
#include "226.h"
#include "100.h"
#include "101.h"
#include "222.h"
#include "110.h"
#include "112.h"
#include "404.h"
#include "257.h"
#include "113.h"
#include "129.h"
#include "437.h"
#include "235.h"
#include "98.h"
#include "450.h"
#include "108.h"
#include "230.h"
#include "236.h"
#include "17.h"
#include "93.h"
#include "131.h"
#include "46.h"
#include "47.h"
#include "77.h"
#include "39.h"
#include "40.h"
#include "216.h"
#include "78.h"
#include "90.h"
#include "401.h"
#include "79.h"
#include "200.h"
#include "130.h"
#include "417.h"

#include "MyUtility.h"

class TestCase {
public:
	void test27(std::ostream& os);
	void test26(std::ostream& os);
	void test80(std::ostream& os);
	void test75(std::ostream& os);
	void test88(std::ostream& os);
	void test215(std::ostream& os);
	void test167(std::ostream& os);
	void test125(std::ostream& os);
	void test344(std::ostream& os);
	void test345(std::ostream& os);
	void test11(std::ostream& os);
	void test209(std::ostream& os);
	void test3(std::ostream& os);
	void test438(std::ostream& os);
	void test76(std::ostream& os);
	void test349(std::ostream& os);
	void test350(std::ostream& os);
	void test242(std::ostream& os);
	void test202(std::ostream& os);
	void test290(std::ostream& os);
	void test205(std::ostream& os);
	void test451(std::ostream& os);
	void test1(std::ostream& os);
	void test15(std::ostream& os);
	void test18(std::ostream& os);
	void test16(std::ostream& os);
	void test454(std::ostream& os);
	void test49(std::ostream& os);
	void test447(std::ostream& os);
	void test149(std::ostream& os);
	void test206(std::ostream& os);
	void test92(std::ostream& os);
	void test83(std::ostream& os);
	void test86(std::ostream& os);
	void test328(std::ostream& os);
	void test2(std::ostream& os);
	void test445(std::ostream& os);
	void test203(std::ostream& os);
	void test82(std::ostream& os);
	void test21(std::ostream& os);
	void test24(std::ostream& os);
	void test25(std::ostream& os);
	void test147(std::ostream& os); //对链表进行插入排序
	void test148(std::ostream& os); //排序链表, O(n log n) 时间复杂度和常数级空间复杂度
	void test237(std::ostream& os); // 删除链表中的节点(非尾节点)，O(1)时间复杂度
	void test19(std::ostream& os);  //删除链表的倒数第N个节点（使用一趟扫描）
	void test61(std::ostream& os);  //旋转链表
	void test143(std::ostream& os); //重排链表
	void test234(std::ostream& os); //回文链表

	/** 栈 **/
	void test20(std::ostream& os);  //有效的括号
	void test150(std::ostream& os); //逆波兰表达式求值
	void test71(std::ostream& os);  //简化路径（实现很晦涩）

	/** 二叉树 **/
	void test144(std::ostream& os);  //二叉树的前序遍历
	void test94(std::ostream& os);  //二叉树的中序遍历
	void test341(std::ostream& os); //扁平化嵌套列表迭代器（设计问题）
	void test102(std::ostream& os); //二叉树的层次遍历（注意层号）
	void test107(std::ostream& os); //二叉树的层次遍历 II（vector的reverse_iterator迭代器）
	void test103(std::ostream& os); //二叉树的锯齿形层次遍历
	void test199(std::ostream& os); //二叉树的右视图

	/** 无权图的最短路径 **/
	void test279(std::ostream& os); //完全平方数
	void test127(std::ostream& os); //单词接龙

	void test347(std::ostream& os);  //前K个高频元素
	void test23(std::ostream& os);   //合并K个排序链表

	/** 递归 **/
	void test104(std::ostream& os); //二叉树的最大深度
	void test111(std::ostream& os); //二叉树的最小深度
	void test226(std::ostream& os); //翻转二叉树
	void test100(std::ostream& os); //相同的树
	void test101(std::ostream& os); //对称二叉树
	void test222(std::ostream& os); //完全二叉树的节点个数
	void test110(std::ostream& os); //平衡二叉树
	void test112(std::ostream& os); //路径总和
	void test404(std::ostream& os); //左叶子之和
	void test257(std::ostream& os); //二叉树的所有路径
	void test113(std::ostream& os); //路径总和 II
	void test129(std::ostream& os); //求根到叶子节点数字之和
	void test437(std::ostream& os); //路径总和 III
	void test235(std::ostream& os); //二叉搜索树的最近公共祖先
	void test98(std::ostream& os); //验证二叉搜索树
	void test450(std::ostream& os); //删除二叉搜索树中的节点
	void test108(std::ostream& os); //将有序数组转换为二叉搜索树
	void test230(std::ostream& os); //二叉搜索树中第K小的元素
	void test236(std::ostream& os); //二叉树的最近公共祖先

	/** 回溯 **/
	void test17(std::ostream& os); //电话号码的字母组合
	void test93(std::ostream& os); //复原IP地址
	void test131(std::ostream& os); //分割回文串
	void test46(std::ostream& os);  //全排列
	void test47(std::ostream& os);  //全排列 II

	/*** 回溯-剪枝 ***/
	void test77(std::ostream& os); //组合
	void test39(std::ostream& os); //组合总和
	void test40(std::ostream& os); //组合总和 II
	void test216(std::ostream& os); //组合总和 III
	void test78(std::ostream& os); //子集
	void test90(std::ostream& os); //子集 II
	void test401(std::ostream& os); //二进制手表

	/*** 回溯-二维 ***/
	void test79(std::ostream& os);  //单词搜索
	void test200(std::ostream& os); //岛屿数量
	void test130(std::ostream& os); //被围绕的区域
	void test417(std::ostream& os); //太平洋大西洋水流问题
};
#endif // !_TESTCASE_H

