#include "header.h"


/* �ܰ躰 Ǯ��� > ���Ʈ���� > ���� (����� 2)
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


/* �ܰ躰 Ǯ��� > ���Ʈ���� > ������ (����� 2)
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


/* �ܰ躰 Ǯ��� > ���Ʈ���� > ��ġ (�ǹ� 5)
* https://www.acmicpc.net/problem/7568
*/
void func_7568() {

}

/*
void func_1018(); // ü���� �ٽ� ĥ�ϱ�
void func_1436(); // ��ȭ���� ��
*/


// DFS BFS > ���̷��� �ǹ�3
void func_2606() {
	// Ʈ�� ����
	// �湮 ���� üũ
	// Ž�� �˰��� 
}


// ����� �۳� 12: 1
// 1���� ��� �߱� ��� ? , 2���� �߻�� �÷� ?
// �˰��� : 
// sql : 
// web : html css javascript ���� ���
// ��Ʈ������ ���� github velog
