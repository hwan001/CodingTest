#include "header.h"

// ���� Ż��2 (���1)
void func_13460() {}

// 2048(Easy) (���2)
void func_12100() {}

// �� (��� 5)
void func_3190() {}

/* ���� ����(����� 2)
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

// �ֻ��� ������ (��� 4)
void func_14499() {}

// ��Ʈ�ι̳� (��� 5)
void func_14500() {}

// ��� (�ǹ� 3)
void func_14501() {}

// ������ (��� 5)
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

			// ���̸� ����
			if (_map[_x][_y] == 1 || _map[_x][_y] == 2) {
				continue;
			}

			// �湮������ ����
			if (_visit[_x][_y] == 1)
				continue;

			// �湮���� �ʾҰ�, ���� �ƴϸ� q�� ����ϰ� �湮ó��
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
	
	// �ʱ�ȭ �� ���� ����
	int** _map = new int* [n];
	int** _map_copy = new int* [n];
	int** _visit = new int* [n];

	for (int i = 0; i < n; i++) {
		_map[i] = new int[m];
		_map_copy[i] = new int[m];
		_visit[i] = new int[m];
	}

	// �Է� �ޱ�
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

	// permutation �� �������� ����
	sort(_map_v.begin(), _map_v.end());

	// 0�� ��ǥ �� ������ 3���� ������ ���� -> �ش� ��ǥ�� 1�� �ٲ۵� bfs�ؼ� max ����
	do {
		// �ʱ�ȭ, _map ���� �� �Ʒ� ��ǥ�� 1�� ����
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

		// ����� map���� ���̷��� Ȯ�� �� ���� ���� üũ -> 2���� ���� �湮ó���� �湮 �ȵ� ��� (���� �湮ó���� 0, ť���� x)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (_map_copy[i][j] == 2) {
					_visit[i][j] = 1;
					q.push({ i, j });
				}
			}
		}

		// �� �������� ���̷��� Ȯ��
		func_14502_virusInfect(n, m, _map_copy, _visit, q);

		//func_14502_print(_map_copy, n, m);
		//func_14502_print(_visit, n, m);

		// ���� ������ �ִ밪�� Ȯ���ϰ� ����
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

// �κ� û�ұ� (��� 5)
void func_14503() {}

// ������ �����ֱ� (�ǹ� 1)
void func_14888() {}

// ��ŸƮ�� ��ũ (�ǹ� 2)
void func_14889() {}

// ���� (��� 3)
void func_14890() {}

// ��Ϲ��� (�ǹ� 1)
void func_14891() {}

// ���� (��� 5)
void func_15683() {}

// ��ٸ� ���� (��� 4)
void func_15684() {}

// �巡�� Ŀ�� (��� 4)
void func_15685() {}

// ġŲ ��� (��� 5)
void func_15686() {}

// ť�� (�÷�Ƽ�� 5)
void func_5373() {}

// �α� �̵� (��� 5)
void func_16234() {}

 // ���� ����ũ (��� 4)
void func_16235() {}

// �Ʊ� ��� (��� 3)
void func_16236() {}

// �̼����� �ȳ�! (��� 4)
void func_17144() {}

// ���ÿ� (��� 2)
void func_17143() {}

// ������ �迭�� ���� (��� 4)
void func_17140() {}

// ������ 3 (��� 4)
void func_17142() {}

// �Ը��Ǵ��� 2 (��� 4)
void func_17779() {}

// ���ο� ���� 2 (��� 2)
void func_17837() {}

// ���� ������ (��� 3)
void func_17822() {}

 // �ֻ��� ������ (��� 2)
void func_17825() {}

 // ���̳뵵�̳� 2 (��� 2)
void func_20061() {}

// û�ҳ� ��� (��� 2)
void func_19236() {}

// � ��� (��� 3)
void func_19237() {}

// ��ŸƮ �ý� (��� 4)
void func_19238() {}

// �����̾� ��Ʈ ���� �κ� (��� 5)
void func_20055() {}

// ������ ���� ���̾  (��� 4)
void func_20056() {}

// ������ ���� ����̵�  (��� 3)
void func_20057() {}

// ������ ���� ���̾��  (��� 4)
void func_20058() {}

// ��� �ʵ��б� (�ǹ� 1)
void func_21608() {}

// ��� ���б� (��� 2)
void func_21609() {}

// ������ ���� ��ٶ�� (��� 5)
void func_21610() {}

// ������ ���� ���ڵ� (��� 1)
void func_21611() {}

// �ֻ��� ������ 2 (��� 3)
void func_23288() {}

// ��ǳ�� �ȳ�! (��� 1)
void func_23289() {}

// ������ ���� ���� (��� 1)
void func_23290() {}

 // ���� ���� (��� 1) 
void func_23291() {}