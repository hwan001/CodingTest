#include "header.h"

/*
*  �ܰ躰�� Ǯ��� �ּ�
*  https://www.acmicpc.net/step
*/

/*
*  *************************************
*  �ܰ躰�� Ǯ��� > ����°� ��Ģ����
*  *************************************
*/

/* Hello Word
* https://www.acmicpc.net/problem/2557
*/
void func_2557() {
	cout << "Hello World!";
}

/* We love kriii
* https://www.acmicpc.net/problem/10718
*/
void func_10718() {
	cout << "����ģ�� ��������";
	cout << "����ģ�� ��������";
}

/*
void func_10171(); // �����
void func_10172(); // ��
void func_1000(); // A+B
void func_1001(); // A-B
void func_10998(); // A*B
void func_1008(); // A/B
void func_10869(); // ��Ģ����
void func_10430(); // ������
void func_2588(); // ����
*/

/* ??! (����� 5)
*  https://www.acmicpc.net/problem/10926
*/
void func_10926() {
	string str;
	cin >> str;

	cout << str + "??!" << endl;
}

/* 1998����� ���� �±������� 2541��� ? ! (����� 5)
*  https://www.acmicpc.net/problem/18108
*/
void func_18108() {
	int a;
	cin >> a;

	cout << a - 543 << endl;
}





/* 
*  ************************
*  �ܰ躰�� Ǯ��� > if��
*  ************************
*/

/*
void func_1330(); // �� �� ���ϱ�
void func_9498(); // ���� ����
void func_2753(); // ����
void func_14681(); // ��и� ����
void func_2884(); // �˶� �ð�
*/





/*
*  *************************
*  �ܰ躰�� Ǯ��� > for��
*  *************************
*/

/*
void func_2739(); // ������
void func_10950(); // A+B - 3
void func_8393(); // ��
void func_15552(); // ���� A+B
void func_2741(); // N ���
void func_2742(); // ���� N
void func_11021(); // A+B - 7
void func_11022(); // A+B - 8
void func_2438(); // �� ��� - 1
void func_2439(); // �� ��� - 2
void func_10871(); // X���� ���� ��
*/





/*
*  ***************************
*  �ܰ躰�� Ǯ��� > while��
*  ***************************
*/

/*
void func_10952(); // A+B - 5
void func_10951(); // A+B - 4
void func_1110(); // ���ϱ� ����Ŭ
*/





/*
*  ****************************
*  �ܰ躰 Ǯ��� > 1���� �迭
*  ****************************
*/

/*
void func_10818(); // �ּ�, �ִ�
void func_2562(); // �ִ�
void func_2577(); // ������ ����
void func_3052(); // ������
void func_1546(); // ���
void func_8958(); // OX����
void func_4344(); // ����� �Ѱ���
*/





/*
*  ****************************
*  �ܰ躰�� Ǯ��� > �Լ�
*  ****************************
*/

/* ���� N���� ��
* https://www.acmicpc.net/problem/15596
*/
void func_15596() {

}

/* ���� �ѹ�
* https://www.acmicpc.net/problem/4673
*/
void func_4673() {

}

/* �Ѽ�
* https://www.acmicpc.net/problem/1065
*/
void func_1065() {

}





/*
*  ************************
*  �ܰ躰 Ǯ��� > ���ڿ�
*  ************************
*/

/* �ܾ� ����
*  https://www.acmicpc.net/problem/1157
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


/* ���ڿ� �ݺ�
*  https://www.acmicpc.net/problem/2675
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


/* �ܾ��� ����
*  https://www.acmicpc.net/problem/1152
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


/* ���
*  https://www.acmicpc.net/problem/2908
*/
void func_2908() {
	string a, b;
	string a_r, b_r;
	int res;
	int cnt = 0;

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

	cout << res;
}


