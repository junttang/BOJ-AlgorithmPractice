#include <iostream>
#include <queue>
// BOJ - 14226 Emoticon
using namespace std;

int seconds[1001][1001];	// 0은 미방문, 실제 시간은 -1
queue<pair<int, int>> Q;	// (s, c) : screen, clipboard

int bfs(int S) {
	int s, c, MIN = 100000000;

	Q.push(make_pair(1, 0));
	seconds[1][0] = 1;

	while (!Q.empty()) {
		s = Q.front().first;
		c = Q.front().second;
		Q.pop();

		if (s == S)
			continue;

		if (s - 1 >= 0 && seconds[s - 1][c] == 0) {
			seconds[s - 1][c] = seconds[s][c] + 1;
			Q.push(make_pair(s - 1, c));
		}

		if (c != 0 && s + c <= 1000 && seconds[s + c][c] == 0) {
			seconds[s + c][c] = seconds[s][c] + 1;
			Q.push(make_pair(s + c, c));
		}

		if (s <= S && seconds[s][s] == 0) {
			seconds[s][s] = seconds[s][c] + 1;
			Q.push(make_pair(s, s));
		}
	}

	/*
		if (s <= S && seconds[s][s] == 0) {
		seconds[s][s] = seconds[s][c] + 1;
		Q.push(make_pair(s, s));

	이 친구들로 인해 bfs가 버블처럼 번질 수 있음을 이해하자.

	한편, s<=S역시 주요한 조건 중 하나이다. 굳이 1000으로 두면 너무 많은
	시간 손실이 일어나기 때문이다.

	check를 도입하지 않고 seconds로만 처리하는 아이디어도 주요하다.
	*/

	for (int i = 0; i <= 1000; i++) {
		if (seconds[S][i] != 0 && seconds[S][i] < MIN)
			MIN = seconds[S][i];
	}

	return MIN - 1;
}

int main(void) {
	int S;

	cin >> S;
	cout << bfs(S);

	return 0;
}