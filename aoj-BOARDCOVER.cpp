#include<iostream>
#include<string>
// Algospot - BOARDCOVER
using namespace std;

int T, H, W;
int wayCount;
int board[20][20];
int coverType[4][3][2] = {	// cover�Լ����� �߰ߵ� �������ֻ�� ��� ĭ�� �������� 
	{ { 0, 0 }, { 1, 0 }, { 0, 1 } },	// �ߺ� ó�� �帧�� �ſ����� �ʴ�, ������
	{ { 0, 0 }, { 0, 1 }, { 1, 1 } },	// L�� ��ġ ���°� �ٷ� �� �� �����̴�.
	{ { 0, 0 }, { 1, 0 }, { 1, 1 } },	// �� ���� ���� �Ȱ�, �� ���� ���� �ȴ� ������
	{ { 0, 0 }, { 1, 0 }, { 1, -1 } }	// �ߺ� ó�� �帧�� �̾����Ƿ�, �� �� ������ 
};										// ������. �̰��� �߰��� �ſ� �ֿ��� idea

bool isInRange(int y, int x) {		// ny�� nx�� ���� ������� üũ
	return 0 <= x && x < W && 0 <= y && y < H;
}

bool set(int y, int x, int type, int block) {
	bool check = true;

	for (int i = 0; i < 3; i++) {
		int ny = y + coverType[type][i][0];	// �ſ� �Ź��� ��ǥ ó�� ��� (������)
		int nx = x + coverType[type][i][1];

		if (!isInRange(ny, nx))		// L�� ĭ�� ��� ��ġ ������ ��츸 �ٷ��
			check = false;
		else if ((board[ny][nx] += block) > 1)	// �̹� cover�� ���̰ų�, ���� ĭ��
			check = false;						// ��ġ�� ��쵵 ���ش�.
	}

	return check;	// ����� üũ�� ��� ����� ��츸 cover�Ѵ�.
}

void cover(void) {
	int x = -1, y = -1;		// default ���� : �߰� ���� ������ ���� -1�� �� ��

	for (int i = 0; i < H; i++) {		// �ߺ� ó���� ���� ���� ��ܿ�������
		for (int j = 0; j < W; j++) {	// �����鼭, ó������ �߰ߵǴ� uncover
			if (board[i][j] == 0) {		// ĭ�� Ư���� x�� y�� �����Ѵ�.
				x = j;
				y = i;
				break;
			}
		}
		if (y != -1) break;				// ���� �߰� ��ġ�� ����ϹǷ� ������ �ʿ�x
	}

	if (y == -1) {		// ��� cover�Ǿ� ��� ĭ�� �߰ߵ��� ������
		wayCount++;		// ����� ���� �ϳ� count�Ǵ� ���̴�.
		return;
	}

	for (int i = 0; i < 4; i++) {// �ش� ��� ĭ���� 4���� ����� L�� ��ġ ���� ���� üũ
		if (set(y, x, i, 1))	// cover�� ����� board�迭 ���� 0->1�� �ȴ�.
			cover();
		set(y, x, i, -1);		// �׸��� ����� �帧�� ���� �ٽ� ���ܳ���.
	}
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> H >> W;
		wayCount = 0;
		int dotCount = 0;

		for (int i = 0; i < H; i++) {
			string str;		// �� string���� �޴� ���� ���� �� ����ϴ�.
			cin >> str;

			for (int j = 0; j < W; j++) {	// �� ��ȣ�� �������� ó�����ָ� �ȴ�.
				if (str[j] == '#')
					board[i][j] = 1;
				else
					board[i][j] = 0;
			}
		}
		if (dotCount % 3 != 0) {
			cout << 0 << '\n';
			continue;
		}

		cover();
		cout << wayCount << '\n';
	}
}