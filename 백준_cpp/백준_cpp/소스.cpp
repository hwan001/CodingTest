#include <iostream>
#include <vector>
#include <string> // string
#include <algorithm> // minmax, ...
#include <map> // map
#include <utility> // pair

using namespace std;

int main() {
	string str;
	map<char, int> myMap;
	map<char, int>::iterator iter;
	pair<int, int> a1;


	// a~z, A~Z 0으로 초기화
	for (char c = 'a'; c <= 'z'; c++) {
		myMap[c] == 0;
	}
	for (char c = 'A'; c <= 'Z'; c++) {
		myMap[c] == 0;
	}

	// 입력 받고 카운트
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		myMap[str[i]]++;
	}

	// 전체 출력
	for (iter = myMap.begin(); iter != myMap.end(); iter++) {
		cout << iter->first << ", " << iter->second << endl;
	}

	//minmax(myMap);
	// 대소문자 구분기능, 알파벳 카운팅 기능
	// 카운팅 된 알파벳 중 가장 많이 사용된 건?
	// 여러개 인 경우를 알려면?

	return 0;
}