/* ���̾�
*  https://www.acmicpc.net/problem/5622
*/
void func_5622() {
	string str;
	cin >> str;
	map<char, int> m;
	int point, sum = 0;

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


/* ũ�ξ�Ƽ�� ���ĺ�
*  https://www.acmicpc.net/problem/2941
*/
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


/* �׷� �ܾ� üĿ
*  https://www.acmicpc.net/problem/1316
*/
void func_1316() {
	int a;
	cin >> a;

	string* arr_str = new string[a];
	map<char, int> m;
	int cnt = 0;

	for (int i = 0; i < a; i++) {
		cin >> arr_str[i];
	}

	char pre_ch;
	bool is_flag;

	for (int i = 0; i < a; i++) {
		pre_ch = '0';
		is_flag = true;
		for (char ch = 'a'; ch <= 'z'; ch++) {
			m[ch] = 0;
		}

		for (int j = 0; j < arr_str[i].length(); j++) {
			if (m[arr_str[i][j]] != 0) {
				if (pre_ch != arr_str[i][j]) {
					is_flag = false;
					break;
				}
			}

			m[arr_str[i][j]]++;
			pre_ch = arr_str[i][j];
		}

		if (is_flag) {
			cnt++;
		}
	}

	cout << cnt;
}





/*
*  *****************************
*  �ܰ躰 Ǯ��� > �⺻ ���� 1
*  *****************************
*/

/* ���ͺб���
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


/* ����
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


/* �м�ã��
* https://www.acmicpc.net/problem/1193
*/
unsigned long long func_1193_sum_of_arithmetic_sequences(int n) {
	return (n * (n + 1)) / 2;
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


/* �����̴� �ö󰡰� �ʹ�
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


/* ACM ȣ��
* https://www.acmicpc.net/problem/2869
*/
void func_10250() {
	int a, h, w, n;
	int f, no;

	cin >> a;

	for (int i = 0; i < a; i++) {
		f = 1;
		no = 1;
		cin >> h >> w >> n;

		f += (n % h) - 1;
		if (n % h == 0) {
			f = h;
			no = n / h;
		}
		else {
			no += (n / h);
		}

		printf("%d%02d\n", f, no);
	}
}


/* �γ�ȸ���� ���׾�
* https://www.acmicpc.net/problem/2775
*/
int func_2775_sum_people(int k, int n) {
	if (k == 0) return n;
	if (n == 1) return 1;
	return func_2775_sum_people(k, n - 1) + func_2775_sum_people(k - 1, n);
}

void func_2775() {
	int int_k, int_n, int_t;
	int int_sum = 0;

	cin >> int_t;

	for (int i = 0; i < int_t; i++) {
		cin >> int_k;
		cin >> int_n;

		cout << func_2775_sum_people(int_k, int_n) << endl;
	}
}


/* �������
* https://www.acmicpc.net/problem/2839
*/
void func_2839() {
	int a, b, n, min, tmp, res;
	bool is_flag;

	cin >> n;

	min = n;
	res = -1;
	is_flag = false;

	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			tmp = (3 * a) + (5 * b);

			if (tmp > n) break;
			if (tmp == n) {
				if (min >= a + b) {
					min = a + b;
					is_flag = true;
				}
			}
		}
	}

	if (is_flag) res = min;

	cout << res << endl;
}


/* ū �� A+B
* https://www.acmicpc.net/problem/10757
*/

vector<int> func_10757_reverseVector(string num) {
	vector<int> v;

	for (int i = num.length() - 1; i >= 0; i--) {
		v.push_back((num[i] - '0'));
	}

	return v;
}

void func_10757() {
	string str_a, str_b;
	cin >> str_a >> str_b;

	vector<int> a, b, c;
	int int_a, int_b, int_tmp = 0, int_len;

	a = func_10757_reverseVector(str_a);
	b = func_10757_reverseVector(str_b);

	if (a.size() >= b.size()) {
		int_len = a.size();
	}
	else {
		int_len = b.size();
	}


	for (int i = 0; i < int_len; i++) {
		try {
			int_a = a.at(i);
		}
		catch (exception e) {
			int_a = 0;
		}

		try {
			int_b = b.at(i);
		}
		catch (exception e) {
			int_b = 0;
		}

		c.push_back((int_a + int_b + int_tmp) % 10);

		if ((int_a + int_b + int_tmp) >= 10) {
			int_tmp = 1;
		}
		else {
			int_tmp = 0;
		}
	}

	if (int_tmp) {
		c.push_back(1);
	}

	for (int i = c.size() - 1; i >= 0; i--) {
		cout << c.at(i);
	}
}


