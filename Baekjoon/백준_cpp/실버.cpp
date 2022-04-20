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

/* ī��2 (�ǹ� 4)
* https://www.acmicpc.net/problem/2164
*/
void func_2164() {
    queue<int> q;
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (q.size() > 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front() << "\n";

}

/*�似Ǫ�� ���� (�ǹ� 4)
* https://www.acmicpc.net/problem/11866
*/
void func_11866() {
    int n, k, cnt;
    queue<int> q;
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        q.push(i+1);
    }

    cout << "<";
    cnt = 1;
    while (!q.empty()) {
        if (cnt % k != 0) {
            q.push(q.front());
            q.pop();
            cnt++;
        }
        else {
            if (q.size() == 1)
                cout << q.front();
            else
                cout << q.front() << ", ";

            q.pop();
            cnt = 1;
        }
    }
    cout << ">";
}

/* ����ũ����Ʈ (�ǹ� 2)
*  https://www.acmicpc.net/problem/18111
*/
void func_18111_v1() {
    int n, m, inventory, height, time = 0;
    double sum = 0;

    cin >> n >> m >> inventory;

    // �� �Է�
    int** map = new int*[n];
    for (int i = 0; i < n; i++) {
        map[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            sum += map[i][j];
        }
    }

    // ��ü ���� ���� (�κ��丮 ����)
    if (inventory > 0) {
        height = round(sum / (n * m));
    }
    else {
        height = floor(sum / (n * m));
    }
    
    // �� �ٵ��
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == height)
                continue;

            if (map[i][j] > height) {
                while (map[i][j] != height) {
                    time += 2;
                    map[i][j] -= 1;
                    inventory++;
                }
            }
            else {
                while (map[i][j] != height) {
                    time += 1;
                    map[i][j] += 1;
                    inventory--;
                }
            }

        }
    }

    cout << time << " " << height << "\n";
}

int func_18111_getTime(int height, int n, int m, int inventory, int **map) {
    int time = 0, tmp_map;
    bool flag = true;

    cout << "height : " << height << ", inven : " << inventory << " -> "; 
    
    // ��� ȸ�� (���� ���߱�)
    for (int i = 0; i < n && flag; i++) {
        for (int j = 0; j < m && flag; j++) {
            tmp_map = map[i][j];
            //cout << tmp_map << " ";

            if (tmp_map == height)
                continue;

            // ������ ȸ��
            if (tmp_map > height) {
                while (tmp_map != height) {
                    time += 2;
                    tmp_map -= 1;
                    inventory++;
                }
            }
        }
    }
    
    // ��� ��ġ (���� ���̱�) - �����ϸ� flag == false
    for (int i = 0; i < n && flag; i++) {
        for (int j = 0; j < m && flag; j++) {
            tmp_map = map[i][j];
            //cout << tmp_map << " ";

            if (tmp_map == height)
                continue;

            if (tmp_map < height) {
                while (tmp_map != height) {
                    if (inventory > 0) {
                        inventory--;
                    }
                    else {
                        flag = false;
                    }

                    if (!flag)
                        break;

                    time += 1;
                    tmp_map += 1;
                }

                if (!flag || tmp_map != height) {
                    flag = false;
                    cout << " inventory empty ";
                    break;
                }
            }
        }
    }

    if (!flag) {
        time = 0;
    }

    cout << "time : " << time << "\n";
    return time;
}

void func_18111_v3() {
    int n, m, inventory, height=-1, time = 0, tmp, min = 2100000000, max=0;
    double sum = 0;

    cin >> n >> m >> inventory;

    // �� �Է�
    int** map = new int* [n];
    for (int i = 0; i < n; i++) {
        map[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            // sum += map[i][j];
            if (max < map[i][j]) {
                max = map[i][j];
            }
        }
    }
    
    for (int i = 0; i <= max; i++) {
        tmp = func_18111_getTime(i, n, m, inventory, map);
        //cout << " �߰���� :  " << tmp << ", " << min;
        
        if (min >= tmp && tmp > 0) {
            //cout << "- find \n";
            // ������ �ð��� �ִٸ� ���̰� ���� �� ����
            if (min == tmp && height > i) continue;

            min = tmp;
            height = i;
        }
        else {
            //cout << "\n";
        }
    }

    if (min == 2100000000 || height == -1) {
        min = 0;
        height = 0;
    }

    cout << min << " " << height << "\n";
}

