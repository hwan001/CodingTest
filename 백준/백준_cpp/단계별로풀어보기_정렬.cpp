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
	int a, sum = 0;
	double tmp;
	double aver, max;
	int min_val, max_val;

	cin >> a;
	map<int, int> m;
	map<int, int>::iterator iter;
	vector<int> v;
	 
	// 값 받아서 키로 넣고 sum 누적
	for (int i = 0; i < a; i++) {
		cin >> tmp;

		if (m[tmp] == 0) {
			m[tmp] = 1;
		}
		else {
			m[tmp]++;
		}
		
		sum += tmp;
	}

	for (auto num : m) {
		v.push_back(num.first);
	}

	// 1. 산술평균, 소수점 이하 첫째 자리 반올림 값 
	aver = (double)sum / a;
	printf("%.0f\n", aver);
	//cout <<sum << ", " << a << ", " << aver << "\n";

	// 2. 중앙값 
	int cnt = 0;
	int index = floor(a / 2);

	if (a % 2 == 0)
		cout << (v.at(index) + v.at(index+1)) / 2 << "\n";
	else
		cout << v.at(index) << "\n";

	// 3. 최빈값 , 여러개일 경우 2번째로 작은 값
	// 키값 으로 정렬 후 find 하여 나온게 여러개면 count 세기
	max = -4000;

	for (auto num : m) {
		if (num.second > max) {
			max = num.second;
		}
	}

	cnt = 0;
	for (auto num : m) {
		if (num.second == max) {
			cnt++;
		}
		if (cnt == 1) {
			tmp = num.first;
		}
		if (cnt == 2) {
			cout << num.first << "\n";
			break;
		}
	}
	if (cnt == 1) {
		cout << tmp << "\n";
	}

	// 4. 범위 -> 가장 작은 값 ~ 가장 큰 값
	min_val = v.at(0);
	max_val = v.at(v.size() - 1);
	cout << max_val - min_val << "\n";
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
