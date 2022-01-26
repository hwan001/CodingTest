#include "header.h"

void func_test() {
    int n, m;
    cin >> n >> m; // 정점과 간선의 개수를 입력받음

    int ** graph = new int*[n];
    for (int i = 0; i <= n; i++)
        graph[i] = new int[m];


     // Visual Studio의 경우
    /* 변수를 통해서 배열을 동적으로 생성할 때
    int ** graph = new int * [n];
    for (int i = 0; i <= n; ++i)
        graph[i] = new int[m];
    */

    // 정적으로 선언했기 때문에 값들을 전부 -1로 초기화
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
        //graph[u][v] = graph[v][u] = 1;
        graph[u][v] = 1;
        // 가중치가 있는 경우 단방향의 경우 graph[u][v] = 가중치값;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void (*func)() = func_test;

int main() {
    func();

	return 0;
}