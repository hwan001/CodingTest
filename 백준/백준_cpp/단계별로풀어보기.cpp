#include "header.h"

/*
*  단계별로 풀어보기 주소
*  https://www.acmicpc.net/step
*/

/*
*  *************************************
*  단계별로 풀어보기 > 입출력과 사칙연산
*  *************************************
*/

/* Hello Word
* https://www.acmicpc.net/problem/2557
*/
void func_2557() {
	cout << "Hello World!";
}

/* We love kriii
* https://www.acmicpc.net/problem/10718
*/
void func_10718() {
	cout << "강한친구 대한육군";
	cout << "강한친구 대한육군";
}

/*
void func_10171(); // 고양이
void func_10172(); // 개
void func_1000(); // A+B
void func_1001(); // A-B
void func_10998(); // A*B
void func_1008(); // A/B
void func_10869(); // 사칙연산
void func_10430(); // 나머지
void func_2588(); // 곱셈
*/

/* ??! (브론즈 5)
*  https://www.acmicpc.net/problem/10926
*/
void func_10926() {
	string str;
	cin >> str;

	cout << str + "??!" << endl;
}

/* 1998년생인 내가 태국에서는 2541년생 ? ! (브론즈 5)
*  https://www.acmicpc.net/problem/18108
*/
void func_18108() {
	int a;
	cin >> a;

	cout << a - 543 << endl;
}





/* 
*  ************************
*  단계별로 풀어보기 > if문
*  ************************
*/

/*
void func_1330(); // 두 수 비교하기
void func_9498(); // 시험 성적
void func_2753(); // 윤년
void func_14681(); // 사분면 고르기
void func_2884(); // 알람 시계
*/





/*
*  *************************
*  단계별로 풀어보기 > for문
*  *************************
*/

/*
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
*/





/*
*  ***************************
*  단계별로 풀어보기 > while문
*  ***************************
*/

/*
void func_10952(); // A+B - 5
void func_10951(); // A+B - 4
void func_1110(); // 더하기 사이클
*/





/*
*  ****************************
*  단계별 풀어보기 > 1차원 배열
*  ****************************
*/

/*
void func_10818(); // 최소, 최대
void func_2562(); // 최댓값
void func_2577(); // 숫자의 개수
void func_3052(); // 나머지
void func_1546(); // 평균
void func_8958(); // OX퀴즈
void func_4344(); // 평균은 넘겠지
*/





/*
*  ****************************
*  단계별로 풀어보기 > 함수
*  ****************************
*/

/* 정수 N개의 합
* https://www.acmicpc.net/problem/15596
*/
void func_15596() {

}

/* 셀프 넘버
* https://www.acmicpc.net/problem/4673
*/
void func_4673() {

}

/* 한수
* https://www.acmicpc.net/problem/1065
*/
void func_1065() {

}





/*
*  ************************
*  단계별 풀어보기 > 문자열
*  ************************
*/

/* 단어 공부
*  https://www.acmicpc.net/problem/1157
*/
void func_1157() {
	string str;
	map<char, int> myMap;
	map<char, int>::iterator iter;

	int int_max = 0;

	char ch_result;
	int int_cnt = 0;

	// a~z 0으로 초기화
	for (char c = 'a'; c <= 'z'; c++) {
		myMap[c] == 0;
	}

	// 입력받고 소문자 변경 후 카운트
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
		myMap[str[i]]++;
	}

	// max 값 설정
	for (iter = myMap.begin(); iter != myMap.end(); iter++) {
		if (iter->second > int_max) {
			int_max = iter->second;
		}
	}

	// max 랑 값이 같으면서 cnt 개수가 1인거는 출력, 아니면 ?
	for (iter = myMap.begin(); iter != myMap.end(); iter++) {
		if (int_max == iter->second) {
			int_cnt++;
			ch_result = iter->first;
		}
	}

	if (int_cnt == 1) {
		printf("%c\n", toupper(ch_result));
	}
	else {
		cout << '?' << endl;
	}
}


/* 문자열 반복
*  https://www.acmicpc.net/problem/2675
*/
void func_2675() {
	int a, b;
	string str;

	cin >> a;

	for (int i = 0; i < a; i++) {
		cin >> b >> str;
		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < b; j++) {
				cout << str[i];
			}
		}
		cout << endl;
	}
}


