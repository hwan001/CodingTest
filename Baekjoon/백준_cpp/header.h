/*
* Include
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm> 
#include <map> 
#include <utility> 
#include <sstream> 
#include <cmath> 
#include <stack> 
#include <queue> 
#include <numeric>
#include <functional> 
#include <locale>
#include <cctype>


/*
* Namespace
*/
using namespace std;


/*
* Type Define
*/
typedef unsigned long long ll;


/*
*  Custom Function
*/
vector<string> split(string, char);
int is_prime_number_custom(ll);
int is_prime_number_sqrt(ll);
bool *Sieve_of_Eratosthenes(ll);
double const_pi();
ll gcd_recusion(ll, ll);


/*
*  ����°� ��Ģ����
*/
void func_2557(); // Hello Word
void func_10718(); // We love kriii
void func_10171(); // �����
void func_10172(); // ��
void func_1000(); // A+B
void func_1001(); // A-B
void func_10998(); // A*B
void func_1008(); // A/B
void func_10869(); // ��Ģ����
void func_10430(); // ������
void func_2588(); // ����

// 2022-01-26 ���� �߰���
void func_10926(); // ??!
void func_18108(); // 1998����� ���� �±������� 2541���?!


/*
*  if��
*/
void func_1330(); // �� �� ���ϱ�
void func_9498(); // ���� ����
void func_2753(); // ����
void func_14681(); // ��и� ����
void func_2884(); // �˶� �ð�

// 2022-02-16 ���� �߰���
void func_2525(); // ���� �ð�
void func_2480(); // �ֻ��� ����


/*
*  for��
*/
void func_2739(); // ������
void func_10950(); // A+B - 3
void func_8393(); // ��
void func_15552(); // ���� A+B
void func_2741(); // N ���
void func_2742(); // ���� N
void func_11021(); // A+B - 7
void func_11022(); // A+B - 8
void func_2438(); // �� ��� - 1
void func_2439(); // �� ��� - 2
void func_10871(); // X���� ���� ��

/*
*  while��
*/
void func_10952(); // A+B - 5
void func_10951(); // A+B - 4
void func_1110(); // ���ϱ� ����Ŭ

/*
*  1���� �迭
*/
void func_10818(); // �ּ�, �ִ�
void func_2562(); // �ִ�
void func_2577(); // ������ ����
void func_3052(); // ������
void func_1546(); // ���
void func_8958(); // OX����
void func_4344(); // ����� �Ѱ���

/*
*  �Լ�
*/
void func_15596(); // ���� N���� ��
void func_4673(); // ���� �ѹ�
void func_1065(); // �Ѽ�

/* 
*  ���ڿ�
*/
void func_1157(); // �ܾ� ����
void func_2675(); // ���ڿ� �ݺ�
void func_1152(); // �ܾ��� ����
void func_2908(); // ���
void func_5622(); // ���̾�
void func_2941(); // ũ�ξ�Ƽ�� ���ĺ�
void func_1316(); // �׷�ܾ�üĿ 

/*
*  �⺻ ���� 1
*/
void func_1712(); // ���ͺб���
void func_2292(); // ����
void func_1193(); // �м�ã��
void func_2869(); // �����̴� �ö󰡰� �ʹ�
void func_10250(); // ACM ȣ��
void func_2775(); // �γ�ȸ���� ���׾�
void func_2839(); // �������
void func_10757(); // ū �� A+B
void func_1011(); // Fly me to the Alpha Centauri [�ۼ���]

/*
*  �⺻ ���� 2
*/
void func_1978(); // �Ҽ� ã��
void func_2581(); // �Ҽ�
void func_11653(); // ���μ�����
void func_1929(); // �Ҽ� ���ϱ�
void func_4948(); // ����Ʈ�� ����
void func_9020(); // �������� ����
void func_1085(); // ���簢������ Ż��
void func_3009(); // �� ��° ��
void func_4153(); // �����ﰢ��
void func_3053(); // �ý� ������
void func_1002(); // �ͷ�

/*
*  ���
*/
void func_10872(); // ���丮��
void func_10870(); // �Ǻ���ġ �� 5
void func_2447(); // �� ��� -10 [�ۼ���]
void func_11729(); // �ϳ��� ž �̵� ���� [�ۼ���]

/*
*  ���Ʈ ����
*/
void func_2798(); // ����
void func_2231(); // ������
void func_7568(); // ��ġ
void func_1018(); // ü���� �ٽ� ĥ�ϱ� [�ۼ���]
void func_1436(); // ��ȭ���� �� [�ۼ���]


/*
*  ����
*/
void func_2750(); // �� �����ϱ�
void func_2751(); // �� �����ϱ� 2
void func_10989(); // �� �����ϱ� 3
void func_2108(); // �����
void func_1427(); // ��Ʈ�λ��̵�
void func_11650(); // ��ǥ �����ϱ�
void func_11651(); // ��ǥ �����ϱ� 2
void func_1181(); // �ܾ� ����
void func_10814(); // ���̼� ����
void func_18870(); // ��ǥ ����


/*
* ���� ��ȹ�� 1
*/
void func_1003(); // �Ǻ���ġ �Լ� (�ǹ� 3)
void func_9184(); // �ų��� �Լ� ���� (�ǹ� 2)
void func_1904(); // 01Ÿ�� (�ǹ� 3)
void func_9461(); // �ĵ��� ���� (�ǹ� 3)
void func_12865(); // ����� �賶 (���5)


/*
*  �׸��� �˰���
*/
void func_11047(); // ���� 0
void func_1931(); // ȸ�ǽ� ����
void func_11399(); // ATM


