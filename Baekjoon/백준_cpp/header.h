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
void func_12865(); // 평범한 배낭 (골드5)


/*
*  그리디 알고리즘
*/
void func_11047(); // 동전 0
void func_1931(); // 회의실 배정
void func_11399(); // ATM


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
void func_1009(); // 분산처리 (브론즈 3) 
void func_2475(); // 검증수 (브론즈 5)
void func_2920(); // 음계 (브론즈 2)
void func_1259(); // 팰린드롬수 (브론즈 1)
void func_11050(); // 이항 계수1 (브론즈 1)
void func_15829(); // Hashing (브론즈 2)
void func_1032(); // 명령 프롬프트 (브론즈 1)


/*
*  실버 티어 문제 풀이
*/
void func_15965(); // k번째 소수 
void func_1004(); // 어린왕자 
void func_1697(); // 숨바꼭질 (실버 1)
void func_2164(); // 카드2 (실버 4)
void func_11866(); // 요세푸스 문제 (실버 4)
void func_18111(); // 마인크래프트 (실버 2)
void func_10773(); // 제로 (실버 4)
void func_9012(); // 괄호 (실버 4)
void func_2609(); // 최대공약수와 최소공배수 (실버 5)
void func_18258(); // 큐 2 (실버 4)
void func_1463(); // 1로 만들기 (실버 3)
void func_1920(); // 수 찾기 (실버 4)
void func_4963(); // 섬의 개수 (실버 2)
void func_11726(); // 2 * N 타일링 (실버 2)
void func_11724(); // 연결 요소의 개수 (실버 2)
void func_10816(); // 숫자 카드 2 (실버 4)
void func_4949(); // 균형잡힌 세상 (실버 4)

/*
*  골드 티어 문제 풀이
*/
void func_1019(); // 책 페이지 (골드 1)
void func_10026(); // 적록색약 (골드 5)
void func_2206(); // 벽부수고 이동하기 (골드4)
void func_1753(); // 최단 거리 (골드 5)
void func_1300(); // K번째의 수 (골드 2)
 
/* 
*  2022 중앙대학교 CHAC Open Contest
*  https://www.acmicpc.net/contest/view/767
*  대회 문제들은 문제번호가 할당되어짐 -> 재정리 필요
*/
void func_CHAC_A(); // 정답
void func_CHAC_B(); // 시간초과, 오답
void func_CHAC_D(); // 오답 


/*
*  문제집 > 삼성 SW 역량 테스트 기출 문제
*   https://www.acmicpc.net/workbook/view/1152
*/
void func_13460(); // 구슬 탈출2 (골드1)
void func_12100(); // 2048(Easy) (골드2)
void func_3190(); // 뱀 (골드 5)
void func_13458(); // 시험 감독 (브론즈 2)
void func_14499(); // 주사위 굴리기 (골드 4)
void func_14500(); // 테트로미노 (골드 5)
void func_14501(); // 퇴사 (실버 3)
void func_14502(); // 연구소 (골드 5)
void func_14503(); // 로봇 청소기 (골드 5)
void func_14888(); // 연산자 끼워넣기 (실버 1)
void func_14889(); // 스타트와 링크 (실버 2)
void func_14890(); // 경사로 (골드 3)
void func_14891(); // 톱니바퀴 (실버 1)
void func_15683(); // 감시 (골드 5)
void func_15684(); // 사다리 조작 (골드 4)
void func_15685(); // 드래곤 커브 (골드 4)
void func_15686(); // 치킨 배달 (골드 5)
void func_5373(); // 큐빙 (플래티넘 5)
void func_16234(); // 인구 이동 (골드 5)
void func_16235(); // 나무 재테크 (골드 4)
void func_16236(); // 아기 상어 (골드 3)
void func_17144(); // 미세먼지 안녕! (골드 4)
void func_17143(); // 낚시왕 (골드 2)
void func_17140(); // 이차원 배열과 연산 (골드 4)
void func_17142(); // 연구소 3 (골드 4)
void func_17779(); // 게리맨더링 2 (골드 4)
void func_17837(); // 새로운 게임 2 (골드 2)
void func_17822(); // 원판 돌리기 (골드 3)
void func_17825(); // 주사위 윷놀이 (골드 2)
void func_20061(); // 모노미노도미노 2 (골드 2)
void func_19236(); // 청소년 상어 (골드 2)
void func_19237(); // 어른 상어 (골드 3)
void func_19238(); // 스타트 택시 (골드 4)
void func_20055(); // 컨베이어 벨트 위의 로봇 (골드 5)
void func_20056(); // 마법사 상어와 파이어볼  (골드 4)
void func_20057(); // 마법사 상어와 토네이도  (골드 3)
void func_20058(); // 마법사 상어와 파이어스톰  (골드 4)
void func_21608(); // 상어 초등학교 (실버 1)
void func_21609(); // 상어 중학교 (골드 2)
void func_21610(); // 마법사 상어와 비바라기 (골드 5)
void func_21611(); // 마법사 상어와 블리자드 (골드 1)
void func_23288(); // 주사위 굴리기 2 (골드 3)
void func_23289(); // 온풍기 안녕! (골드 1)
void func_23290(); // 마법사 상어와 복제 (골드 1)
void func_23291(); // 어항 정리 (골드 1) 


