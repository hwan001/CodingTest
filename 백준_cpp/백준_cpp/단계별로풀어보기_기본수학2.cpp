#include "header.h"


/* �ܰ躰 Ǯ��� >> �⺻ ���� 2 >> �Ҽ� ã��
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


/* �ܰ躰 Ǯ��� >> �⺻ ���� 2 >> �Ҽ�
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


/* �ܰ躰 Ǯ��� >> �⺻ ���� 2 >> ���μ�����
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


/* �ܰ躰 Ǯ��� >> �⺻ ���� 2 >> �Ҽ� ���ϱ�
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


/* �ܰ躰 Ǯ��� >> �⺻ ���� 2 >> ����Ʈ�� ����
* https://www.acmicpc.net/problem/4948
*/
void func_4948() {
    int int_N, cnt;
    bool* arr = Sieve_of_Eratosthenes(123456 * 2);

    do {
        cin >> int_N;
        cnt = 0;
        
        
        for (int i = int_N + 1; i <= int_N*2; i++){
            if (arr[i]) {
                cnt++;
            }
        }

        if(int_N != 0) cout << cnt << endl;
    } while (int_N != 0);

}


/* �ܰ躰 Ǯ��� >> �⺻ ���� 2 >> �������� ����
* https://www.acmicpc.net/problem/9020
*/
void func_9020() {
    int int_a, int_N, int_sum;
    bool* arr = Sieve_of_Eratosthenes(20000);
    int tmp_a, tmp_b, tmp_min;
    vector<int> v;

    cin >> int_a;
    for (int i = 0; i < int_a; i++) {
        cin >> int_N;
        
        // �ʱ�ȭ
        int_sum = 0;
        v.clear();

        // �ش� ������ ���� �Ҽ� ������
        for (int j = 2; j < int_N; j++) {
            if (arr[j]) {
                v.push_back(j);
            }
        }

        tmp_a = 0;
        tmp_b = 0;
        tmp_min = int_N;

        for (int j = 0; j < v.size(); j++) {
            for (int k = 0; k < v.size(); k++) {
                if (int_N == v.at(j) + v.at(k) && tmp_min > abs(v.at(j) - v.at(k))) {
                    tmp_a = v.at(j);
                    tmp_b = v.at(k);
                    tmp_min = abs(v.at(j) - v.at(k));
                }
            }
        }

        if (tmp_a + tmp_b != 0) cout << tmp_a << " " << tmp_b << endl;
    }
}


/* �ܰ躰 Ǯ��� >> �⺻ ���� 2 >> ���簢������ Ż��
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


/* �ܰ躰 Ǯ��� >> �⺻ ���� 2 >> �� ��° ��
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


/* �ܰ躰 Ǯ��� >> �⺻ ���� 2 >> �����ﰢ��
* https://www.acmicpc.net/problem/4153
*/
void func_4153() {
    // ���̵�� : ��Ÿ��� ���� Ȱ��
    int a, b, c;
    int pow_a, pow_b, pow_c, pow_sum;

    while (1) {
        cin >> a >> b >> c;

        pow_a = pow(a, 2);
        pow_b = pow(b, 2);
        pow_c = pow(c, 2);
        pow_sum = pow_a + pow_b + pow_c;

        if (pow_sum == 0)
            break;

        if (pow_a == pow_sum - pow_a || pow_b == pow_sum - pow_b || pow_c == pow_sum - pow_c) {
            cout << "right" << endl;
        }
        else {
            cout << "wrong" << endl;
        }
    }
}


/* �ܰ躰 Ǯ��� >> �⺻ ���� 2 >> �ý� ������
* https://www.acmicpc.net/problem/3053
*/
void func_3053() {
    // cmath ���� pi : M_PI (cmath include �� #define _USE_MATH_DEFINES �ʿ�)
    int r;
    cin >> r;

    // ��Ŭ���� �����п����� ����
    printf("%.6f\n", const_pi() * pow(r, 2));

    // �ý� ������ ������ ���� : �밢�� ���̰� r�� �������� ����
    printf("%.6f\n", pow(2 * r, 2) / 2);
    
}


/* �ܰ躰 Ǯ��� >> �⺻ ���� 2 >> �ͷ�
* https://www.acmicpc.net/problem/1002
*/
void func_1002() {
    int a;
    cin >> a;

    int x1, y1, r1, x2, y2, r2;
    double len;

    for (int i = 0; i < a; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        // �� �� ������ �Ÿ�
        len = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

        // �ݰ��� �Ϻ��ϰ� ��ġ�� ���Ѵ��� ���
        if (len == 0 && r1 - r2 == 0) {
            cout << -1 << endl;
            continue;
        }

        // �������� ������ �ݰ��� �޶� ���� �� ����
        if (len == 0 && r1 - r2 != 0) {
            cout << 0 << endl;
            continue;
        }

        // �ﰢ���� �����Ǹ� 2��, ��ġ�ϸ� 1��, �ȵǸ� 0��
        // ���� ������ �̿��ؼ� Ǭ ��찡 ��κ�, �ﰢ�� �������� Ǭ ���� ��ã��
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