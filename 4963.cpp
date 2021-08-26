#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// BOJ - 4963 섬의 개수
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

/*
이 문제는 의외로 상당히 고생한 문제이다.

방향이 대각선까지 허용된 상황을 처리하는 방법에서 문제가 발생했는데,

만약
0 1 0
1 0 1
1 1 0
과 같은 상황을 처리한다고 해보자. 이는 하나의 섬이다.

최초에는 동, 남, 동남 방향만으로 처리하려고 했는데, 이렇게 하면, 북동 방향에 대한 처리가 불가능하다는 것을
알 수 있다.

따라서, i>=1일때 북동방향의 연결관계도 간선으로 이어주는 처리가 필요했다.

이어서, 이들을 선형으로 펴, 각각을 정점으로 취급하여 DFS해 연결요소 개수를 찾으면 되는 문제이다.

그럼에도, 지속적으로 해결하지 못한 이유는 바로 초기화에 있었다.

vector를 초기화해주지 않았다!! 테스트 케이스 문제에서는 이러한 초기화작업이 정말 중요하다.*/

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
