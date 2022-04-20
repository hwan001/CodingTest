#include "header.h"

void (*func)() = func_1654;

int main() {
	while(1) func();

	return 0;
}


/*
#include <stdio.h>

int number = 5;
int INF = 10000000;

int a[5][5] = {
	{0, 9, 1, INF, INF},
	{INF, 0, INF, INF, 1},
	{INF, INF, 0, 1, INF},
	{INF, 1, INF, 0, INF},
	{INF, INF, INF, INF, 0}
};

int a2[6][6] = {
{0, 3, 2, INF, 1, INF},
{INF, 0, 1, INF, INF, INF},
{INF, INF, 0, 1, 5, 4},
{INF, INF, INF, 0, INF, 2},
{INF, INF, INF, INF, 0, INF},
{INF, 3, INF, INF, 6, 0},
};

bool v[5];
int d[5];

int getSmallIndex() {
	int min = INF;
	int index = 0;

	for (int i = 0; i < number; i++) {
		if (d[i] < min && !v[i]) {
			min = d[i];
			index = i;
		}
	}

	return index;
}

void pirnt_d() {
	for (int i = 0; i < number; i++) {
		if(d[i] == INF)
			printf("INF ");
		else
			printf("%d ", d[i]);
	}
	printf("\n");
}

void dijkstra(int start) {
	for (int i = 0; i < number; i++) {
		d[i] = a[start][i];
	}

	printf("%c : ", start+'a');
	pirnt_d();

	v[start] = true;
	for (int i = 0; i < number - 1; i++) {
		int current = getSmallIndex();
		printf("%c : ", current + 'a');
		v[current] = true;
		for (int j = 0; j < number; j++) {
			if (!v[j]) {
				if (d[current] + a[current][j] < d[j]) {
					d[j] = d[current] + a[current][j];
					pirnt_d();
				}
			}
		}
		printf("\n");
	}
}
*/