#include "header.h"

/* k��° �Ҽ� (�ǹ� 2, �Ҽ� ����)
 * https://www.acmicpc.net/problem/15965
 */
void func_15965()
{
    int a, max = 500000000, sum = 0;
    bool *arr = Sieve_of_Eratosthenes(max);
    cin >> a;

    for (int i = 0; i <= max; i++)
    {
        sum += arr[i];
        // cout << i << " " << sum << endl;
        if (sum == a + 1)
        {
            cout << i << endl;
            break;
        }
    }
}

/* ����� (�ǹ� 3)
 * https://www.acmicpc.net/problem/1004
 */

bool func_1004_isInCircle(pair<int, int> coord, int c1, int c2, int r)
{
    if (pow(coord.first - c1, 2) + pow(coord.second - c2, 2) <= (r * r))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void func_1004()
{
    int test_case, n, cnt;
    int x, y, r;

    pair<int, int> start_coord, end_cood;

    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        cnt = 0;
        cin >> start_coord.first >> start_coord.second >> end_cood.first >> end_cood.second;
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            cin >> x >> y >> r;

            // �Ѵ� ���� ���ȿ� ��������� ī��Ʈ ����
            if (func_1004_isInCircle(start_coord, x, y, r) && func_1004_isInCircle(end_cood, x, y, r))
            {
                continue;
            }

            if (func_1004_isInCircle(start_coord, x, y, r) || func_1004_isInCircle(end_cood, x, y, r))
            {

                cnt++;
            }
        }

        cout << cnt << "\n";
    }
}

/* ���ٲ��� (�ǹ� 1)
 * https://www.acmicpc.net/problem/1697
 */
void func_1697_bfs(int k, queue<int> q, int *visited)
{
    int now;

    while (!q.empty())
    {
        now = q.front();
        q.pop();

        // cout << "now : " << now << ", visited : " << visited[now] << "\n";

        if (now == k)
        {
            break;
        }

        if (visited[now - 1] == 0 && (now - 1) >= 0)
        {
            visited[now - 1] = visited[now] + 1;
            q.push(now - 1);
        }

        if ((now + 1) < 100000 && visited[now + 1] == 0)
        {
            visited[now + 1] = visited[now] + 1;
            q.push(now + 1);
        }

        if ((now * 2) <= 100000 && visited[now * 2] == 0)
        {
            visited[now * 2] = visited[now] + 1;
            q.push(now * 2);
        }
    }
}

void func_1697()
{
    int n, k;
    cin >> n >> k;
    int *visited = new int[100000];
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
void func_2164()
{
    queue<int> q;
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (q.size() > 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front() << "\n";
}

/*�似Ǫ�� ���� (�ǹ� 4)
 * https://www.acmicpc.net/problem/11866
 */
void func_11866()
{
    int n, k, cnt;
    queue<int> q;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        q.push(i + 1);
    }

    cout << "<";
    cnt = 1;
    while (!q.empty())
    {
        if (cnt % k != 0)
        {
            q.push(q.front());
            q.pop();
            cnt++;
        }
        else
        {
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
void func_18111_v1()
{
    int n, m, inventory, height, time = 0;
    double sum = 0;

    cin >> n >> m >> inventory;

    // �� �Է�
    int **map = new int *[n];
    for (int i = 0; i < n; i++)
    {
        map[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            sum += map[i][j];
        }
    }

    // ��ü ���� ���� (�κ��丮 ����)
    if (inventory > 0)
    {
        height = round(sum / (n * m));
    }
    else
    {
        height = floor(sum / (n * m));
    }

    // �� �ٵ��
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == height)
                continue;

            if (map[i][j] > height)
            {
                while (map[i][j] != height)
                {
                    time += 2;
                    map[i][j] -= 1;
                    inventory++;
                }
            }
            else
            {
                while (map[i][j] != height)
                {
                    time += 1;
                    map[i][j] += 1;
                    inventory--;
                }
            }
        }
    }

    cout << time << " " << height << "\n";
}

int func_18111_getTime(int height, int n, int m, int inventory, int **map)
{
    int time = 0, tmp_map;
    bool flag = true;

    cout << "height : " << height << ", inven : " << inventory << " -> ";

    // ���� ȸ�� (���� ���߱�)
    for (int i = 0; i < n && flag; i++)
    {
        for (int j = 0; j < m && flag; j++)
        {
            tmp_map = map[i][j];
            // cout << tmp_map << " ";

            if (tmp_map == height)
                continue;

            // ������ ȸ��
            if (tmp_map > height)
            {
                while (tmp_map != height)
                {
                    time += 2;
                    tmp_map -= 1;
                    inventory++;
                }
            }
        }
    }

    // ���� ��ġ (���� ���̱�) - �����ϸ� flag == false
    for (int i = 0; i < n && flag; i++)
    {
        for (int j = 0; j < m && flag; j++)
        {
            tmp_map = map[i][j];
            // cout << tmp_map << " ";

            if (tmp_map == height)
                continue;

            if (tmp_map < height)
            {
                while (tmp_map != height)
                {
                    if (inventory > 0)
                    {
                        inventory--;
                    }
                    else
                    {
                        flag = false;
                    }

                    if (!flag)
                        break;

                    time += 1;
                    tmp_map += 1;
                }

                if (!flag || tmp_map != height)
                {
                    flag = false;
                    cout << " inventory empty ";
                    break;
                }
            }
        }
    }

    if (!flag)
    {
        time = 0;
    }

    cout << "time : " << time << "\n";
    return time;
}

void func_18111_v3()
{
    int n, m, inventory, height = -1, time = 0, tmp, min = 2100000000, max = 0;
    double sum = 0;

    cin >> n >> m >> inventory;

    // �� �Է�
    int **map = new int *[n];
    for (int i = 0; i < n; i++)
    {
        map[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            // sum += map[i][j];
            if (max < map[i][j])
            {
                max = map[i][j];
            }
        }
    }

    for (int i = 0; i <= max; i++)
    {
        tmp = func_18111_getTime(i, n, m, inventory, map);
        // cout << " �߰���� :  " << tmp << ", " << min;

        if (min >= tmp && tmp > 0)
        {
            // cout << "- find \n";
            //  ������ �ð��� �ִٸ� ���̰� ���� �� ����
            if (min == tmp && height > i)
                continue;

            min = tmp;
            height = i;
        }
        else
        {
            // cout << "\n";
        }
    }

    if (min == 2100000000 || height == -1)
    {
        min = 0;
        height = 0;
    }

    cout << min << " " << height << "\n";
}

void func_18111()
{
    int n, m, inventory, min = 2100000000, max = 0;
    int height = -1, time = 0, tmp_block, time_min = 2100000000;
    double sum = 0;

    cin >> n >> m >> inventory;

    // �� �Է�
    int **map = new int *[n];
    for (int i = 0; i < n; i++)
    {
        map[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            if (max < map[i][j])
            {
                max = map[i][j];
            }

            if (min > map[i][j])
            {
                min = map[i][j];
            }
        }
    }

    // cout << "min : " << min << ", max : " << max << "\n";

    int build_block, remove_block;

    // ���� �ּ� ���� ���̺��� ���� ���� ���ϱ��� �ݺ�
    for (int h = min; h <= max; h++)
    {
        build_block = 0;
        remove_block = 0;

        // h������ ȸ���� ����, ��ġ�� ���� ���� ���ϱ�
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                tmp_block = map[i][j];

                // ���� ������ h���� ������ ��ġ�� ���� ���� ����
                if (h > tmp_block)
                {
                    build_block += h - tmp_block;
                }

                // ���� ������ h ���� ������ ȸ���� ���� ���� ����
                if (h < tmp_block)
                {
                    remove_block += tmp_block - h;
                }
            }
        }

        // cout << "h : " << h << ", build_block : " << build_block << ", remove_block : " << remove_block << " ";

        // ��ġ�� ���� ������ �κ��丮�� ȸ���� �������պ��� �������� �˻�
        if (build_block <= remove_block + inventory)
        {
            // �ð� ����ϱ�
            time = remove_block * 2 + build_block;

            // ����� �ð��� �ּ� ���̸� ���
            if (time_min >= time)
            {
                // ����� �ð��� �ּ� ������ �۰ų� ����, ���̰� h���� ������ ���
                if (height > h)
                    continue;
                time_min = time;
                height = h;
                // cout << "-> " << height << ", time_min : " << time_min << "";
            }
        }

        // cout << "\n";
    }

    cout << time_min << " " << height << "\n";
}

/* ���� (�ǹ� 4)
 *  https://www.acmicpc.net/problem/10773
 */
void func_10773()
{
    int test_case, tmp, sum = 0;
    cin >> test_case;

    stack<int> stack_zero;

    for (int i = 0; i < test_case; i++)
    {
        cin >> tmp;
        if (tmp == 0)
        {
            stack_zero.pop();
        }
        else
        {
            stack_zero.push(tmp);
        }
    }

    while (!stack_zero.empty())
    {
        sum += stack_zero.top();
        stack_zero.pop();
    }

    cout << sum << "\n";
}

/* �ִ������� �ּҰ���� (�ǹ� 5)
 *  https://www.acmicpc.net/problem/2609
 */
int func_2609_gcd(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return func_2609_gcd(b, a % b);
    }
}

int func_2609_lcm(int a, int b)
{
    return (a * b) / func_2609_gcd(a, b);
}

void func_2609()
{
    int a, b;
    cin >> a >> b;

    cout << func_2609_gcd(a, b) << "\n";
    cout << func_2609_lcm(a, b) << "\n";
}

/* ��ȣ (�ǹ� 4)
 *  https://www.acmicpc.net/problem/9012
 */
