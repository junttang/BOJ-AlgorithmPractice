#include <iostream>
#include <algorithm>
// BOJ - 2565 Electric Line
using namespace std;

typedef struct { int a; int b; } Line;
Line line[100];
int LIS[100];	// LIS[i] : line[i].b로 끝나는 가장 긴 증가부분수열
bool pred(Line x, Line y) { if (x.a < y.a) return true; return false; }

int solve(int n) {
	int MAXIMUM = 1;
	sort(line, line + n, pred);
	for (int i = 0; i < n; i++) { LIS[i] = 1; }

	for (int i = 1; i < n; i++) {
		int MAX = 0;
		for (int j = 0; j < i; j++)
			if (LIS[j] > MAX && line[j].b < line[i].b) MAX = LIS[j];
		LIS[i] = MAX + 1;
	}

	for (int i = 0; i < n; i++) 
		if (MAXIMUM < LIS[i]) MAXIMUM = LIS[i];

	return MAXIMUM;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) { cin >> line[i].a >> line[i].b; }
	cout << n - solve(n);

	return 0;
}