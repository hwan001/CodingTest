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

}


/* �ܰ躰 Ǯ��� >> �⺻ ���� 2 >> �������� ����
* https://www.acmicpc.net/problem/9020
*/
void func_9020() {

}


/* �ܰ躰 Ǯ��� >> �⺻ ���� 2 >> ���簢������ Ż��
* https://www.acmicpc.net/problem/1085
*/
void func_1085() {
    
}


/* �ܰ躰 Ǯ��� >> �⺻ ���� 2 >> �� ��° ��
* https://www.acmicpc.net/problem/3009
*/
void func_3009() {

}


/* �ܰ躰 Ǯ��� >> �⺻ ���� 2 >> �����ﰢ��
* https://www.acmicpc.net/problem/4153
*/
void func_4153() {

}


/* �ܰ躰 Ǯ��� >> �⺻ ���� 2 >> �ý� ������
* https://www.acmicpc.net/problem/3053
*/
void func_3053() {
    
}


/* �ܰ躰 Ǯ��� >> �⺻ ���� 2 >> �ͷ�
* https://www.acmicpc.net/problem/1002
*/
void func_1002() {
    
}