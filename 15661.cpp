#include <iostream>
#include <vector>
#include <cstdlib>
// BOJ - 15661 Link And Start
#define MAX_NUM		20
#define INF	1000000000
using namespace std;

int S[MAX_NUM + 1][MAX_NUM + 1];
int MIN = INF;

void go(int N, int index, vector<int> &first, vector<int> &second) {
	if (first.size() > N || second.size() > N)
		return;
	if (index > N + 1) return;
	/*
	재귀호출은 예외 처리를 엄밀하게 안해주면 조금만 넘어가도 바로 시간초과가
	날 정도로 커진다.
	여기에선 첫번째 if 문만으로는 시간 줄이기가 이루어지지 않는다.
	그 이유는, index가 N보다 커져도 first와 second의 사이즈가 N이 초과가 안될 수가
	있기 때문이다.

	이런 부분 주의해야한다.
	*/

	if (index == N + 1) {
		int sum1 = 0, sum2 = 0;
		if (first.size() == 0 || second.size() == 0)
			return;

		for (int i = 0; i < first.size(); i++) {
			for (int j = 0; j < first.size(); j++)
				sum1 += S[first[i]][first[j]];
		}
		for (int i = 0; i < second.size(); i++) {
			for (int j = 0; j < second.size(); j++)
				sum2 += S[second[i]][second[j]];
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