/* Fly me to the Alpha Centauri
* https://www.acmicpc.net/problem/1011
*/
void func_1011() {
	int int_case;
	ll x, y, res, distance, level;

	cin >> int_case;

	for (int i = 0; i < int_case; i++) {
		cin >> x >> y;
		distance = y - x;

		if (distance > 0 && distance <= 3) {
			res = distance;
		}
		else {
			level = (int)sqrt(distance);

			if (((level + 1) * (level + 1)) - (level + 1) < distance && distance < ((level + 1) * (level + 1))) {
				res = 2 * level + 1;
			}
			else if (distance == level * level) {
				res = 2 * level - 1;
			}
			else {
				res = 2 * level;
			}
		}

		cout << res << "\n";
	}
}





/*
*  *****************************
*  �ܰ躰 Ǯ��� > �⺻ ���� 2
*  *****************************
*/

/* �Ҽ� ã��
* https://www.acmicpc.net/problem/1978
*/
void func_1978() {
	int a, cnt = 0;
	cin >> a;

	int* arr = new int[a];

	for (int i = 0; i < a; i++) {
		cin >> arr[i];
		if (is_prime_number_custom(arr[i])) {
			cnt++;
		}
	}

	cout << cnt;
}


/* �Ҽ�
* https://www.acmicpc.net/problem/2581
*/
void func_2581() {
	int a, b, min, sum = 0;
	cin >> a >> b;

	for (int i = a; i <= b; i++) {
		if (is_prime_number_custom(i)) {
			if (sum == 0) min = i;
			sum += i;
		}
	}

	if (sum == 0) cout << -1 << endl;
	else {
		cout << sum << endl;
		cout << min;
	}
}


/* ���μ�����
* https://www.acmicpc.net/problem/11653
*/
void func_11653_Factorization(int a) {
	bool is_flag = true;

	for (int i = 2; i < a; i++) {
		if (a % i == 0) {
			is_flag = false;
			cout << i << endl;
			func_11653_Factorization(a / i);
			break;
		}
	}

	if (is_flag) cout << a << endl;
}

void func_11653() {
	int a;
	cin >> a;

	if (a != 1) {
		func_11653_Factorization(a);
		/*
		if (is_prime_number_custom(a)) {
			cout << a;
		}
		else {
			func_11653_Factorization(a);
		}
		*/
	}
}


/* �Ҽ� ���ϱ�
* https://www.acmicpc.net/problem/1929
*/
void func_1929() {
	int int_M, int_N;
	cin >> int_M >> int_N;

	for (int i = int_M; i <= int_N; i++)
	{
		if (is_prime_number_custom(i)) {
			cout << i << endl;
		}
	}
}


/* ����Ʈ�� ����
* https://www.acmicpc.net/problem/4948
*/
void func_4948() {
	int int_N, cnt;
	bool* arr = Sieve_of_Eratosthenes(123456 * 2);

	do {
		cin >> int_N;
		cnt = 0;


		for (int i = int_N + 1; i <= int_N * 2; i++) {
			if (arr[i]) {
				cnt++;
			}
		}

		if (int_N != 0) cout << cnt << endl;
	} while (int_N != 0);

}


/* �������� ����
* https://www.acmicpc.net/problem/9020
*/
void func_9020() {
	int int_a, int_N, int_sum;
	bool* arr = Sieve_of_Eratosthenes(20000);
	int tmp_a, tmp_b, tmp_min;
	vector<int> v;

	cin >> int_a;
	for (int i = 0; i < int_a; i++) {
		cin >> int_N;

		// �ʱ�ȭ
		int_sum = 0;
		v.clear();

		// �ش� ������ ���� �Ҽ� ������
		for (int j = 2; j < int_N; j++) {
			if (arr[j]) {
				v.push_back(j);
			}
		}

		tmp_a = 0;
		tmp_b = 0;
		tmp_min = int_N;

		for (int j = 0; j < v.size(); j++) {
			for (int k = 0; k < v.size(); k++) {
				if (int_N == v.at(j) + v.at(k) && tmp_min > abs(v.at(j) - v.at(k))) {
					tmp_a = v.at(j);
					tmp_b = v.at(k);
					tmp_min = abs(v.at(j) - v.at(k));
				}
			}
		}

		if (tmp_a + tmp_b != 0) cout << tmp_a << " " << tmp_b << endl;
	}
}


/* ���簢������ Ż��
* https://www.acmicpc.net/problem/1085
*/
void func_1085() {
	int x, y, w, h, min;

	cin >> x;
	min = x;

	cin >> y;
	if (min > y) min = y;

	cin >> w;
	if (min > w - x) min = w - x;

	cin >> h;
	if (min > h - y) min = h - y;

	cout << min;
}