void func_18111() {
    int n, m, inventory, min = 2100000000, max = 0;
    int height = -1, time = 0, tmp_block, time_min= 2100000000;
    double sum = 0;

    cin >> n >> m >> inventory;

    // �� �Է�
    int** map = new int* [n];
    for (int i = 0; i < n; i++) {
        map[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (max < map[i][j]) {
                max = map[i][j];
            }

            if (min > map[i][j]) {
                min = map[i][j];
            }
        }
    }

    //cout << "min : " << min << ", max : " << max << "\n";

    int build_block, remove_block;

    // ���� �ּ� ��� ���̺��� ���� ���� ��ϱ��� �ݺ�
    for (int h = min; h <= max; h++) {
        build_block = 0;
        remove_block = 0;

        // h������ ȸ���� ���, ��ġ�� ��� ���� ���ϱ�
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp_block = map[i][j];

                // ���� ����� h���� ������ ��ġ�� ��� ���� ����
                if (h > tmp_block) {
                    build_block += h - tmp_block;
                }

                // ���� ����� h ���� ������ ȸ���� ��� ���� ����
                if (h < tmp_block) {
                    remove_block += tmp_block - h;
                }
            }
        }

        //cout << "h : " << h << ", build_block : " << build_block << ", remove_block : " << remove_block << " ";

        // ��ġ�� ��� ������ �κ��丮�� ȸ���� ������պ��� �������� �˻�
        if (build_block <= remove_block + inventory) {
            // �ð� ����ϱ�
            time = remove_block * 2 + build_block;

            // ����� �ð��� �ּ� ���̸� ���
            if (time_min >= time) {
                // ����� �ð��� �ּ� ������ �۰ų� ����, ���̰� h���� ������ ���
                if (height > h) continue;
                time_min = time;
                height = h;
                //cout << "-> " << height << ", time_min : " << time_min << "";
            }
        }

        //cout << "\n";
    }


    cout << time_min << " " << height << "\n";
}

/* ���� (�ǹ� 4)
*  https://www.acmicpc.net/problem/10773
*/
void func_10773() {
    int test_case, tmp, sum=0;
    cin >> test_case;

    stack<int> stack_zero;

    for (int i = 0; i < test_case; i++) {
        cin >> tmp;
        if (tmp==0) {
            stack_zero.pop();
        }
        else {
            stack_zero.push(tmp);
        }
    }
    
    while (!stack_zero.empty()) {
        sum += stack_zero.top();
        stack_zero.pop();
    }

    cout << sum << "\n";
}

/* �ִ������� �ּҰ���� (�ǹ� 5)
*  https://www.acmicpc.net/problem/2609
*/
int func_2609_gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    else {
        return func_2609_gcd(b, a % b);
    }
}

int func_2609_lcm(int a, int b) {
    return (a * b) / func_2609_gcd(a, b);
}

void func_2609(){
    int a, b;
    cin >> a >> b;

    cout << func_2609_gcd (a, b) << "\n";
    cout << func_2609_lcm(a, b) << "\n";
}

/* ��ȣ (�ǹ� 4)
*  https://www.acmicpc.net/problem/9012
*/
void func_9012() {
    int test_case;
    cin >> test_case;

    string str;
    map<char, int> m;
    vector<char> v;
    bool flag;
    int count;

    for (int i = 0; i < test_case; i++) {
        m.clear();
        v.clear();
            
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            m[str[j]]++;
            v.push_back(str[j]);
        }

        if (m['('] == m[')']) {
            count = 0;
            flag = false;
            //cout << "same\n";
            // �������¸� +1, ���� ���¸� -1, ���� 0���� �۾����� no, �ٵ��Ҵµ� 0�� �ƴϸ� no
            for (auto v_tmp : v) {
                //cout << v_tmp << ", " << count << "\n";
                if (v_tmp == '(') {
                    count++;
                }
                if (v_tmp == ')') {
                    count--;
                }
                if (count < 0) {
                    flag = true;
                    break;
                }
            }

            if (!flag && count == 0) {
                cout << "YES\n";
                continue; 
            }

        }

        cout << "NO\n";
    }
}

