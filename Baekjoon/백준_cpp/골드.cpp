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




/* 적록색약 (골드 5)
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

    // 좌표 받아서 인접한 같은 값 좌표의 방문 여부를 판단하고, 값이 같고 방문을 안했으면 방문여부를 구분값으로 초기화하고 큐에 추가
    while (!q.empty()) {
        tmp_coord = q.front();
        tmp_color = _map[tmp_coord.first][tmp_coord.second];
        q.pop();

        // 시계방향 인접 노드 검사
        for (int i = 0; i < 4; i++) {
            _x = tmp_coord.first + direct[i][0];
            _y = tmp_coord.second + direct[i][1];

            // 좌표 검사
            if (_x >= n || _x < 0)
                continue;
            if (_y >= n || _y < 0)
                continue;

            // 방문 검사 (방문했으면 스킵)
            if (visited[_x][_y] != 0)
                continue;

            // 값 검사 (값이 다르면 스킵)
            if (_map[_x][_y] != tmp_color)
                continue;

            // 위에 다 통과하면 방문 여부에 현재 value 넣고, q에 해당 좌표값 넣기
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
    
    // 일반지도 입력 받고 색맹지도도 생성
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

    // map 초기화
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            cin >> map_origin[i][j];
            
            // 색맹용 지도 생성
            if (map_origin[i][j] == 'R')
                map_rg[i][j] = 'G';
            else
                map_rg[i][j] = map_origin[i][j];
        }
    }

    func_10026_printmap(map_origin, n, 0);
    func_10026_printmap(map_rg, n, 0);

    // 각 좌표를 전부 방문할때 까지 한번씩 bfs 때리기(어차피 방문했으면 안돔)
    // bfs 한번 끝날때마다 visit_value++;
    visit_value = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 현재 좌표의 구역이 분류되지 않았으면 q에 추가
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


    // 색맹용 맵
    // 각 좌표를 전부 방문할때 까지 한번씩 bfs 때리기(어차피 방문했으면 안돔)
    // bfs 한번 끝날때마다 visit_value++;
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