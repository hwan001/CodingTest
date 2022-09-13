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

void func_10026_printmap(string memo, char **_map, int n) {
    cout << memo << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                cout << _map[i][j];
        }
        cout << "\n";
    }

    cout << "\n";
}

void func_10026_printmap_int(string memo, int** _map, int n) {
    cout << memo << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << _map[i][j];
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

    
    func_10026_printmap("map_origin", map_origin, n);
    func_10026_printmap("map_rg", map_rg, n);

    // �� ��ǥ�� ���� �湮�Ҷ� ���� �ѹ��� bfs ������(������ �湮������ �ȵ�)
    // bfs �ѹ� ���������� visit_value++;
    visit_value = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // ���� ��ǥ�� ������ �з����� �ʾ����� q�� �߰�
            if (map_visit[i][j] == 0) {
                q.push({i, j});
                map_visit[i][j] = ++visit_value;
            }

            func_10026_bfs(q, map_origin, map_visit, visit_value, n);
        }
    }


    while (!q.empty()) {
        q.pop();
    }

    func_10026_printmap_int("origin_visit_1", map_visit, n);
    func_10026_printmap_int("rg_visit_1", map_rg_visit, n);

    // ���Ϳ� ��
    // �� ��ǥ�� ���� �湮�Ҷ� ���� �ѹ��� bfs ������(������ �湮������ �ȵ�)
    // bfs �ѹ� ���������� visit_value++;
    visit_value = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map_rg_visit[i][j] == 0) {
                q.push({ i, j });
                map_rg_visit[i][j] = ++visit_value;
            }

            func_10026_bfs(q, map_rg, map_rg_visit, visit_value, n);
        }
    }

    func_10026_printmap_int("origin_visit_2", map_visit, n);
    func_10026_printmap_int("rg_visit_2", map_rg_visit, n);

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



/* �� �μ��� �̵��ϱ� (��� 4) - �ۼ� �� 
* https://www.acmicpc.net/problem/2206
*/
void func_2206() {
    int n, m;
    cin >> n >> m;
    
    // �ʱ�ȭ
    int** _map = new int* [n];
    for (int i = 0; i < n; i++) {
        _map[i] = new int[m];
    }

    // map �Է�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> _map[i][j];
        }
    }

    // ���
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << _map[i][j];
        }
        cout << "\n";
    }

    // 
}


/* �ִܰ�� (��� 5)
* https://www.acmicpc.net/problem/1753

6 10
1
1 2 3
1 3 2
1 5 1
2 3 1
3 4 1
3 5 5
3 6 4
4 6 2
6 2 3
6 5 6

5 5
1
1 2 9
1 3 1
2 5 1
3 4 1
4 2 1
*/

/*
5 5
0 3 0 3 2
0 0 0 0 5
0 0 0 0 0
0 0 0 0 5
0 0 6 0 0

0 3 8 3 2


6 6
0 3 2 0 1 0
0 0 1 0 0 0
0 0 0 1 5 4
0 0 0 0 0 2
0 0 0 0 0 0
0 3 0 0 0 6

0 3 2 3 1 5
*/

void func_1753_print_distance(int num, int* d, int max) {
    for (int i = 0; i < num; i++) {
        if (d[i] != max) {
            cout << d[i] << " ";
        }
        else {
            cout << "INF ";
        }
    }
    cout << "\n";
}

void func_1753_dijkstra_first(int start, int num, int ** graph, int* visit, int max) {
    int current;

    int* d = new int[num];
    for (int i = 0; i < num; i++) {
        d[i] = max;
    }
    d[start - 1] = 0;

    queue<int> q;
    visit[start - 1] = 1;
    q.push(start - 1);

    while (!q.empty()) {
        current = q.front();
        q.pop();

        for (int i = 0; i < num; i++) {
            if (graph[current][i] != 0) {
                if (d[i] > d[current] + graph[current][i]) {
                    d[i] = d[current] + graph[current][i];
                }

                if (visit[i] == 0) {
                    visit[i] = 1;
                    q.push(i);
                }
            }
        }
    }

    for (int i = 0; i < num; i++) {
        if (d[i] != max) {
            cout << d[i] << " ";
        }
        else {
            cout << "INF ";
        }
    }
    cout << "\n";
}

