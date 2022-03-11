#include "header.h"

/* 분산처리 (브론즈 3)
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



/* 검증수 (브론즈 5, 클래스)
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

/* 음계 (브론즈 2, 클래스)
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