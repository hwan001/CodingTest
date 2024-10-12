#include "header.h"

/* �л�ó�� (����� 3)
* https://www.acmicpc.net/problem/1009
*/
int func_1009_mod(int a, int b) {
    vector<int> tmp, tmp2;
    int* x;
    ll res = 1;

    while (b != 0) {
        tmp.push_back(b % 2);
        b /= 2;
    }

    x = new int[21];
    x[0] = a % 10;
    for (int j = 1; j <= 20; j++) {
        x[j] = (x[j - 1] * x[j - 1]) % 10;
    }

    for (int i = 0; i < tmp.size(); i++) {
        if (tmp.at(i) == 1) {
            res *= x[i];
        }
    }

    if (res % 10 == 0) res = 10;
    else res %= 10;

    return res;
}

void func_1009() {
    int n, a, b;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << func_1009_mod(a, b);
    }
}


/* ������ (����� 5)
* https://www.acmicpc.net/problem/2475
*/
void func_2475() {
    vector<int> input;
    input.clear();
    int a;

    for (int i = 0; i < 5; i++) {
        cin >> a;
        input.push_back(a * a);
    }

    cout << accumulate(input.begin(), input.end(), 0) % 10;
}


/* ���� (����� 2)
* https://www.acmicpc.net/problem/2920
*/
void func_2920() {
    vector<int> input;
    int a;

    for (int i = 0; i < 8; i++) {
        cin >> a;
        input.push_back(a);
    }

    vector<int> cp_sort(input);
    sort(cp_sort.begin(), cp_sort.end());

    vector<int> cp_reverse(cp_sort);
    reverse(cp_reverse.begin(), cp_reverse.end());

    if(input == cp_sort)
        cout << "ascending\n";
    else if (input == cp_reverse)
        cout << "descending\n";
    else
        cout << "mixed\n";

}


/* �Ӹ���Ҽ� (����� 1)
* https://www.acmicpc.net/problem/1259
*/
void func_1259() {
    string a;
    int len, tmp_left, tmp_right;
    bool flag;

    while (1) {
        cin >> a;

        flag = false;

        if (stoi(a) == 0)
            break;

        len = a.length();
        tmp_right = ceil(len / 2);
        if (len % 2 == 0) {
            tmp_left = tmp_right - 1;
        }
        else {
            tmp_left = tmp_right;
        }

        for (int i = 0; i < len; i++) {
            if (tmp_left < 0) break;

            if (tmp_right >= len) break;

            if (a[tmp_left] != a[tmp_right]) {
                flag = false;
                break;
            }

            if (a[tmp_left] == a[tmp_right]) {
                flag = true;
            }

            tmp_left--;
            tmp_right++;
        }

        if (flag) cout << "yes\n";
        else cout << "no\n";
    }
}


/* ���� ��� (����� 1)
* https://www.acmicpc.net/problem/11050
*/
int func_11050_factorial(int n) {
    if (n <= 1) return 1;
    return n * func_11050_factorial(n-1);
}

void func_11050() {
    int n, k;
    cin >> n >> k;

    cout << func_11050_factorial(n) / (func_11050_factorial(n-k) * func_11050_factorial(k));
}


/* Hashing (����� 2)
* https://www.acmicpc.net/problem/15829
*/
void func_15829_50() {
    int str_len;
    cin >> str_len;
    string str;
    cin >> str;

    int a, r = 31, M = 1234567891;
    ll sum = 0;

    for (int i = 0; i < str_len; i++) {
        a = (str[i] - 'a') + 1;
        sum += a * pow(r, i);
    }

    cout << sum % M << "\n";
}

void func_15829() {
    int str_len;
    cin >> str_len;

    string str;
    cin >> str;

    ll r, sum = 0, a;
    int M = 1234567891;

    for (int i = 0; i < str_len; i++) {
        a = (str[i] - 'a') + 1;

        r = 1;
        for (int j = 0; j < i; j++) {
            r *= 31;
            r %= M;
        }

        sum += a * r;
        sum %= M;
    }
    
    cout << sum;
}


/* ��� ������Ʈ (����� 1)
*  https://www.acmicpc.net/problem/1032
*/
void func_1032() {
    int test_case, cnt;
    string tmp, res = "";
    vector<string> v;

    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    tmp = v.at(0);
    for (int i = 0; i < tmp.length(); i++) {
        cnt = 0;

        for (int j = 0; j < test_case; j++) {
            if (v.at(j)[i] == tmp[i]) {
                cnt++;
            }
        }

        if (cnt == test_case) {
            res += tmp[i];
        }
        else {
            res += "?";
        }
    }

    cout << res << "\n";

}


