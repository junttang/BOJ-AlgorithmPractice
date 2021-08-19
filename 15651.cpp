#include <iostream>
// BOJ - 15651 N and M (3)
#define MAX_SIZE		10
using namespace std;

int A[MAX_SIZE];

void makeAArray(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << A[i];

			if (i != m - 1) 
				cout << ' ';
		}
		cout << '\n';
		
		return;
	}

	for (int i = 1; i <= n; i++) {
		A[index] = i;
		makeAArray(index + 1, n, m);
	}
}

int main(void) {
	int N, M;

	cin >> N >> M;
	makeAArray(0, N, M);

	return 0;
}