/* �� ��° ��
* https://www.acmicpc.net/problem/3009
*/
void func_3009() {
	int a, b;
	map<int, int> x, y;
	map<int, int>::iterator iter;

	for (int i = 0; i < 3; i++) {
		cin >> a >> b;

		if (x.count(a)) x[a]++;
		else x[a] = 1;

		if (y.count(b)) y[b]++;
		else y[b] = 1;
	}

	for (iter = x.begin(); iter != x.end(); iter++) {
		if (iter->second == 1) {
			cout << iter->first << " ";
		}
	}

	for (iter = y.begin(); iter != y.end(); iter++) {
		if (iter->second == 1) {
			cout << iter->first;
		}
	}
}


/* �����ﰢ��
* https://www.acmicpc.net/problem/4153
*/
void func_4153() {
	// ���̵�� : ��Ÿ��� ���� Ȱ��
	int a, b, c;
	int pow_a, pow_b, pow_c, pow_sum;

	while (1) {
		cin >> a >> b >> c;

		pow_a = pow(a, 2);
		pow_b = pow(b, 2);
		pow_c = pow(c, 2);
		pow_sum = pow_a + pow_b + pow_c;

		if (pow_sum == 0)
			break;

		if (pow_a == pow_sum - pow_a || pow_b == pow_sum - pow_b || pow_c == pow_sum - pow_c) {
			cout << "right" << endl;
		}
		else {
			cout << "wrong" << endl;
		}
	}
}


/* �ý� ������
* https://www.acmicpc.net/problem/3053
*/
void func_3053() {
	// cmath ���� pi : M_PI (cmath include �� #define _USE_MATH_DEFINES �ʿ�)
	int r;
	cin >> r;

	// ��Ŭ���� �����п����� ����
	printf("%.6f\n", const_pi() * pow(r, 2));

	// �ý� ������ ������ ���� : �밢�� ���̰� r�� �������� ����
	printf("%.6f\n", pow(2 * r, 2) / 2);

}


/* �ͷ�
* https://www.acmicpc.net/problem/1002
*/
void func_1002() {
	int a;
	cin >> a;

	int x1, y1, r1, x2, y2, r2;
	double len;

	for (int i = 0; i < a; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		// �� �� ������ �Ÿ�
		len = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

		// �ݰ��� �Ϻ��ϰ� ��ġ�� ���Ѵ��� ���
		if (len == 0 && r1 - r2 == 0) {
			cout << -1 << endl;
			continue;
		}

		// �������� ������ �ݰ��� �޶� ���� �� ����
		if (len == 0 && r1 - r2 != 0) {
			cout << 0 << endl;
			continue;
		}

		// �ﰢ���� �����Ǹ� 2��, ��ġ�ϸ� 1��, �ȵǸ� 0��
		// ���� ������ �̿��ؼ� Ǭ ��찡 ��κ�, �ﰢ�� �������� Ǭ ���� ��ã��
		if (len < r1 + r2 && r1 < r2 + len && r2 < len + r1) {
			cout << 2 << endl;
		}
		else if (len == r1 + r2 || r1 == len + r2 || r2 == len + r1) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
}





/*
*  **********************
*  �ܰ躰 Ǯ��� > ���
*  **********************
*/

/* ���丮�� (����� 3, ����)
* https://www.acmicpc.net/problem/10872
*/
int func_10872_factorial(int n) {
	if (n == 0) return 1;
	else return n * func_10872_factorial(n - 1);
}

void func_10872() {
	int a;
	cin >> a;

	cout << func_10872_factorial(a);
}


/* �Ǻ���ġ �� 5 (����� 2, ����/DP)
* https://www.acmicpc.net/problem/10870
*/
int func_10870_fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return func_10870_fibonacci(n - 1) + func_10870_fibonacci(n - 2);
}

void func_10870() {
	int a;
	cin >> a;

	cout << func_10870_fibonacci(a);
}


/* �� ��� -10 (�ǹ� 1, ��������)
* https://www.acmicpc.net/problem/2447
*/
void func_2447_starPrint(int n, int a, int b) {
	int n_copy = n;
	int int_squared = 0;

	if (n == 1) return;

	for (int i = 0; i < 8; i++) {
		if (n_copy == 1) {
			int_squared = i - 1;
			break;
		}
		n_copy /= 3;
	}

	int remove_a = pow(3, int_squared);
	int remove_b = (pow(3, int_squared) * 2) - 1;

	func_2447_starPrint(n / 3, remove_a, remove_b);

	for (int i = a; i < b; i++) {
		for (int j = a; j < b; j++) {
			// ��� ����
			if ((i >= remove_a && i <= remove_b) && (j >= remove_a && j <= remove_b))
			{
				cout << " ";
			}
			else
				cout << "*";
		}
		cout << "\n";
	}
}