/* 단어의 개수
*  https://www.acmicpc.net/problem/1152
*/
void func_1152() {
	string str;
	vector<string> res;
	int cnt = 0;

	getline(cin, str, '\n');
	res = split(str, ' ');

	for (int i = 0; i < res.size(); i++) {
		if (res[i].size() > 0) cnt++;
	}

	cout << cnt << endl;
}


/* 상수
*  https://www.acmicpc.net/problem/2908
*/
void func_2908() {
	string a, b;
	string a_r, b_r;
	int res;
	int cnt = 0;

	cin >> a >> b;

	a_r = a;
	b_r = b;

	for (int i = 2; i >= 0; i--) {
		a_r[cnt] = a[i];
		b_r[cnt++] = b[i];
	}

	if (stoi(a_r) > stoi(b_r)) {
		res = stoi(a_r);
	}
	else {
		res = stoi(b_r);
	}

	cout << res;
}


/* 다이얼
*  https://www.acmicpc.net/problem/5622
*/
void func_5622() {
	string str;
	cin >> str;
	map<char, int> m;
	int point, sum = 0;

	for (int i = 0; i < 26; i++) {
		if ('A' + i < 'Z') point = 10;
		if ('A' + i < 'W') point = 9;
		if ('A' + i < 'T') point = 8;
		if ('A' + i < 'P') point = 7;
		if ('A' + i < 'M') point = 6;
		if ('A' + i < 'J') point = 5;
		if ('A' + i < 'G') point = 4;
		if ('A' + i < 'D') point = 3;

		m['A' + i] = point;
	}

	for (int i = 0; i < str.length(); i++) {
		sum += m[str[i]];
	}

	cout << sum << endl;
}


/* 크로아티아 알파벳
*  https://www.acmicpc.net/problem/2941
*/
void func_2941() {
	vector<string> v_str = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	string str;

	cin >> str;
	for (int i = 0; i < v_str.size(); i++) {
		while (1) {
			if (str.find(v_str[i]) == string::npos) {
				break;
			}
			else {
				str.replace(str.find(v_str[i]), v_str[i].length(), "!");
			}
		}
	}

	cout << str.length() << endl;
}


/* 그룹 단어 체커
*  https://www.acmicpc.net/problem/1316
*/
void func_1316() {
	int a;
	cin >> a;

	string* arr_str = new string[a];
	map<char, int> m;
	int cnt = 0;

	for (int i = 0; i < a; i++) {
		cin >> arr_str[i];
	}

	char pre_ch;
	bool is_flag;

	for (int i = 0; i < a; i++) {
		pre_ch = '0';
		is_flag = true;
		for (char ch = 'a'; ch <= 'z'; ch++) {
			m[ch] = 0;
		}

		for (int j = 0; j < arr_str[i].length(); j++) {
			if (m[arr_str[i][j]] != 0) {
				if (pre_ch != arr_str[i][j]) {
					is_flag = false;
					break;
				}
			}

			m[arr_str[i][j]]++;
			pre_ch = arr_str[i][j];
		}

		if (is_flag) {
			cnt++;
		}
	}

	cout << cnt;
}





/*
*  *****************************
*  단계별 풀어보기 > 기본 수학 1
*  *****************************
*/

/* 손익분기점
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


/* 벌집
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


/* 분수찾기
* https://www.acmicpc.net/problem/1193
*/
unsigned long long func_1193_sum_of_arithmetic_sequences(int n) {
	return (n * (n + 1)) / 2;
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


/* 달팽이는 올라가고 싶다
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


/* ACM 호텔
* https://www.acmicpc.net/problem/2869
*/
void func_10250() {
	int a, h, w, n;
	int f, no;

	cin >> a;

	for (int i = 0; i < a; i++) {
		f = 1;
		no = 1;
		cin >> h >> w >> n;

		f += (n % h) - 1;
		if (n % h == 0) {
			f = h;
			no = n / h;
		}
		else {
			no += (n / h);
		}

		printf("%d%02d\n", f, no);
	}
}


/* 부녀회장이 될테야
* https://www.acmicpc.net/problem/2775
*/
int func_2775_sum_people(int k, int n) {
	if (k == 0) return n;
	if (n == 1) return 1;
	return func_2775_sum_people(k, n - 1) + func_2775_sum_people(k - 1, n);
}

void func_2775() {
	int int_k, int_n, int_t;
	int int_sum = 0;

	cin >> int_t;

	for (int i = 0; i < int_t; i++) {
		cin >> int_k;
		cin >> int_n;

		cout << func_2775_sum_people(int_k, int_n) << endl;
	}
}


/* 설탕배달
* https://www.acmicpc.net/problem/2839
*/
void func_2839() {
	int a, b, n, min, tmp, res;
	bool is_flag;

	cin >> n;

	min = n;
	res = -1;
	is_flag = false;

	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			tmp = (3 * a) + (5 * b);

			if (tmp > n) break;
			if (tmp == n) {
				if (min >= a + b) {
					min = a + b;
					is_flag = true;
				}
			}
		}
	}

	if (is_flag) res = min;

	cout << res << endl;
}