/* ť 2 (�ǹ� 4)
*  https://www.acmicpc.net/problem/9012
*/
void func_18258() {
    int n, num;
    cin >> n;
    
    string cmd;
    queue<int> q;

    for (int i = 0; i <= n; i++) {
        cin >> cmd;

        if (cmd == "push") {
            cin >> num;
            q.push(num);
        }
        else if (cmd == "pop") {
            if (q.size() > 0) {
                cout << q.front() << "\n";
                q.pop();
            }
            else {
                cout << "-1\n";
            }
        }
        else if (cmd == "front") {
            if (q.size() > 0) {
                cout << q.front() << "\n";
            }
            else {
                cout << "-1\n";
            }
        }
        else if (cmd == "back") {
            if (q.size() > 0) {
                cout << q.back() << "\n";
            }
            else {
                cout << "-1\n";
            }
        }
        else if (cmd == "empty") {
            if (q.empty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (cmd == "size") {
            cout << q.size() << "\n";
        }
    }
}

/* 1�� ����� (�ǹ� 3)
*  https://www.acmicpc.net/problem/1463
*/
void func_1463() {
    int min, num;

    cin >> num;

    int* dp = new int[num+2];
    memset(dp, 0, sizeof(int) * (num+2));
    
    for (int i = 2; i <= num; i++) {
        dp[i]++;
        min = 0;

        if (min > dp[i - 1] || min == 0)
            min = dp[i - 1];

        if (i % 2 == 0) {
            if (min > dp[i / 2])
                min = dp[i / 2];
        }

        if (i % 3 == 0) {
            if (min > dp[i / 3])
                min = dp[i / 3];
        }

        dp[i] += min;
    }

    cout << dp[num] << "\n";
}

/* �� ã�� (�ǹ� 4)
*  https://www.acmicpc.net/problem/1920
*  ����, ���� Ž�� ����
*/
vector<int> func_1920_An;

int func_1920_isExist(int find_value) {
    int res = 0;
    int start_index = 0, end_index = func_1920_An.size();
    int index = (int)floor((start_index + end_index) / 2);

    while(start_index < end_index) {
        // ������ Ż��
        if (find_value == func_1920_An.at(index)) {
            res = 1;
            //cout << "start : " << start_index << ", end : " << end_index << ", index : " << index << ", value : " << v.at(index) << "\n";
            break;
        }

        if (start_index == index)
        {  
            break;
        }

        // ã�� ���� ���� �ε��� �� ���� ũ�� start�� �����ε����� �ʱ�ȭ
        if (find_value > func_1920_An.at(index)) {
            start_index = index;
        }

        // ������ end�� index�� �ʱ�ȭ
        if (find_value < func_1920_An.at(index)) {
            end_index = index;
        }

        // �ε��� ����
        index = (int)floor((start_index + end_index) / 2);

        //cout << "start : " << start_index << ", end : " << end_index << ", index : " << index << ", value : " << v.at(index) << "\n";
    }

    return res;
}

void func_1920() {
    int n, m, tmp;
    vector<int> Am;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // An �ޱ�
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        func_1920_An.push_back(tmp);
    }

    sort(func_1920_An.begin(), func_1920_An.end());

    // Am �ޱ�
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        Am.push_back(tmp);
    }

    // ã��
    for (auto m_tmp : Am) {
        cout << func_1920_isExist(m_tmp) << "\n";
    }
}

/* ���� ���� (�ǹ� 2)
*  https://www.acmicpc.net/problem/4963
*/

