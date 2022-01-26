#include "header.h"

/* 문제집 > DFS+BFS 필수 문제, 단계별로 풀어보기 >  DFS와 BFS (실버 2)
*  https://www.acmicpc.net/problem/1260
*/
void func_1260_DFS() {
}

void func_1260_BFS() {
}

void func_1260() {
	int n, m, start_node;
	int u, v;

	cin >> n >> m >> start_node;

	// 동적 그래프 생성
	int** graph = new int* [n];
	for (int i = 0; i <= n; i++) {
		graph[i] = new int[m];
	}

	// 전부 -1로 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			graph[i][j] = 0;
		}
	}

	// 간선 개수 만큼 받기
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u][v] = graph[v][u] = 1; // 양방향
	}

	// 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}