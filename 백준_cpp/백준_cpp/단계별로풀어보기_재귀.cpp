#include "header.h"


/* 단계별 풀어보기 > 재귀 > 팩토리얼 (브론즈 3, 구현)
* https://www.acmicpc.net/problem/10872
*/
int func_10872_factorial(int n) {
	if (n == 0) return 1;
	else return n * func_10872_factorial(n-1);
}

void func_10872() {
	int a;
	cin >> a;

	cout << func_10872_factorial(a);
}


/* 단계별 풀어보기 > 재귀 > 피보나치 수 5 (브론즈 2, 구현/DP)
* https://www.acmicpc.net/problem/10870
*/
int func_10870_fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return func_10870_fibonacci(n - 1) + func_10870_fibonacci(n-2);
}

void func_10870() {
	int a;
	cin >> a;

	cout << func_10870_fibonacci(a);
}


/* 단계별 풀어보기 > 재귀 > 별 찍기 -10 (실버 1, 분할정복)
* https://www.acmicpc.net/problem/2447
*/


void func_2447() {

}


/* 단계별 풀어보기 > 재귀 > 하노이 탑 이동 순서
* https://www.acmicpc.net/problem/11729
*/
void func_11729() {

}
