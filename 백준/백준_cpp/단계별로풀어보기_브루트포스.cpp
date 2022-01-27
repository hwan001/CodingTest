#include "header.h"


/* 단계별 풀어보기 > 브루트포스 > 블랙잭 (브론즈 2)
* https://www.acmicpc.net/problem/2798
*/
void func_2798() {
	int n, m, sum, min, res = 0;
	cin >> n >> m;
	int* card = new int[n];
	bool is_flag;

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	
	sum = 0;
	min = m;
	is_flag = true;

	if (is_flag) {
		for (int i = 0; i < n - 1; i++) {
			if (is_flag) {
				for (int j = i + 1; j < n; j++) {
					if (is_flag) {
						for (int k = j + 1; k < n; k++) {
							sum = card[i] + card[j] + card[k];
							//cout << "i : " << i << ", j : " << j << ", k : " << k << ", sum : " << sum << endl;

							if (sum == m) {
								is_flag = false;
							}

							if (min > m - sum && m >= sum) {
								min = m - sum;
								res = sum;
							}

						}
					}
				}
			}
		}
	}

	cout << res << endl;
}


/* 단계별 풀어보기 > 브루트포스 > 분해합 (브론즈 2)
* https://www.acmicpc.net/problem/2231
*/

int func_2231_create_decompose(int a) {
	int len, res = a;

	len = to_string(a).length();

	for (int i = len; a > 0; i--) {
		res += a / pow(10, i);
		a %= (int)pow(10, i);
	}

	return res;
}

void func_2231() {
	int a, key;
	cin >> a;

	map<int, int> m;

	for (int i = 1; i < a; i++) {
		key = func_2231_create_decompose(i);
		
		if(!m[key])
			m[key] = i;
	}

	cout << m[a];
}


/* 단계별 풀어보기 > 브루트포스 > 덩치 (실버 5)
* https://www.acmicpc.net/problem/7568
*/
void func_7568() {

}

/*
void func_1018(); // 체스판 다시 칠하기
void func_1436(); // 영화감독 숌
*/


// DFS BFS > 바이러스 실버3
void func_2606() {
	// 트리 구현
	// 방문 여부 체크
	// 탐색 알고리즘 
}


// 경쟁률 작년 12: 1
// 1차는 상용 중급 골드 ? , 2차는 중상급 플래 ?
// 알고리즘 : 
// sql : 
// web : html css javascript 이해 운용
// 포트폴리오 내부 github velog