/* 큰 수 A+B
* https://www.acmicpc.net/problem/10757
*/

vector<int> func_10757_reverseVector(string num) {
	vector<int> v;

	for (int i = num.length() - 1; i >= 0; i--) {
		v.push_back((num[i] - '0'));
	}

	return v;
}

void func_10757() {
	string str_a, str_b;
	cin >> str_a >> str_b;

	vector<int> a, b, c;
	int int_a, int_b, int_tmp = 0, int_len;

	a = func_10757_reverseVector(str_a);
	b = func_10757_reverseVector(str_b);

	if (a.size() >= b.size()) {
		int_len = a.size();
	}
	else {
		int_len = b.size();
	}


	for (int i = 0; i < int_len; i++) {
		try {
			int_a = a.at(i);
		}
		catch (exception e) {
			int_a = 0;
		}

		try {
			int_b = b.at(i);
		}
		catch (exception e) {
			int_b = 0;
		}

		c.push_back((int_a + int_b + int_tmp) % 10);

		if ((int_a + int_b + int_tmp) >= 10) {
			int_tmp = 1;
		}
		else {
			int_tmp = 0;
		}
	}

	if (int_tmp) {
		c.push_back(1);
	}

	for (int i = c.size() - 1; i >= 0; i--) {
		cout << c.at(i);
	}
}


/* Fly me to the Alpha Centauri
* https://www.acmicpc.net/problem/1011
*/
void func_1011() {
	int int_case;
	ll x, y, res, distance, level;

	cin >> int_case;

	for (int i = 0; i < int_case; i++) {
		cin >> x >> y;
		distance = y - x;

		if (distance > 0 && distance <= 3) {
			res = distance;
		}
		else {
			level = (int)sqrt(distance);

			if (((level + 1) * (level + 1)) - (level + 1) < distance && distance < ((level + 1) * (level + 1))) {
				res = 2 * level + 1;
			}
			else if (distance == level * level) {
				res = 2 * level - 1;
			}
			else {
				res = 2 * level;
			}
		}

		cout << res << "\n";
	}
}





/*
*  *****************************
*  단계별 풀어보기 > 기본 수학 2
*  *****************************
*/

/* 소수 찾기
* https://www.acmicpc.net/problem/1978
*/
void func_1978() {
	int a, cnt = 0;
	cin >> a;

	int* arr = new int[a];

	for (int i = 0; i < a; i++) {
		cin >> arr[i];
		if (is_prime_number_custom(arr[i])) {
			cnt++;
		}
	}

	cout << cnt;
}


/* 소수
* https://www.acmicpc.net/problem/2581
*/
void func_2581() {
	int a, b, min, sum = 0;
	cin >> a >> b;

	for (int i = a; i <= b; i++) {
		if (is_prime_number_custom(i)) {
			if (sum == 0) min = i;
			sum += i;
		}
	}

	if (sum == 0) cout << -1 << endl;
	else {
		cout << sum << endl;
		cout << min;
	}
}


/* 소인수분해
* https://www.acmicpc.net/problem/11653
*/
void func_11653_Factorization(int a) {
	bool is_flag = true;

	for (int i = 2; i < a; i++) {
		if (a % i == 0) {
			is_flag = false;
			cout << i << endl;
			func_11653_Factorization(a / i);
			break;
		}
	}

	if (is_flag) cout << a << endl;
}

void func_11653() {
	int a;
	cin >> a;

	if (a != 1) {
		func_11653_Factorization(a);
		/*
		if (is_prime_number_custom(a)) {
			cout << a;
		}
		else {
			func_11653_Factorization(a);
		}
		*/
	}
}


