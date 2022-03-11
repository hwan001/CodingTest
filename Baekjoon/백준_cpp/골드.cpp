#include "header.h"

/* 책 페이지 (골드 1)
* https://www.acmicpc.net/problem/1019
*/
void func_1019_v1() {
    int n, a;
    string str_n;
    string str_page;
    map<char, int> m;
    cin >> a;
    cin >> n;

    str_n = to_string(n);

    for (int i = 0; i < 9; i++) m['0' + i] = 0;

    for (int page = a; page <= n; page++) {
        str_page = to_string(page);
        for (int j = 0; j < str_page.length(); j++) {
            m[str_page[j]]++;
        }
    }

    for (auto m_tmp : m) {
        cout << m_tmp.second << " ";
    }
}

void func_1019_sub(map<char, int> m, int n, vector<pair<int, int>> v) {
    string str_n, str_page;
    str_n = to_string(n);
    int a = (pow(10, str_n.length()) - 1);
    cout << n << " ~ " << a << "\n";


    // 미리 계산된거 더하기
    m['0'] += v[str_n.length() - 2].first;
    for (int i = 1; i <= 9; i++) {
        m['0' + i] += v[str_n.length() - 2].second;
    }

    // 해당 숫자부터 빼기
    for (int page = a; page > n; page--) {
        str_page = to_string(page);
        for (int j = 0; j < str_page.length(); j++) {
            m[str_page[j]]--;
        }
    }

    for (auto m_tmp : m) {
        cout << m_tmp.second << " ";
    }
}

void func_1019_sum(map<char, int> m, int n, vector<pair<int, int>> v) {
    string str_n, str_page;
    str_n = to_string(n);
    int a = (pow(10, str_n.length() - 1) - 1);
    cout << a << " ~ " << n << "\n";

    // 미리 계산된거 더하기
    m['0'] += v[str_n.length() - 2].first;
    for (int i = 1; i <= 9; i++) {
        m['0' + i] += v[str_n.length() - 2].second;
    }

    for (int page = a + 1; page <= n; page++) {
        str_page = to_string(page);
        for (int j = 0; j < str_page.length(); j++) {
            m[str_page[j]]++;
        }
    }

    for (auto m_tmp : m) {
        cout << m_tmp.second << " ";
    }
}

void func_1019_v2() {
    int n, tmp_first, tmp_second;
    string str_n;
    map<char, int> m;
    vector<pair<int, int>> v_dp;

    cin >> n;
    str_n = to_string(n);

    // 초기화
    for (int i = 0; i < 9; i++) m['0' + i] = 0;

    // 기준값
    v_dp.push_back({ 0, 1 });
    for (int i = 1; i < 9; i++) {
        tmp_first = 9 * v_dp[i - 1].second + v_dp[i - 1].first;
        tmp_second = tmp_first + v_dp[i - 1].second + pow(10, i) - v_dp[i - 1].first;

        v_dp.push_back({ tmp_first, tmp_second });
        cout << "pair (" << i << ") : " << tmp_first << ", " << tmp_second << "\n";
    }

    // 판단
    if (abs(n - (pow(10, str_n.length() - 1) - 1) <= abs(n - (pow(10, str_n.length()) - 1)))) {
        func_1019_sum(m, n, v_dp);
    }
    else {
        func_1019_sub(m, n, v_dp);
    }
}

void calc_1019(long long n, long long point, long long* count_1019) {
    while (n > 0) {
        count_1019[n % 10] += point;
        n /= 10;
    }
}

// 정답 코드 복붙
void func_1019_v3(int n) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long count_1019[10];
    //long long n;
    long long start = 1;
    long long end;
    long long point = 1;
    memset(count_1019, 0, sizeof(count_1019));
    //cin >> n;
    end = n;

    while (end >= start) {
        // 시작 값 늘리기 (0까지)
        while (start % 10 != 0 && start <= end) {
            calc_1019(start, point, count_1019);
            start++;
        }

        // start 증가 시키다가 end 보다 커지면 (남은 start, end가 1자리 수일때 발생)
        if (start > end) break;

        // 종료 값 줄이기 (9까지)
        while (end % 10 != 9 && start <= end) {
            calc_1019(end, point, count_1019);
            end--;
        }

        // 각 자리수 별 개수 계산
        long long rescalc = end / 10 - start / 10 + 1;
        for (int i = 0; i < 10; i++) {
            count_1019[i] += (point * rescalc);
        }

        // 다음 자리로 이동
        start /= 10;
        end /= 10;
        point *= 10LL;
    }

    // 출력
    for (int i = 0; i < 10; i++) {
        cout << count_1019[i] << " ";
    }
    cout << "\n";

}

void func_1019() {
    /*for (int i = 1; i < 10000; i *= 10){
        cout << i << " - ";
        func_1019_v3(i);
    }*/

    long long n, start, end, digit;
    string str_tmp;
    long long cnt_num[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    cin >> n;

    start = 1;
    end = n;
    digit = 1;

    while (end >= start) {
        //start 는 끝 자리가 0일때 까지 +하고, 0일때 start 값~ 끝자리 0인 값 -1까지 0~9를 증가 시켜줌
        while (start % 10 != 0 && start <= end) {
            str_tmp = to_string(start);
            for (int i = 0; i < str_tmp.length(); i++) {
                cnt_num[str_tmp[i] - '0'] += digit;
            }

            start++;
        }

        if (start > end) break;

        //end 는 끝 자리가 9일때 까지 -하고, 끝자리 9인 값+1~ 원래 값 까지 0~9를 감소 시켜줌
        while (end % 10 != 9 && start <= end) {
            str_tmp = to_string(end);
            for (int i = 0; i < str_tmp.length(); i++) {
                cnt_num[str_tmp[i] - '0'] -= digit;
            }

            end--;
        }


        //cout << start << "~" << end << "\n";

        for (int i = 0; i < 10; i++) {
            cnt_num[i] += ((end / 10) - (start / 10) + 1) * digit;
        }

        end /= 10;
        start /= 10;
        digit *= 10;
    }

    // 출력
    cout << "\n원본 - ";
    for (int i = 0; i < 10; i++) {
        cout << cnt_num[i] << " ";
    }

    cout << "\n답지 - ";
    func_1019_v3(n);
}
