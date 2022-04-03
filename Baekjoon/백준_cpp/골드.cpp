#include "header.h"

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
    long long cnt_num[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

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

    // ���
    cout << "\n���� - ";
    for (int i = 0; i < 10; i++) {
        cout << cnt_num[i] << " ";
    }

    cout << "\n���� - ";
    func_1019_v3(n);
}




/* ���ϻ��� (��� 5)
* https://www.acmicpc.net/problem/10026
*/

void func_10026_printmap(void** _map, int n, int flag) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!flag)
                cout << (char **)_map[i][j];
            else
                cout << (int **)_map[i][j];

        }
        cout << "\n";
    }

    cout << "\n";
}

void func_10026_bfs(queue<pair<int, int>> q, char **_map, int **visited, int visit_value, int n) {
    pair<int, int> tmp_coord;
    int _x, _y;
    char tmp_color;

    int direct[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    // ��ǥ �޾Ƽ� ������ ���� �� ��ǥ�� �湮 ���θ� �Ǵ��ϰ�, ���� ���� �湮�� �������� �湮���θ� ���а����� �ʱ�ȭ�ϰ� ť�� �߰�
    while (!q.empty()) {
        tmp_coord = q.front();
        tmp_color = _map[tmp_coord.first][tmp_coord.second];
        q.pop();

        // �ð���� ���� ��� �˻�
        for (int i = 0; i < 4; i++) {
            _x = tmp_coord.first + direct[i][0];
            _y = tmp_coord.second + direct[i][1];

            // ��ǥ �˻�
            if (_x >= n || _x < 0)
                continue;
            if (_y >= n || _y < 0)
                continue;

            // �湮 �˻� (�湮������ ��ŵ)
            if (visited[_x][_y] != 0)
                continue;

            // �� �˻� (���� �ٸ��� ��ŵ)
            if (_map[_x][_y] != tmp_color)
                continue;

            // ���� �� ����ϸ� �湮 ���ο� ���� value �ְ�, q�� �ش� ��ǥ�� �ֱ�
            visited[_x][_y] = visit_value;
            q.push({_x, _y});
        }
    }
}

void func_10026() {
    queue<pair<int, int>> q;
    int visit_value, map_max, map_rg_max;
    
    int n;
    cin >> n;
    
    // �Ϲ����� �Է� �ް� ���������� ����
    char** map_origin = new char* [n];
    char** map_rg = new char* [n];
    int** map_visit = new int* [n];
    int** map_rg_visit = new int* [n];

    for (int i = 0; i < n; i++) {
        map_origin[i] = new char[n];
        map_rg[i] = new char[n];
        map_visit[i] = new int[n];
        map_rg_visit[i] = new int[n];

        memset(map_visit[i], 0, sizeof(int) * n);
        memset(map_rg_visit[i], 0, sizeof(int) * n);
    }

    // map �ʱ�ȭ
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            cin >> map_origin[i][j];
            
            // ���Ϳ� ���� ����
            if (map_origin[i][j] == 'R')
                map_rg[i][j] = 'G';
            else
                map_rg[i][j] = map_origin[i][j];
        }
    }

    func_10026_printmap(map_origin, n, 0);
    func_10026_printmap(map_rg, n, 0);

    // �� ��ǥ�� ���� �湮�Ҷ� ���� �ѹ��� bfs ������(������ �湮������ �ȵ�)
    // bfs �ѹ� ���������� visit_value++;
    visit_value = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // ���� ��ǥ�� ������ �з����� �ʾ����� q�� �߰�
            if (map_visit[i][j] == 0) {
                q.push({i, j});
                visit_value++;
            }

            func_10026_bfs(q, map_origin, map_visit, visit_value, n);
        }
    }


    while (!q.empty()) {
        q.pop();
    }


    // ���Ϳ� ��
    // �� ��ǥ�� ���� �湮�Ҷ� ���� �ѹ��� bfs ������(������ �湮������ �ȵ�)
    // bfs �ѹ� ���������� visit_value++;
    visit_value = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map_rg_visit[i][j] == 0) {
                q.push({ i, j });
                visit_value++;
            }

            func_10026_bfs(q, map_rg, map_rg_visit, visit_value, n);
        }
    }

    func_10026_printmap((char **)map_visit, n, 1);
    func_10026_printmap((char **)map_rg_visit, n, 1);

    map_max = 0;
    map_rg_max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map_max < map_visit[i][j]) {
                map_max = map_visit[i][j];
            }

            if (map_rg_max < map_rg_visit[i][j]) {
                map_rg_max = map_rg_visit[i][j];
            }
        }
    }
    cout << map_max << " " << map_rg_max << "\n";
}