void func_9012()
{
    int test_case;
    cin >> test_case;

    string str;
    map<char, int> m;
    vector<char> v;
    bool flag;
    int count;

    for (int i = 0; i < test_case; i++)
    {
        m.clear();
        v.clear();

        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            m[str[j]]++;
            v.push_back(str[j]);
        }

        if (m['('] == m[')'])
        {
            count = 0;
            flag = false;
            // cout << "same\n";
            //  �������¸� +1, ���� ���¸� -1, ���� 0���� �۾����� no, �ٵ��Ҵµ� 0�� �ƴϸ� no
            for (auto v_tmp : v)
            {
                // cout << v_tmp << ", " << count << "\n";
                if (v_tmp == '(')
                {
                    count++;
                }
                if (v_tmp == ')')
                {
                    count--;
                }
                if (count < 0)
                {
                    flag = true;
                    break;
                }
            }

            if (!flag && count == 0)
            {
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
void func_18258()
{
    int n, num;
    cin >> n;

    string cmd;
    queue<int> q;

    for (int i = 0; i <= n; i++)
    {
        cin >> cmd;

        if (cmd == "push")
        {
            cin >> num;
            q.push(num);
        }
        else if (cmd == "pop")
        {
            if (q.size() > 0)
            {
                cout << q.front() << "\n";
                q.pop();
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (cmd == "front")
        {
            if (q.size() > 0)
            {
                cout << q.front() << "\n";
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (cmd == "back")
        {
            if (q.size() > 0)
            {
                cout << q.back() << "\n";
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (cmd == "empty")
        {
            if (q.empty())
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (cmd == "size")
        {
            cout << q.size() << "\n";
        }
    }
}

/* 1�� ����� (�ǹ� 3)
 *  https://www.acmicpc.net/problem/1463
 */
void func_1463()
{
    int min, num;

    cin >> num;

    int *dp = new int[num + 2];
    memset(dp, 0, sizeof(int) * (num + 2));

    for (int i = 2; i <= num; i++)
    {
        dp[i]++;
        min = 0;

        if (min > dp[i - 1] || min == 0)
            min = dp[i - 1];

        if (i % 2 == 0)
        {
            if (min > dp[i / 2])
                min = dp[i / 2];
        }

        if (i % 3 == 0)
        {
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

int func_1920_isExist(int find_value)
{
    int res = 0;
    int start_index = 0, end_index = func_1920_An.size();
    int index = (int)floor((start_index + end_index) / 2);

    while (start_index < end_index)
    {
        // ������ Ż��
        if (find_value == func_1920_An.at(index))
        {
            res = 1;
            // cout << "start : " << start_index << ", end : " << end_index << ", index : " << index << ", value : " << v.at(index) << "\n";
            break;
        }

        if (start_index == index)
        {
            break;
        }

        // ã�� ���� ���� �ε��� �� ���� ũ�� start�� �����ε����� �ʱ�ȭ
        if (find_value > func_1920_An.at(index))
        {
            start_index = index;
        }

        // ������ end�� index�� �ʱ�ȭ
        if (find_value < func_1920_An.at(index))
        {
            end_index = index;
        }

        // �ε��� ����
        index = (int)floor((start_index + end_index) / 2);

        // cout << "start : " << start_index << ", end : " << end_index << ", index : " << index << ", value : " << v.at(index) << "\n";
    }

    return res;
}

void func_1920()
{
    int n, m, tmp;
    vector<int> Am;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // An �ޱ�
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        func_1920_An.push_back(tmp);
    }

    sort(func_1920_An.begin(), func_1920_An.end());

    // Am �ޱ�
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        Am.push_back(tmp);
    }

    // ã��
    for (auto m_tmp : Am)
    {
        cout << func_1920_isExist(m_tmp) << "\n";
    }
}

/* ���� ���� (�ǹ� 2)
 *  https://www.acmicpc.net/problem/4963
 */

void func_4963()
{
    int w = 1, h = 1;
    queue<pair<int, int>> q;
    int direc[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    int visit_value, _x, _y;
    pair<int, int> front;

    while (true)
    {
        cin >> w >> h;

        if (w + h == 0)
            break;

        int **_map = new int *[h];
        int **visit = new int *[h];
        for (int i = 0; i < h; i++)
        {
            _map[i] = new int[w];
            visit[i] = new int[w];
            memset(visit[i], 0, sizeof(int) * w);
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> _map[i][j];
            }
        }

        visit_value = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (visit[i][j] == 0 && _map[i][j] == 1)
                {
                    q.push({i, j});
                    visit[i][j] = ++visit_value;
                }

                // bfs
                while (!q.empty())
                {
                    front = q.front();
                    q.pop();

                    // �ð�������� 8���� ����
                    for (int i = 0; i < 8; i++)
                    {
                        _x = front.first + direc[i][0];
                        _y = front.second + direc[i][1];

                        if (_x >= h || _x < 0)
                        {
                            continue;
                        }

                        if (_y >= w || _y < 0)
                        {
                            continue;
                        }

                        if (visit[_x][_y] != 0)
                        {
                            continue;
                        }

                        if (_map[_x][_y] != 1)
                        {
                            continue;
                        }

                        visit[_x][_y] = visit_value;
                        q.push({_x, _y});
                    }
                }
            }
        }

        cout << visit_value << "\n";

        while (!q.empty())
        {
            q.pop();
        }

        for (int i = 0; i < h; i++)
        {
            delete (_map[i]);
            delete (visit[i]);
        }
    }
}

/* 2 * N Ÿ�ϸ� (�ǹ� 2)
 *  https://www.acmicpc.net/problem/11726
 */
void func_11726()
{
    int n;
    cin >> n;

    int *dp = new int[n + 1];
    dp[0] = 0;

    if (n > 0)
    {
        dp[1] = 1;
    }

    if (n > 1)
    {
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
        }
    }

    cout << dp[n] << "\n";
}

/* ���� ����� ���� (�ǹ� 2)
 *  https://www.acmicpc.net/problem/11724
 */

// dfs �޸� �ʰ�
void func_11724_dfs(int node, bool *visit, map<int, vector<int>> _map)
{
    visit[node] = true;

    for (auto tmp : _map[node])
    {
        if (visit[tmp] == 0)
            func_11724_dfs(tmp, visit, _map);
    }
}

void func_11724_bfs(bool *visit, map<int, vector<int>> _map, queue<int> q)
{
    int tmp_node;

    while (!q.empty())
    {
        tmp_node = q.front();
        q.pop();

        for (auto tmp : _map[tmp_node])
        {
            if (!visit[tmp])
            {
                visit[tmp] = 1;
                q.push(tmp);
            }
        }
    }
}

void func_11724()
{
    int n, m, u, v, cnt;
    queue<int> q;

    cin >> n >> m;

    map<int, vector<int>> _map;
    bool *visit = new bool[n + 1];
    memset(visit, 0, sizeof(bool) * (n + 1));

    for (int i = 0; i < m; i++)
    {
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
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == 0)
        {
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
void func_10816()
{
    int n, m, tmp;
    map<int, int> n_count;
    vector<int> vm;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        n_count[tmp]++;
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> tmp;

        cout << n_count[tmp] << " ";
        // vm.push_back(tmp);
    }
}

/* �������� ���� (�ǹ� 4)
 *  https://www.acmicpc.net/problem/4949
 */
void func_4949()
{
    string str, tmp, rep1 = "()", rep2 = "[]";
    int size;

    do
    {
        getline(cin, tmp);

        if (tmp == ".")
        {
            break;
        }

        for (int i = 0; i < tmp.length(); i++)
        {
            if (tmp[i] == '(' or tmp[i] == ')')
            {
                str += tmp[i];
            }

            if (tmp[i] == '[' or tmp[i] == ']')
            {
                str += tmp[i];
            }
        }

        // cout << "str1 : " << str1 << ", str2 : " << str2;
        size = str.length();

        for (int i = 0; i < size; i++)
        {
            if (str.find(rep1) != string::npos)
            {
                str.replace(str.find(rep1), rep1.length(), "");
            }
            if (str.find(rep2) != string::npos)
            {
                str.replace(str.find(rep2), rep2.length(), "");
            }
        }

        // cout << "-> str1 : " << str1 << ", str2 : " << str2 << "\n";
        if (str.length() > 0)
        {
            cout << "no\n";
        }
        else
        {
            cout << "yes\n";
        }

        str = "";
        tmp = "";
    } while (tmp != ".");
}

/* ���� (�ǹ� 4)
 *  https://www.acmicpc.net/problem/10828
 */
void func_10828()
{
    int n, num;
    cin >> n;

    string cmd;
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        cin >> cmd;

        if (cmd == "push")
        {
            cin >> num;
            st.push(num);
        }
        else if (cmd == "pop")
        {
            if (st.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if (cmd == "top")
        {
            if (st.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << st.top() << "\n";
            }
        }
        else if (cmd == "empty")
        {
            if (st.empty())
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (cmd == "size")
        {
            cout << st.size() << "\n";
        }
    }

    while (!st.empty())
    {
        st.pop();
    }
}

/* ť (�ǹ� 4)
 *  https://www.acmicpc.net/problem/10845
 */
void func_10845()
{
    int n, num;
    cin >> n;

    string cmd;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        cin >> cmd;

        if (cmd == "push")
        {
            cin >> num;
            q.push(num);
        }
        else if (cmd == "pop")
        {
            if (q.size() > 0)
            {
                cout << q.front() << "\n";
                q.pop();
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (cmd == "front")
        {
            if (q.size() > 0)
            {
                cout << q.front() << "\n";
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (cmd == "back")
        {
            if (q.size() > 0)
            {
                cout << q.back() << "\n";
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (cmd == "empty")
        {
            if (q.empty())
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (cmd == "size")
        {
            cout << q.size() << "\n";
        }
    }
}

/* �� (�ǹ� 4)
 *  https://www.acmicpc.net/problem/10866
 */
void func_10866()
{
    int n, num;
    cin >> n;

    string cmd;
    deque<int> dq;

    for (int i = 0; i < n; i++)
    {
        cin >> cmd;

        if (cmd == "push_front")
        {
            cin >> num;
            dq.push_front(num);
        }
        else if (cmd == "push_back")
        {
            cin >> num;
            dq.push_back(num);
        }
        else if (cmd == "pop_front")
        {
            if (dq.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if (cmd == "pop_back")
        {
            if (dq.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if (cmd == "front")
        {
            if (dq.size() > 0)
            {
                cout << dq.front() << "\n";
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (cmd == "back")
        {
            if (dq.size() > 0)
            {
                cout << dq.back() << "\n";
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (cmd == "empty")
        {
            if (dq.empty())
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (cmd == "size")
        {
            cout << dq.size() << "\n";
        }
    }
}

/* ������ ť (�ǹ� 3)
 *  https://www.acmicpc.net/problem/1966
 */
void func_1966()
{
    int cnt, n, m, tmp, max = 0;
    queue<pair<int, int>> q; // �켱����, ���� ����(�ε���)
    vector<int> v;
    vector<pair<int, int>> res;

    cin >> cnt;

    for (int i = 0; i < cnt; i++)
    {
        cin >> n >> m;

        // �Է�
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            if (tmp > max)
                max = tmp;
            q.push({tmp, j});
            v.push_back(tmp);
        }

        // �μ� ������ res ����
        while (!q.empty())
        {
            // ���������ϰ� �� �ڿ��� �ҷ��ͼ� pop
            sort(v.begin(), v.end());
            max = v.back();
            v.pop_back();

            // max ����ġ�� ���ö����� ť ���ġ
            while (q.front().first != max)
            {
                q.push(q.front());
                q.pop();
            }

            // �μ�
            res.push_back(q.front());
            q.pop();
        }

        // �ش� ���� ã��
        for (int j = 0; j < res.size(); j++)
        {
            if (res.at(j).second == m)
            {
                cout << j + 1 << "\n";
                break;
            }
        }

        // Clear
        v.clear();
        res.clear();
        while (!q.empty())
        {
            q.pop();
        }
    }
}

/* ���� ���� (�ǹ� 3)
 *  https://www.acmicpc.net/problem/1874
 */
void func_1874()
{
    int n, tmp, num_cur, flag;
    cin >> n;

    vector<int> num_v, stack_v, target_v;
    vector<char> res_v;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        target_v.push_back(tmp);
        num_v.push_back(i + 1);
    }

    reverse(num_v.begin(), num_v.end());

    // target_arr�� �޼��ϱ� ���� ��������
    for (auto tmp_target : target_v)
    {
        // cout << "current target : " << tmp_target << " - " << num_v.size() << ", " << stack_v.size()<<"\n";
        flag = 0;

        if (num_v.size() == 0 && stack_v.size() == 0)
        {
            res_v.clear();
            break;
        }

        // ���� Ÿ���� Stack�� top�� ������ -�ϰ� ���� �ɷ�
        if (!stack_v.empty())
        {
            if (tmp_target == stack_v.back())
            {
                stack_v.pop_back();
                res_v.push_back('-');
                flag = 1;
                continue;
            }
        }

        while (true)
        {
            // num_v �� ������� ������ �ϳ��� stack�� �߰�
            if (!num_v.empty())
            {
                num_cur = num_v.back();
                stack_v.push_back(num_cur);
                res_v.push_back('+');
                num_v.pop_back();

                // target�� num���� �����°� ������ Ż��
                if (tmp_target == num_cur)
                {
                    stack_v.pop_back();
                    res_v.push_back('-');
                    flag = 1;
                    break;
                }
                // �ٸ��� ���� �� ���� ��� �߰�
            }
            // num_v�� ��������� (�� �̻� ������ �� ������)
            else
            {

                if (stack_v.empty())
                    break;

                // ���ÿ��� ã��
                while (!stack_v.empty())
                {
                    // stack back�� target�̶� ������
                    if (tmp_target == stack_v.back())
                    {
                        stack_v.pop_back();
                        res_v.push_back('-');
                        flag = 1;
                        break;
                    }
                    // �ٸ��� �� pop�ϰ� ��
                    else
                    {
                        stack_v.pop_back();
                    }
                }

                // ���� �� ���� ��ã������ NO
                if (!flag)
                {
                    res_v.clear();
                    break;
                }
            }
        }
        // cout << "target end\n";
    }

    if (res_v.empty())
    {
        cout << "NO\n";
    }
    else
    {
        for (auto tmp_res : res_v)
        {
            cout << tmp_res << "\n";
        }
    }
}

/* ���� �ڸ��� (�ǹ� 3)
 *  https://www.acmicpc.net/problem/1654
 */
void func_1654()
{
    unsigned int n, k, right = 0, left = 1, mid, sum, max = 0;

    cin >> n >> k;

    unsigned int *arr = new unsigned int[n];

    // �Է�
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] > right)
        {
            right = arr[i];
        }
    }

    // �̺� Ž��
    while (left <= right)
    {
        mid = ((right + left) / 2);
        sum = 0;
        // cout << mid << "\n";

        for (int i = 0; i < n; i++)
        {
            // ������ ������ ����� ��
            sum += (int)(arr[i] / mid);
        }
        // cout << mid << "\n";

        if (sum >= k)
        {
            left = mid + 1;
        }

        if (sum < k)
        {
            right = mid - 1;
        }
    }

    cout << right << "\n";
}

/* ���� �ڸ��� (�ǹ� 3)
 *  https://www.acmicpc.net/problem/2805
 */
void func_2805()
{
    long long n, m, right = 0, left = 1, h, sum;

    cin >> n >> m;

    long long *namu_arr = new long long[n];

    // �Է�
    for (long long i = 0; i < n; i++)
    {
        cin >> namu_arr[i];

        // �Է� ���� ������ �ִ� ���� Right�� ����
        if (namu_arr[i] > right)
        {
            right = namu_arr[i];
        }
    }

    // �̺� Ž��
    while (left <= right)
    {
        h = ((right + left) / 2);
        sum = 0;

        for (long long i = 0; i < n; i++)
        {
            if (namu_arr[i] > h)
            {
                sum += (namu_arr[i] - h);
            }
        }
        // cout << "right : " << right << ", left : " << left << ", h : " << h << ", sum : " << sum << ", m : " << m << "\n";

        if (sum >= m)
        {
            left = h + 1;
        }

        if (sum < m)
        {
            right = h - 1;
        }
    }

    cout << right << "\n";
}

/* Contact (�ǹ� 1)
 *  https://www.acmicpc.net/problem/1013
 */
void func_1013()
{
    long long n, m, right = 0, left = 1, h, sum;

    cin >> n >> m;
    // (100+1+ | 01)+
}

/* �׸� (�ǹ� 1)
 *  https://www.acmicpc.net/problem/1926
 */
void func_1926()
{
    int n, m;

    cin >> n >> m;

    int **_map = new int *[n];
    int **_visit = new int *[n];

    for (int i = 0; i < n; i++)
    {
        _map[i] = new int[m];
        _visit[i] = new int[m];
        memset(_visit[i], 0, sizeof(int) * m);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> _map[i][j];
        }
    }

    // bfs
    queue<pair<int, int>> _q;
    pair<int, int> tmp_pair;
    int direct[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int _x, _y, cnt_map = 0, _max = 0, map_size;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (_visit[i][j] == 0 && _map[i][j] == 1)
            {
                cnt_map++;
                map_size = 0;
                _visit[i][j] = 1;
                _q.push({i, j});

                while (!_q.empty())
                {
                    tmp_pair = _q.front();
                    _q.pop();
                    map_size++;

                    for (int i = 0; i < 4; i++)
                    {
                        _x = tmp_pair.first + direct[i][0];
                        _y = tmp_pair.second + direct[i][1];

                        // ������ ����� pass
                        if (_x < 0 || _x >= n || _y < 0 || _y >= m)
                            continue;

                        // 0 >�� pass
                        if (_map[_x][_y] == 0)
                            continue;

                        // �湮������ pass
                        if (_visit[_x][_y] > 0)
                            continue;

                        _visit[_x][_y] = _visit[tmp_pair.first][tmp_pair.second] + 1;

                        _q.push({_x, _y});
                    }
                }

                if (_max < map_size)
                {
                    _max = map_size;
                }
            }
        }
    }

    cout << cnt_map << ", " << _max;
}

/* �л�ó�� (����� 3)
 * https://www.acmicpc.net/problem/1009
 */
int func_1009_mod(int a, int b)
{
    vector<int> tmp, tmp2;
    int *x;
    ll res = 1;

    while (b != 0)
    {
        tmp.push_back(b % 2);
        b /= 2;
    }

    x = new int[21];
    x[0] = a % 10;
    for (int j = 1; j <= 20; j++)
    {
        x[j] = (x[j - 1] * x[j - 1]) % 10;
    }

    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp.at(i) == 1)
        {
            res *= x[i];
        }
    }

    if (res % 10 == 0)
        res = 10;
    else
        res %= 10;

    return res;
}

void func_1009()
{
    int n, a, b;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        cout << func_1009_mod(a, b);
    }
}

/* ������ (����� 5)
 * https://www.acmicpc.net/problem/2475
 */
void func_2475()
{
    vector<int> input;
    input.clear();
    int a;

    for (int i = 0; i < 5; i++)
    {
        cin >> a;
        input.push_back(a * a);
    }

    cout << accumulate(input.begin(), input.end(), 0) % 10;
}

/* ���� (����� 2)
 * https://www.acmicpc.net/problem/2920
 */
void func_2920()
{
    vector<int> input;
    int a;

    for (int i = 0; i < 8; i++)
    {
        cin >> a;
        input.push_back(a);
    }

    vector<int> cp_sort(input);
    sort(cp_sort.begin(), cp_sort.end());

    vector<int> cp_reverse(cp_sort);
    reverse(cp_reverse.begin(), cp_reverse.end());

    if (input == cp_sort)
        cout << "ascending\n";
    else if (input == cp_reverse)
        cout << "descending\n";
    else
        cout << "mixed\n";
}

/* �Ӹ���Ҽ� (����� 1)
 * https://www.acmicpc.net/problem/1259
 */
void func_1259()
{
    string a;
    int len, tmp_left, tmp_right;
    bool flag;

    while (1)
    {
        cin >> a;

        flag = false;

        if (stoi(a) == 0)
            break;

        len = a.length();
        tmp_right = ceil(len / 2);
        if (len % 2 == 0)
        {
            tmp_left = tmp_right - 1;
        }
        else
        {
            tmp_left = tmp_right;
        }

        for (int i = 0; i < len; i++)
        {
            if (tmp_left < 0)
                break;

            if (tmp_right >= len)
                break;

            if (a[tmp_left] != a[tmp_right])
            {
                flag = false;
                break;
            }

            if (a[tmp_left] == a[tmp_right])
            {
                flag = true;
            }

            tmp_left--;
            tmp_right++;
        }

        if (flag)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}

/* ���� ��� (����� 1)
 * https://www.acmicpc.net/problem/11050
 */
int func_11050_factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * func_11050_factorial(n - 1);
}

void func_11050()
{
    int n, k;
    cin >> n >> k;

    cout << func_11050_factorial(n) / (func_11050_factorial(n - k) * func_11050_factorial(k));
}

/* Hashing (����� 2)
 * https://www.acmicpc.net/problem/15829
 */
void func_15829_50()
{
    int str_len;
    cin >> str_len;
    string str;
    cin >> str;

    int a, r = 31, M = 1234567891;
    ll sum = 0;

    for (int i = 0; i < str_len; i++)
    {
        a = (str[i] - 'a') + 1;
        sum += a * pow(r, i);
    }

    cout << sum % M << "\n";
}

void func_15829()
{
    int str_len;
    cin >> str_len;

    string str;
    cin >> str;

    ll r, sum = 0, a;
    int M = 1234567891;

    for (int i = 0; i < str_len; i++)
    {
        a = (str[i] - 'a') + 1;

        r = 1;
        for (int j = 0; j < i; j++)
        {
            r *= 31;
            r %= M;
        }

        sum += a * r;
        sum %= M;
    }

    cout << sum;
}

/* ���� ������Ʈ (����� 1)
 *  https://www.acmicpc.net/problem/1032
 */
void func_1032()
{
    int test_case, cnt;
    string tmp, res = "";
    vector<string> v;

    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    tmp = v.at(0);
    for (int i = 0; i < tmp.length(); i++)
    {
        cnt = 0;

        for (int j = 0; j < test_case; j++)
        {
            if (v.at(j)[i] == tmp[i])
            {
                cnt++;
            }
        }

        if (cnt == test_case)
        {
            res += tmp[i];
        }
        else
        {
            res += "?";
        }
    }

    cout << res << "\n";
}

/* å ������ (��� 1)
 * https://www.acmicpc.net/problem/1019
 */
void func_1019_v1()
{
    int n, a;
    string str_n;
    string str_page;
    map<char, int> m;
    cin >> a;
    cin >> n;

    str_n = to_string(n);

    for (int i = 0; i < 9; i++)
        m['0' + i] = 0;

    for (int page = a; page <= n; page++)
    {
        str_page = to_string(page);
        for (int j = 0; j < str_page.length(); j++)
        {
            m[str_page[j]]++;
        }
    }

    for (auto m_tmp : m)
    {
        cout << m_tmp.second << " ";
    }
}

void func_1019_sub(map<char, int> m, int n, vector<pair<int, int>> v)
{
    string str_n, str_page;
    str_n = to_string(n);
    int a = (pow(10, str_n.length()) - 1);
    cout << n << " ~ " << a << "\n";

    // �̸� ���Ȱ� ���ϱ�
    m['0'] += v[str_n.length() - 2].first;
    for (int i = 1; i <= 9; i++)
    {
        m['0' + i] += v[str_n.length() - 2].second;
    }

    // �ش� ���ں��� ����
    for (int page = a; page > n; page--)
    {
        str_page = to_string(page);
        for (int j = 0; j < str_page.length(); j++)
        {
            m[str_page[j]]--;
        }
    }

    for (auto m_tmp : m)
    {
        cout << m_tmp.second << " ";
    }
}

void func_1019_sum(map<char, int> m, int n, vector<pair<int, int>> v)
{
    string str_n, str_page;
    str_n = to_string(n);
    int a = (pow(10, str_n.length() - 1) - 1);
    cout << a << " ~ " << n << "\n";

    // �̸� ���Ȱ� ���ϱ�
    m['0'] += v[str_n.length() - 2].first;
    for (int i = 1; i <= 9; i++)
    {
        m['0' + i] += v[str_n.length() - 2].second;
    }

    for (int page = a + 1; page <= n; page++)
    {
        str_page = to_string(page);
        for (int j = 0; j < str_page.length(); j++)
        {
            m[str_page[j]]++;
        }
    }

    for (auto m_tmp : m)
    {
        cout << m_tmp.second << " ";
    }
}

void func_1019_v2()
{
    int n, tmp_first, tmp_second;
    string str_n;
    map<char, int> m;
    vector<pair<int, int>> v_dp;

    cin >> n;
    str_n = to_string(n);

    // �ʱ�ȭ
    for (int i = 0; i < 9; i++)
        m['0' + i] = 0;

    // ���ذ�
    v_dp.push_back({0, 1});
    for (int i = 1; i < 9; i++)
    {
        tmp_first = 9 * v_dp[i - 1].second + v_dp[i - 1].first;
        tmp_second = tmp_first + v_dp[i - 1].second + pow(10, i) - v_dp[i - 1].first;

        v_dp.push_back({tmp_first, tmp_second});
        cout << "pair (" << i << ") : " << tmp_first << ", " << tmp_second << "\n";
    }

    // �Ǵ�
    if (abs(n - (pow(10, str_n.length() - 1) - 1) <= abs(n - (pow(10, str_n.length()) - 1))))
    {
        func_1019_sum(m, n, v_dp);
    }
    else
    {
        func_1019_sub(m, n, v_dp);
    }
}

void calc_1019(long long n, long long point, long long *count_1019)
{
    while (n > 0)
    {
        count_1019[n % 10] += point;
        n /= 10;
    }
}

// ���� �ڵ� ����
void func_1019_v3(int n)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long count_1019[10];
    // long long n;
    long long start = 1;
    long long end;
    long long point = 1;
    memset(count_1019, 0, sizeof(count_1019));
    // cin >> n;
    end = n;

    while (end >= start)
    {
        // ���� �� �ø��� (0����)
        while (start % 10 != 0 && start <= end)
        {
            calc_1019(start, point, count_1019);
            start++;
        }

        // start ���� ��Ű�ٰ� end ���� Ŀ���� (���� start, end�� 1�ڸ� ���϶� �߻�)
        if (start > end)
            break;

        // ���� �� ���̱� (9����)
        while (end % 10 != 9 && start <= end)
        {
            calc_1019(end, point, count_1019);
            end--;
        }

        // �� �ڸ��� �� ���� ���
        long long rescalc = end / 10 - start / 10 + 1;
        for (int i = 0; i < 10; i++)
        {
            count_1019[i] += (point * rescalc);
        }

        // ���� �ڸ��� �̵�
        start /= 10;
        end /= 10;
        point *= 10LL;
    }

    // ���
    for (int i = 0; i < 10; i++)
    {
        cout << count_1019[i] << " ";
    }
    cout << "\n";
}

void func_1019()
{
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

    while (end >= start)
    {
        // start �� �� �ڸ��� 0�϶� ���� +�ϰ�, 0�϶� start ��~ ���ڸ� 0�� �� -1���� 0~9�� ���� ������
        while (start % 10 != 0 && start <= end)
        {
            str_tmp = to_string(start);
            for (int i = 0; i < str_tmp.length(); i++)
            {
                cnt_num[str_tmp[i] - '0'] += digit;
            }

            start++;
        }

        if (start > end)
            break;

        // end �� �� �ڸ��� 9�϶� ���� -�ϰ�, ���ڸ� 9�� ��+1~ ���� �� ���� 0~9�� ���� ������
        while (end % 10 != 9 && start <= end)
        {
            str_tmp = to_string(end);
            for (int i = 0; i < str_tmp.length(); i++)
            {
                cnt_num[str_tmp[i] - '0'] -= digit;
            }

            end--;
        }

        // cout << start << "~" << end << "\n";

        for (int i = 0; i < 10; i++)
        {
            cnt_num[i] += ((end / 10) - (start / 10) + 1) * digit;
        }

        end /= 10;
        start /= 10;
        digit *= 10;
    }

    // ���
    cout << "\n���� - ";
    for (int i = 0; i < 10; i++)
    {
        cout << cnt_num[i] << " ";
    }

    cout << "\n���� - ";
    func_1019_v3(n);
}

/* ���ϻ��� (��� 5)
 * https://www.acmicpc.net/problem/10026
 */

void func_10026_printmap(string memo, char **_map, int n)
{
    cout << memo << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << _map[i][j];
        }
        cout << "\n";
    }

    cout << "\n";
}

void func_10026_printmap_int(string memo, int **_map, int n)
{
    cout << memo << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << _map[i][j];
        }
        cout << "\n";
    }

    cout << "\n";
}

void func_10026_bfs(queue<pair<int, int>> q, char **_map, int **visited, int visit_value, int n)
{
    pair<int, int> tmp_coord;
    int _x, _y;
    char tmp_color;

    int direct[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // ��ǥ �޾Ƽ� ������ ���� �� ��ǥ�� �湮 ���θ� �Ǵ��ϰ�, ���� ���� �湮�� �������� �湮���θ� ���а����� �ʱ�ȭ�ϰ� ť�� �߰�
    while (!q.empty())
    {
        tmp_coord = q.front();
        tmp_color = _map[tmp_coord.first][tmp_coord.second];
        q.pop();

        // �ð���� ���� ��� �˻�
        for (int i = 0; i < 4; i++)
        {
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

void func_10026()
{
    queue<pair<int, int>> q;
    int visit_value, map_max, map_rg_max;

    int n;
    cin >> n;

    // �Ϲ����� �Է� �ް� ���������� ����
    char **map_origin = new char *[n];
    char **map_rg = new char *[n];
    int **map_visit = new int *[n];
    int **map_rg_visit = new int *[n];

    for (int i = 0; i < n; i++)
    {
        map_origin[i] = new char[n];
        map_rg[i] = new char[n];
        map_visit[i] = new int[n];
        map_rg_visit[i] = new int[n];

        memset(map_visit[i], 0, sizeof(int) * n);
        memset(map_rg_visit[i], 0, sizeof(int) * n);
    }

    // map �ʱ�ȭ
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // ���� ��ǥ�� ������ �з����� �ʾ����� q�� �߰�
            if (map_visit[i][j] == 0)
            {
                q.push({i, j});
                map_visit[i][j] = ++visit_value;
            }

            func_10026_bfs(q, map_origin, map_visit, visit_value, n);
        }
    }

    while (!q.empty())
    {
        q.pop();
    }

    func_10026_printmap_int("origin_visit_1", map_visit, n);
    func_10026_printmap_int("rg_visit_1", map_rg_visit, n);

    // ���Ϳ� ��
    // �� ��ǥ�� ���� �湮�Ҷ� ���� �ѹ��� bfs ������(������ �湮������ �ȵ�)
    // bfs �ѹ� ���������� visit_value++;
    visit_value = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map_rg_visit[i][j] == 0)
            {
                q.push({i, j});
                map_rg_visit[i][j] = ++visit_value;
            }

            func_10026_bfs(q, map_rg, map_rg_visit, visit_value, n);
        }
    }

    func_10026_printmap_int("origin_visit_2", map_visit, n);
    func_10026_printmap_int("rg_visit_2", map_rg_visit, n);

    map_max = 0;
    map_rg_max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map_max < map_visit[i][j])
            {
                map_max = map_visit[i][j];
            }

            if (map_rg_max < map_rg_visit[i][j])
            {
                map_rg_max = map_rg_visit[i][j];
            }
        }
    }
    cout << map_max << " " << map_rg_max << "\n";
}

/* �� �μ��� �̵��ϱ� (��� 4) - �ۼ� ��
 * https://www.acmicpc.net/problem/2206
 */
void func_2206()
{
    int n, m;
    cin >> n >> m;

    // �ʱ�ȭ
    int **_map = new int *[n];
    for (int i = 0; i < n; i++)
    {
        _map[i] = new int[m];
    }

    // map �Է�
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> _map[i][j];
        }
    }

    // ���
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
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

void func_1753_print_distance(int num, int *d, int max)
{
    for (int i = 0; i < num; i++)
    {
        if (d[i] != max)
        {
            cout << d[i] << " ";
        }
        else
        {
            cout << "INF ";
        }
    }
    cout << "\n";
}

void func_1753_dijkstra_first(int start, int num, int **graph, int *visit, int max)
{
    int current;

    int *d = new int[num];
    for (int i = 0; i < num; i++)
    {
        d[i] = max;
    }
    d[start - 1] = 0;

    queue<int> q;
    visit[start - 1] = 1;
    q.push(start - 1);

    while (!q.empty())
    {
        current = q.front();
        q.pop();

        for (int i = 0; i < num; i++)
        {
            if (graph[current][i] != 0)
            {
                if (d[i] > d[current] + graph[current][i])
                {
                    d[i] = d[current] + graph[current][i];
                }

                if (visit[i] == 0)
                {
                    visit[i] = 1;
                    q.push(i);
                }
            }
        }
    }

    for (int i = 0; i < num; i++)
    {
        if (d[i] != max)
        {
            cout << d[i] << " ";
        }
        else
        {
            cout << "INF ";
        }
    }
    cout << "\n";
}

void func_1753_dijkstra_bfs(int start, int num, vector<pair<int, int>> *graph, int *visit, int max)
{
    pair<int, int> current;

    // �ִܰŸ� ����Ʈ ���� �� �ʱ�ȭ
    int *d = new int[num];
    for (int i = 0; i < num; i++)
    {
        d[i] = max;
    }
    d[start - 1] = 0;

    queue<pair<int, int>> q;
    int min = max, minIndex = 0;

    // ���� ��� �湮 ó���� ť ���, ���� ��忡�� ���۳��� ���� ����ġ�� �����Ƿ� 0 �Է�
    visit[start - 1] = 1;
    q.push({start - 1, 0});

    while (!q.empty())
    {
        current = q.front();
        q.pop();

        // ���� �۾� ��忡�� ������ ����� ��� ���� �����ؾ���
        // ���� ���� ������ ��带 ��� �ҷ�����
        for (auto adj_node : graph[current.first])
        {
            // ������ ���� ���� ��� ���� ������ ���� �Ÿ����� ��
            // ���� ���� �Ÿ� �� : d[adj_node.first]
            // �ش� ����Ʈ�� ����� ���� ���� ���ϰ� �� ª���� ����
            if (d[adj_node.first] > d[current.first] + adj_node.second)
            {
                // start���� i����� �ִܰŸ� = ���� ������ ���� �ִܰŸ� + ���� ���� ���� ���
                d[adj_node.first] = d[current.first] + adj_node.second;
            }

            // �湮���� �ʾ����� �湮 ���� üũ �� ť�� ���
            if (visit[adj_node.first] == 0)
            {
                visit[adj_node.first] = 1;
                q.push(adj_node);
            }
        }
    }

    // ���
    for (int i = 0; i < num; i++)
    {
        if (d[i] != max)
        {
            cout << d[i] << " ";
        }
        else
        {
            cout << "INF ";
        }
    }
    cout << "\n";
}

void func_1753_dijkstra_dfs(int node, vector<pair<int, int>> *graph, int *visit, int *d)
{
    // �湮 ���� üũ
    visit[node] = 1;
    cout << "current node ; " << (char)(node + 'a') << "\n";

    // ���� ����Ȯ��
    for (auto tmp : graph[node])
    {
        cout << (char)(tmp.first + 'a') << " " << tmp.second << " " << visit[node] << "\n";

        if (d[tmp.first] > d[node] + tmp.second)
        {
            d[tmp.first] = d[node] + tmp.second;
        }

        if (!visit[tmp.first])
        {
            func_1753_dijkstra_dfs(tmp.first, graph, visit, d);
        }
    }
}

bool func_1753_cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

// ��������Ʈ ���ͽ�Ʈ�� bfs -> 4% Ʋ��
void func_1753_adjlist_bfs()
{
    int n, m;
    cin >> n >> m;

    // ���� ����Ʈ ����
    vector<pair<int, int>> *adjlist = new vector<pair<int, int>>[n];
    ;

    int *visit = new int[n + 1];
    memset(visit, 0, sizeof(int) * (n + 1));

    int u, v, a, start_node;
    cin >> start_node;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> a;
        adjlist[u - 1].push_back({v - 1, a});
        adjlist[v - 1].push_back({u - 1, a});
    }

    for (int i = 0; i < n; i++)
    {
        sort(adjlist[i].begin(), adjlist[i].end(), func_1753_cmp);
        // reverse(adjlist[i].begin(), adjlist[i].end());

        cout << (char)('a' + i) << " : ";
        for (auto adjlist_tmp : adjlist[i])
        {
            cout << "{" << (char)('a' + adjlist_tmp.first) << ", " << adjlist_tmp.second << "} ";
        }
        cout << "\n";
    }

    func_1753_dijkstra_bfs(start_node, n, adjlist, visit, 99999999);
}

// ������� ���ͽ�Ʈ�� -> 4% �޸� �ʰ�
void func_1753_first_adjmatrix()
{
    int n, m;
    cin >> n >> m;

    int **_map = new int *[n];
    for (int i = 0; i < n; i++)
    {
        _map[i] = new int[n];
        memset(_map[i], 0, sizeof(int) * n);
    }

    int *visit2 = new int[n + 1];
    memset(visit2, 0, sizeof(int) * (n + 1));

    int u, v, a, start_node;
    cin >> start_node;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> a;
        _map[u - 1][v - 1] = a;
    }

    func_1753_dijkstra_first(start_node, n, _map, visit2, 99999999);
}

// ��������Ʈ ���ͽ�Ʈ�� dfs -> 4% Ʋ��
void func_1753_adjlist_dfs()
{
    int n, m, max = 99999999;
    cin >> n >> m;

    vector<pair<int, int>> *adjlist = new vector<pair<int, int>>[n];
    ;

    int *visit = new int[n + 1];
    memset(visit, 0, sizeof(int) * (n + 1));

    int u, v, a, start_node;
    cin >> start_node;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> a;
        adjlist[u - 1].push_back({v - 1, a});
        // adjlist[v - 1].push_back({ u - 1, a });
    }

    for (int i = 0; i < n; i++)
    {
        // sort(adjlist[i].begin(), adjlist[i].end(), func_1753_cmp);
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
    int *d = new int[n];
    for (int i = 0; i < n; i++)
    {
        d[i] = max;
    }
    d[start_node - 1] = 0;

    func_1753_dijkstra_dfs(start_node - 1, adjlist, visit, d);

    func_1753_print_distance(n, d, max);
}

// O(V^2) ��� ���� -> 4% �ð� �ʰ�
void func_1753_old()
{
    int n, m, start, max = 99999999;
    int min = max, current;
    int u, v, a;

    cin >> n >> m;

    int *visit = new int[n + 1];
    memset(visit, 0, sizeof(int) * (n + 1));

    int *d = new int[n];
    for (int i = 0; i < n; i++)
    {
        d[i] = max;
    }

    vector<pair<int, int>> *adjlist = new vector<pair<int, int>>[n];

    cin >> start;
    if (start > 0)
        start--;
    d[start] = 0;

    // �Է�
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> a;
        adjlist[u - 1].push_back({v - 1, a});
    }

    // ���۳���� ���� ��� �Ÿ��� ����
    for (auto tmp : adjlist[start])
    {
        d[tmp.first] = tmp.second;
    }

    visit[start] = 1;

    // ���ͽ�Ʈ��
    for (int i = 0; i < n - 1; i++)
    {
        min = max;
        current = 0;

        for (int j = 0; j < n; j++)
        {
            if (d[j] < min && !visit[j])
            {
                min = d[j];
                current = j;
            }
        }

        visit[current] = 1;

        for (auto cur : adjlist[current])
        {
            if (!visit[cur.first])
            {
                if (d[current] + cur.second < d[cur.first])
                {
                    d[cur.first] = d[current] + cur.second;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << d[i] << " ";
    }
    cout << "\n";
}

void func_1753_dijkstra_pq(int start, vector<pair<int, int>> *graph, int *d)
{
    int _current, _next, _distance, _nextDistance;

    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({start, 0});

    while (!pq.empty())
    {
        _current = pq.top().second;
        _distance = -pq.top().first;

        pq.pop();

        if (d[_current] < _distance)
            continue;

        for (int i = 0; i < graph[_current].size(); i++)
        {
            _next = graph[_current][i].second;
            _nextDistance = _distance + graph[_current][i].first;

            if (_nextDistance < d[_next])
            {
                d[_next] = _nextDistance;
                pq.push({-_nextDistance, _next});
            }
        }
    }
}

// �켱���� ť ��� ����
void func_1753()
{
    int n, m, start, max = 99999999;
    int u, v, a;

    cin >> n >> m;

    int *d = new int[n];
    for (int i = 0; i < n; i++)
    {
        d[i] = max;
    }

    vector<pair<int, int>> *adjlist = new vector<pair<int, int>>[n];

    cin >> start;
    if (start > 0)
        start--;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> a;
        adjlist[u - 1].push_back({a, v - 1});
    }

    func_1753_dijkstra_pq(start, adjlist, d);

    for (int i = 0; i < n; i++)
    {
        if (d[i] == max)
        {
            cout << "INF ";
        }
        else
        {
            cout << d[i] << " ";
        }
    }
    cout << "\n";
}

/* k��° �� (��� 2)
 *  https://www.acmicpc.net/problem/1300
 */
void func_1300()
{
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
void func_9663_mapset(int **_map, int n)
{
    for (int i = 0; i < n; i++)
    {
        memset(_map[i], 0, sizeof(int) * n);
    }
}

bool func_9663_check(int **map, int n, pair<int, int> cur)
{
    pair<int, int> direc[8] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    int _x, _y;
    pair<int, int> next_node;
    queue<pair<int, int>> q;

    if (map[cur.second][cur.first] == 0)
    {
        map[cur.second][cur.first] = 9;
        // visit[cur.second][cur.first] = 1;

        for (int i = 0; i < 8; i++)
        {
            _x = cur.second + direc[i].second;
            _y = cur.first + direc[i].first;

            // cout << i << "\n";

            q.push({_x, _y});

            while (!q.empty())
            {
                _x = q.front().first;
                _y = q.front().second;
                q.pop();

                // �ش� ��ǥ�� �� �ȿ� �ִ��� üũ
                if (_x >= n || _x < 0 || _y >= n || _y < 0)
                    break;

                // ���� �ش� ������ �����ϸ鼭 ���� ������ return
                if (map[_x][_y] == 9)
                {
                    return false;
                }

                // cout << i << " - " << _x << " + " << direc[i].second << ", " << _y << " + " << direc[i].first << "\n";

                // �� �ȿ� ��ġ�� ������ �湮 ǥ��
                // visit[_x][_y] = 1;
                map[_x][_y] = 1;

                q.push({_x + direc[i].second, _y + direc[i].first});
            }
        }
    }
    else
    {
        return false;
    }

    return true;
}

int func_9663_dfs(const int n)
{
    // ���� �޸𸮷� �ϰ� ���� ä���ִ� ��� �ۼ�
    stack<int **> stack_map;
    int **_map; // �޸� �Ҵ� �ʿ�
    int cnt, cnt2 = 0;

    stack_map.push(_map); // ����ִ� ��

    // 0�� ���� �� �ΰ� ���ÿ� �ֱ� -> ���̻� �� �� ������ pop
    while (!stack_map.empty())
    {
        cnt = 0;
        _map = stack_map.top();
        stack_map.pop();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (_map[i][j] == 0)
                {
                    if (func_9663_check(_map, n, {i, j}))
                    {
                        cnt++;
                    }
                }
            }
        }

        if (cnt == n)
        {
            cnt2++;
            // ��� ���� ���̽��� �ݺ��� �� ���� - > ���⼭ ���� ó��?
            break;
        }
        else
        {
            cnt = 0;
            stack_map.push(_map);
        }
    }

    return cnt2;
}

void func_9663()
{
    int n;
    cin >> n;

    // create map
    int **_map = new int *[n];
    // int** _visit = new int* [n];

    for (int i = 0; i < n; i++)
    {
        _map[i] = new int[n];
        //_visit[i] = new int[n];

        memset(_map[i], 0, sizeof(int) * n);
        // memset(_visit[i], 0, sizeof(int) * n);
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

    cout << cnt << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << _map[i][j];
        }
        cout << "\n";
    }
}

/* ��� ���� (��� 5)
 *  https://www.acmicpc.net/problem/6593
 */
void func_6593()
{
    int L, R, C;
    queue<vector<int>> q;
    vector<int> start_v, tmp_v, input_v;

    cin >> L >> R >> C; // ��, ����(R*C)
    if (L == 0 && R == 0 && C == 0)
    {
        return;
    }

    // 3���� �迭 �޸� �Ҵ�  building[L][R][C];
    char ***building = new char **[L];
    int ***visit = new int **[L];

    for (int i = 0; i < L; i++)
    {
        building[i] = new char *[R];
        visit[i] = new int *[R];
        memset(visit[i], 0, sizeof(int) * R);
        for (int j = 0; j < R; j++)
        {
            building[i][j] = new char[C];
            visit[i][j] = new int[C];
            memset(visit[i][j], 0, sizeof(int) * C);
        }
    }

    // 3���� �迭 �Է�
    for (int k = 0; k < L; k++)
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> building[k][i][j];
                if (building[k][i][j] == 'S')
                {
                    start_v.push_back(k);
                    start_v.push_back(i);
                    start_v.push_back(j);
                }
            }
        }
    }

    // bfs

    int direct[6][3] = {{0, 1, 0}, {1, 0, 0}, {0, -1, 0}, {-1, 0, 0}, {0, 0, 1}, {0, 0, -1}}; // L, R, C
    int _x, _y, _z;

    // x, y, z
    visit[start_v.at(0)][start_v.at(1)][start_v.at(2)] = 1;
    q.push(start_v);

    while (!q.empty())
    {
        tmp_v = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            _x = tmp_v.at(0) + direct[i][0];
            _y = tmp_v.at(1) + direct[i][1];
            _z = tmp_v.at(2) + direct[i][2];
            // cout << "�˻� : " << _x << " " << _y << " " << _z << "\n";
            if (_x >= L || _x < 0 || _y < 0 || _y >= R || _z >= C || _z < 0)
                continue;

            // cout << "�˻� : " << _x << " " << _y << " " << _z << " -> " << building[_x][_y][_z] << " \n";

            if (building[_x][_y][_z] == '#')
                continue;

            if (visit[_x][_y][_z] > 0)
                continue;
            /*
            if (building[_x][_y][_z] == 'E') {
                if (_min > visit[_x][_y][_z]) {
                    _min = visit[_x][_y][_z];
                    cout << "E : " << _x << " " << _y << " " << _z << " -> " << building[_x][_y][_z] << ", "<< visit[_x][_y][_z] << " \n";
                }
            }
            */
            // cout << "��� : " << _x << " " << _y << " " << _z << " -> " << building[_x][_y][_z] << " \n";

            input_v.push_back(_x);
            input_v.push_back(_y);
            input_v.push_back(_z);

            visit[input_v.at(0)][input_v.at(1)][input_v.at(2)] = visit[tmp_v.at(0)][tmp_v.at(1)][tmp_v.at(2)] + 1;
            q.push(input_v);

            input_v.clear();
        }
        tmp_v.clear();
        // cout << " \n";
    }

    // 3���� �迭 ���
    int _max = 0, _min = 31 * 31 * 31;

    for (int k = 0; k < L; k++)
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cout << visit[k][i][j];
                if (_max < visit[k][i][j])
                {
                    _max = visit[k][i][j];
                }
                if (building[k][i][j] == 'E')
                {
                    if (_min > visit[k][i][j])
                    {
                        _min = visit[k][i][j];
                    }
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }

    if (_max == 1 || _min == 0)
    {
        cout << "Trapped!\n";
    }
    else
    {
        cout << "Escaped in " << (_min - 1) << " minute(s).\n";
    }

    // �޸� ����
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < R; j++)
        {
            delete[] building[i][j];
            delete[] visit[i][j];
        }
    }

    for (int i = 0; i < L; i++)
    {
        delete[] building[i];
        delete[] visit[i];
    }

    delete[] building;
    delete[] visit;
}

