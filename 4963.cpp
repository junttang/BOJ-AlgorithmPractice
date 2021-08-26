#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// BOJ - 4963 ¼¶ÀÇ °³¼ö
#define MAX_SIZE		60
using namespace std;

int A[MAX_SIZE][MAX_SIZE];
vector<int> Edge[MAX_SIZE*MAX_SIZE];
bool check[MAX_SIZE*MAX_SIZE];

void DFS(int vertex) {
	check[vertex] = true;
	for (int i = 0; i < Edge[vertex].size(); i++) {
		if (check[Edge[vertex][i]] == false)
			DFS(Edge[vertex][i]);
	}
}

int main(void) {
	int w, h, cnt;

	while (1) {
		cin >> w >> h; cnt = 0;
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++)
				cin >> A[i][j];
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (A[i][j]) {
					if (i >= 1 && A[i - 1][j + 1]) {
						Edge[i*w + j].push_back((i - 1)*w + j + 1);
						Edge[(i - 1)*w + j + 1].push_back(i*w + j);
					}
					if (A[i][j + 1]) {
						Edge[i*w + j].push_back(i*w + j + 1);
						Edge[i*w + j + 1].push_back(i*w + j);
					}
					if (A[i + 1][j]) {
						Edge[i*w + j].push_back((i + 1)*w + j);
						Edge[(i + 1)*w + j].push_back(i*w + j);
					}
					if (A[i + 1][j + 1]) {
						Edge[i*w + j].push_back((i + 1)*w + j + 1);
						Edge[(i + 1)*w + j + 1].push_back(i*w + j);
					}
				} // 17 -> 3, 2		[w5 h4]
			}
		}

		for (int i = 0; i < w*h; i++) {
			if (check[i] == false && A[i / w][i%w]) {
				DFS(i);
				cnt++;
			}
		}
		cout << cnt << '\n';

		for (int i = 0; i < w*h; i++) {
			check[i] = false;
			Edge[i].clear();
			A[i / w][i%w] = 0;
		}
	}

	return 0;
}