/* 소수 구하기
* https://www.acmicpc.net/problem/1929
*/
void func_1929() {
	int int_M, int_N;
	cin >> int_M >> int_N;

	for (int i = int_M; i <= int_N; i++)
	{
		if (is_prime_number_custom(i)) {
			cout << i << endl;
		}
	}
}


/* 베르트랑 공준
* https://www.acmicpc.net/problem/4948
*/
void func_4948() {
	int int_N, cnt;
	bool* arr = Sieve_of_Eratosthenes(123456 * 2);

	do {
		cin >> int_N;
		cnt = 0;


		for (int i = int_N + 1; i <= int_N * 2; i++) {
			if (arr[i]) {
				cnt++;
			}
		}

		if (int_N != 0) cout << cnt << endl;
	} while (int_N != 0);

}


/* 골드바흐의 추측
* https://www.acmicpc.net/problem/9020
*/
void func_9020() {
	int int_a, int_N, int_sum;
	bool* arr = Sieve_of_Eratosthenes(20000);
	int tmp_a, tmp_b, tmp_min;
	vector<int> v;

	cin >> int_a;
	for (int i = 0; i < int_a; i++) {
		cin >> int_N;

		// 초기화
		int_sum = 0;
		v.clear();

		// 해당 수보다 작은 소수 모으기
		for (int j = 2; j < int_N; j++) {
			if (arr[j]) {
				v.push_back(j);
			}
		}

		tmp_a = 0;
		tmp_b = 0;
		tmp_min = int_N;

		for (int j = 0; j < v.size(); j++) {
			for (int k = 0; k < v.size(); k++) {
				if (int_N == v.at(j) + v.at(k) && tmp_min > abs(v.at(j) - v.at(k))) {
					tmp_a = v.at(j);
					tmp_b = v.at(k);
					tmp_min = abs(v.at(j) - v.at(k));
				}
			}
		}

		if (tmp_a + tmp_b != 0) cout << tmp_a << " " << tmp_b << endl;
	}
}


/* 직사각형에서 탈출
* https://www.acmicpc.net/problem/1085
*/
void func_1085() {
	int x, y, w, h, min;

	cin >> x;
	min = x;

	cin >> y;
	if (min > y) min = y;

	cin >> w;
	if (min > w - x) min = w - x;

	cin >> h;
	if (min > h - y) min = h - y;

	cout << min;
}


/* 네 번째 점
* https://www.acmicpc.net/problem/3009
*/
void func_3009() {
	int a, b;
	map<int, int> x, y;
	map<int, int>::iterator iter;

	for (int i = 0; i < 3; i++) {
		cin >> a >> b;

		if (x.count(a)) x[a]++;
		else x[a] = 1;

		if (y.count(b)) y[b]++;
		else y[b] = 1;
	}

	for (iter = x.begin(); iter != x.end(); iter++) {
		if (iter->second == 1) {
			cout << iter->first << " ";
		}
	}

	for (iter = y.begin(); iter != y.end(); iter++) {
		if (iter->second == 1) {
			cout << iter->first;
		}
	}
}


/* 직각삼각형
* https://www.acmicpc.net/problem/4153
*/
void func_4153() {
	// 아이디어 : 피타고라스 정리 활용
	int a, b, c;
	int pow_a, pow_b, pow_c, pow_sum;

	while (1) {
		cin >> a >> b >> c;

		pow_a = pow(a, 2);
		pow_b = pow(b, 2);
		pow_c = pow(c, 2);
		pow_sum = pow_a + pow_b + pow_c;

		if (pow_sum == 0)
			break;

		if (pow_a == pow_sum - pow_a || pow_b == pow_sum - pow_b || pow_c == pow_sum - pow_c) {
			cout << "right" << endl;
		}
		else {
			cout << "wrong" << endl;
		}
	}
}


/* 택시 기하학
* https://www.acmicpc.net/problem/3053
*/
void func_3053() {
	// cmath 내부 pi : M_PI (cmath include 전 #define _USE_MATH_DEFINES 필요)
	int r;
	cin >> r;

	// 유클리드 기하학에서의 넓이
	printf("%.6f\n", const_pi() * pow(r, 2));

	// 택시 기하학 에서의 넓이 : 대각선 길이가 r인 마름모의 넓이
	printf("%.6f\n", pow(2 * r, 2) / 2);

}


