#include<iostream>
#include<string>
// Algospot - BOARDCOVER
using namespace std;

int T, H, W;
int wayCount;
int board[20][20];
int coverType[4][3][2] = {	// cover함수에서 발견된 최좌측최상단 흰색 칸을 기준으로 
	{ { 0, 0 }, { 1, 0 }, { 0, 1 } },	// 중복 처리 흐름에 거역하지 않는, 가능한
	{ { 0, 0 }, { 0, 1 }, { 1, 1 } },	// L자 배치 형태가 바로 이 네 가지이다.
	{ { 0, 0 }, { 1, 0 }, { 1, 1 } },	// 한 행을 먼저 훑고, 그 다음 행을 훑는 식으로
	{ { 0, 0 }, { 1, 0 }, { 1, -1 } }	// 중복 처리 흐름이 이어지므로, 이 네 가지만 
};										// 가능함. 이것의 발견이 매우 주요한 idea

bool isInRange(int y, int x) {		// ny와 nx가 범위 벗어나는지 체크
	return 0 <= x && x < W && 0 <= y && y < H;
}

bool set(int y, int x, int type, int block) {
	bool check = true;

	for (int i = 0; i < 3; i++) {
		int ny = y + coverType[type][i][0];	// 매우 신박한 좌표 처리 방법 (익히자)
		int nx = x + coverType[type][i][1];

		if (!isInRange(ny, nx))		// L자 칸이 모두 배치 가능한 경우만 다룬다
			check = false;
		else if ((board[ny][nx] += block) > 1)	// 이미 cover된 곳이거나, 검은 칸과
			check = false;						// 겹치는 경우도 빼준다.
	}

	return check;	// 상단의 체크를 모두 통과한 경우만 cover한다.
}

void cover(void) {
	int x = -1, y = -1;		// default 세팅 : 발견 못함 구분을 위해 -1로 둔 것

	for (int i = 0; i < H; i++) {		// 중복 처리를 위해 좌측 상단에서부터
		for (int j = 0; j < W; j++) {	// 훑으면서, 처음으로 발견되는 uncover
			if (board[i][j] == 0) {		// 칸을 특정해 x와 y에 지정한다.
				x = j;
				y = i;
				break;
			}
		}
		if (y != -1) break;				// 최초 발견 위치를 기록하므로 나머진 필요x
	}

	if (y == -1) {		// 모두 cover되어 흰색 칸이 발견되지 않으면
		wayCount++;		// 경우의 수가 하나 count되는 것이다.
		return;
	}

	for (int i = 0; i < 4; i++) {// 해당 흰색 칸에서 4가지 경우의 L자 배치 가능 여부 체크
		if (set(y, x, i, 1))	// cover를 씌우면 board배열 값이 0->1이 된다.
			cover();
		set(y, x, i, -1);		// 그리고 재귀적 흐름에 의해 다시 벗겨낸다.
	}
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> H >> W;
		wayCount = 0;
		int dotCount = 0;

		for (int i = 0; i < H; i++) {
			string str;		// 행 string으로 받는 것이 보다 더 깔끔하다.
			cin >> str;

			for (int j = 0; j < W; j++) {	// 열 번호를 기준으로 처리해주면 된다.
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