#include <iostream>
#include <climits>
// BOJ - 13305 Gas Station
using namespace std;

int cost[100001], dist[100001];

long long solve(int n) {
	int MINcost = INT_MAX;
	long long dist_sum = 0;
	
	for (int i = 1; i < n; i++) {
		if (cost[i] < MINcost) MINcost = cost[i];
		dist_sum += (long long)MINcost * (long long)dist[i];
	}

	return dist_sum;
}

int main(void) {
	int n;
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 1; i < n; i++) cin >> dist[i];
	for (int i = 1; i <= n; i++) cin >> cost[i];
	cout << solve(n);

	return 0;
}