#include <iostream>
// BOJ - 15654 N and M (5)
#define MAX_SIZE		10
using namespace std;

bool check[MAX_SIZE];
int A[MAX_SIZE];
int num[MAX_SIZE];

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
		A[index] = num[i];
		makeAArray(index + 1, n, m);
		check[i] = false;
	}
}

int main(void) {
	int N, M, temp;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		for (int j = i - 1; j >= 1; j--) {
			if (num[j] > num[j + 1]) {
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}

	makeAArray(0, N, M);

	return 0;
}