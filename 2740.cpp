#include <iostream>
// BOJ - 2740 Matrix Multiplication
using namespace std;

int a[100][100], b[100][100], res[100][100];

void matrix_mul(int n, int m, int k) {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < k; j++) 
			for (int t = 0; t < m; t++) res[i][j] += a[i][t] * b[t][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) cout << res[i][j] << ' ';
		cout << '\n';
	}
}

int main(void) {
	int n, m, k;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	cin >> m >> k;
	for (int i = 0; i < m; i++) for (int j = 0; j < k; j++) cin >> b[i][j];
	matrix_mul(n, m, k);

	return 0;
}