void func_2447() {
	int a;
	cin >> a;
	func_2447_starPrint(a, 0, a);
}


/* �ϳ��� ž �̵� ����
* https://www.acmicpc.net/problem/11729
*/
void func_11729() {

}




/*
*  ****************************
*  �ܰ躰 Ǯ��� > ���Ʈ����
*  ****************************
*/

/* ���� (����� 2)
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


/* ������ (����� 2)
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

		if (!m[key])
			m[key] = i;
	}

	cout << m[a];
}


/* ��ġ (�ǹ� 5)
* https://www.acmicpc.net/problem/7568
*/
void func_7568() {
	int int_case;
	int cnt, grade;
	int* bulk;

	cin >> int_case;

	map<char, int*> m_input;

	// �Է�
	for (int i = 0; i < int_case; i++) {
		bulk = new int[2];

		cin >> bulk[0] >> bulk[1];

		m_input['a' + i] = bulk;
	}

	// ���� �ű��
	for (int i = 0; i < int_case; i++) {
		cnt = 1;

		for (int j = 0; j < int_case; j++) {
			// ��ġ : Ű�� ũ��, �����Ե� ���ſ� ��� ��
			if (m_input['a' + i][0] < m_input['a' + j][0] && m_input['a' + i][1] < m_input['a' + j][1]) {
				cnt++;
			}
		}

		// ���� ���
		cout << cnt << " ";
	}

	for (int i = 0; i < int_case; i++) {
		delete m_input['a' + i];
	}
}
void func_7568_2() {
	int int_case, cnt;
	cin >> int_case;
	int** arr = new int* [int_case];
	int* bulk;

	for (int i = 0; i < int_case; i++) {
		bulk = new int[2];
		cin >> bulk[0] >> bulk[1];
		arr[i] = bulk;
	}

	for (int i = 0; i < int_case; i++) {
		cnt = 1;
		for (int j = 0; j < int_case; j++) {
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) {
				cnt++;
			}
		}
		cout << cnt << " ";
	}
}

/* ü���� �ٽ� ĥ�ϱ� (�ǹ� 5)
* https://www.acmicpc.net/problem/1018
*/
void func_1018() {

}

/* ��ȭ���� �� (�ǹ� )
* https://www.acmicpc.net/problem/1436
*/
void func_1436() {

}



/*
*  **********************
*  �ܰ躰 Ǯ��� > ����
*  **********************
*/

/* �� �����ϱ�
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

/* �� �����ϱ� 2
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

/* �� �����ϱ� 3
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

/* �����
* https://www.acmicpc.net/problem/2108
*/
void func_2108() {
	int a, sum = 0;
	double tmp;
	double aver, max;
	int min_val, max_val;

	cin >> a;
	map<int, int> m;
	map<int, int>::iterator iter;
	vector<int> v;

	// �� �޾Ƽ� Ű�� �ְ� sum ����
	for (int i = 0; i < a; i++) {
		cin >> tmp;

		if (m[tmp] == 0) {
			m[tmp] = 1;
		}
		else {
			m[tmp]++;
		}

		sum += tmp;
	}

	for (auto num : m) {
		v.push_back(num.first);
	}

	// 1. ������, �Ҽ��� ���� ù° �ڸ� �ݿø� �� 
	aver = (double)sum / a;
	printf("%.0f\n", aver);
	//cout <<sum << ", " << a << ", " << aver << "\n";

	// 2. �߾Ӱ� 
	int cnt = 0;
	int index = floor(a / 2);

	if (a % 2 == 0)
		cout << (v.at(index) + v.at(index + 1)) / 2 << "\n";
	else
		cout << v.at(index) << "\n";

	// 3. �ֺ� , �������� ��� 2��°�� ���� ��
	// Ű�� ���� ���� �� find �Ͽ� ���°� �������� count ����
	max = -4000;

	for (auto num : m) {
		if (num.second > max) {
			max = num.second;
		}
	}

	cnt = 0;
	for (auto num : m) {
		if (num.second == max) {
			cnt++;
		}
		if (cnt == 1) {
			tmp = num.first;
		}
		if (cnt == 2) {
			cout << num.first << "\n";
			break;
		}
	}
	if (cnt == 1) {
		cout << tmp << "\n";
	}

	// 4. ���� -> ���� ���� �� ~ ���� ū ��
	min_val = v.at(0);
	max_val = v.at(v.size() - 1);
	cout << max_val - min_val << "\n";
}