/* ���� (��� 4)
 *  https://www.acmicpc.net/problem/2573
 */
void func_2573()
{
    int n, m;
    cin >> n >> m;

    // 3���� �迭 �޸� �Ҵ�  building[L][R][C];
    char **_map = new char *[n];
    int **visit = new int *[n];

    for (int i = 0; i < n; i++)
    {
        _map[i] = new char[m];
        visit[i] = new int[m];
        memset(visit[i], 0, sizeof(int) * m);
    }

    // 2���� �迭 �Է�
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> _map[i][j];
            // cout << _map[i][j];
        }
        // cout << "\n";
    }
}

/*
 *  �ܰ躰�� Ǯ��� �ּ�
 *  https://www.acmicpc.net/step
 */

/*
 *  *************************************
 *  �ܰ躰�� Ǯ��� > ����°� ��Ģ����
 *  *************************************
 */

/* Hello Word
 * https://www.acmicpc.net/problem/2557
 */
void func_2557()
{
    cout << "Hello World!";
}

/* We love kriii
 * https://www.acmicpc.net/problem/10718
 */
void func_10718()
{
    cout << "����ģ�� ��������";
    cout << "����ģ�� ��������";
}

/*
void func_10171(); // ������
void func_10172(); // ��
void func_1000(); // A+B
void func_1001(); // A-B
void func_10998(); // A*B
void func_1008(); // A/B
void func_10869(); // ��Ģ����
void func_10430(); // ������
void func_2588(); // ����
*/