void func_1753_dijkstra_bfs(int start, int num, vector<pair<int, int>> *graph, int* visit, int max) {
    pair<int, int> current;
    
    // �ִܰŸ� ����Ʈ ���� �� �ʱ�ȭ
    int* d = new int[num];
    for (int i = 0; i < num; i++) {
        d[i] = max;
    }
    d[start - 1] = 0;

    queue<pair<int, int>> q;
    int min = max, minIndex = 0;

    // ���� ��� �湮 ó���� ť ���, ���� ��忡�� ���۳��� ���� ����ġ�� �����Ƿ� 0 �Է�
    visit[start - 1] = 1;
    q.push({start - 1, 0});


    while (!q.empty()) {
        current = q.front();
        q.pop();

        // ���� �۾� ��忡�� ������ ����� ��� ���� �����ؾ���
        // ���� ���� ������ ��带 ��� �ҷ����� 
        for (auto adj_node : graph[current.first]) {
            // ������ ���� ���� ��� ���� ������ ���� �Ÿ����� ��
            // ���� ���� �Ÿ� �� : d[adj_node.first]
            // �ش� ����Ʈ�� ����� ���� ���� ���ϰ� �� ª���� ����
            if (d[adj_node.first] > d[current.first] + adj_node.second) {
                // start���� i����� �ִܰŸ� = ���� ������ ���� �ִܰŸ� + ���� ���� ���� ���
                d[adj_node.first] = d[current.first] + adj_node.second;
            }

            // �湮���� �ʾ����� �湮 ���� üũ �� ť�� ���
            if (visit[adj_node.first] == 0) {
                visit[adj_node.first] = 1;
                q.push(adj_node);
            }
        }
    }

    // ���
    for (int i = 0; i < num; i++) {
        if (d[i] != max) {
            cout << d[i] << " ";
        }
        else {
            cout << "INF ";
        }
    }
    cout << "\n";
}

void func_1753_dijkstra_dfs(int node, vector<pair<int, int>>* graph, int* visit, int *d) {
    // �湮 ���� üũ
    visit[node] = 1;
    cout << "current node ; " << (char)(node+'a') << "\n";

    // ���� ����Ȯ��
    for (auto tmp : graph[node]) {
        cout << (char)(tmp.first + 'a') << " " << tmp.second << " " << visit[node] << "\n";
        
        if (d[tmp.first] > d[node] + tmp.second) {
            d[tmp.first] = d[node] + tmp.second;
        }

        if (!visit[tmp.first]) {
            func_1753_dijkstra_dfs(tmp.first, graph, visit, d);
        }
    }


}

bool func_1753_cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second < b.second;
}

// ��������Ʈ ���ͽ�Ʈ�� bfs -> 4% Ʋ��
void func_1753_adjlist_bfs() {
    int n, m;
    cin >> n >> m;

    // ���� ����Ʈ ����
    vector<pair<int, int>>* adjlist = new vector<pair<int, int>> [n];;

    int* visit = new int[n + 1];
    memset(visit, 0, sizeof(int) * (n + 1));

    int u, v, a, start_node;
    cin >> start_node;
    for (int i = 0; i < m; i++) { 
        cin >> u >> v >> a;
        adjlist[u - 1].push_back({v - 1, a});
        adjlist[v - 1].push_back({ u - 1, a });
    }
    
    for (int i = 0; i < n; i++) {
        sort(adjlist[i].begin(), adjlist[i].end(), func_1753_cmp);
        //reverse(adjlist[i].begin(), adjlist[i].end());

        cout << (char)('a' + i) << " : ";
        for (auto adjlist_tmp : adjlist[i]) {
            cout << "{" << (char)('a' + adjlist_tmp.first) << ", " << adjlist_tmp.second << "} ";
        }
        cout << "\n";
    }

    func_1753_dijkstra_bfs(start_node, n, adjlist, visit, 99999999);
}

