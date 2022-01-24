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

}


/* 단계별 풀어보기 >> 기본 수학 2 >> 골드바흐의 추측
* https://www.acmicpc.net/problem/9020
*/
void func_9020() {

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

}


/* 단계별 풀어보기 >> 기본 수학 2 >> 택시 기하학
* https://www.acmicpc.net/problem/3053
*/
void func_3053() {
    
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