/* ��Ʈ�λ��̵�
* https://www.acmicpc.net/problem/1427
*/
void func_1427() {

}

/* ��ǥ �����ϱ�
* https://www.acmicpc.net/problem/11650
*/
void func_11650() {

}

/* ��ǥ �����ϱ� 2
* https://www.acmicpc.net/problem/11651
*/
void func_11651() {

}

/* �ܾ� ����
* https://www.acmicpc.net/problem/1181
*/
void func_1181() {

}

/* ���̼� ����
* https://www.acmicpc.net/problem/10814
*/
void func_10814() {

}

/* ��ǥ ����
* https://www.acmicpc.net/problem/18870
*/
void func_18870() {

}




/*
*  ***************************
*  �ܰ躰 Ǯ��� > DFS�� BFS
*  ***************************
*/

/*  DFS�� BFS
*   https://www.acmicpc.net/problem/1260
*/
void func_1260_graphPrint(map<int, vector<int>> graph) {
	for (auto node : graph) {
		cout << node.first << " : ";
		for (auto nd : node.second) {
			cout << nd << " ";
		}
		cout << "\n";
	}
}

void func_1260_dfs_recursion(int n, vector<int>* graph, bool* visited) {
	visited[n] = true;
	cout << n << " ";

	for (auto node : graph[n]) {
		if (!visited[node]) {
			func_1260_dfs_recursion(node, graph, visited);
		}
	}
}

void func_1260_dfs_stack() {

}

void func_1260_bfs_queue(int n, vector<int>* graph, bool* visited) {
	queue<int> q;
	int now_node;

	visited[n] = true;
	q.push(n);

	while (!q.empty()) {
		now_node = q.front();
		q.pop();
		cout << now_node << " ";

		for (auto node : graph[now_node]) {
			if (!visited[node]) {
				visited[node] = true;
				q.push(node);
			}
		}
	}
}

void func_1260_bfs_queue_matrix(int n, int** graph, bool* visited) {
	queue<int> q;
	int now_node;

	visited[n] = true;
	q.push(n);

	while (!q.empty()) {
		now_node = q.front();
		q.pop();
		cout << now_node << " ";

		for(int i=0; i < sizeof(graph[n]); i++) {
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

void func_1260() {
	int n, m, start_node, u, v;
	
	cin >> n >> m >> start_node;

	// map<int, vector<int>> graph;
	
	vector<int> *graph = new vector<int>[n+1];

	bool *visited = new bool[n+1];
	memset(visited, 0, sizeof(bool) * (n+1));

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	func_1260_dfs_recursion(start_node, graph, visited);
	cout << "\n";

	memset(visited, 0, sizeof(bool) * (n + 1));
	func_1260_bfs_queue(start_node, graph, visited);
}

void func_1260_matrix() {
	int n, m, start_node, u, v;

	cin >> n >> m >> start_node;

	// ������� ����
	int** graph = new int* [n];
	for (int i = 0; i < n; i++) {
		graph[i] = new int[n];
	}

	bool* visited = new bool[n + 1];
	memset(visited, 0, sizeof(bool) * (n + 1));

	// ������� �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = 0;
		}
	}

	// ���� �Է�
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		u--;
		v--;
		// ������ �׷���
		graph[u][v] = graph[v][u] = 1;
	}


	// ������� ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}

	func_1260_bfs_queue_matrix(start_node, graph, visited);
}


/*  ���̷���
*   https://www.acmicpc.net/problem/2606
*/

static int func_2606_cnt;

void func_2606_dfs(int start, vector<int> *graph, bool* visited) {
	visited[start] = true;
	//cout << start << " ";

	func_2606_cnt++;

	for (auto node : graph[start]) {
		if (!visited[node]) {
			func_2606_dfs(node, graph, visited);
		}
	}
}

