#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <map> 
#include <utility> 
#include <sstream> 

using namespace std;

/*
*  Custom Function 
*/
vector<string> split(string str, char ch) {
	stringstream ss(str);
	string tmp;
	vector<string> res;

	while (getline(ss, tmp, ch)) {
		if (tmp.size() > 0) {
			res.push_back(tmp);
		}
	}

	return res;
}


/* �ܰ躰 Ǯ��� >> ���ڿ� >> �ܾ� ����
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

/* �ܰ躰 Ǯ��� >> ���ڿ� >> ���ڿ� �ݺ�
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

/* �ܰ躰 Ǯ��� >> ���ڿ� >> �ܾ��� ����
* https://www.acmicpc.net/problem/1152
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


/* �ܰ躰 Ǯ��� >> ���ڿ� >> ���
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

/* �ܰ躰 Ǯ��� >> ���ڿ� >> ���̾�
* https://www.acmicpc.net/problem/5622
*/
void func_5622() {
	string str;
	cin >> str;
	map<char, int> m;
	int point, sum=0;

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

/* �ܰ躰 Ǯ��� >> ���ڿ� >> ũ�ξ�Ƽ�� ���ĺ�
* https://www.acmicpc.net/problem/2941
*/
//ljes=njakljes=njakljes=njakljes=njakljes=njakljes=njakljes=njak
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

/* �ܰ躰 Ǯ��� >> ���ڿ� >> �׷� �ܾ� üĿ
* https://www.acmicpc.net/problem/1316
*/
void func_1316() {

}

int main() {
	func_2941();

	return 0;
}

