#include "header.h"

/* ������ > DFS+BFS �ʼ� ����, �ܰ躰�� Ǯ��� >  DFS�� BFS (�ǹ� 2)
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

	// ���� �׷��� ����
	int** graph = new int* [n];
	for (int i = 0; i <= n; i++) {
		graph[i] = new int[m];
	}

	// ���� -1�� �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			graph[i][j] = 0;
		}
	}

	// ���� ���� ��ŭ �ޱ�
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u][v] = graph[v][u] = 1; // �����
	}

	// ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}