void func_2606() {
	int n, m, u, v;

	cin >> n;
	cin >> m;

	vector<int> *graph = new vector<int>[n+1];

	// ��� ���� +1��
	bool* visited = new bool[n+1];
	memset(visited, 0, sizeof(bool) * (n+1));

	func_2606_cnt = 0;

	// ���� �Է�
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	func_2606_dfs(1, graph, visited);

	cout << func_2606_cnt -1 << "\n";
}


/*  ������ȣ���̱�
*   https://www.acmicpc.net/problem/2667
*/
void func_2667_HouseComplex_Detection(int n, int** map) {
	bool is_comp = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j]) {
				is_comp = true;
			}

			if (is_comp) {
			}
		}
	}
}

vector<int> *func_2667_Convert_adjMatrix_to_adjList(int n, int** matrix) {
	vector<int> * adjlist = new vector<int>[n+1];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == 1 && i != j) {
				adjlist[i+1].push_back(j + 1);
			}
		}

		sort(adjlist[i+1].begin(), adjlist[i+1].end());
	}

	return adjlist;
}

void func_2667() {
	int n;
	string str;

	cin >> n;

	int** map = new int* [n];
	for (int i = 0; i < n; i++) {
		str = "";
		map[i] = new int[n];

		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			map[i][j] = str[j] - '0';
		}
	}

	
	func_2667_HouseComplex_Detection(n, map);


}



/*  �̷�Ž��
*   https://www.acmicpc.net/problem/2178
*/

class func_2178_node {
public:
	int x;
	int y;
	int value;
	int visited;
};

int func_2178_BFS(int n, int m, func_2178_node **_map, int *start_node, int *end_node) {
	// BFS Ž���� ���� ť ���� ���� ��� ����
	queue<func_2178_node> q;
	func_2178_node tmp_node, now_node;

	// ��0, ��1, ��2, ��3 
	int** direction = new int*[4];
	for (int i = 0; i < 4; i++) {
		direction[i] = new int[2];

		if (i == 0) {
			direction[i][0] = 0;
			direction[i][1] = -1;
		}
		if (i == 1) {
			direction[i][0] = 1;
			direction[i][1] = 0;
		}
		if (i == 2) {
			direction[i][0] = 0;
			direction[i][1] = 1;
		}
		if (i == 3) {
			direction[i][0] = -1;
			direction[i][1] = 0;
		}

		//cout << i << " - " << direction[i][0] << ", " << direction[i][1] << "\n";
	}


	// ���۳���� �湮 ���� ����
	_map[start_node[0]][start_node[1]].visited = 1;
	// ���۳�� �ֱ�
	q.push(_map[start_node[0]][start_node[1]]);


	// ť�� ���� ������ Ž�� ����
	while (!q.empty()) {
		// ���� ť�� �� �������� + pop
		now_node = q.front();
		q.pop();

		// ���� ��� Ž�� (�ð�������� Ž��)
		for (int i = 0; i < 4; i++) {
			// ���� ��ǥ�� �¿츦 �Ѿ���� Ȯ�� (�Ѿ�� continue)
			if (now_node.x + direction[i][0] <= 0 || now_node.x + direction[i][0] > n) {
				continue;
			}

			// ���� ��ǥ�� ���ϸ� �Ѿ���� Ȯ�� (�Ѿ�� continue)
			if (now_node.y + direction[i][1] <= 0 || now_node.y + direction[i][1] > m) {
				continue;
			}

			// �̵��� ���� �� �ȿ� ������ ��� �̵�
			tmp_node = _map[now_node.x + direction[i][0]][now_node.y + direction[i][1]];

			// ���� 1�� �ƴ��� �˻�, �ƴϸ� continue;
			if (tmp_node.value == 0) {
				continue;
			}

			// ���� 1�̰�, �湮 ���ΰ� ������ �˻� (�湮������ ������)
			if (tmp_node.visited) {
				continue;
			}

			// ���� ��尡 �� �ȿ� �ְ�, �̵��� �����ϸ�, �湮�� ���� ���ٸ� ť�� ����ϰ� �湮���� �ٲٰ� Ž��Ƚ�� ����
			_map[tmp_node.x][tmp_node.y].visited = _map[now_node.x][now_node.y].visited + 1;
			q.push(_map[tmp_node.x][tmp_node.y]);

			//cout << "tmp_node[" << tmp_node.x << "][" << tmp_node.y << "] "<< _map[tmp_node.x][tmp_node.y].visited << " -> Ž�� �Ϸ� \n";
		}

		// �湮 ���� ���
		/*
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << _map[i][j].visited << "";
			}
			cout << "\n";
		}
		cout << "\n";
		*/
	}

	return _map[n][m].visited;
}

