#include "header.h"


/* 단계별 풀어보기 >> 기본 수학 1 >> 손익분기점
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


/* 단계별 풀어보기 >> 기본 수학 1 >> 벌집
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


/* 단계별 풀어보기 >> 기본 수학 1 >> 분수찾기
* https://www.acmicpc.net/problem/1193
*/
unsigned long long func_1193_sum_of_arithmetic_sequences(int n) {
	return ( n * (n+1) ) / 2;
}

string func_1193_create(int n) {
	// 입력받은 인덱스를 규칙을 기반으로 생성 (입력시마다 생성, 모든 수가 비슷한 시간)
	// 규칙. 칸 수가 내려갈수록 1개씩 증가 1-> 2 -> 3 -> 4 ... 그리고 a/b 가 a는 증가, b는 감소
	int lv, pos;
	int a, b;

	// 계층 구하기
	for (int i = 0; i < 10000; i++) {
		if (n <= func_1193_sum_of_arithmetic_sequences(i)) {
			lv = i;
			break;
		}
	}

	// 계층과 차이나는 위치값 구하기
	pos = n - func_1193_sum_of_arithmetic_sequences(lv);

	// 시작지점의 값 설정
	if (lv % 2 == 0) {
		a = 1;
		b = lv;
		pos *= -1;
	}
	else {
		a = lv;
		b = 1;
	}

	// 차이나는 값 만큼 보정
	a += pos;
	b -= pos;

	return to_string(b) + "/" + to_string(a);
}

void func_1193() {
	int a;
	cin >> a;

	cout << func_1193_create(a) << endl;
}


/* 단계별 풀어보기 >> 기본 수학 1 >> 달팽이는 올라가고 싶다
* https://www.acmicpc.net/problem/2869
*/
void func_2869() {
	long long a, b, v, day;
	cin >> a >> b >> v;

	if (v <= a) {
		day = 1;
	}
	else {
		day = (v - b) / (a - b);
		if ((v - b) % (a - b) > 0) {
			day++;
		}
	}

	cout << day << endl;
}


/* 단계별 풀어보기 >> 기본 수학 1 >> ACM 호텔
* https://www.acmicpc.net/problem/2869
*/
void func_10250() {
	
}


/* 단계별 풀어보기 >> 기본 수학 1 >> 부녀회장이 될테야
* https://www.acmicpc.net/problem/2775
*/
void func_2775() {

}


/* 단계별 풀어보기 >> 기본 수학 1 >> 설탕배달
* https://www.acmicpc.net/problem/2839
*/
void func_2839() {

}


/* 단계별 풀어보기 >> 기본 수학 1 >> 큰 수 A+B
* https://www.acmicpc.net/problem/10757
*/
void func_10757() {

}


/* 단계별 풀어보기 >> 기본 수학 1 >> Fly me to the Alpha Centauri
* https://www.acmicpc.net/problem/1011
*/
void func_1011() {

}