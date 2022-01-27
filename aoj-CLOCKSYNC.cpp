#include <iostream>
#include <vector>
#include <algorithm>
// Algospot - CLOCKSYNC
using namespace std;

#define INF 9999		// INF에 더했을때도 int 범위 내에 있을 수 있으면서, 적당한 INF값
#define SWITCH 10
#define CLOCK 16

// linked[i][j] : 스위치와 시계의 연결관계를 표현한 2차원 그래프
// 1이면 연결된 것. 행이 스위치, 열이 시계. ~> push 상황의 처리가 효율적!
int linked[SWITCH][CLOCK] = {
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};

// 모든 시계가 12시를 가리키고 있는지 확인하는 단순한 프로시저
bool areAligned(const vector<int> &clocks) {
	for (int i = 0; i < CLOCK; i++)
		if (clocks[i] != 12)
			return false;
	return true;
}

// swtch번 스위치를 눌러 시계의 시간을 조정하는 간단하면서도 효율적인 함수
void push(vector<int> &clocks, int swtch) {
	for (int clock = 0; clock < CLOCK; clock++)
		if (linked[swtch][clock] == 1) { // swtch행을 쭉 순회하면서, 연결된 시계의
			clocks[clock] += 3;			// 시간을 바꿔준다.

			if (clocks[clock] == 15)
				clocks[clock] = 3;
		}
}

// clocks : 현재 시계들의 상태
// swtch : 이번에 누를 스위치의 번호
//가 주어질 때, 남은 스위치들을 눌러서 clocks를 12시로 맞출 수 있는 최소 횟수를 반환
//만약 불가능하다면 INF 이상의 큰 수를 반환

int solve(vector<int> &clocks, int swtch) {
	if (swtch == SWITCH) // 10개의 스위치에 대해 모두 고려했으면 정렬 상태 확인(탈출조건)
		return areAligned(clocks) ? 0 : INF;	// 정렬된 경우 0을 반환해서 재귀 누적
			// 정렬되지 않은 경우엔 INF를 출력해 방법이 없음을 알린다
	int result = INF;
	/*
	현재 swtch 스위치를 0번 누르는 경우부터 세번까지를 모두 시도함.

	즉, 사실상 (,,,,,,,,,)이며, 각 칸이 0~3이 가능한, 모든 조합(4^10)에서 정렬이 가능한
	최소의 횟수(result)를 찾아 반환하는 과정인 것!!

	아래 함수에서 push(clocks, swtch)가 네번 호출되었으니 결국 clocks는 원래와 같은 상태
	*/
	for (int cnt = 0; cnt < 4; cnt++) {
		result = min(result, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}

	return result;
}

int main(void) {
	int C;

	vector<int> clocks(CLOCK);
	cin >> C;

	while (C--) {
		for (int i = 0; i < CLOCK; i++)
			cin >> clocks[i];

		int result = solve(clocks, 0);

		if (result == INF)
			cout << -1 << endl;
		else
			cout << result << endl;

	}

	return 0;
}