/* 터렛
* https://www.acmicpc.net/problem/1002
*/
void func_1002() {
	int a;
	cin >> a;

	int x1, y1, r1, x2, y2, r2;
	double len;

	for (int i = 0; i < a; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		// 두 점 사이의 거리
		len = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

		// 반경이 완벽하게 겹치면 무한대의 경우
		if (len == 0 && r1 - r2 == 0) {
			cout << -1 << endl;
			continue;
		}

		// 시작점은 같은데 반경이 달라 만날 수 없음
		if (len == 0 && r1 - r2 != 0) {
			cout << 0 << endl;
			continue;
		}

		// 삼각형이 성립되면 2개, 일치하면 1개, 안되면 0개
		// 원의 교점을 이용해서 푼 경우가 대부분, 삼각형 성립으로 푼 경우는 못찾음
		if (len < r1 + r2 && r1 < r2 + len && r2 < len + r1) {
			cout << 2 << endl;
		}
		else if (len == r1 + r2 || r1 == len + r2 || r2 == len + r1) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
}





/*
*  **********************
*  단계별 풀어보기 > 재귀
*  **********************
*/

/* 팩토리얼 (브론즈 3, 구현)
* https://www.acmicpc.net/problem/10872
*/
int func_10872_factorial(int n) {
	if (n == 0) return 1;
	else return n * func_10872_factorial(n - 1);
}

void func_10872() {
	int a;
	cin >> a;

	cout << func_10872_factorial(a);
}


/* 피보나치 수 5 (브론즈 2, 구현/DP)
* https://www.acmicpc.net/problem/10870
*/
int func_10870_fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return func_10870_fibonacci(n - 1) + func_10870_fibonacci(n - 2);
}

void func_10870() {
	int a;
	cin >> a;

	cout << func_10870_fibonacci(a);
}


/* 별 찍기 -10 (실버 1, 분할정복)
* https://www.acmicpc.net/problem/2447
*/
void func_2447_starPrint(int n, int a, int b) {
	int n_copy = n;
	int int_squared = 0;

	if (n == 1) return;

	for (int i = 0; i < 8; i++) {
		if (n_copy == 1) {
			int_squared = i - 1;
			break;
		}
		n_copy /= 3;
	}

	int remove_a = pow(3, int_squared);
	int remove_b = (pow(3, int_squared) * 2) - 1;

	func_2447_starPrint(n / 3, remove_a, remove_b);

	for (int i = a; i < b; i++) {
		for (int j = a; j < b; j++) {
			// 가운데 공백
			if ((i >= remove_a && i <= remove_b) && (j >= remove_a && j <= remove_b))
			{
				cout << " ";
			}
			else
				cout << "*";
		}
		cout << "\n";
	}
}

void func_2447() {
	int a;
	cin >> a;
	func_2447_starPrint(a, 0, a);
}


/* 하노이 탑 이동 순서
* https://www.acmicpc.net/problem/11729
*/
void func_11729() {

}




/*
*  ****************************
*  단계별 풀어보기 > 브루트포스
*  ****************************
*/

/* 블랙잭 (브론즈 2)
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


/* 분해합 (브론즈 2)
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

		if (!m[key])
			m[key] = i;
	}

	cout << m[a];
}


/* 덩치 (실버 5)
* https://www.acmicpc.net/problem/7568
*/
void func_7568() {
	int int_case;
	int cnt, grade;
	int* bulk;

	cin >> int_case;

	map<char, int*> m_input;

	// 입력
	for (int i = 0; i < int_case; i++) {
		bulk = new int[2];

		cin >> bulk[0] >> bulk[1];

		m_input['a' + i] = bulk;
	}

	// 점수 매기기
	for (int i = 0; i < int_case; i++) {
		cnt = 1;

		for (int j = 0; j < int_case; j++) {
			// 덩치 : 키도 크고, 몸무게도 무거운 사람 수
			if (m_input['a' + i][0] < m_input['a' + j][0] && m_input['a' + i][1] < m_input['a' + j][1]) {
				cnt++;
			}
		}

		// 점수 기록
		cout << cnt << " ";
	}

	for (int i = 0; i < int_case; i++) {
		delete m_input['a' + i];
	}
}
void func_7568_2() {
	int int_case, cnt;
	cin >> int_case;
	int** arr = new int* [int_case];
	int* bulk;

	for (int i = 0; i < int_case; i++) {
		bulk = new int[2];
		cin >> bulk[0] >> bulk[1];
		arr[i] = bulk;
	}

	for (int i = 0; i < int_case; i++) {
		cnt = 1;
		for (int j = 0; j < int_case; j++) {
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) {
				cnt++;
			}
		}
		cout << cnt << " ";
	}
}