void func_2178() {
	int n, m;
	int* start_node = new int[2];
	int* end_node = new int[2];
	string str_input;

	cin >> n >> m;

	start_node[0] = 1;
	start_node[1] = 1;
	end_node[0] = n;
	end_node[1] = m;

	// ��� �� �ʱ�ȭ
	func_2178_node** map = new func_2178_node*[n+1];
	for (int i = 1; i <= n; i++) {
		map[i] = new func_2178_node[m+1];
	}

	// �Է� �� �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		cin >> str_input;
		for (int j = 1; j <= m; j++) {
			map[i][j].x = i;
			map[i][j].y = j;
			map[i][j].value = str_input[j-1] - '0';
			map[i][j].visited = 0;
		}
	}

	cout << func_2178_BFS(n, m, map, start_node, end_node) << "\n";

}




/*  ����� ����
*   https://www.acmicpc.net/problem/1012
*/
class func_1012_node {
public:
	int x;
	int y;
	int value;
	int visited;
};


void func_1012_bfs(int n, func_1012_node **map, bool* visited) {
	queue<func_1012_node> q;
	
	
	
}

void func_1012() {
	int test_case;
	int n, m, k;
	int u, v;
	int cnt;
	bool* visited;
	func_1012_node** map;

	cin >> test_case;
	
	for (int a = 0; a < test_case; a++) {
		cin >> m >> n >> k;

		// �� �ʱ�ȭ
		map = new func_1012_node *[n];
		cnt = 0;

		// Map ���� �� �ʱ�ȭ
		for (int i = 0; i < n; i++) {
			map[i] = new func_1012_node[m];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j].x = i;
				map[i][j].y = j;
				map[i][j].value = 0;
				map[i][j].visited = 0;
			}
		}

		// Map ������Ʈ
		for (int j = 0; j < k; j++) {
			cin >> u >> v;
			map[u][v].value = 1;
		}

		// �湮 ��� Ȯ���ϸ鼭 Map Ž��

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				/*
				if (!map[i][j].visited) {
					func_1012_bfs(1, map, visited);
					cnt++;
				}
				*/
				cout << map[i][j].value << "";
			}
			cout << "\n";
		}

		cout << cnt << "\n";
		
		// map ����
		for (int j = 0; j <= n; j++) {
			delete map[j];
		}
		delete map;
	}
}


/*  �丶��
*   https://www.acmicpc.net/problem/7576
*/
class func_7576_tomato {
public:
	int x;
	int y;
	int visited;
	int value;
	bool is_count;
};

bool func_7576_count_Box(int n, int m, func_7576_tomato** box) {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j].is_count) {
				sum++;
			}
		}
	}
	if (sum == n * m) {
		return true;
	}
	else {
		return false;
	}
}

int func_7576_bfs(int n, int m, func_7576_tomato** box, vector<int*> start) {
	queue<func_7576_tomato> q;

}

void func_7576() {
	int m, n, tmp;
	vector<int*> start;

	// ��� ����
	cin >> m >> n;

	// ��� ����
	func_7576_tomato** box = new func_7576_tomato*[n];
	for (int i = 0; i < n; i++) {
		box[i] = new func_7576_tomato[m];
	}

	// �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			box[i][j].x = i;
			box[i][j].y = j;
			box[i][j].visited = 0;
			box[i][j].value = 0;
			box[i][j].is_count = false;
		}
	}

	// �Է°� �ޱ� + �Է¿� ���� �� ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp = box[i][j].value;
			cin >> tmp;

			if (tmp != 0){
				// 0�� �ƴϸ� ī��Ʈ�� ����(0�̸� ���� ����)
				box[i][j].is_count = true;
			}
			if (tmp == 1) {
				//�Է� ���� 1�̸� ���� ��ǥ�� ��� �� ���� ���ؼ� bfs

			}
		}
	}

	
	// BFS�� visit�� ������� ���ϴ��� ī��Ʈ + ���ϸ� count = true;
	func_7576_bfs(n, m, box, start);

	// ī��Ʈ�� ������ ���� ���� ��ü ���� ���� ������
	if (!func_7576_count_Box(n, m, box)) {
		cout << -1 << "\n";
	}


}