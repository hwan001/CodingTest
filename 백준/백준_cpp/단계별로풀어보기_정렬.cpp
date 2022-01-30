#include "header.h"


/* 단계별 풀어보기 > 정렬 > 수 정렬하기
* https://www.acmicpc.net/problem/2750
*/
void func_2750() {
	int a, num;
	vector<int> v;
	cin >> a;
	
	for (int i = 0; i < a; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << "\n";
	}
}

/* 단계별 풀어보기 > 정렬 > 수 정렬하기 2
* https://www.acmicpc.net/problem/2751
*/
void func_2751() {
	int a, num;
	vector<int> v;
	cin >> a;

	for (int i = 0; i < a; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << "\n";
	}
}

/* 단계별 풀어보기 > 정렬 > 수 정렬하기 3
* https://www.acmicpc.net/problem/10989
*/
void func_10989() {
	int a, num;
	map<int, int> m;
	map<int, int>::iterator iter;
	cin >> a;

	for (int i = 0; i < a; i++) {
		cin >> num;
		if (m[num] == 0) m[num] = 1;
		else m[num]++;
	}

	for (iter = m.begin(); iter != m.end(); iter++) {
		for (int i = 0; i < iter->second; i++) {
			cout << iter->first << "\n";
		}
	}
}

/* 단계별 풀어보기 > 정렬 > 통계학
* https://www.acmicpc.net/problem/2108
*/
void func_2108() {

}

/* 단계별 풀어보기 > 정렬 > 소트인사이드
* https://www.acmicpc.net/problem/1427
*/
void func_1427() {

}

/* 단계별 풀어보기 > 정렬 > 좌표 정렬하기
* https://www.acmicpc.net/problem/11650
*/
void func_11650() {

}

/* 단계별 풀어보기 > 정렬 > 좌표 정렬하기 2
* https://www.acmicpc.net/problem/11651
*/
void func_11651() {

}

/* 단계별 풀어보기 > 정렬 > 단어 정렬
* https://www.acmicpc.net/problem/1181
*/
void func_1181() {

}

/* 단계별 풀어보기 > 정렬 > 나이순 정렬
* https://www.acmicpc.net/problem/10814
*/
void func_10814() {

}


/* 단계별 풀어보기 > 정렬 > 좌표 압축
* https://www.acmicpc.net/problem/18870
*/
void func_18870() {

}