/* 체스판 다시 칠하기 (실버 5)
* https://www.acmicpc.net/problem/1018
*/
void func_1018() {

}

/* 영화감독 숌 (실버 )
* https://www.acmicpc.net/problem/1436
*/
void func_1436() {

}



/*
*  **********************
*  단계별 풀어보기 > 정렬
*  **********************
*/

/* 수 정렬하기
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

/* 수 정렬하기 2
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

/* 수 정렬하기 3
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

/* 통계학
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
		cout << (v.at(index) + v.at(index + 1)) / 2 << "\n";
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

/* 소트인사이드
* https://www.acmicpc.net/problem/1427
*/
void func_1427() {

}

/* 좌표 정렬하기
* https://www.acmicpc.net/problem/11650
*/
void func_11650() {

}

/* 좌표 정렬하기 2
* https://www.acmicpc.net/problem/11651
*/
void func_11651() {

}

/* 단어 정렬
* https://www.acmicpc.net/problem/1181
*/
void func_1181() {

}

/* 나이순 정렬
* https://www.acmicpc.net/problem/10814
*/
void func_10814() {

}

/* 좌표 압축
* https://www.acmicpc.net/problem/18870
*/
void func_18870() {

}




/*
*  ***************************
*  단계별 풀어보기 > DFS와 BFS
*  ***************************
*/

/*  DFS와 BFS
*   https://www.acmicpc.net/problem/1260
*/
void func_1260_graphPrint(map<int, vector<int>> graph) {
	for (auto node : graph) {
		cout << node.first << " : ";
		for (auto nd : node.second) {
			cout << nd << " ";
		}
		cout << "\n";
	}
}

void func_1260_dfs_recursion(int n, vector<int>* graph, bool* visited) {
	visited[n] = true;
	cout << n << " ";

	for (auto node : graph[n]) {
		if (!visited[node]) {
			func_1260_dfs_recursion(node, graph, visited);
		}
	}
}

void func_1260_dfs_stack() {

}

void func_1260_bfs_queue(int n, vector<int>* graph, bool* visited) {
	queue<int> q;
	int now_node;

	visited[n] = true;
	q.push(n);

	while (!q.empty()) {
		now_node = q.front();
		q.pop();
		cout << now_node << " ";

		for (auto node : graph[now_node]) {
			if (!visited[node]) {
				visited[node] = true;
				q.push(node);
			}
		}
	}
}

void func_1260_bfs_queue_matrix(int n, int** graph, bool* visited) {
	queue<int> q;
	int now_node;

	visited[n] = true;
	q.push(n);

	while (!q.empty()) {
		now_node = q.front();
		q.pop();
		cout << now_node << " ";

		for(int i=0; i < sizeof(graph[n]); i++) {
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

void func_1260() {
	int n, m, start_node, u, v;
	
	cin >> n >> m >> start_node;

	// map<int, vector<int>> graph;
	
	vector<int> *graph = new vector<int>[n+1];

	bool *visited = new bool[n+1];
	memset(visited, 0, sizeof(bool) * (n+1));

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	func_1260_dfs_recursion(start_node, graph, visited);
	cout << "\n";

	memset(visited, 0, sizeof(bool) * (n + 1));
	func_1260_bfs_queue(start_node, graph, visited);
}

void func_1260_matrix() {
	int n, m, start_node, u, v;

	cin >> n >> m >> start_node;

	// 인접행렬 생성
	int** graph = new int* [n];
	for (int i = 0; i < n; i++) {
		graph[i] = new int[n];
	}

	bool* visited = new bool[n + 1];
	memset(visited, 0, sizeof(bool) * (n + 1));

	// 인접행렬 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = 0;
		}
	}

	// 간선 입력
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		u--;
		v--;
		// 무방향 그래프
		graph[u][v] = graph[v][u] = 1;
	}


	// 인접행렬 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}

	func_1260_bfs_queue_matrix(start_node, graph, visited);
}


/*  바이러스
*   https://www.acmicpc.net/problem/2606
*/

static int func_2606_cnt;

void func_2606_dfs(int start, vector<int> *graph, bool* visited) {
	visited[start] = true;
	//cout << start << " ";

	func_2606_cnt++;

	for (auto node : graph[start]) {
		if (!visited[node]) {
			func_2606_dfs(node, graph, visited);
		}
	}
}