// ������� ���ͽ�Ʈ�� -> 4% �޸� �ʰ�
void func_1753_first_adjmatrix() {
    int n, m;
    cin >> n >> m;

    int** _map = new int* [n];
    for (int i = 0; i < n; i++) {
        _map[i] = new int[n];
        memset(_map[i], 0, sizeof(int) * n);
    }

    int* visit2 = new int[n + 1];
    memset(visit2, 0, sizeof(int) * (n + 1));

    int u, v, a, start_node;
    cin >> start_node;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> a;
        _map[u - 1][v - 1] = a;
    }

    func_1753_dijkstra_first(start_node, n, _map, visit2, 99999999);
}

// ��������Ʈ ���ͽ�Ʈ�� dfs -> 4% Ʋ��
void func_1753_adjlist_dfs() {
    int n, m, max = 99999999;
    cin >> n >> m;

    vector<pair<int, int>>* adjlist = new vector<pair<int, int>>[n];;

    int* visit = new int[n + 1];
    memset(visit, 0, sizeof(int) * (n + 1));

    int u, v, a, start_node;
    cin >> start_node;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> a;
        adjlist[u - 1].push_back({ v - 1, a });
        //adjlist[v - 1].push_back({ u - 1, a });
    }

    for (int i = 0; i < n; i++) {
        //sort(adjlist[i].begin(), adjlist[i].end(), func_1753_cmp);
        sort(adjlist[i].begin(), adjlist[i].end());
        reverse(adjlist[i].begin(), adjlist[i].end());

        /*
        cout << (char)('a' + i) << " : ";
        for (auto adjlist_tmp : adjlist[i]) {
            cout << "{" << (char)('a' + adjlist_tmp.first) << ", " << adjlist_tmp.second << "} ";
        }
        cout << "\n";
        */
    }

    // �ִܰŸ� ����Ʈ ���� �� �ʱ�ȭ
    int* d = new int[n];
    for (int i = 0; i < n; i++) {
        d[i] = max;
    }
    d[start_node - 1] = 0;

    func_1753_dijkstra_dfs(start_node-1, adjlist, visit, d);

    func_1753_print_distance(n, d, max);
}

// O(V^2) ��� ���� -> 4% �ð� �ʰ�
void func_1753_old() {
    int n, m, start, max = 99999999;
    int min = max, current;
    int u, v, a;

    cin >> n >> m;

    int* visit = new int[n+1];
    memset(visit, 0, sizeof(int) * (n+1));

    int* d = new int[n];
    for (int i = 0; i < n; i++) {
        d[i] = max;
    }

    vector<pair<int, int>>* adjlist = new vector<pair<int, int>>[n];

    cin >> start;
    if(start > 0) start--;
    d[start] = 0;

    // �Է�
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> a;
        adjlist[u - 1].push_back({ v - 1, a });
    }

    // ���۳���� ���� ��� �Ÿ��� ����
    for (auto tmp : adjlist[start]) {
        d[tmp.first] = tmp.second;
    }

    visit[start] = 1;

    // ���ͽ�Ʈ��
    for (int i = 0; i < n - 1; i++) {
        min = max;
        current = 0;

        for (int j = 0; j < n;j++) {
            if (d[j] < min && !visit[j]) {
                min = d[j];
                current = j;
            }
        }
        
        visit[current] = 1;

        for (auto cur : adjlist[current]){
            if (!visit[cur.first]) {
                if (d[current] + cur.second < d[cur.first]) {
                    d[cur.first] = d[current] + cur.second;
                }
            }
        }   
    }

    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << "\n";
}

void func_1753_dijkstra_pq(int start, vector<pair<int, int>>* graph, int *d) {
    int _current, _next, _distance, _nextDistance;

    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({start, 0});
    
    while (!pq.empty()) {
        _current = pq.top().second;
        _distance = -pq.top().first;

        pq.pop();

        if (d[_current] < _distance)
            continue;

        for (int i = 0; i < graph[_current].size(); i++) {
            _next = graph[_current][i].second;
            _nextDistance = _distance + graph[_current][i].first;

            if (_nextDistance < d[_next]) {
                d[_next] = _nextDistance;
                pq.push({-_nextDistance, _next});
            }
        }
    }
}

