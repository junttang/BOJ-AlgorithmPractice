#include <iostream>
// BOJ - 12865 Normal Knapsack
using namespace std;

int w[101], v[101];
int dp[102][100001];

int solve(int n, int k) {
	for (int i = 1; i <= n + 1; i++) 
		for (int j = 1; j <= k; j++) {
			int temp = dp[i - 1][j];
			
			if (j - w[i - 1] >= 0 && dp[i - 1][j - w[i - 1]] + v[i - 1] > temp) 
				temp = dp[i - 1][j - w[i - 1]] + v[i - 1];

			dp[i][j] = temp;
		}

	return dp[n + 1][k];
}

int main(void) {
	int n, k;
	ios_base::sync_with_stdio(false); cin.tie(NULL); 

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	cout << solve(n, k);

	return 0;
}