void func_4963() {
    int w=1, h=1;
    queue<pair<int, int>> q;
    int direc[8][2] = { {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };
    int visit_value, _x, _y;
    pair<int, int> front;

    while (true) {
        cin >> w >> h;

        if (w + h == 0)
            break;

        int** _map = new int* [h];
        int** visit = new int* [h];
        for (int i = 0; i < h; i++) {
            _map[i] = new int[w];
            visit[i] = new int[w];
            memset(visit[i], 0, sizeof(int) * w);
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> _map[i][j];
            }
        }

        visit_value = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (visit[i][j] == 0 && _map[i][j] == 1) {
                    q.push({ i, j });
                    visit[i][j] = ++visit_value;
                }

                //bfs
                while (!q.empty()) {
                    front = q.front();
                    q.pop();

                    // �ð�������� 8���� ����
                    for (int i = 0; i < 8; i++) {
                        _x = front.first + direc[i][0];
                        _y = front.second + direc[i][1];

                        if (_x >= h || _x < 0) {
                            continue;
                        }

                        if (_y >= w || _y < 0) {
                            continue;
                        }

                        if (visit[_x][_y] != 0) {
                            continue;
                        }

                        if (_map[_x][_y] != 1) {
                            continue;
                        }

                        visit[_x][_y] = visit_value;
                        q.push({ _x, _y });
                    }
                }
            }
        }

        cout << visit_value << "\n";

        while (!q.empty()) {
            q.pop();
        }

        for (int i = 0; i < h; i++) {
            delete(_map[i]);
            delete(visit[i]);
        }
    }
}

/* 2 * N Ÿ�ϸ� (�ǹ� 2)
*  https://www.acmicpc.net/problem/11726
*/
void func_11726() {
    int n;
    cin >> n;

    int* dp = new int[n+1];
    dp[0] = 0;

    if (n > 0) {
        dp[1] = 1;
    }

    if (n > 1) {
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
        }
    }

    cout << dp[n] << "\n";
}

/* ���� ����� ���� (�ǹ� 2)
*  https://www.acmicpc.net/problem/11724
*/

// dfs �޸� �ʰ�
void func_11724_dfs(int node, bool* visit, map<int, vector<int>> _map) {
    visit[node] = true;

    for (auto tmp : _map[node]) {
        if(visit[tmp] == 0)
            func_11724_dfs(tmp, visit, _map);
    }
}

void func_11724_bfs(bool* visit, map<int, vector<int>> _map, queue<int> q) {
    int tmp_node;

    while (!q.empty()) {
        tmp_node = q.front();
        q.pop();

        for (auto tmp : _map[tmp_node]) {
            if (!visit[tmp]) {
                visit[tmp] = 1;
                q.push(tmp);
            }
        }
    }
}

void func_11724() {
    int n, m, u, v, cnt;
    queue<int> q;

    cin >> n >> m;

    map<int, vector<int>> _map;
    bool* visit = new bool[n+1];
    memset(visit, 0, sizeof(bool) * (n+1));

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        _map[u].push_back(v);
        _map[v].push_back(u);
    }

    /*cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (visit[i] == 0) {
            func_11724_dfs(i, visit, _map); 
            cnt++;
        }
    }*/

    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (visit[i] == 0) {
            q.push(i);
            visit[i] = 1;
            cnt++;
            func_11724_bfs(visit, _map, q);
        }
    }


    cout << cnt << "\n";
}


/* ���� ī�� 2 (�ǹ� 4)
*  https://www.acmicpc.net/problem/10816
*/
void func_10816() {
    int n, m, tmp;
    map<int, int> n_count;
    vector<int> vm;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        n_count[tmp]++;
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> tmp;

        cout << n_count[tmp] << " ";
        //vm.push_back(tmp);
    }
}

/* �������� ���� (�ǹ� 4)
*  https://www.acmicpc.net/problem/4949
*/
void func_4949() {
    string str, tmp, rep1 = "()", rep2="[]";
    int size;

    do {
        getline(cin, tmp);

        if (tmp == ".") {
            break;
        }

        for (int i = 0; i < tmp.length(); i++) {
            if (tmp[i] == '(' or tmp[i] == ')') {
                str += tmp[i];
            }

            if (tmp[i] == '[' or tmp[i] == ']') {
                str += tmp[i];
            }
        }
        
        //cout << "str1 : " << str1 << ", str2 : " << str2;
        size = str.length();

        for (int i = 0; i < size; i++) {
            if (str.find(rep1) != string::npos) {
                str.replace(str.find(rep1), rep1.length(), "");
            }
            if (str.find(rep2) != string::npos) {
                str.replace(str.find(rep2), rep2.length(), "");
            }
        }

        //cout << "-> str1 : " << str1 << ", str2 : " << str2 << "\n";
        if (str.length() > 0) {
            cout << "no\n";
        }
        else {
            cout << "yes\n";
        }

        str = "";
        tmp = "";
    } while (tmp != ".");
}

