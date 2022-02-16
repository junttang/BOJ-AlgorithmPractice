#include <iostream>
#include <string>
#include <vector>
// BOJ - 10757 Big Number A+B
using namespace std;

int A[10001], B[10001], C[10001];

void cal(void) {
	for (int i = 0; i < 10000; i++) {
		C[i] += A[i] + B[i];
		if (C[i] >= 10) { C[i] %= 10; C[i + 1] += 1; }
	}
}

int main(void) {
	string a, b;
	bool flag = true;

	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--) { A[a.size() - 1 - i] = (a[i] - 48); }
	for (int i = b.size() - 1; i >= 0; i--) { B[b.size() - 1 - i] = (b[i] - 48); }

	cal();
	for (int i = 10000; i >= 0; i--) { 
		if (C[i] == 0 && flag) continue;
		if (C[i] != 0) flag = false;
		cout << C[i]; 
	}

	return 0;
}