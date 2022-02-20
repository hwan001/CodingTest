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
*  입출력과 사칙연산
*/
void func_2557(); // Hello Word
void func_10718(); // We love kriii
void func_10171(); // 고양이
void func_10172(); // 개
void func_1000(); // A+B
void func_1001(); // A-B
void func_10998(); // A*B
void func_1008(); // A/B
void func_10869(); // 사칙연산
void func_10430(); // 나머지
void func_2588(); // 곱셈

// 2022-01-26 새로 추가됨
void func_10926(); // ??!
void func_18108(); // 1998년생인 내가 태국에서는 2541년생?!

/*
*  if문
*/
void func_1330(); // 두 수 비교하기
void func_9498(); // 시험 성적
void func_2753(); // 윤년
void func_14681(); // 사분면 고르기
void func_2884(); // 알람 시계

// 2022-02-16 새로 추가됨
void func_2525(); // 오븐 시계
void func_2480(); // 주사위 세개

/*
*  for문
*/
void func_2739(); // 구구단
void func_10950(); // A+B - 3
void func_8393(); // 합
void func_15552(); // 빠른 A+B
void func_2741(); // N 찍기
void func_2742(); // 기찍 N
void func_11021(); // A+B - 7
void func_11022(); // A+B - 8
void func_2438(); // 별 찍기 - 1
void func_2439(); // 별 찍기 - 2
void func_10871(); // X보다 작은 수

/*
*  while문
*/
void func_10952(); // A+B - 5
void func_10951(); // A+B - 4
void func_1110(); // 더하기 사이클

/*
*  1차원 배열
*/
void func_10818(); // 최소, 최대
void func_2562(); // 최댓값
void func_2577(); // 숫자의 개수
void func_3052(); // 나머지
void func_1546(); // 평균
void func_8958(); // OX퀴즈
void func_4344(); // 평균은 넘겠지

/*
*  함수
*/
void func_15596(); // 정수 N개의 합
void func_4673(); // 셀프 넘버
void func_1065(); // 한수

/* 
*  문자열
*/
void func_1157(); // 단어 공부
void func_2675(); // 문자열 반복
void func_1152(); // 단어의 개수
void func_2908(); // 상수
void func_5622(); // 다이얼
void func_2941(); // 크로아티아 알파벳
void func_1316(); // 그룹단어체커 

/*
*  기본 수학 1
*/
void func_1712(); // 손익분기점
void func_2292(); // 벌집
void func_1193(); // 분수찾기
void func_2869(); // 달팽이는 올라가고 싶다
void func_10250(); // ACM 호텔
void func_2775(); // 부녀회장이 될테야
void func_2839(); // 설탕배달
void func_10757(); // 큰 수 A+B
void func_1011(); // Fly me to the Alpha Centauri [작성중]

/*
*  기본 수학 2
*/
void func_1978(); // 소수 찾기
void func_2581(); // 소수
void func_11653(); // 소인수분해
void func_1929(); // 소수 구하기
void func_4948(); // 베르트랑 공준
void func_9020(); // 골드바흐의 추측
void func_1085(); // 직사각형에서 탈출
void func_3009(); // 네 번째 점
void func_4153(); // 직각삼각형
void func_3053(); // 택시 기하학
void func_1002(); // 터렛

/*
*  재귀
*/
void func_10872(); // 팩토리얼
void func_10870(); // 피보나치 수 5
void func_2447(); // 별 찍기 -10 [작성중]
void func_11729(); // 하노이 탑 이동 순서 [작성중]

/*
*  브루트 포스
*/
void func_2798(); // 블랙잭
void func_2231(); // 분해합
void func_7568(); // 덩치
void func_1018(); // 체스판 다시 칠하기 [작성중]
void func_1436(); // 영화감독 숌 [작성중]


/*
*  정렬
*/
void func_2750(); // 수 정렬하기
void func_2751(); // 수 정렬하기 2
void func_10989(); // 수 정렬하기 3
void func_2108(); // 통계학
void func_1427(); // 소트인사이드
void func_11650(); // 좌표 정렬하기
void func_11651(); // 좌표 정렬하기 2
void func_1181(); // 단어 정렬
void func_10814(); // 나이순 정렬
void func_18870(); // 좌표 압축


/*
* 동적 계획법 1
*/
void func_1003(); // 피보나치 함수 (실버 3)
void func_9184(); // 신나는 함수 실행 (실버 2)
void func_1904(); // 01타일 (실버 3)
void func_9461(); // 파도반 수열 (실버 3)


/*
*   DFS와 BFS
*   https://www.acmicpc.net/step/24
*/
void func_1260(); // DFS와 BFS 
void func_2606(); // 바이러스
void func_2667(); // 단지번호붙이기
void func_1012(); // 유기농 배추
void func_2178(); // 미로 탐색
void func_7576(); // 토마토


/*
*  브론즈 티어 문제 풀이
*/


/*
*  실버 티어 문제 풀이
*/
void func_15965(); // k번째 소수


/*
*  골드 티어 문제 풀이
*/



/* 
*  2022 중앙대학교 CHAC Open Contest
*  https://www.acmicpc.net/contest/view/767
*/
void func_CHAC_A(); // 정답
void func_CHAC_B(); // 시간초과, 오답
void func_CHAC_D(); // 오답 


/*
*  문제집 > 단기간 성장 - redbin0471
*   https://www.acmicpc.net/workbook/view/4349
*/
void func_12865(); // 평범한 배낭 (골드5) [작성중]
