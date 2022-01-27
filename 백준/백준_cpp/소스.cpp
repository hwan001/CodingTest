#include "header.h"

void func_test() {
    int n, m;
    cin >> n >> m; // ������ ������ ������ �Է¹���

    int ** graph = new int*[n];
    for (int i = 0; i <= n; i++)
        graph[i] = new int[m];


    // ���� -1�� �ʱ�ȭ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            graph[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1; // �����
        //graph[u][v] = 1; // �ܹ���
        // ����ġ�� �ִ� ��� �ܹ����� ��� graph[u][v] = ����ġ��;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void (*func)() = func_2231;

int main() {
    func();

	return 0;
}