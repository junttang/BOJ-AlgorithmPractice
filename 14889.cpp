#include <iostream>
#include <vector>
#include <cstdlib>
// BOJ - 14889 Start And Link
#define MAX_NUM		20
#define INF	1000000000
using namespace std;

int S[MAX_NUM + 1][MAX_NUM + 1];
int MIN = INF;

void go(int N, int index, vector<int> &first, vector<int> &second) {
	if (first.size() > N / 2 || second.size() > N / 2)
		return;
	if (index == N + 1) {
		int sum1 = 0, sum2 = 0;

		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				sum1 += S[first[i]][first[j]];
				sum2 += S[second[i]][second[j]];
			}
		}

		if (abs(sum1 - sum2) < MIN)
			MIN = abs(sum1 - sum2);
	}

	first.push_back(index);
	go(N, index + 1, first, second);
	first.pop_back();
	second.push_back(index);
	go(N, index + 1, first, second);
	second.pop_back();
}

int main(void) {
	int N;
	vector<int> first;
	vector<int> second;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> S[i][j];
	}

	go(N, 1, first, second);
	cout << MIN;

	return 0;
}