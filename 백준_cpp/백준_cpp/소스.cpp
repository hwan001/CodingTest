#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <map> 
#include <utility> 
#include <sstream> 

using namespace std;

/* 단계별 풀어보기 >> 문자열 >> 단어 공부
* https://www.acmicpc.net/problem/1157
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

/* 단계별 풀어보기 >> 문자열 >> 문자열 반복
* https://www.acmicpc.net/problem/2675
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

/* 단계별 풀어보기 >> 문자열 >> 단어의 개수
* https://www.acmicpc.net/problem/1152
*/
vector<string> func_1152_split(string str, char ch) {
	stringstream ss(str);
	string tmp;
	vector<string> res;

	while (getline(ss, tmp, ch)) {
		res.push_back(tmp);
	}

	return res;
}

void func_1152() {
	string str;
	vector<string> res;
	int cnt = 0;

	getline(cin, str, '\n');
	res = func_1152_split(str, ' ');

	for (int i = 0; i < res.size(); i++) {
		if (res[i].size() > 0) cnt++;
	}

	cout << cnt << endl;
}


/* 단계별 풀어보기 >> 문자열 >> 상수
* https://www.acmicpc.net/problem/2908
*/
void func_2908() {
	string a, b;
	string a_r, b_r;
	int res;
	int cnt=0;

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

	cout << res ;
}

/* 단계별 풀어보기 >> 문자열 >> 다이얼
* https://www.acmicpc.net/problem/5622
*/
void func_5622() {

}

/* 단계별 풀어보기 >> 문자열 >> 크로아티아 알파벳
* https://www.acmicpc.net/problem/2941
*/
void func_2941() {

}

/* 단계별 풀어보기 >> 문자열 >> 그룹 단어 체커
* https://www.acmicpc.net/problem/1316
*/
void func_1316() {

}

int main() {
	func_5622();

	return 0;
}

