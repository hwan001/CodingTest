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
void func_14502() {}

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