/* ??! (����� 5)
 *  https://www.acmicpc.net/problem/10926
 */
void func_10926()
{
    string str;
    cin >> str;

    cout << str + "??!" << endl;
}

/* 1998����� ���� �±������� 2541��� ? ! (����� 5)
 *  https://www.acmicpc.net/problem/18108
 */
void func_18108()
{
    int a;
    cin >> a;

    cout << a - 543 << endl;
}

/*
 *  ************************
 *  �ܰ躰�� Ǯ��� > if��
 *  ************************
 */

// void func_1330(); // �� �� ���ϱ�
// void func_9498(); // ���� ����
// void func_2753(); // ����
// void func_14681(); // ��и� ������
// void func_2884(); // �˶� �ð�

/* ���� �ð�
 * https://www.acmicpc.net/problem/2525
 */
void func_2525()
{
    int a, b, c;
    cin >> a >> b >> c;

    b = b + c;
    if (b < 0)
    {
        b = 0;
    }
    while (b >= 60)
    {
        b -= 60;
        a += 1;
    }

    if (a < 0)
    {
        a = 0;
    }
    while (a >= 24)
    {
        a -= 24;
    }

    cout << a << " " << b << "\n";
}

/* �ֻ��� ����
 * https://www.acmicpc.net/problem/2480
 */
void func_2480()
{
    map<int, int> m;
    int a, res = 0, k_max = 0, v_max = 0;

    for (int i = 0; i < 3; i++)
    {
        cin >> a;
        m[a]++;

        // key max
        if (k_max < a)
        {
            k_max = a;
        }
        // value max
        if (v_max < m[a])
        {
            v_max = m[a];
        }
    }

    // �Ʒ����ǿ� �ش�Ǵ� �� ������ �׳� �ִ� �ֻ��� ���� kmax��
    for (auto v : m)
    {
        // ���� �� �� 1���� �ƴϰ�, �ִ� ������ ���� ��ȣ�� ������ ������
        if (v_max != 1 && v_max == v.second)
        {
            k_max = v.first; // �� ���� Ű��(�ֻ��� ��)�� ����
        }
    }

    if (v_max == 3)
    {
        res = 10000 + k_max * 1000;
    }
    if (v_max == 2)
    {
        res = 1000 + k_max * 100;
    }
    if (v_max == 1)
    {
        res = k_max * 100;
    }

    cout << res << "\n";
}

/*
 *  *************************
 *  �ܰ躰�� Ǯ��� > for��
 *  *************************
 */

/*
void func_2739(); // ������
void func_10950(); // A+B - 3
void func_8393(); // ��
void func_15552(); // ���� A+B
void func_2741(); // N ���
void func_2742(); // ���� N
void func_11021(); // A+B - 7
void func_11022(); // A+B - 8
void func_2438(); // �� ��� - 1
void func_2439(); // �� ��� - 2
void func_10871(); // X���� ���� ��
*/

