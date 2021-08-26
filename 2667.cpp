#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// BOJ - 2667 단지 번호 붙이기
#define MAX_SIZE		30
using namespace std;

int A[MAX_SIZE][MAX_SIZE];
vector<int> Edge[MAX_SIZE*MAX_SIZE];
bool check[MAX_SIZE*MAX_SIZE];
int cnt = 0;

void DFS(int vertex) {
	check[vertex] = true; cnt++;
	for (int i = 0; i < Edge[vertex].size(); i++) {
		if (check[Edge[vertex][i]] == false)
			DFS(Edge[vertex][i]);
	}
}

int main(void) {
	int N;
	string input;
	vector<int> danji;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++)
			A[i][j] = input[j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == '1') {	// 이 부분 주의!! string으로 받았으므로!!
				if (A[i][j + 1] == '1') {
					Edge[i*N + j].push_back(i*N + j + 1);
					Edge[i*N + j + 1].push_back(i*N + j);
				}
				if (A[i + 1][j] == '1') {
					Edge[i*N + j].push_back((i + 1)*N + j);
					Edge[(i + 1)*N + j].push_back(i*N + j);
				}
			}
		}
	}

	for (int i = 0; i < N*N; i++) {
		if (check[i] == false && A[i / N][i%N] == '1') {
			DFS(i);
			danji.push_back(cnt);
			cnt = 0;
		}
	}
	sort(danji.begin(), danji.end());
	cout << danji.size() << '\n';
	for (int i = 0; i < danji.size(); i++)
		cout << danji[i] << '\n';

	return 0;
}