// �켱���� ť ��� ����
void func_1753() {
    int n, m, start, max = 99999999;
    int u, v, a;

    cin >> n >> m;

    int* d = new int[n];
    for (int i = 0; i < n; i++) {
        d[i] = max;
    }

    vector<pair<int, int>>* adjlist = new vector<pair<int, int>>[n];

    cin >> start;
    if (start > 0) start--;

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> a;
        adjlist[u - 1].push_back({ a, v - 1 });
    }

    func_1753_dijkstra_pq(start, adjlist, d);


    for (int i = 0; i < n; i++) {
        if (d[i] == max) {
            cout << "INF ";
        }
        else {
            cout << d[i] << " ";
        }
    }
    cout << "\n";
}


/* k��° �� (��� 2)
*  https://www.acmicpc.net/problem/1300
*/
void func_1300() {
    // �̰� ���� ���� �ȵ� 
    int n, k, i, j;
    
    cin >> n >> k;

    i = (int)(k / n) + 1;
    j = (int)(k % n) + 1;

    cout << i * j;
    
}   


/* N-Queen (��� 4)
*  https://www.acmicpc.net/problem/9663
*/
void func_9663_mapset(int **_map, int n) {
    for (int i = 0; i < n; i++) {
        memset(_map[i], 0, sizeof(int) * n);
    }
}

bool func_9663_check(int **map, int n, pair<int, int> cur) {
    pair<int, int> direc[8] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };
    int _x, _y;
    pair<int, int> next_node;
    queue<pair<int, int>> q;

    if (map[cur.second][cur.first] == 0) {
        map[cur.second][cur.first] = 9;
        //visit[cur.second][cur.first] = 1;

        for (int i = 0; i < 8; i++) {
            _x = cur.second + direc[i].second;
            _y = cur.first + direc[i].first;

            //cout << i << "\n";

            q.push({ _x, _y });

            while (!q.empty()) {
                _x = q.front().first;
                _y = q.front().second;
                q.pop();

                // �ش� ��ǥ�� �� �ȿ� �ִ��� üũ 
                if (_x >= n || _x < 0 || _y >= n || _y < 0) break;

                // ���� �ش� ������ �����ϸ鼭 ���� ������ return
                if (map[_x][_y] == 9) {
                    return false;
                }

                //cout << i << " - " << _x << " + " << direc[i].second << ", " << _y << " + " << direc[i].first << "\n";

                // �� �ȿ� ��ġ�� ������ �湮 ǥ��
                //visit[_x][_y] = 1;
                map[_x][_y] = 1;

                q.push({ _x + direc[i].second, _y + direc[i].first });
            }
        }
    }
    else {
        return false;
    }

    return true;
}

int func_9663_dfs(const int n) {
    // ���� �޸𸮷� �ϰ� ���� ä���ִ� ��� �ۼ�
    stack<int**> stack_map;
    int **_map; // �޸� �Ҵ� �ʿ�
    int cnt, cnt2=0;

    stack_map.push(_map); // ����ִ� ��

    // 0�� ���� �� �ΰ� ���ÿ� �ֱ� -> ���̻� �� �� ������ pop
    while (!stack_map.empty()) {
        cnt = 0;
        _map = stack_map.top();
        stack_map.pop();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (_map[i][j] == 0) {
                    if (func_9663_check(_map, n, { i, j })) {
                        cnt++;
                    }
                }
            }
        }

        if (cnt == n) {
            cnt2++;
            // ��� ���� ���̽��� �ݺ��� �� ���� - > ���⼭ ���� ó��?
            break;
        }
        else {
            cnt = 0;
            stack_map.push(_map);
        }
    }

    return cnt2;
}

void func_9663() {
    int n;
    cin >> n;

    // create map
    int** _map = new int*[n];
    //int** _visit = new int* [n];

    for (int i = 0; i < n; i++) {
        _map[i] = new int[n];
        //_visit[i] = new int[n];

        memset(_map[i], 0, sizeof(int) * n);
        //memset(_visit[i], 0, sizeof(int) * n);
    }

    int cnt = 0;

    // ������ ��ü ��� �ѹ��� Ž�� (�ش� ��ġ�� ���� �ΰ� ����)
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            if (_map[i][j] == 0) {
                if (func_9663_check(_map, n, { i, j })) {
                    cnt++;
                }
            }
        }
    }
    */
    cnt = func_9663_dfs(n);

    cout << cnt << "\n" ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << _map[i][j];
        }
        cout << "\n";
    }

}