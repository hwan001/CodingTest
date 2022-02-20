/*
* Include
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm> 
#include <map> 
#include <utility> 
#include <sstream> 
#include <cmath> 
#include <stack> 
#include <queue> 
#include <numeric>

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


/*
*  �ǹ� Ƽ�� ���� Ǯ��
*/
void func_15965(); // k��° �Ҽ�


/*
*  ��� Ƽ�� ���� Ǯ��
*/



/* 
*  2022 �߾Ӵ��б� CHAC Open Contest
*  https://www.acmicpc.net/contest/view/767
*/
void func_CHAC_A(); // ����
void func_CHAC_B(); // �ð��ʰ�, ����
void func_CHAC_D(); // ���� 


/*
*  ������ > �ܱⰣ ���� - redbin0471
*   https://www.acmicpc.net/workbook/view/4349
*/
void func_12865(); // ����� �賶 (���5) [�ۼ���]
