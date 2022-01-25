#include "header.h"

// 2�Ǻ��� ���� -> ����
void func_CHAC_A() {
	// 2�� ����
	unsigned int a, b, c;
	int cnt = 0;

	cin >> a;

	b = ~a;
	b += 1;

	c = a ^ b;

	for (int i = 0; c > 0; i++) {
		if (c % 2 == 1) cnt++;
		c /= 2;
	}

	cout << cnt;
}


// ��Ŀ ã�� -> �ð� �ʰ�, ����
void func_CHAC_B() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	// �� ó�� ��Ŀ ��ġ �ʱ�ȭ
	int card[27];

	vector<int> left, right;
	memset(card, 0, sizeof(int) * 27);
	card[0] = 1;

	// ī�� ���� Ƚ��
	int a;
	cin >> a;

	int int_card, int_card_sum, int_cnt;
	int left_cnt, right_cnt;

	// ī�� ����
	for (int i = 0; i < a; i++) {

		left.clear();
		right.clear();

		for (int n = 0; n < 27; n++) {
			if (n < 13) left.push_back(card[n]);
			else right.push_back(card[n]);
		}

		int_card_sum = 0;
		right_cnt = 0;
		left_cnt = 0;
		int_cnt = 0;

		// ī�� �й�
		while (int_card_sum < 27) {
			cin >> int_card;
			int_cnt++;

			if (int_card + int_card_sum > 27)
				break;

			if (int_cnt % 2 != 0) {
				printf("%d ������, %d ~ %d\n", int_cnt, int_card_sum, int_card_sum + int_card - 1);
				for (int k = int_card_sum; k < int_card_sum + int_card; k++) {
					if (right_cnt >= 14) { 
						int_card_sum--;
						break; 
					}
					printf("%d ", right_cnt);
					card[k] = right[right_cnt];
					right[right_cnt++] = 0;
					
				}
				printf("\n ");
			}
			else {
				printf("%d ����, %d ~ %d\n", int_cnt, int_card_sum, int_card_sum + int_card - 1);
				for (int k = int_card_sum; k < int_card_sum + int_card; k++) {
					if (left_cnt >= 13) {
						int_card_sum--;
						break;
					}
					printf("%d ", left_cnt);
					card[k] = left[left_cnt];
					left[left_cnt++] = 0;
					
				}
				printf("\n ");
			}

			// ī�� ���� ����
			int_card_sum += int_card;
		}
		
		//ī�� ���
		for (int j = 0; j < 27; j++) {
			cout << card[j] << " ";
		}
		cout << endl;
	}

	// ��� ���
	for (int j = 0; j < 27; j++) {
		if (card[j] == 1) cout << j + 1 << endl;
	}
}


// �� ���ڷ�������? -> ����
void func_CHAC_D() {
	string str_time, str_m, str_s;
	int cnt = 0, int_m, int_s, int_total_s, int_total_s_copy;
	int int_10s = 0, int_1m = 0, int_10m = 0, int_30s = 0;

	cin >> str_time;
	vector<string> v;

	v = split(str_time, ':');

	str_m = v.at(0);
	str_s = v.at(1);

	int_m = (str_m[0] - '0') * 10 + (str_m[1] - '0');
	int_s = (str_s[0] - '0') * 10 + (str_s[1] - '0');

	int_total_s = int_m * 60 + int_s;
	int_total_s_copy = int_total_s;
	//cout << int_total_s << endl;

	int_10m = int_total_s_copy / 600;
	int_total_s_copy %= 600;

	int_1m = int_total_s_copy / 60;
	int_total_s_copy %= 60;

	int_30s = int_total_s_copy / 30;
	int_total_s_copy %= 30;

	int_10s = int_total_s_copy / 10;
	int_total_s_copy %= 10;

	if (int_30s == 0)
		cout << int_10m + int_1m + int_10s + 1 << endl;
	else
		cout << int_10m << int_1m << int_10s << int_30s << endl;
}