/*
 *  ***************************
 *  �ܰ躰�� Ǯ��� > while��
 *  ***************************
 */

/*
void func_10952(); // A+B - 5
void func_10951(); // A+B - 4
void func_1110(); // ���ϱ� ����Ŭ
*/

/*
 *  ****************************
 *  �ܰ躰 Ǯ��� > 1���� �迭
 *  ****************************
 */

/*
void func_10818(); // �ּ�, �ִ�
void func_2562(); // �ִ�
void func_2577(); // ������ ����
void func_3052(); // ������
void func_1546(); // ���
void func_8958(); // OX����
void func_4344(); // ����� �Ѱ���
*/

/*
 *  ****************************
 *  �ܰ躰�� Ǯ��� > �Լ�
 *  ****************************
 */

/* ���� N���� ��
 * https://www.acmicpc.net/problem/15596
 */
ll func_15596_sum(vector<int> &a)
{
    long long ans = 0;

    for (int i = 0; i < a.size(); i++)
    {
        ans += a.at(i);
    }

    return ans;
}
void func_15596()
{
    int a;
    vector<int> v;
    cin >> a;
    v.push_back(a);
    cout << func_15596_sum(v);
}

/* ���� �ѹ�
 * https://www.acmicpc.net/problem/4673
 */
int func_4673_selfnumber(int a)
{
    int digit = to_string(a).size(), tmp = 0, a_copy = a, sum = a;
    int *arr = new int[digit];

    for (int i = 0; i < digit; i++)
    {
        tmp = pow(10, (digit - (i + 1)));
        arr[i] = a_copy / tmp;
        a_copy %= tmp;
    }

    for (int i = 0; i < digit; i++)
    {
        sum += arr[i];
    }

    return sum;
}

void func_4673()
{
    int a = 10000;

    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int *arr = new int[a];
    for (int i = 0; i < a; i++)
    {
        arr[i] = 0;
    }

    for (int i = 0; i < a; i++)
    {
        arr[func_4673_selfnumber(i) - 1]++;
    }

    for (int i = 0; i < a; i++)
    {
        if (arr[i] == 0)
        {
            cout << i + 1 << endl;
        }
    }
}

/* �Ѽ�
 * https://www.acmicpc.net/problem/1065
 */
bool func_1065_hansu(int a)
{
    bool is_flag = false;
    int tmp, cnt = 0;
    int digit = to_string(a).size();

    if (digit > 2)
    {
        int *arr = new int[digit];

        for (int i = 0; i < digit; i++)
        {
            tmp = pow(10, (digit - (i + 1)));
            arr[i] = a / tmp;
            a %= tmp;
        }

        int now_dif = 0;
        int pre_dif = arr[0] - arr[1];

        for (int i = 0; i < digit - 1; i++)
        {
            now_dif = arr[i] - arr[i + 1];
            if (now_dif == pre_dif)
                cnt++;
            pre_dif = now_dif;
        }

        if (digit - 1 == cnt)
        {
            is_flag = true;
        }
    }
    else
    {
        is_flag = true;
    }
    return is_flag;
}

void func_1065()
{
    int a = 0, cnt = 0;

    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> a;

    for (int i = 1; i <= a; i++)
    {
        if (func_1065_hansu(i))
            cnt++;
    }

    cout << cnt << endl;
}

/*
 *  ************************
 *  �ܰ躰 Ǯ��� > ���ڿ�
 *  ************************
 */

/* �ܾ� ����
 *  https://www.acmicpc.net/problem/1157
 */
void func_1157()
{
    string str;
    map<char, int> myMap;
    map<char, int>::iterator iter;

    int int_max = 0;

    char ch_result;
    int int_cnt = 0;

    // a~z 0���� �ʱ�ȭ
    for (char c = 'a'; c <= 'z'; c++)
    {
        myMap[c] == 0;
    }

    // �Է¹ް� �ҹ��� ���� �� ī��Ʈ
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
        myMap[str[i]]++;
    }

    // max �� ����
    for (iter = myMap.begin(); iter != myMap.end(); iter++)
    {
        if (iter->second > int_max)
        {
            int_max = iter->second;
        }
    }

    // max �� ���� �����鼭 cnt ������ 1�ΰŴ� ���, �ƴϸ� ?
    for (iter = myMap.begin(); iter != myMap.end(); iter++)
    {
        if (int_max == iter->second)
        {
            int_cnt++;
            ch_result = iter->first;
        }
    }

    if (int_cnt == 1)
    {
        printf("%c\n", toupper(ch_result));
    }
    else
    {
        cout << '?' << endl;
    }
}

/* ���ڿ� �ݺ�
 *  https://www.acmicpc.net/problem/2675
 */
void func_2675()
{
    int a, b;
    string str;

    cin >> a;

    for (int i = 0; i < a; i++)
    {
        cin >> b >> str;
        for (int i = 0; i < str.length(); i++)
        {
            for (int j = 0; j < b; j++)
            {
                cout << str[i];
            }
        }
        cout << endl;
    }
}

/* �ܾ��� ����
 *  https://www.acmicpc.net/problem/1152
 */
void func_1152()
{
    string str;
    vector<string> res;
    int cnt = 0;

    getline(cin, str, '\n');
    res = split(str, ' ');

    for (int i = 0; i < res.size(); i++)
    {
        if (res[i].size() > 0)
            cnt++;
    }

    cout << cnt << endl;
}

/* ���
 *  https://www.acmicpc.net/problem/2908
 */
void func_2908()
{
    string a, b;
    string a_r, b_r;
    int res;
    int cnt = 0;

    cin >> a >> b;

    a_r = a;
    b_r = b;

    for (int i = 2; i >= 0; i--)
    {
        a_r[cnt] = a[i];
        b_r[cnt++] = b[i];
    }

    if (stoi(a_r) > stoi(b_r))
    {
        res = stoi(a_r);
    }
    else
    {
        res = stoi(b_r);
    }

    cout << res;
}

/* ���̾�
 *  https://www.acmicpc.net/problem/5622
 */
void func_5622()
{
    string str;
    cin >> str;
    map<char, int> m;
    int point, sum = 0;

    for (int i = 0; i < 26; i++)
    {
        if ('A' + i < 'Z')
            point = 10;
        if ('A' + i < 'W')
            point = 9;
        if ('A' + i < 'T')
            point = 8;
        if ('A' + i < 'P')
            point = 7;
        if ('A' + i < 'M')
            point = 6;
        if ('A' + i < 'J')
            point = 5;
        if ('A' + i < 'G')
            point = 4;
        if ('A' + i < 'D')
            point = 3;

        m['A' + i] = point;
    }

    for (int i = 0; i < str.length(); i++)
    {
        sum += m[str[i]];
    }

    cout << sum << endl;
}

/* ũ�ξ�Ƽ�� ���ĺ�
 *  https://www.acmicpc.net/problem/2941
 */
void func_2941()
{
    vector<string> v_str = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string str;

    cin >> str;
    for (int i = 0; i < v_str.size(); i++)
    {
        while (1)
        {
            if (str.find(v_str[i]) == string::npos)
            {
                break;
            }
            else
            {
                str.replace(str.find(v_str[i]), v_str[i].length(), "!");
            }
        }
    }

    cout << str.length() << endl;
}

/* �׷� �ܾ� üĿ
 *  https://www.acmicpc.net/problem/1316
 */
void func_1316()
{
    int a;
    cin >> a;

    string *arr_str = new string[a];
    map<char, int> m;
    int cnt = 0;

    for (int i = 0; i < a; i++)
    {
        cin >> arr_str[i];
    }

    char pre_ch;
    bool is_flag;

    for (int i = 0; i < a; i++)
    {
        pre_ch = '0';
        is_flag = true;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            m[ch] = 0;
        }

        for (int j = 0; j < arr_str[i].length(); j++)
        {
            if (m[arr_str[i][j]] != 0)
            {
                if (pre_ch != arr_str[i][j])
                {
                    is_flag = false;
                    break;
                }
            }

            m[arr_str[i][j]]++;
            pre_ch = arr_str[i][j];
        }

        if (is_flag)
        {
            cnt++;
        }
    }

    cout << cnt;
}

/*
 *  *****************************
 *  �ܰ躰 Ǯ��� > �⺻ ���� 1
 *  *****************************
 */

/* ���ͺб���
 * https://www.acmicpc.net/problem/1712
 */
void func_1712()
{
    int a, b, c;
    // map<char, int> m = { {'A', 1000}, {'B', 70}, {'C', 1}};
    cin >> a >> b >> c;
    int unit_profit = c - b;

    if (unit_profit <= 0)
    {
        cout << -1;
    }
    else
    {
        cout << a / unit_profit + 1 << endl;
    }
}

/* ����
 * https://www.acmicpc.net/problem/2292
 */
void func_2292()
{
    int a;
    cin >> a;

    for (int i = 1; true; i++)
    {
        if (a == 1)
        {
            cout << i;
            break;
        }

        a -= (6 * i);

        if (a <= 0)
        {
            cout << i + 1;
            break;
        }
    }
}

/* �м�ã��
 * https://www.acmicpc.net/problem/1193
 */
unsigned long long func_1193_sum_of_arithmetic_sequences(int n)
{
    return (n * (n + 1)) / 2;
}

string func_1193_create(int n)
{
    // �Է¹��� �ε����� ��Ģ�� ������� ���� (�Է½ø��� ����, ��� ���� ����� �ð�)
    // ��Ģ. ĭ ���� ���������� 1���� ���� 1-> 2 -> 3 -> 4 ... �׸��� a/b �� a�� ����, b�� ����
    int lv, pos;
    int a, b;

    // ���� ���ϱ�
    for (int i = 0; i < 10000; i++)
    {
        if (n <= func_1193_sum_of_arithmetic_sequences(i))
        {
            lv = i;
            break;
        }
    }

    // ������ ���̳��� ��ġ�� ���ϱ�
    pos = n - func_1193_sum_of_arithmetic_sequences(lv);

    // ���������� �� ����
    if (lv % 2 == 0)
    {
        a = 1;
        b = lv;
        pos *= -1;
    }
    else
    {
        a = lv;
        b = 1;
    }

    // ���̳��� �� ��ŭ ����
    a += pos;
    b -= pos;

    return to_string(b) + "/" + to_string(a);
}

void func_1193()
{
    int a;
    cin >> a;

    cout << func_1193_create(a) << endl;
}

/* �����̴� �ö󰡰� �ʹ�
 * https://www.acmicpc.net/problem/2869
 */
void func_2869()
{
    long long a, b, v, day;
    cin >> a >> b >> v;

    if (v <= a)
    {
        day = 1;
    }
    else
    {
        day = (v - b) / (a - b);
        if ((v - b) % (a - b) > 0)
        {
            day++;
        }
    }

    cout << day << endl;
}

/* ACM ȣ��
 * https://www.acmicpc.net/problem/2869
 */
void func_10250()
{
    int a, h, w, n;
    int f, no;

    cin >> a;

    for (int i = 0; i < a; i++)
    {
        f = 1;
        no = 1;
        cin >> h >> w >> n;

        f += (n % h) - 1;
        if (n % h == 0)
        {
            f = h;
            no = n / h;
        }
        else
        {
            no += (n / h);
        }

        printf("%d%02d\n", f, no);
    }
}

/* �γ�ȸ���� ���׾�
 * https://www.acmicpc.net/problem/2775
 */
int func_2775_sum_people(int k, int n)
{
    if (k == 0)
        return n;
    if (n == 1)
        return 1;
    return func_2775_sum_people(k, n - 1) + func_2775_sum_people(k - 1, n);
}

void func_2775()
{
    int int_k, int_n, int_t;
    int int_sum = 0;

    cin >> int_t;

    for (int i = 0; i < int_t; i++)
    {
        cin >> int_k;
        cin >> int_n;

        cout << func_2775_sum_people(int_k, int_n) << endl;
    }
}

/* �������
 * https://www.acmicpc.net/problem/2839
 */
void func_2839()
{
    int n, min, tmp, res;
    bool is_flag;

    cin >> n;

    min = n;
    res = -1;
    is_flag = false;

    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            tmp = (3 * a) + (5 * b);

            if (tmp > n)
                break;
            if (tmp == n)
            {
                if (min >= a + b)
                {
                    min = a + b;
                    is_flag = true;
                }
            }
        }
    }

    if (is_flag)
        res = min;

    cout << res << endl;
}

/* ū �� A+B
 * https://www.acmicpc.net/problem/10757
 */

vector<int> func_10757_reverseVector(string num)
{
    vector<int> v;

    for (int i = num.length() - 1; i >= 0; i--)
    {
        v.push_back((num[i] - '0'));
    }

    return v;
}

void func_10757()
{
    string str_a, str_b;
    cin >> str_a >> str_b;

    vector<int> a, b, c;
    int int_a, int_b, int_tmp = 0, int_len;

    a = func_10757_reverseVector(str_a);
    b = func_10757_reverseVector(str_b);

    if (a.size() >= b.size())
    {
        int_len = a.size();
    }
    else
    {
        int_len = b.size();
    }

    for (int i = 0; i < int_len; i++)
    {
        try
        {
            int_a = a.at(i);
        }
        catch (exception e)
        {
            int_a = 0;
        }

        try
        {
            int_b = b.at(i);
        }
        catch (exception e)
        {
            int_b = 0;
        }

        c.push_back((int_a + int_b + int_tmp) % 10);

        if ((int_a + int_b + int_tmp) >= 10)
        {
            int_tmp = 1;
        }
        else
        {
            int_tmp = 0;
        }
    }

    if (int_tmp)
    {
        c.push_back(1);
    }

    for (int i = c.size() - 1; i >= 0; i--)
    {
        cout << c.at(i);
    }
}

/* Fly me to the Alpha Centauri
 * https://www.acmicpc.net/problem/1011
 */
void func_1011()
{
    int int_case;
    ll x, y, res, distance, level;

    cin >> int_case;

    for (int i = 0; i < int_case; i++)
    {
        cin >> x >> y;
        distance = y - x;

        if (distance > 0 && distance <= 3)
        {
            res = distance;
        }
        else
        {
            level = (int)sqrt(distance);

            if (((level + 1) * (level + 1)) - (level + 1) < distance && distance < ((level + 1) * (level + 1)))
            {
                res = 2 * level + 1;
            }
            else if (distance == level * level)
            {
                res = 2 * level - 1;
            }
            else
            {
                res = 2 * level;
            }
        }

        cout << res << "\n";
    }
}

/*
 *  *****************************
 *  �ܰ躰 Ǯ��� > �⺻ ���� 2
 *  *****************************
 */

/* �Ҽ� ã��
 * https://www.acmicpc.net/problem/1978
 */
void func_1978()
{
    int a, cnt = 0;
    cin >> a;

    int *arr = new int[a];

    for (int i = 0; i < a; i++)
    {
        cin >> arr[i];
        if (is_prime_number_custom(arr[i]))
        {
            cnt++;
        }
    }

    cout << cnt;
}

/* �Ҽ�
 * https://www.acmicpc.net/problem/2581
 */
void func_2581()
{
    int a, b, min, sum = 0;
    cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        if (is_prime_number_custom(i))
        {
            if (sum == 0)
                min = i;
            sum += i;
        }
    }

    if (sum == 0)
        cout << -1 << endl;
    else
    {
        cout << sum << endl;
        cout << min;
    }
}

/* ���μ�����
 * https://www.acmicpc.net/problem/11653
 */
