#include "header.h"


/* �ܰ躰 Ǯ��� > ��� > ���丮�� (����� 3, ����)
* https://www.acmicpc.net/problem/10872
*/
int func_10872_factorial(int n) {
	if (n == 0) return 1;
	else return n * func_10872_factorial(n-1);
}

void func_10872() {
	int a;
	cin >> a;

	cout << func_10872_factorial(a);
}


/* �ܰ躰 Ǯ��� > ��� > �Ǻ���ġ �� 5 (����� 2, ����/DP)
* https://www.acmicpc.net/problem/10870
*/
int func_10870_fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return func_10870_fibonacci(n - 1) + func_10870_fibonacci(n-2);
}

void func_10870() {
	int a;
	cin >> a;

	cout << func_10870_fibonacci(a);
}


/* �ܰ躰 Ǯ��� > ��� > �� ��� -10 (�ǹ� 1, ��������)
* https://www.acmicpc.net/problem/2447
*/


void func_2447() {

}


/* �ܰ躰 Ǯ��� > ��� > �ϳ��� ž �̵� ����
* https://www.acmicpc.net/problem/11729
*/
void func_11729() {

}
