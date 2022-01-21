#include "header.h"


/* �ܰ躰 Ǯ��� >> �⺻ ���� 1 >> ���ͺб���
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


/* �ܰ躰 Ǯ��� >> �⺻ ���� 1 >> ����
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


/* �ܰ躰 Ǯ��� >> �⺻ ���� 1 >> �м�ã��
* https://www.acmicpc.net/problem/1193
*/
unsigned long long func_1193_sum_of_arithmetic_sequences(int n) {
	return ( n * (n+1) ) / 2;
}

string func_1193_create(int n) {
	// �Է¹��� �ε����� ��Ģ�� ������� ���� (�Է½ø��� ����, ��� ���� ����� �ð�)
	// ��Ģ. ĭ ���� ���������� 1���� ���� 1-> 2 -> 3 -> 4 ... �׸��� a/b �� a�� ����, b�� ����
	int lv, pos;
	int a, b;

	// ���� ���ϱ�
	for (int i = 0; i < 10000; i++) {
		if (n <= func_1193_sum_of_arithmetic_sequences(i)) {
			lv = i;
			break;
		}
	}

	// ������ ���̳��� ��ġ�� ���ϱ�
	pos = n - func_1193_sum_of_arithmetic_sequences(lv);

	// ���������� �� ����
	if (lv % 2 == 0) {
		a = 1;
		b = lv;
		pos *= -1;
	}
	else {
		a = lv;
		b = 1;
	}

	// ���̳��� �� ��ŭ ����
	a += pos;
	b -= pos;

	return to_string(b) + "/" + to_string(a);
}

void func_1193() {
	int a;
	cin >> a;

	cout << func_1193_create(a) << endl;
}


/* �ܰ躰 Ǯ��� >> �⺻ ���� 1 >> �����̴� �ö󰡰� �ʹ�
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


/* �ܰ躰 Ǯ��� >> �⺻ ���� 1 >> ACM ȣ��
* https://www.acmicpc.net/problem/2869
*/
void func_10250() {
	
}


/* �ܰ躰 Ǯ��� >> �⺻ ���� 1 >> �γ�ȸ���� ���׾�
* https://www.acmicpc.net/problem/2775
*/
void func_2775() {

}


/* �ܰ躰 Ǯ��� >> �⺻ ���� 1 >> �������
* https://www.acmicpc.net/problem/2839
*/
void func_2839() {

}


/* �ܰ躰 Ǯ��� >> �⺻ ���� 1 >> ū �� A+B
* https://www.acmicpc.net/problem/10757
*/
void func_10757() {

}


/* �ܰ躰 Ǯ��� >> �⺻ ���� 1 >> Fly me to the Alpha Centauri
* https://www.acmicpc.net/problem/1011
*/
void func_1011() {

}