void func_11653_Factorization(int a)
{
    bool is_flag = true;

    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            is_flag = false;
            cout << i << endl;
            func_11653_Factorization(a / i);
            break;
        }
    }

    if (is_flag)
        cout << a << endl;
}

void func_11653()
{
    int a;
    cin >> a;

    if (a != 1)
    {
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

/* �Ҽ� ���ϱ�
 * https://www.acmicpc.net/problem/1929
 */
void func_1929()
{
    int int_M, int_N;
    cin >> int_M >> int_N;

    for (int i = int_M; i <= int_N; i++)
    {
        if (is_prime_number_custom(i))
        {
            cout << i << endl;
        }
    }
}

/* ����Ʈ�� ����
 * https://www.acmicpc.net/problem/4948
 */
void func_4948()
{
    int int_N, cnt;
    bool *arr = Sieve_of_Eratosthenes(123456 * 2);

    do
    {
        cin >> int_N;
        cnt = 0;

        for (int i = int_N + 1; i <= int_N * 2; i++)
        {
            if (arr[i])
            {
                cnt++;
            }
        }

        if (int_N != 0)
            cout << cnt << endl;
    } while (int_N != 0);
}

/* �������� ����
 * https://www.acmicpc.net/problem/9020
 */
void func_9020()
{
    int int_a, int_N, int_sum;
    bool *arr = Sieve_of_Eratosthenes(20000);
    int tmp_a, tmp_b, tmp_min;
    vector<int> v;

    cin >> int_a;
    for (int i = 0; i < int_a; i++)
    {
        cin >> int_N;

        // �ʱ�ȭ
        int_sum = 0;
        v.clear();

        // �ش� ������ ���� �Ҽ� ������
        for (int j = 2; j < int_N; j++)
        {
            if (arr[j])
            {
                v.push_back(j);
            }
        }

        tmp_a = 0;
        tmp_b = 0;
        tmp_min = int_N;

        for (int j = 0; j < v.size(); j++)
        {
            for (int k = 0; k < v.size(); k++)
            {
                if (int_N == v.at(j) + v.at(k) && tmp_min > abs(v.at(j) - v.at(k)))
                {
                    tmp_a = v.at(j);
                    tmp_b = v.at(k);
                    tmp_min = abs(v.at(j) - v.at(k));
                }
            }
        }

        if (tmp_a + tmp_b != 0)
            cout << tmp_a << " " << tmp_b << endl;
    }
}

/* ���簢������ Ż��
 * https://www.acmicpc.net/problem/1085
 */
void func_1085()
{
    int x, y, w, h, min;

    cin >> x;
    min = x;

    cin >> y;
    if (min > y)
        min = y;

    cin >> w;
    if (min > w - x)
        min = w - x;

    cin >> h;
    if (min > h - y)
        min = h - y;

    cout << min;
}

/* �� ��° ��
 * https://www.acmicpc.net/problem/3009
 */
void func_3009()
{
    int a, b;
    map<int, int> x, y;
    map<int, int>::iterator iter;

    for (int i = 0; i < 3; i++)
    {
        cin >> a >> b;

        if (x.count(a))
            x[a]++;
        else
            x[a] = 1;

        if (y.count(b))
            y[b]++;
        else
            y[b] = 1;
    }

    for (iter = x.begin(); iter != x.end(); iter++)
    {
        if (iter->second == 1)
        {
            cout << iter->first << " ";
        }
    }

    for (iter = y.begin(); iter != y.end(); iter++)
    {
        if (iter->second == 1)
        {
            cout << iter->first;
        }
    }
}

/* �����ﰢ��
 * https://www.acmicpc.net/problem/4153
 */
void func_4153()
{
    // ���̵�� : ��Ÿ���� ���� Ȱ��
    int a, b, c;
    int pow_a, pow_b, pow_c, pow_sum;

    while (1)
    {
        cin >> a >> b >> c;

        pow_a = pow(a, 2);
        pow_b = pow(b, 2);
        pow_c = pow(c, 2);
        pow_sum = pow_a + pow_b + pow_c;

        if (pow_sum == 0)
            break;

        if (pow_a == pow_sum - pow_a || pow_b == pow_sum - pow_b || pow_c == pow_sum - pow_c)
        {
            cout << "right" << endl;
        }
        else
        {
            cout << "wrong" << endl;
        }
    }
}

/* �ý� ������
 * https://www.acmicpc.net/problem/3053
 */
void func_3053()
{
    // cmath ���� pi : M_PI (cmath include �� #define _USE_MATH_DEFINES �ʿ�)
    int r;
    cin >> r;

    // ��Ŭ���� �����п����� ����
    printf("%.6f\n", const_pi() * pow(r, 2));

    // �ý� ������ ������ ���� : �밢�� ���̰� r�� �������� ����
    printf("%.6f\n", pow(2 * r, 2) / 2);
}

/* �ͷ�
 * https://www.acmicpc.net/problem/1002
 */
void func_1002()
{
    int a;
    cin >> a;

    int x1, y1, r1, x2, y2, r2;
    double len;

    for (int i = 0; i < a; i++)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        // �� �� ������ �Ÿ�
        len = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

        // �ݰ��� �Ϻ��ϰ� ��ġ�� ���Ѵ��� ���
        if (len == 0 && r1 - r2 == 0)
        {
            cout << -1 << endl;
            continue;
        }

        // �������� ������ �ݰ��� �޶� ���� �� ����
        if (len == 0 && r1 - r2 != 0)
        {
            cout << 0 << endl;
            continue;
        }

        // �ﰢ���� �����Ǹ� 2��, ��ġ�ϸ� 1��, �ȵǸ� 0��
        // ���� ������ �̿��ؼ� Ǭ ��찡 ��κ�, �ﰢ�� �������� Ǭ ���� ��ã��
        if (len < r1 + r2 && r1 < r2 + len && r2 < len + r1)
        {
            cout << 2 << endl;
        }
        else if (len == r1 + r2 || r1 == len + r2 || r2 == len + r1)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}

/*
 *  **********************
 *  �ܰ躰 Ǯ��� > ���
 *  **********************
 */

/* ���丮�� (����� 3, ����)
 * https://www.acmicpc.net/problem/10872
 */
int func_10872_factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * func_10872_factorial(n - 1);
}

void func_10872()
{
    int a;
    cin >> a;

    cout << func_10872_factorial(a);
}

/* �Ǻ���ġ �� 5 (����� 2, ����/DP)
 * https://www.acmicpc.net/problem/10870
 */
int func_10870_fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return func_10870_fibonacci(n - 1) + func_10870_fibonacci(n - 2);
}

void func_10870()
{
    int a;
    cin >> a;

    cout << func_10870_fibonacci(a);
}

/* �� ��� -10 (�ǹ� 1, ��������)
 * https://www.acmicpc.net/problem/2447
 */
void func_2447_starPrint(int n, int a, int b)
{
    int n_copy = n;
    int int_squared = 0;

    if (n == 1)
        return;

    for (int i = 0; i < 8; i++)
    {
        if (n_copy == 1)
        {
            int_squared = i - 1;
            break;
        }
        n_copy /= 3;
    }

    int remove_a = pow(3, int_squared);
    int remove_b = (pow(3, int_squared) * 2) - 1;

    func_2447_starPrint(n / 3, remove_a, remove_b);

    for (int i = a; i < b; i++)
    {
        for (int j = a; j < b; j++)
        {
            // ��� ����
            if ((i >= remove_a && i <= remove_b) && (j >= remove_a && j <= remove_b))
            {
                cout << " ";
            }
            else
                cout << "*";
        }
        cout << "\n";
    }
}

void func_2447()
{
    int a;
    cin >> a;
    func_2447_starPrint(a, 0, a);
}

/* �ϳ��� ž �̵� ����
 * https://www.acmicpc.net/problem/11729
 */
int func_11729_hanoi(int n, int from, int to)
{
    if (n == 1)
    {
        cout << from << " " << to << "\n";
        return 0;
    }
    func_11729_hanoi(n - 1, from, 6 - from - to);
    cout << from << " " << to << "\n";
    func_11729_hanoi(n - 1, 6 - from - to, to);
}

void func_11729()
{
    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n";
    func_11729_hanoi(n, 1, 3);
}

/*
 *  ****************************
 *  �ܰ躰 Ǯ��� > ���Ʈ����
 *  ****************************
 */

/* ������ (����� 2)
 * https://www.acmicpc.net/problem/2798
 */
void func_2798()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, m, min, res = 0, sum = 0;
    cin >> n >> m;
    int *card = new int[n];
    bool is_flag;

    for (int i = 0; i < n; i++)
    {
        cin >> card[i];
    }

    min = m;
    is_flag = true;

    // for (int i = 0; i < n - 1; i++) {
    //	if (!is_flag) break;
    //	for (int j = i + 1; j < n; j++) {
    //		if (!is_flag) break;
    //		for (int k = j + 1; k < n; k++) {
    //			sum = card[i] + card[j] + card[k];
    //			//cout << "i : " << i << ", j : " << j << ", k : " << k << ", sum : " << sum << endl;
    //			if (sum == m) is_flag = false;
    //			if (min > m - sum && m >= sum) {
    //				min = m - sum;
    //				res = sum;
    //			}
    //		}
    //	}
    // }

    for (int i = 0; i < n - 1 && is_flag; i++)
    {
        for (int j = i + 1; j < n && is_flag; j++)
        {
            for (int k = j + 1; k < n && is_flag; k++)
            {
                sum = card[i] + card[j] + card[k];
                // cout << "i : " << i << ", j : " << j << ", k : " << k << ", sum : " << sum << endl;
                if (sum == m)
                    is_flag = false;

                if (min > m - sum && m >= sum)
                {
                    min = m - sum;
                    res = sum;
                }
            }
        }
    }

    cout << res << endl;
}

/* ������ (����� 2)
 * https://www.acmicpc.net/problem/2231
 */

int func_2231_create_decompose(int a)
{
    int len, res = a;

    len = to_string(a).length();

    for (int i = len; a > 0; i--)
    {
        res += a / pow(10, i);
        a %= (int)pow(10, i);
    }

    return res;
}

void func_2231()
{
    int a, key;
    cin >> a;

    map<int, int> m;

    for (int i = 1; i < a; i++)
    {
        key = func_2231_create_decompose(i);

        if (!m[key])
            m[key] = i;
    }

    cout << m[a];
}

/* ��ġ (�ǹ� 5)
 * https://www.acmicpc.net/problem/7568
 */
void func_7568()
{
    int int_case;
    int cnt;
    int *bulk;

    cin >> int_case;

    map<char, int *> m_input;

    // �Է�
    for (int i = 0; i < int_case; i++)
    {
        bulk = new int[2];

        cin >> bulk[0] >> bulk[1];

        m_input['a' + i] = bulk;
    }

    // ���� �ű��
    for (int i = 0; i < int_case; i++)
    {
        cnt = 1;

        for (int j = 0; j < int_case; j++)
        {
            // ��ġ : Ű�� ũ��, �����Ե� ���ſ� ��� ��
            if (m_input['a' + i][0] < m_input['a' + j][0] && m_input['a' + i][1] < m_input['a' + j][1])
            {
                cnt++;
            }
        }

        // ���� ���
        cout << cnt << " ";
    }

    for (int i = 0; i < int_case; i++)
    {
        delete m_input['a' + i];
    }
}
void func_7568_2()
{
    int int_case, cnt;
    cin >> int_case;
    int **arr = new int *[int_case];
    int *bulk;

    for (int i = 0; i < int_case; i++)
    {
        bulk = new int[2];
        cin >> bulk[0] >> bulk[1];
        arr[i] = bulk;
    }

    for (int i = 0; i < int_case; i++)
    {
        cnt = 1;
        for (int j = 0; j < int_case; j++)
        {
            if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
            {
                cnt++;
            }
        }
        cout << cnt << " ";
    }
}

/* ü���� �ٽ� ĥ�ϱ� (�ǹ� 5)
 * https://www.acmicpc.net/problem/1018
 */

int func_1018_bitmask(char **_map)
{
    int cnt_1 = 0, cnt_2 = 0;
    char filter_1[8][8] = {
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0}};
    char filter_2[8][8] = {
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1}};

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (!(_map[i][j] ^ filter_1[i][j]))
            {
                cnt_1++;
            }
            if (!(_map[i][j] ^ filter_2[i][j]))
            {
                cnt_2++;
            }
        }
    }

    if (cnt_1 >= cnt_2)
        return cnt_2;
    else
        return cnt_1;
}

void func_1018()
{
    int n, m;
    int min, cnt;
    string tmp;
    cin >> n >> m;

    char **tmp_map = new char *[8];
    for (int i = 0; i < 8; i++)
    {
        tmp_map[i] = new char[8];
    }
    char **bwmap = new char *[n];
    for (int i = 0; i < n; i++)
    {
        bwmap[i] = new char[m];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            if (tmp[j] == 'B')
            {
                bwmap[i][j] = 1;
            }
            else
            {
                bwmap[i][j] = 0;
            }
        }
    }

    // cout << "���\n";
    cnt = 0;
    min = 64;
    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
        {
            // cout << i << ", " << j << " ���\n";
            for (int a = i, aa = 0; a < i + 8; a++, aa++)
            {
                for (int b = j, bb = 0; b < j + 8; b++, bb++)
                {
                    // cout << (int)bwmap[a][b];
                    tmp_map[aa][bb] = bwmap[a][b];
                }
                // cout << "\n";
            }
            cnt = func_1018_bitmask(tmp_map);
            if (cnt < min)
            {
                min = cnt;
            }
        }
        // cout << "\n\n";
    }
    cout << min << "\n";
}

/* ��ȭ���� �� (�ǹ� )
 * https://www.acmicpc.net/problem/1436
 */
void func_1436()
{
    int n, cnt = 0;
    string tmp;

    cin >> n;

    for (int i = 666; i < 2100000000; i++)
    {
        tmp = to_string(i);
        if (tmp.find("666") != string::npos)
        {
            cnt++;

            if (cnt > 10000)
                break;
            if (cnt == n)
            {
                cout << cnt << "���� �� : " << tmp << "\n";
            }
        }
    }
}

/*
 *  **********************
 *  �ܰ躰 Ǯ��� > ����
 *  **********************
 */

/* �� �����ϱ�
 * https://www.acmicpc.net/problem/2750
 */
void func_2750()
{
    int a, num;
    vector<int> v;
    cin >> a;

    for (int i = 0; i < a; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << "\n";
    }
}

/* �� �����ϱ� 2
 * https://www.acmicpc.net/problem/2751
 */
void func_2751()
{
    int a, num;
    vector<int> v;
    cin >> a;

    for (int i = 0; i < a; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << "\n";
    }
}

/* �� �����ϱ� 3
 * https://www.acmicpc.net/problem/10989
 */
void func_10989()
{
    int a, num;
    map<int, int> m;
    map<int, int>::iterator iter;
    cin >> a;

    for (int i = 0; i < a; i++)
    {
        cin >> num;
        if (m[num] == 0)
            m[num] = 1;
        else
            m[num]++;
    }

    for (iter = m.begin(); iter != m.end(); iter++)
    {
        for (int i = 0; i < iter->second; i++)
        {
            cout << iter->first << "\n";
        }
    }
}

/* �����
 * https://www.acmicpc.net/problem/2108
 */
