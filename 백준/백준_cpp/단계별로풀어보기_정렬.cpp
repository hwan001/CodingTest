#include "header.h"


/* �ܰ躰 Ǯ��� > ���� > �� �����ϱ�
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

/* �ܰ躰 Ǯ��� > ���� > �� �����ϱ� 2
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

/* �ܰ躰 Ǯ��� > ���� > �� �����ϱ� 3
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

/* �ܰ躰 Ǯ��� > ���� > �����
* https://www.acmicpc.net/problem/2108
*/
void func_2108() {

}

/* �ܰ躰 Ǯ��� > ���� > ��Ʈ�λ��̵�
* https://www.acmicpc.net/problem/1427
*/
void func_1427() {

}

/* �ܰ躰 Ǯ��� > ���� > ��ǥ �����ϱ�
* https://www.acmicpc.net/problem/11650
*/
void func_11650() {

}

/* �ܰ躰 Ǯ��� > ���� > ��ǥ �����ϱ� 2
* https://www.acmicpc.net/problem/11651
*/
void func_11651() {

}

/* �ܰ躰 Ǯ��� > ���� > �ܾ� ����
* https://www.acmicpc.net/problem/1181
*/
void func_1181() {

}

/* �ܰ躰 Ǯ��� > ���� > ���̼� ����
* https://www.acmicpc.net/problem/10814
*/
void func_10814() {

}


/* �ܰ躰 Ǯ��� > ���� > ��ǥ ����
* https://www.acmicpc.net/problem/18870
*/
void func_18870() {

}
