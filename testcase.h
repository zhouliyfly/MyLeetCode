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
	void test147(std::ostream& os); //*** ���������в�������
	void test148(std::ostream& os); //*** ��������, O(n log n) ʱ�临�ӶȺͳ������ռ临�Ӷ�
	void test237(std::ostream& os); // ɾ�������еĽڵ�(��β�ڵ�)��O(1)ʱ�临�Ӷ�
	void test19(std::ostream& os);  //ɾ�������ĵ�����N���ڵ㣨ʹ��һ��ɨ�裩
	void test61(std::ostream& os);  //��ת����
	void test143(std::ostream& os); //��������
	void test234(std::ostream& os); //��������

	/** ջ **/
	void test20(std::ostream& os);  //��Ч������
	void test150(std::ostream& os); //�沨������ʽ��ֵ
	void test71(std::ostream& os);  //��·����ʵ�ֺܻ�ɬ��

	/** ������ **/
	void test144(std::ostream& os);  //��������ǰ�����
	void test94(std::ostream& os);  //���������������
	void test341(std::ostream& os); //��ƽ��Ƕ���б���������������⣩
	void test102(std::ostream& os); //�������Ĳ�α�����ע���ţ�
	void test107(std::ostream& os); //�������Ĳ�α��� II��vector��reverse_iterator��������
	void test103(std::ostream& os); //�������ľ���β�α���
	void test199(std::ostream& os); //������������ͼ

	/** ��Ȩͼ�����·�� **/
	void test279(std::ostream& os); //��ȫƽ����
	void test127(std::ostream& os); //���ʽ���

	void test347(std::ostream& os);  //ǰK����ƵԪ��
	void test23(std::ostream& os);   //�ϲ�K����������

	/** �ݹ� **/
	void test104(std::ostream& os); //��������������
	void test111(std::ostream& os); //����������С���
	void test226(std::ostream& os); //��ת������
	void test100(std::ostream& os); //��ͬ����
	void test101(std::ostream& os); //�Գƶ�����
	void test222(std::ostream& os); //��ȫ�������Ľڵ����
	void test110(std::ostream& os); //ƽ�������
	void test112(std::ostream& os); //·���ܺ�
	void test404(std::ostream& os); //��Ҷ��֮��
	void test257(std::ostream& os); //������������·��
	void test113(std::ostream& os); //·���ܺ� II
	void test129(std::ostream& os); //�����Ҷ�ӽڵ�����֮��
	void test437(std::ostream& os); //·���ܺ� III
	void test235(std::ostream& os); //�����������������������
	void test98(std::ostream& os); //��֤����������
	void test450(std::ostream& os); //ɾ�������������еĽڵ�
	void test108(std::ostream& os); //����������ת��Ϊ����������
	void test230(std::ostream& os); //�����������е�KС��Ԫ��
	void test236(std::ostream& os); //�������������������

	/** ���� **/
	void test17(std::ostream& os); //�绰�������ĸ���
	void test93(std::ostream& os); //��ԭIP��ַ
};
#endif // !_TESTCASE_H
