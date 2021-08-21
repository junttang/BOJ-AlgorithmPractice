#include <iostream>
#include <algorithm>
// BOJ - 6603 Lotto
#define MAX_SIZE		12
using namespace std;

int A[MAX_SIZE];
int D[MAX_SIZE];

int main(void) {
	int k = 12;

	for (int i = 0; i < 6; i++)
		D[i] = 1;

	while (1) {
		cin >> k;
		if (k == 0)
			break;

		for (int i = 0; i < k; i++)
			cin >> A[i];

		for (int i = 0; i < 6; i++)
			D[i] = 1;

		do {
			for (int i = 0; i < k; i++) {
				if (D[i] == 1)
					cout << A[i] << ' ';
			}
			cout << '\n';

		} while (prev_permutation(D, D + k));
		cout << '\n';
	}

	return 0;
}