/* ���� (�ǹ� 4)
*  https://www.acmicpc.net/problem/10828
*/
void func_10828() {
    int n, num;
    cin >> n;

    string cmd;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        cin >> cmd;

        if (cmd == "push") {
            cin >> num;
            st.push(num);
        }
        else if (cmd == "pop") {
            if (st.empty()) {
                cout << "-1\n";
            }
            else {
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if (cmd == "top") {
            if (st.empty()) {
                cout << "-1\n";
            }
            else {
                cout << st.top() << "\n";
            }
        }
        else if (cmd == "empty") {
            if (st.empty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (cmd == "size") {
            cout << st.size() << "\n";
        }
    }

    while (!st.empty()) {
        st.pop();
    }
}

/* ť (�ǹ� 4)
*  https://www.acmicpc.net/problem/10845
*/
void func_10845() {
    int n, num;
    cin >> n;

    string cmd;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        cin >> cmd;

        if (cmd == "push") {
            cin >> num;
            q.push(num);
        }
        else if (cmd == "pop") {
            if (q.size() > 0) {
                cout << q.front() << "\n";
                q.pop();
            }
            else {
                cout << "-1\n";
            }
        }
        else if (cmd == "front") {
            if (q.size() > 0) {
                cout << q.front() << "\n";
            }
            else {
                cout << "-1\n";
            }
        }
        else if (cmd == "back") {
            if (q.size() > 0) {
                cout << q.back() << "\n";
            }
            else {
                cout << "-1\n";
            }
        }
        else if (cmd == "empty") {
            if (q.empty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (cmd == "size") {
            cout << q.size() << "\n";
        }
    }
}

/* �� (�ǹ� 4)
*  https://www.acmicpc.net/problem/10866
*/
void func_10866() {
    int n, num;
    cin >> n;

    string cmd;
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        cin >> cmd;

        if (cmd == "push_front") {
            cin >> num;
            dq.push_front(num);
        }
        else if (cmd == "push_back") {
            cin >> num;
            dq.push_back(num);
        }
        else if (cmd == "pop_front") {
            if (dq.empty()) {
                cout << "-1\n";
            }
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if (cmd == "pop_back") {
            if (dq.empty()) {
                cout << "-1\n";
            }
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if (cmd == "front") {
            if (dq.size() > 0) {
                cout << dq.front() << "\n";
            }
            else {
                cout << "-1\n";
            }
        }
        else if (cmd == "back") {
            if (dq.size() > 0) {
                cout << dq.back() << "\n";
            }
            else {
                cout << "-1\n";
            }
        }
        else if (cmd == "empty") {
            if (dq.empty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (cmd == "size") {
            cout << dq.size() << "\n";
        }
    }
}

/* ������ ť (�ǹ� 3)
*  https://www.acmicpc.net/problem/1966
*/
void func_1966() {
    int cnt, n, m, tmp, max = 0;
    queue<pair<int, int>> q; // �켱����, ���� ����(�ε���)
    vector<int> v;
    vector<pair<int, int>> res;

    cin >> cnt;
    
    for (int i = 0; i < cnt; i++) {
        cin >> n >> m;

        // �Է�
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if (tmp > max) max = tmp;
            q.push({tmp, j});
            v.push_back(tmp);
        }   

        // �μ� ������ res ����
        while(!q.empty()) {
            // ���������ϰ� �� �ڿ��� �ҷ��ͼ� pop
            sort(v.begin(), v.end());
            max = v.back();
            v.pop_back();

            // max ����ġ�� ���ö����� ť ���ġ
            while (q.front().first != max) {
                q.push(q.front());
                q.pop();
            }

            // �μ�
            res.push_back(q.front());
            q.pop();
        }

        // �ش� ���� ã��
        for (int j = 0; j < res.size(); j++) {
            if (res.at(j).second == m) {
                cout << j+1 << "\n";
                break;
            }
        }


        // Clear
        v.clear();
        res.clear();
        while (!q.empty()) {
            q.pop();
        }
    }

}

/* ���� ���� (�ǹ� 3)
*  https://www.acmicpc.net/problem/1874
*/
void func_1874() {
    int n, tmp, num_cur, flag;
    cin >> n;

    vector<int> num_v, stack_v, target_v;
    vector<char> res_v;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        target_v.push_back(tmp);
        num_v.push_back(i + 1);
    }

    reverse(num_v.begin(), num_v.end());
    
    // target_arr�� �޼��ϱ� ���� �������� 
    for (auto tmp_target : target_v) {
        //cout << "current target : " << tmp_target << " - " << num_v.size() << ", " << stack_v.size()<<"\n";
        flag = 0;

        if (num_v.size() == 0 && stack_v.size() == 0) {
            res_v.clear();
            break;
        }

        // ���� Ÿ���� Stack�� top�� ������ -�ϰ� ���� �ɷ�
        if (!stack_v.empty()) {
            if (tmp_target == stack_v.back()) {
                stack_v.pop_back();
                res_v.push_back('-');
                flag = 1;
                continue;
            }
        }

        while (true) {
            // num_v �� ������� ������ �ϳ��� stack�� �߰�
            if (!num_v.empty()) {
                num_cur = num_v.back();
                stack_v.push_back(num_cur);
                res_v.push_back('+');
                num_v.pop_back();

                // target�� num���� �����°� ������ Ż��
                if (tmp_target == num_cur) {
                    stack_v.pop_back();
                    res_v.push_back('-');
                    flag = 1;
                    break;
                }
                // �ٸ��� ���� �� ���� ��� �߰�
            }
            // num_v�� ��������� (�� �̻� ������ �� ������)
            else {

                if (stack_v.empty())
                    break;

                // ���ÿ��� ã��
                while (!stack_v.empty()) {
                    // stack back�� target�̶� ������
                    if (tmp_target == stack_v.back()) {
                        stack_v.pop_back();
                        res_v.push_back('-');
                        flag = 1;
                        break;
                    }
                    // �ٸ��� �� pop�ϰ� ��
                    else {
                        stack_v.pop_back();
                    }
                }

                // ���� �� ���� ��ã������ NO
                if (!flag) {
                    res_v.clear();
                    break;
                }
            }
        }
        //cout << "target end\n";
    }

    if (res_v.empty()) {
        cout << "NO\n";
    }
    else {
        for (auto tmp_res : res_v) {
            cout << tmp_res << "\n";
        }
    }

}

/* ���� �ڸ��� (�ǹ� 3)
*  https://www.acmicpc.net/problem/1654
*/
void func_1654() {
    unsigned int n, k, right = 0, left = 1, mid, sum, max=0;

    cin >> n >> k;

    unsigned int * arr = new unsigned int[n];

    // �Է�
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] > right) {
            right = arr[i];
        }
    }

    // �̺� Ž��
    while (left <= right) {
        mid = ((right + left) / 2);
        sum = 0;
        //cout << mid << "\n";

        for (int i = 0; i < n; i++) {
            // ������ ������ ����� ��
            sum += (int)(arr[i] / mid);
        }
        //cout << mid << "\n";

        if (sum >= k) {
            left = mid + 1;
        }

        if (sum < k) {
            right = mid - 1;
        }

    }

    cout << right << "\n";
    
}

/* ���� �ڸ��� (�ǹ� 3)
*  https://www.acmicpc.net/problem/2805
*/
void func_2805() {
    long long n, m, right = 0, left = 1, h, sum;

    cin >> n >> m;

    long long * namu_arr = new long long[n];
    
    // �Է�
    for (long long i = 0; i < n; i++) {
        cin >> namu_arr[i];

        // �Է� ���� ������ �ִ� ���� Right�� ����
        if (namu_arr[i] > right) {
            right = namu_arr[i];
        }
    }

    // �̺� Ž��
    while (left <= right) {
        h = ((right + left) / 2);
        sum = 0;


        for (long long i = 0; i < n; i++) {
            if (namu_arr[i] > h) {
                sum += (namu_arr[i] - h); 
            }
        }
        // cout << "right : " << right << ", left : " << left << ", h : " << h << ", sum : " << sum << ", m : " << m << "\n";

        if (sum >= m) {
            left = h + 1;
        }

        if (sum < m) {
            right = h - 1;
        }

    }

    cout << right << "\n";

}