void func_2108()
{
    int a;
    double tmp, sum, aver, max, min_val, max_val;

    cin >> a;
    map<double, int> m;
    vector<double> v, v_mode;

    // �Է�, ���� �߰�, map ���� ����, �հ�
    sum = 0;
    for (int i = 0; i < a; i++)
    {
        cin >> tmp;

        v.push_back(tmp);

        if (m[tmp] == 0)
        {
            m[tmp] = 1;
        }
        else
        {
            m[tmp]++;
        }

        sum += tmp;
    }

    // 1. ������, �Ҽ��� ���� ù° �ڸ� �ݿø� ��
    aver = accumulate(v.begin(), v.end(), 0.0) / v.size();
    printf("%.0f\n", aver <= 0 && aver > -1 ? (int)aver : aver);

    // 2. �߾Ӱ�  - �߾ӿ� ��ġ�� ��
    int cnt = 0;
    int index = (int)floor(a / 2);
    sort(v.begin(), v.end());

    cout << v.at(index) << "\n";

    // 3. �ֺ� - ���� ���� ���� ��
    max = 0;
    for (auto num : m)
    {
        if (num.second > max)
        {
            max = num.second;
        }
    }
    // cout << "�ֺ� " << max << "\n";
    cnt = 0;
    for (auto num : m)
    {
        if (num.second == max)
        {
            v_mode.push_back(num.first);
        }
    }

    if (v_mode.size() > 1)
    {
        sort(v_mode.begin(), v_mode.end());
        cout << v_mode.at(1) << "\n";
    }
    else
    {
        cout << v_mode.at(0) << "\n";
    }

    // 4. ���� -> ���� ���� �� ~ ���� ū ��
    min_val = v.at(0);
    max_val = v.at(v.size() - 1);
    cout << max_val - min_val << "\n";
}

/* ��Ʈ�λ��̵�
 * https://www.acmicpc.net/problem/1427
 */
void func_1427()
{
    vector<char> v;
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        v.push_back(str[i]);
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (auto v_tmp : v)
    {
        cout << v_tmp;
    }
}

/* ��ǥ �����ϱ�
 * https://www.acmicpc.net/problem/11650
 */
void func_11650()
{
    int a, b, test_case;
    vector<pair<int, int>> v;
    pair<int, int> p;

    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    for (auto v_tmp : v)
    {
        cout << v_tmp.first << " " << v_tmp.second << "\n";
    }
}

/* ��ǥ �����ϱ� 2
 * https://www.acmicpc.net/problem/11651
 */
void func_11651()
{
    int a, b, test_case;
    vector<pair<int, int>> v;
    pair<int, int> p;

    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        cin >> a >> b;
        v.push_back({b, a});
    }

    sort(v.begin(), v.end());

    for (auto v_tmp : v)
    {
        cout << v_tmp.second << " " << v_tmp.first << "\n";
    }
}

/* �ܾ� ����
 * https://www.acmicpc.net/problem/1181
 */
void func_1181()
{
    map<int, vector<string>> m;
    int test_case, str_len, str_len_max = 0;
    string str;
    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        cin >> str;
        str_len = str.length();
        m[str_len].push_back(str);
        if (str_len > str_len_max)
            str_len_max = str_len;
    }

    for (int i = 1; i <= str_len_max; i++)
    {
        sort(m[i].begin(), m[i].end());
        m[i].erase(unique(m[i].begin(), m[i].end()), m[i].end());
    }

    for (int i = 1; i <= str_len_max; i++)
    {
        for (auto v : m[i])
        {
            cout << v << "\n";
        }
    }
}

/* ���̼� ����
 * https://www.acmicpc.net/problem/10814
 */
void func_10814()
{
    int test_case;
    cin >> test_case;

    int age;
    string name;
    map<int, vector<string>> m;

    for (int i = 0; i < test_case; i++)
    {
        cin >> age >> name;
        m[age].push_back(name);
    }

    for (auto m_tmp : m)
    {
        for (auto m_name : m_tmp.second)
        {
            cout << m_tmp.first << " " << m_name << "\n";
        }
    }
}

/* ��ǥ ����
 * https://www.acmicpc.net/problem/18870
 */
void func_18870()
{
    int test_case;
    cin >> test_case;

    int tmp;
    map<int, int> m;
    vector<int> v_origin;

    for (int i = 0; i < test_case; i++)
    {
        cin >> tmp;
        v_origin.push_back(tmp);
    }

    vector<int> v_sort(v_origin);
    sort(v_sort.begin(), v_sort.end());
    v_sort.erase(unique(v_sort.begin(), v_sort.end()), v_sort.end());

    for (int i = 0; i < v_sort.size(); i++)
    {
        m[v_sort[i]] = i;
    }

    for (auto v_tmp : v_origin)
    {
        cout << m[v_tmp] << " ";
    }
}

/*
 *  ************************************
 *  �ܰ躰 Ǯ��� > ���� ��ȹ�� 1
 *  ************************************
 */

/* �Ǻ���ġ �Լ�
 * https://www.acmicpc.net/problem/1003
 */
void func_1003()
{
    int test_case;
    cin >> test_case;

    vector<pair<int, int>> f;
    // 0��° ���� ���� - 0�� 1, 0
    f.push_back({1, 0});
    // 1��° ���� ���� - 1�� 0, 1
    f.push_back({0, 1});

    for (int i = 2; i <= 40; i++)
    {
        f.push_back({f.at(i - 1).first + f.at(i - 2).first, f.at(i - 1).second + f.at(i - 2).second});
        // cout << f.at(i).first << ", " << f.at(i).second << "\n";
    }

    int *n = new int[test_case];
    for (int i = 0; i < test_case; i++)
    {
        cin >> n[i];
        cout << f.at(n[i]).first << " " << f.at(n[i]).second << "\n";
    }
}

/* �ų��� �Լ� ����
 * https://www.acmicpc.net/problem/9184
 */
int func_9184_w(int dp[51][51][51], int a, int b, int c)
{
    // a, b, c �� �ϳ��� 0���� �۰ų� ������ 1
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }

    // �ϳ��� 20�̻��̸� 20, 20, 20 ȣ��
    if (a > 20 || b > 20 || c > 20)
    {
        return func_9184_w(dp, 20, 20, 20);
    }

    // ���� ������ �ѹ��� �ʱ�ȭ
    if (dp[a][b][c] != 0)
    {
        return dp[a][b][c];
    }

    if (a < b && b < c)
    {
        dp[a][b][c] = func_9184_w(dp, a, b, c - 1) + func_9184_w(dp, a, b - 1, c - 1) - func_9184_w(dp, a, b - 1, c);
        // dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b-1][c];
    }
    else
    {
        dp[a][b][c] = func_9184_w(dp, a - 1, b, c) + func_9184_w(dp, a - 1, b - 1, c) + func_9184_w(dp, a - 1, b, c - 1) - func_9184_w(dp, a - 1, b - 1, c - 1);
        // dp[a][b][c] = dp[a-1][b][c] + dp[a-1][b-1][c] + dp[a-1][b][c-1] - dp[a-1][b-1][c-1];
    }

    return dp[a][b][c];
}

void func_9184()
{
    int a, b, c;
    int dp[51][51][51] = {
        0,
    };

    while (1)
    {
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }
        else
        {
            if (a <= 0 || b <= 0 || c <= 0)
            {
                cout << "w(" << a << ", " << b << ", " << c << ") = 1\n";
            }
            else
            {
                cout << "w(" << a << ", " << b << ", " << c << ") = " << func_9184_w(dp, a, b, c) << "\n";
            }
        }
    }
}

/* 01Ÿ�� (�ǹ� 3)
 * https://www.acmicpc.net/problem/1904
 */
void func_1904()
{
}

/* �ĵ��� ���� (�ǹ� 3)
 * https://www.acmicpc.net/problem/9461
 */
void func_9461()
{
}

/* ����� �賶
 * https://www.acmicpc.net/problem/12865
 */
void func_12865()
{
}

/*
 *  **************************************
 *  �ܰ躰 Ǯ��� > �׸��� �˰�����
 *  **************************************
 */

/* ���� 0 (�ǹ� 3)
 * https://www.acmicpc.net/problem/11047
 */
void func_11047()
{
    int n, k, tmp;
    map<int, int> m;
    map<int, int>::reverse_iterator reiter;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        m[tmp] = 0;
    }

    for (reiter = m.rbegin(); reiter != m.rend(); reiter++)
    {
        while (reiter->first <= k)
        {
            cout << "coin : " << reiter->first << "\n";
            m[reiter->first]++;
            k -= reiter->first;
        }

        if (k <= 0)
            break;
    }

    tmp = 0;
    for (reiter = m.rbegin(); reiter != m.rend(); reiter++)
    {
        if (reiter->second > 0)
        {
            tmp += reiter->second;
        }
    }

    cout << tmp << "\n";
}

/* ȸ�ǽ� ���� (�ǹ� 2)
 * https://www.acmicpc.net/problem/1931
 */
void func_1931()
{
    int test_case;
    int a, b;

    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        cin >> a >> b;
    }
}

/* ATM (�ǹ� 3)
 * https://www.acmicpc.net/problem/11399
 */
void func_11399()
{
    int test_case;
    int a, sum = 0;

    vector<int> v;

    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < test_case; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sum += v[j];
        }
    }

    cout << sum << "\n";
}

/*
 *  ********************************
 *  �ܰ躰 Ǯ��� > DFS�� BFS
 *  ********************************
 */

/*  DFS�� BFS
 *   https://www.acmicpc.net/problem/1260
 */
void func_1260_graphPrint(map<int, vector<int>> graph)
{
    for (auto node : graph)
    {
        cout << node.first << " : ";
        for (auto nd : node.second)
        {
            cout << nd << " ";
        }
        cout << "\n";
    }
}

void func_1260_dfs_recursion(int n, vector<int> *graph, bool *visited)
{
    visited[n] = true;
    cout << n << " ";

    for (auto node : graph[n])
    {
        if (!visited[node])
        {
            func_1260_dfs_recursion(node, graph, visited);
        }
    }
}

void func_1260_dfs_stack()
{
}

void func_1260_bfs_queue(int n, vector<int> *graph, bool *visited)
{
    queue<int> q;
    int now_node;

    visited[n] = true;
    q.push(n);

    while (!q.empty())
    {
        now_node = q.front();
        q.pop();
        cout << now_node << " ";

        for (auto node : graph[now_node])
        {
            if (!visited[node])
            {
                visited[node] = true;
                q.push(node);
            }
        }
    }
}

void func_1260_bfs_queue_matrix(int n, int **graph, bool *visited)
{
    queue<int> q;
    int now_node;

    visited[n] = true;
    q.push(n);

    while (!q.empty())
    {
        now_node = q.front();
        q.pop();
        cout << now_node << " ";

        for (int i = 0; i < sizeof(graph[n]); i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void func_1260()
{
    int n, m, start_node, u, v;

    cin >> n >> m >> start_node;

    // map<int, vector<int>> graph;

    vector<int> *graph = new vector<int>[n + 1];

    bool *visited = new bool[n + 1];
    memset(visited, 0, sizeof(bool) * (n + 1));

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    func_1260_dfs_recursion(start_node, graph, visited);
    cout << "\n";

    memset(visited, 0, sizeof(bool) * (n + 1));
    func_1260_bfs_queue(start_node, graph, visited);
}

void func_1260_matrix()
{
    int n, m, start_node, u, v;

    cin >> n >> m >> start_node;

    // ������� ����
    int **graph = new int *[n];
    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n];
    }

    bool *visited = new bool[n + 1];
    memset(visited, 0, sizeof(bool) * (n + 1));

    // ������� �ʱ�ȭ
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    // ���� �Է�
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        // ������ �׷���
        graph[u][v] = graph[v][u] = 1;
    }

    // ������� ���
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    func_1260_bfs_queue_matrix(start_node, graph, visited);
}

/*  ���̷���
 *   https://www.acmicpc.net/problem/2606
 */
static int func_2606_cnt;

void func_2606_dfs(int start, vector<int> *graph, bool *visited)
{
    visited[start] = true;
    // cout << start << " ";

    func_2606_cnt++;

    for (auto node : graph[start])
    {
        if (!visited[node])
        {
            func_2606_dfs(node, graph, visited);
        }
    }
}

void func_2606()
{
    int n, m, u, v;

    cin >> n;
    cin >> m;

    vector<int> *graph = new vector<int>[n + 1];

    // ��� ���� +1��
    bool *visited = new bool[n + 1];
    memset(visited, 0, sizeof(bool) * (n + 1));

    func_2606_cnt = 0;

    // ���� �Է�
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    func_2606_dfs(1, graph, visited);

    cout << func_2606_cnt - 1 << "\n";
}

/*  ������ȣ���̱�
 *   https://www.acmicpc.net/problem/2667
 */
void func_2667_HouseComplex_Detection(int n, int **map)
{
    bool is_comp = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j])
            {
                is_comp = true;
            }

            if (is_comp)
            {
            }
        }
    }
}

vector<int> *func_2667_Convert_adjMatrix_to_adjList(int n, int **matrix)
{
    vector<int> *adjlist = new vector<int>[n + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1 && i != j)
            {
                adjlist[i + 1].push_back(j + 1);
            }
        }

        sort(adjlist[i + 1].begin(), adjlist[i + 1].end());
    }

    return adjlist;
}

int func_2667_bfs(int cnt, int n, queue<pair<int, int>> q, int **map, int **v)
{
    int _x, _y, a = 0;
    pair<int, int> now, tmp;

    int **direc = new int *[4];
    for (int i = 0; i < 4; i++)
    {
        direc[i] = new int[2];
        if (i == 0)
        {
            _x = 0;
            _y = -1;
        }
        else if (i == 1)
        {
            _x = 1;
            _y = 0;
        }
        else if (i == 2)
        {
            _x = 0;
            _y = 1;
        }
        else if (i == 3)
        {
            _x = -1;
            _y = 0;
        }
        direc[i][0] = _x;
        direc[i][1] = _y;
    }

    while (!q.empty())
    {
        now = q.front();
        q.pop();
        if (v[now.first][now.second] != 1)
        {
            v[now.first][now.second] = 1;
            a++;
        }

        for (int i = 0; i < 4; i++)
        {
            _x = now.first + direc[i][0];
            _y = now.second + direc[i][1];

            if (_x < 0 || _x >= n)
            {
                continue;
            }
            if (_y < 0 || _y >= n)
            {
                continue;
            }

            if (map[_x][_y] == 0)
            {
                continue;
            }

            if (v[_x][_y] == 1)
            {
                continue;
            }

            // �湮���� ���� ��ǥ�ε� ���� 1���� ũ�� ���� ī��Ʈ�� ����� �� �湮ó��
            if (map[_x][_y] >= 1)
            {
                v[_x][_y] = 1;
                map[_x][_y] = cnt;
                q.push({_x, _y});
                // cout << _x << ", " << _y << "\n";
                a++;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        delete direc[i];
    }

    return a;
}

void func_2667()
{
    int n, cnt = 0;
    string str;
    queue<pair<int, int>> q;
    vector<int> m;
    int tmp_m;

    cin >> n;

    int **v = new int *[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            v[i][j] = 0;
        }
    }

    int **_map = new int *[n];
    for (int i = 0; i < n; i++)
    {
        str = "";
        _map[i] = new int[n];

        cin >> str;
        for (int j = 0; j < n; j++)
        {
            _map[i][j] = str[j] - '0';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (_map[i][j] == 1)
            {
                q.push({i, j});

                tmp_m = func_2667_bfs(cnt + 1, n, q, _map, v);
                if (tmp_m != 0)
                {
                    m.push_back(tmp_m);
                    cnt++;
                }
            }
        }
    }

    sort(m.begin(), m.end());

    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++)
    {
        cout << m[i] << "\n";
    }
}

/*  �̷�Ž��
 *   https://www.acmicpc.net/problem/2178
 */

