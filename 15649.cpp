#include <iostream>
// BOJ - 15649 N and M (1)
#define MAX_SIZE		10
using namespace std;

bool check[MAX_SIZE];
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
		if (check[i]) 
			continue;
		
		check[i] = true;
		A[index] = i;
		makeAArray(index + 1, n, m);
		check[i] = false;
	}
}

int main(void) {
	int N, M;

	cin >> N >> M;
	makeAArray(0, N, M);

	return 0;
}