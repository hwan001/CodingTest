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

/* 1�� ����� (�ǹ� 3)
*  https://www.acmicpc.net/problem/1463
*/