void func_2606() {
	int n, m, u, v;

	cin >> n;
	cin >> m;

	vector<int> *graph = new vector<int>[n+1];

	// 노드 개수 +1개
	bool* visited = new bool[n+1];
	memset(visited, 0, sizeof(bool) * (n+1));

	func_2606_cnt = 0;

	// 간선 입력
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	func_2606_dfs(1, graph, visited);

	cout << func_2606_cnt -1 << "\n";
}


/*  단지번호붙이기
*   https://www.acmicpc.net/problem/2667
*/
void func_2667_HouseComplex_Detection(int n, int** map) {
	bool is_comp = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j]) {
				is_comp = true;
			}

			if (is_comp) {
			}
		}
	}
}

vector<int> *func_2667_Convert_adjMatrix_to_adjList(int n, int** matrix) {
	vector<int> * adjlist = new vector<int>[n+1];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == 1 && i != j) {
				adjlist[i+1].push_back(j + 1);
			}
		}

		sort(adjlist[i+1].begin(), adjlist[i+1].end());
	}

	return adjlist;
}

void func_2667() {
	int n;
	string str;

	cin >> n;

	int** map = new int* [n];
	for (int i = 0; i < n; i++) {
		str = "";
		map[i] = new int[n];

		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			map[i][j] = str[j] - '0';
		}
	}

	
	func_2667_HouseComplex_Detection(n, map);


}



/*  미로탐색
*   https://www.acmicpc.net/problem/2178
*/

class func_2178_node {
public:
	int x;
	int y;
	int value;
	int visited;
};

int func_2178_BFS(int n, int m, func_2178_node **_map, int *start_node, int *end_node) {
	// BFS 탐색을 위한 큐 생성 현재 노드 저장
	queue<func_2178_node> q;
	func_2178_node tmp_node, now_node;

	// 상0, 우1, 하2, 좌3 
	int** direction = new int*[4];
	for (int i = 0; i < 4; i++) {
		direction[i] = new int[2];

		if (i == 0) {
			direction[i][0] = 0;
			direction[i][1] = -1;
		}
		if (i == 1) {
			direction[i][0] = 1;
			direction[i][1] = 0;
		}
		if (i == 2) {
			direction[i][0] = 0;
			direction[i][1] = 1;
		}
		if (i == 3) {
			direction[i][0] = -1;
			direction[i][1] = 0;
		}

		//cout << i << " - " << direction[i][0] << ", " << direction[i][1] << "\n";
	}


	// 시작노드의 방문 여부 변경
	_map[start_node[0]][start_node[1]].visited = 1;
	// 시작노드 넣기
	q.push(_map[start_node[0]][start_node[1]]);


	// 큐에 값이 있으면 탐색 시작
	while (!q.empty()) {
		// 현재 큐의 값 가져오기 + pop
		now_node = q.front();
		q.pop();

		// 인접 노드 탐색 (시계방향으로 탐색)
		for (int i = 0; i < 4; i++) {
			// 현재 좌표가 좌우를 넘어가는지 확인 (넘어가면 continue)
			if (now_node.x + direction[i][0] <= 0 || now_node.x + direction[i][0] > n) {
				continue;
			}

			// 현재 좌표가 상하를 넘어가는지 확인 (넘어가면 continue)
			if (now_node.y + direction[i][1] <= 0 || now_node.y + direction[i][1] > m) {
				continue;
			}

			// 이동한 값이 맵 안에 있으면 노드 이동
			tmp_node = _map[now_node.x + direction[i][0]][now_node.y + direction[i][1]];

			// 값이 1이 아닌지 검사, 아니면 continue;
			if (tmp_node.value == 0) {
				continue;
			}

			// 값이 1이고, 방문 여부가 없는지 검사 (방문했으면 다음거)
			if (tmp_node.visited) {
				continue;
			}

			// 인접 노드가 맵 안에 있고, 이동이 가능하며, 방문한 적이 없다면 큐에 등록하고 방문여부 바꾸고 탐색횟수 증가
			_map[tmp_node.x][tmp_node.y].visited = _map[now_node.x][now_node.y].visited + 1;
			q.push(_map[tmp_node.x][tmp_node.y]);

			//cout << "tmp_node[" << tmp_node.x << "][" << tmp_node.y << "] "<< _map[tmp_node.x][tmp_node.y].visited << " -> 탐색 완료 \n";
		}

		// 방문 상태 출력
		/*
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << _map[i][j].visited << "";
			}
			cout << "\n";
		}
		cout << "\n";
		*/
	}

	return _map[n][m].visited;
}

