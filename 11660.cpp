#include <iostream>
// BOJ - 11660 Summing each range 5
using namespace std;

int mat[1025][1025];

int main(void) {
	int n, m, t, x1, y1, x2, y2, ans;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		cin >> t;
		mat[i][j] = mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1] + t;
	}
	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		ans = mat[x2][y2] - mat[x2][y1 - 1] - mat[x1 - 1][y2] + mat[x1 - 1][y1 - 1];
		cout << ans << '\n';
	}

	return 0;
}
