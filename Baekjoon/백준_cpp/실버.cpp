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
    cout << "\n";

}

void func_1019() {
    /*for (int i = 1; i < 10000; i *= 10){
        cout << i << " - ";
        func_1019_v3(i);
    }*/

    long long n, start, end, digit;
    string str_tmp;
    long long cnt_num[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    cin >> n;
    
    start = 1;
    end = n;
    digit = 1;

    while (end >= start) {
        //start �� �� �ڸ��� 0�϶� ���� +�ϰ�, 0�϶� start ��~ ���ڸ� 0�� �� -1���� 0~9�� ���� ������
        while (start % 10 != 0 && start <= end) {
            str_tmp = to_string(start);
            for (int i = 0; i < str_tmp.length(); i++) {
                cnt_num[str_tmp[i] - '0'] += digit;
            }

            start++;
        }
        
        if (start > end) break;

        //end �� �� �ڸ��� 9�϶� ���� -�ϰ�, ���ڸ� 9�� ��+1~ ���� �� ���� 0~9�� ���� ������
        while (end % 10 != 9 && start <= end){
            str_tmp = to_string(end);
            for (int i = 0; i < str_tmp.length(); i++) {
                cnt_num[str_tmp[i] - '0'] -= digit;
            }

            end--;
        }


        //cout << start << "~" << end << "\n";
        
        for (int i = 0; i < 10; i++) {
            cnt_num[i] += ( (end / 10) - (start / 10) + 1 ) * digit;
        }

        end /= 10;
        start /= 10;
        digit *= 10;
    }

    // ���
    cout << "\n���� - ";
    for (int i = 0; i < 10; i++) {
        cout << cnt_num[i] << " ";
    }

    cout << "\n���� - ";
    func_1019_v3(n);
}


/* ���ٲ��� (�ǹ� 1)
* https://www.acmicpc.net/problem/1697
*/
void func_1697_bfs(int k, queue<int> q, int *visited) {
    int now;

    while (!q.empty()) {
        now = q.front();
        q.pop(); 
        
        //cout << "now : " << now << ", visited : " << visited[now] << "\n";

        if (now == k) {
            break;
        }

        if (visited[now - 1] == 0 && (now - 1) >= 0) {
            visited[now - 1] = visited[now] + 1;
            q.push(now-1);
        }

        if ( (now+1) < 100000 && visited[now + 1] == 0) {
            visited[now + 1] = visited[now] + 1;
            q.push(now+1);
        }
        
        if ( (now * 2) <= 100000 && visited[now * 2] == 0) {
                visited[now * 2] = visited[now] + 1;
                q.push(now * 2);
        }
    }
}

void func_1697() {
    int n, k;
    cin >> n >> k;
    int* visited = new int[100000];
    memset(visited, 0, sizeof(int) * 100000);
    queue<int> q;

    q.push(n);
    visited[n] = 1;
    func_1697_bfs(k, q, visited);

    cout << visited[k] - 1 << "\n";
}


/* �л�ó�� (����� 3)
* https://www.acmicpc.net/problem/1009
*/
int func_1009_mod(int a, int b) {
    vector<int> tmp, tmp2;
    int *x;
    ll res = 1;

    while(b!=0) {
        tmp.push_back(b % 2);
        b /= 2;
    }

    x = new int[21];
    x[0] = a % 10;
    for (int j = 1; j <= 20; j++) {
        x[j] = (x[j-1] * x[j - 1]) % 10;
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

