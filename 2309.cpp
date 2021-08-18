#include <iostream>
// BOJ - 2309 Seven Dwalf
using namespace std;

int dwalf[9];

int main(void) {
	int temp, sum;

	for (int i = 0; i < 9; i++)
		cin >> dwalf[i];

	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			if (dwalf[j] > dwalf[j + 1]) {
				temp = dwalf[j + 1];
				dwalf[j + 1] = dwalf[j];
				dwalf[j] = temp;
			}
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = i; j < 9; j++) {
			sum = 0;
			for (int k = 0; k < 9; k++) {
				if (k != j && k != i)
					sum += dwalf[k];
			}
			if (sum == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != j && k != i)
						cout << dwalf[k] << '\n';
				}
				return 0;
			}
		}
	}

	return 0;
}