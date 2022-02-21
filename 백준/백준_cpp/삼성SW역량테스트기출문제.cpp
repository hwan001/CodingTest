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
void func_14502() {}

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