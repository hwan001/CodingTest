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


	// a~z, A~Z 0���� �ʱ�ȭ
	for (char c = 'a'; c <= 'z'; c++) {
		myMap[c] == 0;
	}
	for (char c = 'A'; c <= 'Z'; c++) {
		myMap[c] == 0;
	}

	// �Է� �ް� ī��Ʈ
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		myMap[str[i]]++;
	}

	// ��ü ���
	for (iter = myMap.begin(); iter != myMap.end(); iter++) {
		cout << iter->first << ", " << iter->second << endl;
	}

	//minmax(myMap);
	// ��ҹ��� ���б��, ���ĺ� ī���� ���
	// ī���� �� ���ĺ� �� ���� ���� ���� ��?
	// ������ �� ��츦 �˷���?

	return 0;
}

