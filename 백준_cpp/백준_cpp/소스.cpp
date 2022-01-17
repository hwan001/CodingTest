#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <map> 
#include <utility> 
#include <sstream> 

using namespace std;

/* �ܰ躰 Ǯ��� >> �ܾ� ����
* https://www.acmicpc.net/problem/1157
*/
void func_1157() {
	string str;
	map<char, int> myMap;
	map<char, int>::iterator iter;

	int int_max = 0;

	char ch_result;
	int int_cnt = 0;

	// a~z 0���� �ʱ�ȭ
	for (char c = 'a'; c <= 'z'; c++) {
		myMap[c] == 0;
	}

	// �Է¹ް� �ҹ��� ���� �� ī��Ʈ
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
		myMap[str[i]]++;
	}

	// max �� ����
	for (iter = myMap.begin(); iter != myMap.end(); iter++) {
		if (iter->second > int_max) {
			int_max = iter->second;
		}
	}

	// max �� ���� �����鼭 cnt ������ 1�ΰŴ� ���, �ƴϸ� ?
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

/* �ܰ躰 Ǯ��� >> ���ڿ� �ݺ�
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

/* �ܰ躰 Ǯ��� >> �ܾ��� ����
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

int main() {
	func_1152();

	return 0;
}

