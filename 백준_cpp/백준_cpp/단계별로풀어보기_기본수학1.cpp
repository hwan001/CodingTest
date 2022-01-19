#include "header.h"


/* 단계별 풀어보기 >> 기본 수학1 >> 손익분기점
* https://www.acmicpc.net/problem/1712
*/
void func_1712() {
	int a, b, c;
	//map<char, int> m = { {'A', 1000}, {'B', 70}, {'C', 1}};
	cin >> a >> b >> c;
	int unit_profit = c - b;

	if (unit_profit <= 0) {
		cout << -1;
	}
	else {
		cout << a / unit_profit + 1 << endl;
	}
}

/* 단계별 풀어보기 >> 기본 수학1 >> 벌집
* https://www.acmicpc.net/problem/2292
*/
void func_2292() {
	int a;
	cin >> a;

	for (int i = 1; true; i++) {
		if (a == 1) {
			cout << i;
			break;
		}

		a -= (6 * i);

		if (a <= 0) {
			cout << i + 1;
			break;
		}
	}
}