void func_2178() {
	int n, m;
	int* start_node = new int[2];
	int* end_node = new int[2];
	string str_input;

	cin >> n >> m;

	start_node[0] = 1;
	start_node[1] = 1;
	end_node[0] = n;
	end_node[1] = m;

	// 노드 맵 초기화
	func_2178_node** map = new func_2178_node*[n+1];
	for (int i = 1; i <= n; i++) {
		map[i] = new func_2178_node[m+1];
	}

	// 입력 및 초기화
	for (int i = 1; i <= n; i++) {
		cin >> str_input;
		for (int j = 1; j <= m; j++) {
			map[i][j].x = i;
			map[i][j].y = j;
			map[i][j].value = str_input[j-1] - '0';
			map[i][j].visited = 0;
		}
	}

	cout << func_2178_BFS(n, m, map, start_node, end_node) << "\n";

}




/*  유기농 배추
*   https://www.acmicpc.net/problem/1012
*/
class func_1012_node {
public:
	int x;
	int y;
	int value;
	int visited;
};


void func_1012_bfs(int n, func_1012_node **map, bool* visited) {
	queue<func_1012_node> q;
	
	
	
}

void func_1012() {
	int test_case;
	int n, m, k;
	int u, v;
	int cnt;
	bool* visited;
	func_1012_node** map;

	cin >> test_case;
	
	for (int a = 0; a < test_case; a++) {
		cin >> m >> n >> k;

		// 값 초기화
		map = new func_1012_node *[n];
		cnt = 0;

		// Map 생성 및 초기화
		for (int i = 0; i < n; i++) {
			map[i] = new func_1012_node[m];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j].x = i;
				map[i][j].y = j;
				map[i][j].value = 0;
				map[i][j].visited = 0;
			}
		}

		// Map 업데이트
		for (int j = 0; j < k; j++) {
			cin >> u >> v;
			map[u][v].value = 1;
		}

		// 방문 기록 확인하면서 Map 탐색

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				/*
				if (!map[i][j].visited) {
					func_1012_bfs(1, map, visited);
					cnt++;
				}
				*/
				cout << map[i][j].value << "";
			}
			cout << "\n";
		}

		cout << cnt << "\n";
		
		// map 정리
		for (int j = 0; j <= n; j++) {
			delete map[j];
		}
		delete map;
	}
}


/*  토마토
*   https://www.acmicpc.net/problem/7576
*/
class func_7576_tomato {
public:
	int x;
	int y;
	int visited;
	int value;
	bool is_count;
};

bool func_7576_count_Box(int n, int m, func_7576_tomato** box) {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j].is_count) {
				sum++;
			}
		}
	}
	if (sum == n * m) {
		return true;
	}
	else {
		return false;
	}
}

int func_7576_bfs(int n, int m, func_7576_tomato** box, vector<int*> start) {
	queue<func_7576_tomato> q;

}

void func_7576() {
	int m, n, tmp;
	vector<int*> start;

	// 노드 개수
	cin >> m >> n;

	// 노드 생성
	func_7576_tomato** box = new func_7576_tomato*[n];
	for (int i = 0; i < n; i++) {
		box[i] = new func_7576_tomato[m];
	}

	// 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			box[i][j].x = i;
			box[i][j].y = j;
			box[i][j].visited = 0;
			box[i][j].value = 0;
			box[i][j].is_count = false;
		}
	}

	// 입력값 받기 + 입력에 따른 값 설정
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp = box[i][j].value;
			cin >> tmp;

			if (tmp != 0){
				// 0이 아니면 카운트가 가능(0이면 세지 않음)
				box[i][j].is_count = true;
			}
			if (tmp == 1) {
				//입력 값이 1이면 시작 좌표를 기록 이 값에 대해서 bfs

			}
		}
	}

	
	// BFS로 visit은 몇번만에 변하는지 카운트 + 변하면 count = true;
	func_7576_bfs(n, m, box, start);

	// 카운트가 가능한 상자 수와 전체 상자 수가 같으면
	if (!func_7576_count_Box(n, m, box)) {
		cout << -1 << "\n";
	}


}