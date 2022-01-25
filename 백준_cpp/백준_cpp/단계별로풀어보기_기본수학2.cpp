#include "header.h"


/* 단계별 풀어보기 >> 기본 수학 2 >> 소수 찾기
* https://www.acmicpc.net/problem/1978
*/
void func_1978() {
    int a, cnt=0;
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


/* 단계별 풀어보기 >> 기본 수학 2 >> 소수
* https://www.acmicpc.net/problem/2581
*/
void func_2581() {
    int a, b, min, sum = 0;
    cin >> a >> b;

    for (int i = a; i <= b; i++) {
        if (is_prime_number_custom(i)) {
            if (sum == 0) min = i;
            sum+=i;
        }
    }

    if (sum == 0) cout << -1 << endl;
    else {
        cout << sum << endl;
        cout << min;
    }
}


/* 단계별 풀어보기 >> 기본 수학 2 >> 소인수분해
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

    if(is_flag) cout << a << endl;
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


/* 단계별 풀어보기 >> 기본 수학 2 >> 소수 구하기
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


/* 단계별 풀어보기 >> 기본 수학 2 >> 베르트랑 공준
* https://www.acmicpc.net/problem/4948
*/
void func_4948() {
    int int_N, cnt;
    bool* arr = Sieve_of_Eratosthenes(123456 * 2);

    do {
        cin >> int_N;
        cnt = 0;
        
        
        for (int i = int_N + 1; i <= int_N*2; i++){
            if (arr[i]) {
                cnt++;
            }
        }

        if(int_N != 0) cout << cnt << endl;
    } while (int_N != 0);

}


/* 단계별 풀어보기 >> 기본 수학 2 >> 골드바흐의 추측
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
        
        // 초기화
        int_sum = 0;
        v.clear();

        // 해당 수보다 작은 소수 모으기
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


/* 단계별 풀어보기 >> 기본 수학 2 >> 직사각형에서 탈출
* https://www.acmicpc.net/problem/1085
*/
void func_1085() {
    int x, y, w, h, min;

    cin >> x;
    min = x;

    cin >> y;
    if (min > y) min = y;

    cin >> w;
    if (min > w-x) min = w-x;

    cin >> h;
    if (min > h - y) min = h - y;

    cout << min;
}


/* 단계별 풀어보기 >> 기본 수학 2 >> 네 번째 점
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
        else y[b]=1;
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


/* 단계별 풀어보기 >> 기본 수학 2 >> 직각삼각형
* https://www.acmicpc.net/problem/4153
*/
void func_4153() {
    // 아이디어 : 피타고라스 정리 활용
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


/* 단계별 풀어보기 >> 기본 수학 2 >> 택시 기하학
* https://www.acmicpc.net/problem/3053
*/
void func_3053() {
    // cmath 내부 pi : M_PI (cmath include 전 #define _USE_MATH_DEFINES 필요)
    int r;
    cin >> r;

    // 유클리드 기하학에서의 넓이
    printf("%.6f\n", const_pi() * pow(r, 2));

    // 택시 기하학 에서의 넓이 : 대각선 길이가 r인 마름모의 넓이
    printf("%.6f\n", pow(2 * r, 2) / 2);
    
}


/* 단계별 풀어보기 >> 기본 수학 2 >> 터렛
* https://www.acmicpc.net/problem/1002
*/
void func_1002() {
    int a;
    cin >> a;

    int x1, y1, r1, x2, y2, r2;
    double len;

    for (int i = 0; i < a; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        // 두 점 사이의 거리
        len = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

        // 반경이 완벽하게 겹치면 무한대의 경우
        if (len == 0 && r1 - r2 == 0) {
            cout << -1 << endl;
            continue;
        }

        // 시작점은 같은데 반경이 달라 만날 수 없음
        if (len == 0 && r1 - r2 != 0) {
            cout << 0 << endl;
            continue;
        }

        // 삼각형이 성립되면 2개, 일치하면 1개, 안되면 0개
        // 원의 교점을 이용해서 푼 경우가 대부분, 삼각형 성립으로 푼 경우는 못찾음
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