/*
*   DFS�� BFS
*   https://www.acmicpc.net/step/24
*/
void func_1260(); // DFS�� BFS 
void func_2606(); // ���̷���
void func_2667(); // ������ȣ���̱�
void func_1012(); // ����� ����
void func_2178(); // �̷� Ž��
void func_7576(); // �丶��


/*
*  ����� Ƽ�� ���� Ǯ��
*/
void func_1009(); // �л�ó�� (����� 3) 
void func_2475(); // ������ (����� 5)
void func_2920(); // ���� (����� 2)
void func_1259(); // �Ӹ���Ҽ� (����� 1)
void func_11050(); // ���� ���1 (����� 1)
void func_15829(); // Hashing (����� 2)
void func_1032(); // ��� ������Ʈ (����� 1)


/*
*  �ǹ� Ƽ�� ���� Ǯ��
*/
void func_15965(); // k��° �Ҽ� 
void func_1004(); // ����� 
void func_1697(); // ���ٲ��� (�ǹ� 1)
void func_2164(); // ī��2 (�ǹ� 4)
void func_11866(); // �似Ǫ�� ���� (�ǹ� 4)
void func_18111(); // ����ũ����Ʈ (�ǹ� 2)
void func_10773(); // ���� (�ǹ� 4)
void func_9012(); // ��ȣ (�ǹ� 4)
void func_2609(); // �ִ������� �ּҰ���� (�ǹ� 5)
void func_18258(); // ť 2 (�ǹ� 4)
void func_1463(); // 1�� ����� (�ǹ� 3)
void func_1920(); // �� ã�� (�ǹ� 4)
void func_4963(); // ���� ���� (�ǹ� 2)
void func_11726(); // 2 * N Ÿ�ϸ� (�ǹ� 2)
void func_11724(); // ���� ����� ���� (�ǹ� 2)
void func_10816(); // ���� ī�� 2 (�ǹ� 4)
void func_4949(); // �������� ���� (�ǹ� 4)

/*
*  ��� Ƽ�� ���� Ǯ��
*/
void func_1019(); // å ������ (��� 1)
void func_10026(); // ���ϻ��� (��� 5)
void func_2206(); // ���μ��� �̵��ϱ� (���4)
void func_1753(); // �ִ� �Ÿ� (��� 5)
void func_1300(); // K��°�� �� (��� 2)
 
/* 
*  2022 �߾Ӵ��б� CHAC Open Contest
*  https://www.acmicpc.net/contest/view/767
*  ��ȸ �������� ������ȣ�� �Ҵ�Ǿ��� -> ������ �ʿ�
*/
void func_CHAC_A(); // ����
void func_CHAC_B(); // �ð��ʰ�, ����
void func_CHAC_D(); // ���� 


/*
*  ������ > �Ｚ SW ���� �׽�Ʈ ���� ����
*   https://www.acmicpc.net/workbook/view/1152
*/
void func_13460(); // ���� Ż��2 (���1)
void func_12100(); // 2048(Easy) (���2)
void func_3190(); // �� (��� 5)
void func_13458(); // ���� ���� (����� 2)
void func_14499(); // �ֻ��� ������ (��� 4)
void func_14500(); // ��Ʈ�ι̳� (��� 5)
void func_14501(); // ��� (�ǹ� 3)
void func_14502(); // ������ (��� 5)
void func_14503(); // �κ� û�ұ� (��� 5)
void func_14888(); // ������ �����ֱ� (�ǹ� 1)
void func_14889(); // ��ŸƮ�� ��ũ (�ǹ� 2)
void func_14890(); // ���� (��� 3)
void func_14891(); // ��Ϲ��� (�ǹ� 1)
void func_15683(); // ���� (��� 5)
void func_15684(); // ��ٸ� ���� (��� 4)
void func_15685(); // �巡�� Ŀ�� (��� 4)
void func_15686(); // ġŲ ��� (��� 5)
void func_5373(); // ť�� (�÷�Ƽ�� 5)
void func_16234(); // �α� �̵� (��� 5)
void func_16235(); // ���� ����ũ (��� 4)
void func_16236(); // �Ʊ� ��� (��� 3)
void func_17144(); // �̼����� �ȳ�! (��� 4)
void func_17143(); // ���ÿ� (��� 2)
void func_17140(); // ������ �迭�� ���� (��� 4)
void func_17142(); // ������ 3 (��� 4)
void func_17779(); // �Ը��Ǵ��� 2 (��� 4)
void func_17837(); // ���ο� ���� 2 (��� 2)
void func_17822(); // ���� ������ (��� 3)
void func_17825(); // �ֻ��� ������ (��� 2)
void func_20061(); // ���̳뵵�̳� 2 (��� 2)
void func_19236(); // û�ҳ� ��� (��� 2)
void func_19237(); // � ��� (��� 3)
void func_19238(); // ��ŸƮ �ý� (��� 4)
void func_20055(); // �����̾� ��Ʈ ���� �κ� (��� 5)
void func_20056(); // ������ ���� ���̾  (��� 4)
void func_20057(); // ������ ���� ����̵�  (��� 3)
void func_20058(); // ������ ���� ���̾��  (��� 4)
void func_21608(); // ��� �ʵ��б� (�ǹ� 1)
void func_21609(); // ��� ���б� (��� 2)
void func_21610(); // ������ ���� ��ٶ�� (��� 5)
void func_21611(); // ������ ���� ���ڵ� (��� 1)
void func_23288(); // �ֻ��� ������ 2 (��� 3)
void func_23289(); // ��ǳ�� �ȳ�! (��� 1)
void func_23290(); // ������ ���� ���� (��� 1)
void func_23291(); // ���� ���� (��� 1) 