class func_2178_node
{
public:
    int x;
    int y;
    int value;
    int visited;
};

int func_2178_BFS(int n, int m, func_2178_node **_map, int *start_node, int *end_node)
{
    // BFS Ž���� ���� ť ���� ���� ��� ����
    queue<func_2178_node> q;
    func_2178_node tmp_node, now_node;

    // ��0, ��1, ��2, ��3
    int **direction = new int *[4];
    for (int i = 0; i < 4; i++)
    {
        direction[i] = new int[2];

        if (i == 0)
        {
            direction[i][0] = 0;
            direction[i][1] = -1;
        }
        if (i == 1)
        {
            direction[i][0] = 1;
            direction[i][1] = 0;
        }
        if (i == 2)
        {
            direction[i][0] = 0;
            direction[i][1] = 1;
        }
        if (i == 3)
        {
            direction[i][0] = -1;
            direction[i][1] = 0;
        }

        // cout << i << " - " << direction[i][0] << ", " << direction[i][1] << "\n";
    }

    // ���۳���� �湮 ���� ����
    _map[start_node[0]][start_node[1]].visited = 1;
    // ���۳�� �ֱ�
    q.push(_map[start_node[0]][start_node[1]]);

    // ť�� ���� ������ Ž�� ����
    while (!q.empty())
    {
        // ���� ť�� �� �������� + pop
        now_node = q.front();
        q.pop();

        // ���� ��� Ž�� (�ð�������� Ž��)
        for (int i = 0; i < 4; i++)
        {
            // ���� ��ǥ�� �¿츦 �Ѿ���� Ȯ�� (�Ѿ�� continue)
            if (now_node.x + direction[i][0] <= 0 || now_node.x + direction[i][0] > n)
            {
                continue;
            }

            // ���� ��ǥ�� ���ϸ� �Ѿ���� Ȯ�� (�Ѿ�� continue)
            if (now_node.y + direction[i][1] <= 0 || now_node.y + direction[i][1] > m)
            {
                continue;
            }

            // �̵��� ���� �� �ȿ� ������ ��� �̵�
            tmp_node = _map[now_node.x + direction[i][0]][now_node.y + direction[i][1]];

            // ���� 1�� �ƴ��� �˻�, �ƴϸ� continue;
            if (tmp_node.value == 0)
            {
                continue;
            }

            // ���� 1�̰�, �湮 ���ΰ� ������ �˻� (�湮������ ������)
            if (tmp_node.visited)
            {
                continue;
            }

            // ���� ��尡 �� �ȿ� �ְ�, �̵��� �����ϸ�, �湮�� ���� ���ٸ� ť�� ����ϰ� �湮���� �ٲٰ� Ž��Ƚ�� ����
            _map[tmp_node.x][tmp_node.y].visited = _map[now_node.x][now_node.y].visited + 1;
            q.push(_map[tmp_node.x][tmp_node.y]);

            // cout << "tmp_node[" << tmp_node.x << "][" << tmp_node.y << "] "<< _map[tmp_node.x][tmp_node.y].visited << " -> Ž�� �Ϸ� \n";
        }

        // �湮 ���� ���
        /*
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << _map[i][j].visited << "";
            }
            cout << "\n";
        }
        cout << "\n";
        */
    }

    return _map[n][m].visited;
}

void func_2178()
{
    int n, m;
    int *start_node = new int[2];
    int *end_node = new int[2];
    string str_input;

    cin >> n >> m;

    start_node[0] = 1;
    start_node[1] = 1;
    end_node[0] = n;
    end_node[1] = m;

    // ��� �� �ʱ�ȭ
    func_2178_node **map = new func_2178_node *[n + 1];
    for (int i = 1; i <= n; i++)
    {
        map[i] = new func_2178_node[m + 1];
    }

    // �Է� �� �ʱ�ȭ
    for (int i = 1; i <= n; i++)
    {
        cin >> str_input;
        for (int j = 1; j <= m; j++)
        {
            map[i][j].x = i;
            map[i][j].y = j;
            map[i][j].value = str_input[j - 1] - '0';
            map[i][j].visited = 0;
        }
    }

    cout << func_2178_BFS(n, m, map, start_node, end_node) << "\n";
}

/*  ����� ����
 *   https://www.acmicpc.net/problem/1012
 */
class func_1012_node
{
public:
    int x;
    int y;
    int value;
    bool visited;
};

int func_1012_bfs_v1(int n, int m, queue<func_1012_node> q, func_1012_node **_map, int **direction)
{
    int a = 0, _x, _y;
    func_1012_node now;

    while (!q.empty())
    {
        now = q.front();
        q.pop();

        if (_map[now.x][now.y].visited != true)
        {
            // cout << now.x << now.y << "\n";
            _map[now.x][now.y].visited = true;
            // a++;
        }

        for (int i = 0; i < 4; i++)
        {
            _x = now.x + direction[i][0];
            _y = now.y + direction[i][1];

            if (_x < 0 || _x >= n)
            {
                continue;
            }
            if (_y < 0 || _y >= m)
            {
                continue;
            }

            // ���� 0�̸� ����
            if (_map[_x][_y].value == 0)
            {
                continue;
            }

            // value�� 0�� �ƴѵ�, �湮�� �Ǿ� ������ ����
            if (_map[_x][_y].visited == true)
            {
                continue;
            }

            // cout << " <- next : " << _x << ", " << _y << "\n";

            _map[_x][_y].visited = true;
            q.push(_map[_x][_y]);
            a++;
        }
    }

    return a;
}

void func_1012_v1()
{
    int test_case, tmp_res;
    int n, m, k;
    int u, v;
    int cnt;
    int _x, _y;
    bool is_flag;
    func_1012_node **_map;
    queue<func_1012_node> q;

    // 4���� ����
    int **_direction = new int *[4];
    for (int i = 0; i < 4; i++)
    {
        _direction[i] = new int[2];
        if (i == 0)
        {
            _x = 0;
            _y = -1;
        }
        else if (i == 1)
        {
            _x = 1;
            _y = 0;
        }
        else if (i == 2)
        {
            _x = 0;
            _y = 1;
        }
        else if (i == 3)
        {
            _x = -1;
            _y = 0;
        }

        _direction[i][0] = _x;
        _direction[i][1] = _y;
    }

    cin >> test_case;

    for (int a = 0; a < test_case; a++)
    {
        cin >> m >> n >> k;

        cnt = 0;
        is_flag = false;

        // map ���� �� �ʱ�ȭ
        _map = new func_1012_node *[n];
        for (int i = 0; i < n; i++)
        {
            _map[i] = new func_1012_node[m];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                _map[i][j].x = i;
                _map[i][j].y = j;
                _map[i][j].value = 0;
                _map[i][j].visited = 0;
            }
        }

        // Map ������Ʈ
        for (int i = 0; i < k; i++)
        {
            cin >> u >> v;
            _map[u][v].value = 1;
        }

        // �׷��� ���
        // for (int i = 0; i < n; i++) {
        //	for (int j = 0; j < m; j++) {
        //		cout << _map[i][j].value;
        //	}
        //	cout << "\n";
        //}

        cnt = 0;
        // �湮 ��� Ȯ���ϸ鼭 Map Ž��
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // ���� _map[i][j].value == 1�̸� bfs ����(bfs ����� 0�̾ƴϸ� �׷��� ���� ī����)
                if (_map[i][j].value == 1)
                {
                    // cout << i << ", " << j << "\n";

                    // �ֺ��� 1���� 1���� üũ
                    is_flag = false;
                    for (int int_direc = 0; int_direc < 4; int_direc++)
                    {
                        _x = i + _direction[int_direc][0];
                        _y = j + _direction[int_direc][1];

                        // 1�� ��� �ֺ��� �ϳ��� 1�̸� �÷���
                        if (_x < 0 || _x >= n)
                        {
                            continue;
                        }
                        if (_y < 0 || _y >= m)
                        {
                            continue;
                        }

                        if (_map[_x][_y].value == 1)
                        {
                            is_flag = true;
                            break;
                        }
                    }

                    // �ֺ��� �� 0�̰� ���� ��� �湮���� ������ �ܵ����
                    if (!is_flag && _map[i][j].visited == 0)
                    {
                        cnt++;
                        _map[i][j].visited = 1;
                        // cout << "Alone Node\n";
                        continue;
                    }

                    // �ܵ���尡 �ƴϸ� bfs
                    q.push(_map[i][j]);

                    tmp_res = func_1012_bfs_v1(n, m, q, _map, _direction);
                    if (tmp_res != 0)
                    {
                        cnt++;
                        // cout << "visit : " << tmp_res  << " find : " << cnt << "\n";
                    }
                }

                // cout << _map[i][j].value << "";
            }
            // cout << "\n";
        }

        cout << cnt << "\n";

        //// �׷��� ���
        // for (int i = 0; i < n; i++) {
        //	for (int j = 0; j < m; j++) {
        //		cout << _map[i][j].visited;
        //	}
        //	cout << "\n";
        // }

        //// �޸� ����
        for (int j = 0; j < n; j++)
        {
            delete _map[j];
        }
    }

    ////
    for (int i = 0; i < 4; i++)
    {
        delete _direction[i];
    }
}

void func_1012()
{
    int test_case;
    int n, m, k;
    int u, v;
    int _x, _y;
    pair<int, int> dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // ��, ��, ��, ��
    pair<int, int> tmp_q;
    int graph_count = 0;

    int **_map;
    int **_visit;
    queue<pair<int, int>> q;

    cin >> test_case;
    for (int a = 0; a < test_case; a++)
    {
        cin >> m >> n >> k;

        // Map ���� �� �ʱ�ȭ
        _map = new int *[n];
        _visit = new int *[n];

        for (int i = 0; i < n; i++)
        {
            _map[i] = new int[m];
            _visit[i] = new int[m];

            memset(_map[i], 0, sizeof(int) * m);
            memset(_visit[i], 0, sizeof(int) * m);
        }

        // Map ������Ʈ
        for (int i = 0; i < k; i++)
        {
            cin >> u >> v;
            _map[v][u] = 1;
        }

        graph_count = 0;

        // Map Ž��
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                // �������� ���� ��ǥ�� 1�̰� �湮�� ���� ������ ���� ��ǥ�� q�� ����ϰ� �湮 ó��
                if (_map[i][j] == 1 && _visit[i][j] != 1)
                {
                    // cout << "���� ��� �߰� : {" << i << ", " << j << "}\n";
                    q.push({i, j});
                    _visit[i][j] = 1;

                    graph_count++;
                }

                // q�� ���� ������
                while (!q.empty())
                {
                    tmp_q = q.front();
                    q.pop();

                    // ���� ��ǥ���� ������ 4���� ��ǥ�� �˻�, ������ �ð����
                    for (int i = 0; i < 4; i++)
                    {
                        _x = tmp_q.first + dir[i].first;
                        _y = tmp_q.second + dir[i].second;

                        // ��輱 �˻�
                        if (_x >= n || _x < 0)
                            continue;

                        if (_y >= m || _y < 0)
                            continue;

                        // �� �˻�
                        if (_map[_x][_y] == 0)
                            continue;

                        // �湮���� �˻�
                        if (_visit[_x][_y] == 1)
                            continue;

                        // �湮��� ����� ���� �۾���� �߰�
                        _visit[_x][_y] = 1;
                        q.push({_x, _y});
                    }
                }

                //// �� ���
                // for (int i = 0; i < n; i++) {
                //	for (int j = 0; j < m; j++) {
                //		cout << _visit[i][j];
                //	}
                //	cout << "\n";
                // }
            }
        }

        cout << graph_count << "\n";

        // �޸� ����
        for (int i = 0; i < n; i++)
        {
            free(_map[i]);
            free(_visit[i]);
        }
    }
}

/*  �丶�� (��� 5)
 *   https://www.acmicpc.net/problem/7576
 */
class func_7576_tomato
{
public:
    int x;
    int y;
    int visited;
    int value;
};

void func_7576_print(int n, int m, func_7576_tomato **box)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << box[i][j].value;
        }
        cout << "\n";
    }
}

void func_7576_bfs(int n, int m, func_7576_tomato **box, queue<func_7576_tomato> q)
{
    func_7576_tomato now_tomato, tmp_tomato;

    // ���� ���� (�ð����)
    int **direc = new int *[4];
    int _x, _y;
    for (int i = 0; i < 4; i++)
    {
        direc[i] = new int[2];

        // ��
        if (i == 0)
        {
            _x = 0;
            _y = -1;
        }
        // ��
        if (i == 1)
        {
            _x = 1;
            _y = 0;
        }
        // ��
        if (i == 2)
        {
            _x = 0;
            _y = 1;
        }
        // ��
        if (i == 3)
        {
            _x = -1;
            _y = 0;
        }

        direc[i][0] = _x;
        direc[i][1] = _y;
    }

    // bfs Ž�� ����
    while (!q.empty())
    {
        now_tomato = q.front();
        q.pop();

        // �� ���⺰ Ž��
        for (int i = 0; i < 4; i++)
        {
            // �̵��� ������ �丶�� ���� �������� �˻� (x��)
            if (now_tomato.x + direc[i][0] < 0 || now_tomato.x + direc[i][0] >= n)
            {
                continue;
            }
            // �̵��� ������ �丶�� ���� �������� �˻� (y��)
            if (now_tomato.y + direc[i][1] < 0 || now_tomato.y + direc[i][1] >= m)
            {
                continue;
            }

            tmp_tomato = box[now_tomato.x + direc[i][0]][now_tomato.y + direc[i][1]];

            // �ش� ��ġ�� ������ �˻�
            if (tmp_tomato.value != 0)
            {
                continue;
            }

            // �ش� ��ġ�� �������� ���� �丶�䰡 ������ ���� ��Ű�� �� ������ �������״��� �Է� �� ť�� ���
            box[tmp_tomato.x][tmp_tomato.y].value = 1;
            box[tmp_tomato.x][tmp_tomato.y].visited = now_tomato.visited + 1;
            q.push(box[tmp_tomato.x][tmp_tomato.y]);
        }

        cout << "\n";
        func_7576_print(n, m, box);
    }

    // �޸� ����
    for (int i = 0; i < 4; i++)
    {
        delete direc[i];
    }
    delete direc;
}

void func_7576()
{
    int m, n, tmp, max;
    queue<func_7576_tomato> q;

    // ��� ����
    cin >> m >> n;

    // ��� ����
    func_7576_tomato **box = new func_7576_tomato *[n];
    for (int i = 0; i < n; i++)
    {
        box[i] = new func_7576_tomato[m];
    }

    // �ʱ�ȭ
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            box[i][j].x = i;
            box[i][j].y = j;
            box[i][j].visited = 0;
            box[i][j].value = 0;
        }
    }

    // �Է°� �ޱ�, �Է¿� ���� �� ����
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tmp;
            box[i][j].value = tmp;

            // �Է� ���� 1�̸� ť�� ���
            if (tmp == 1)
            {
                q.push(box[i][j]);
            }
        }
    }

    func_7576_bfs(n, m, box, q);

    max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // �����ȵ� �丶�䰡 ������ -1
            if (box[i][j].value == 0)
            {
                max = -1;
                break;
            }
            // �ִ밪 ã�Ƽ� ����
            if (max < box[i][j].visited)
            {
                max = box[i][j].visited;
            }
        }
        if (max == -1)
        {
            break;
        }
    }

    cout << max << "\n";

    // �ڽ� ����
    for (int i = 0; i < n; i++)
    {
        delete box[i];
    }

    // return 0;
}

/*  �丶�� (��� 5)
 *   https://www.acmicpc.net/problem/7569
 */
void func_7569()
{
}
