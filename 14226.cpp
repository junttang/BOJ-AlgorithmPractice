#include <iostream>
#include <queue>
// BOJ - 14226 Emoticon
using namespace std;

int seconds[1001][1001];	// 0�� �̹湮, ���� �ð��� -1
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

	�� ģ����� ���� bfs�� ����ó�� ���� �� ������ ��������.

	����, s<=S���� �ֿ��� ���� �� �ϳ��̴�. ���� 1000���� �θ� �ʹ� ����
	�ð� �ս��� �Ͼ�� �����̴�.

	check�� �������� �ʰ� seconds�θ� ó���ϴ� ���̵� �ֿ��ϴ�.
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