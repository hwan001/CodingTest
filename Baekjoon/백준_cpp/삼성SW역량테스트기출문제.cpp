#include "header.h"

// 구슬 탈출2 (골드1)
void func_13460() {}

// 2048(Easy) (골드2)
void func_12100() {}

// 뱀 (골드 5)
void func_3190() {}

/* 시험 감독(브론즈 2)
*  https://www.acmicpc.net/problem/13458
*/
void func_13458() {
	double n, tmp, b, c, sum;
	double sub_supervisor;

	cin >> n;
	sum = 0;
	vector<double> exam_room;

	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		exam_room.push_back(tmp);
	}

	cin >> b >> c;

	for (auto exam : exam_room) {
		if (exam - b <= 0) continue;
		sum += ceil((exam - b) / c);
	}

	//cout << sum + n << "\n";
	printf("%0.lf\n", sum + n);
}

// 주사위 굴리기 (골드 4)
void func_14499() {}

// 테트로미노 (골드 5)
void func_14500() {}

// 퇴사 (실버 3)
void func_14501() {}

// 연구소 (골드 5)
void func_14502_print(int **_map, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << _map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int func_14502_combination(int n, int r) {
	if (n == r || r == 0) {
		return 1;
	}
	else {
		return func_14502_combination(n-1, r-1) + func_14502_combination(n-1, r);
	}
}

// bfs
void func_14502_virusInfect(int n, int m, int **_map, int **_visit, queue<pair<int, int>> q) {
	pair<int, int> cur;
	int _x, _y;
	int direc[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			_x = cur.first + direc[i][0];
			_y = cur.second + direc[i][1];

			if (_x >= n || _x < 0)
				continue;
			if (_y >= m || _y < 0)
				continue;

			// 벽이면 무시
			if (_map[_x][_y] == 1 || _map[_x][_y] == 2) {
				continue;
			}

			// 방문했으면 무시
			if (_visit[_x][_y] == 1)
				continue;

			// 방문하지 않았고, 벽이 아니면 q에 등록하고 방문처리
			_visit[_x][_y] = 1;
			_map[_x][_y] = 2;

			q.push({_x, _y});
		}
	}
}

void func_14502() {
	int n, m;
	int cnt, cnt_1, cnt_2, max_safeZone = 0;

	vector<pair<int, int>> _map_v;
	queue<pair<int, int>> q;

	cin >> n >> m;
	
	// 초기화 및 지도 생성
	int** _map = new int* [n];
	int** _map_copy = new int* [n];
	int** _visit = new int* [n];

	for (int i = 0; i < n; i++) {
		_map[i] = new int[m];
		_map_copy[i] = new int[m];
		_visit[i] = new int[m];
	}

	// 입력 받기
	cnt_1 = 0;
	cnt_2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> _map[i][j];

			if (_map[i][j] == 1) {
				cnt_1++;
			}
			else if(_map[i][j] == 2) {
				cnt_2++;
			}
			else {
				_map_v.push_back({i, j});
			}
		}
	}

	// permutation 전 오름차순 정렬
	sort(_map_v.begin(), _map_v.end());

	// 0인 좌표 중 랜덤한 3개를 선택한 순열 -> 해당 좌표를 1로 바꾼뒤 bfs해서 max 갱신
	do {
		// 초기화, _map 복사 후 아래 좌표는 1로 변경
		while (!q.empty()) {
			q.pop();
		}

		for (int i = 0; i < n; i++) {
			memcpy(_map_copy[i], _map[i], sizeof(int) * m);
			memset(_visit[i], 0, sizeof(int) * m);
		}
		for (int i = 0; i < 3; i++) {
			//cout << "{" << _map_v.at(i).first << ", " << _map_v.at(i).second << "} ";
			_map_copy[_map_v.at(i).first][_map_v.at(i).second] = 1;
		}

		// 변경된 map에서 바이러스 확산 후 남은 공간 체크 -> 2에서 전부 방문처리후 방문 안된 경우 (벽도 방문처리는 0, 큐에는 x)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (_map_copy[i][j] == 2) {
					_visit[i][j] = 1;
					q.push({ i, j });
				}
			}
		}

		// 위 조건으로 바이러스 확산
		func_14502_virusInfect(n, m, _map_copy, _visit, q);

		//func_14502_print(_map_copy, n, m);
		//func_14502_print(_visit, n, m);

		// 남은 공간의 최대값을 확인하고 갱신
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (_map_copy[i][j] == 0) {
					cnt++;
				}
			}
		}
		
		if (cnt > max_safeZone) {
			max_safeZone = cnt;
			//func_14502_print(_visit, n, m);
			//func_14502_print(_map_copy, n, m);
		}

		reverse(_map_v.begin() + 3, _map_v.end());
	} while (next_permutation(_map_v.begin(), _map_v.end()));

	cout << max_safeZone << "\n";
}

// 로봇 청소기 (골드 5)
void func_14503() {}

// 연산자 끼워넣기 (실버 1)
void func_14888() {}

// 스타트와 링크 (실버 2)
void func_14889() {}

// 경사로 (골드 3)
void func_14890() {}

// 톱니바퀴 (실버 1)
void func_14891() {}

// 감시 (골드 5)
void func_15683() {}

// 사다리 조작 (골드 4)
void func_15684() {}

// 드래곤 커브 (골드 4)
void func_15685() {}

// 치킨 배달 (골드 5)
void func_15686() {}

// 큐빙 (플래티넘 5)
void func_5373() {}

// 인구 이동 (골드 5)
void func_16234() {}

 // 나무 재테크 (골드 4)
void func_16235() {}

// 아기 상어 (골드 3)
void func_16236() {}

// 미세먼지 안녕! (골드 4)
void func_17144() {}

// 낚시왕 (골드 2)
void func_17143() {}

// 이차원 배열과 연산 (골드 4)
void func_17140() {}

// 연구소 3 (골드 4)
void func_17142() {}

// 게리맨더링 2 (골드 4)
void func_17779() {}

// 새로운 게임 2 (골드 2)
void func_17837() {}

// 원판 돌리기 (골드 3)
void func_17822() {}

 // 주사위 윷놀이 (골드 2)
void func_17825() {}

 // 모노미노도미노 2 (골드 2)
void func_20061() {}

// 청소년 상어 (골드 2)
void func_19236() {}

// 어른 상어 (골드 3)
void func_19237() {}

// 스타트 택시 (골드 4)
void func_19238() {}

// 컨베이어 벨트 위의 로봇 (골드 5)
void func_20055() {}

// 마법사 상어와 파이어볼  (골드 4)
void func_20056() {}

// 마법사 상어와 토네이도  (골드 3)
void func_20057() {}

// 마법사 상어와 파이어스톰  (골드 4)
void func_20058() {}

// 상어 초등학교 (실버 1)
void func_21608() {}

// 상어 중학교 (골드 2)
void func_21609() {}

// 마법사 상어와 비바라기 (골드 5)
void func_21610() {}

// 마법사 상어와 블리자드 (골드 1)
void func_21611() {}

// 주사위 굴리기 2 (골드 3)
void func_23288() {}

// 온풍기 안녕! (골드 1)
void func_23289() {}

// 마법사 상어와 복제 (골드 1)
void func_23290() {}

 // 어항 정리 (골드 1) 
void func_23291() {}