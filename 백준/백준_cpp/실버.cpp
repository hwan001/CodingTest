#include "header.h"


/* k��° �Ҽ� (�ǹ� 2, �Ҽ� ����)
* https://www.acmicpc.net/problem/15965
*/
void func_15965() {
    int a, max = 500000000, sum=0;
    bool* arr = Sieve_of_Eratosthenes(max);
    cin >> a;

    for (int i = 0; i <= max; i++) {
        sum += arr[i];
        //cout << i << " " << sum << endl;
        if (sum == a+1) {
            cout << i << endl;
            break;
        }
    }
}


/* ����� (�ǹ� 3)
* https://www.acmicpc.net/problem/1004
*/

bool func_1004_isInCircle(pair<int, int> coord, int c1, int c2, int r) {
    if (pow(coord.first - c1, 2) + pow(coord.second - c2, 2) <= (r * r)) {
        return true;
    }
    else {
        return false;
    }
}   


void func_1004() {
    int test_case, n, cnt;
    int x, y, r;

    pair<int, int> start_coord, end_cood;

    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        cnt = 0;
        cin >> start_coord.first >> start_coord.second >> end_cood.first >> end_cood.second;
        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> x >> y >> r;

            // �Ѵ� ���� ���ȿ� ��������� ī��Ʈ ����
            if (func_1004_isInCircle(start_coord, x, y, r) && func_1004_isInCircle(end_cood, x, y, r)) {
                continue;
            }

            if (func_1004_isInCircle(start_coord, x, y, r) || func_1004_isInCircle(end_cood, x, y, r)) {

                cnt++;
            }
        }

        cout << cnt << "\n";
    }
}


/* å ������ (��� 1)
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


    // �̸� ���Ȱ� ���ϱ�
    m['0'] += v[str_n.length() - 2].first;
    for (int i = 1; i <= 9; i++) {
        m['0' + i] += v[str_n.length() - 2].second;
    }

    // �ش� ���ں��� ����
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

    // �̸� ���Ȱ� ���ϱ�
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

    // �ʱ�ȭ
    for (int i = 0; i < 9; i++) m['0' + i] = 0;

    // ���ذ�
    v_dp.push_back({ 0, 1 });
    for (int i = 1; i < 9; i++) {
        tmp_first = 9 * v_dp[i - 1].second + v_dp[i - 1].first;
        tmp_second = tmp_first + v_dp[i - 1].second + pow(10, i) - v_dp[i - 1].first;

        v_dp.push_back({ tmp_first, tmp_second });
        cout << "pair (" << i << ") : " << tmp_first << ", " << tmp_second << "\n";
    }

    // �Ǵ�
    if (abs(n - (pow(10, str_n.length() - 1) - 1) <= abs(n - (pow(10, str_n.length()) - 1)))) {
        func_1019_sum(m, n, v_dp);
    }
    else{
        func_1019_sub(m, n, v_dp);
    }
}

void calc_1019(long long n, long long point, long long *count_1019) {
    while (n > 0) {
        count_1019[n % 10] += point;
        n /= 10;
    }
}

// ���� �ڵ� ����
void func_1019_v3() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long count_1019[10];
    long long n;
    long long start = 1;
    long long end;
    long long point = 1;
    memset(count_1019, 0, sizeof(count_1019));
    cin >> n;
    end = n;

    while (end >= start) {
        // ���� �� �ø��� (0����)
        while (start % 10 != 0 && start <= end) {
            calc_1019(start, point, count_1019);
            start++;
        }
        
        // start ���� ��Ű�ٰ� end ���� Ŀ���� (���� start, end�� 1�ڸ� ���϶� �߻�)
        if (start > end) break;

        // ���� �� ���̱� (9����)
        while (end % 10 != 9 && start <= end) {
            calc_1019(end, point, count_1019);
            end--;
        }

        // �� �ڸ��� �� ���� ���
        long long rescalc = end / 10 - start / 10 + 1;
        for (int i = 0; i < 10; i++) {
            count_1019[i] += (point * rescalc);
        }

        // ���� �ڸ��� �̵�
        start /= 10;
        end /= 10;
        point *= 10LL;
    }

    // ���
    for (int i = 0; i < 10; i++) {
        cout << count_1019[i] << " ";
    }

}

void func_1019() {
    long long n;
    cin >> n;

}