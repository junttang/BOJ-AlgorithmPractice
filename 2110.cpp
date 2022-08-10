#include <iostream>
#include <vector>
#include <algorithm>
// BOJ - 2110 Installing WIFI
using namespace std;

vector<int> house, dist;
int max_dist = 0;

void search_dist(int k, int c, int lo, int hi) {
	int m = (lo + hi) / 2, from_recent = 0, t, inst_cnt = 1;
	if (lo > hi) return;

	for (int i = 0; i < k; i++) {
		t = dist[i] + from_recent;

		if (t >= m) {
			from_recent = 0;
			inst_cnt++;
		}
		else from_recent += dist[i];
	}
	if (inst_cnt >= c) {
		if (m > max_dist)
			max_dist = m;
		search_dist(k, c, m + 1, hi);
	}
	else if (lo != hi) 
		search_dist(k, c, lo, m);
}

int main(void) {
	int n, c, t, t_d;

	cin >> n >> c;
	for (int i = 1; i <= n; i++) 
	{ cin >> t;  house.push_back(t); }

	sort(house.begin(), house.end());

	for (int i = 1; i < n; i++) {
		t_d = house[i] - house[i - 1];
		dist.push_back(t_d);
	}
	search_dist(n - 1, c, 1, 1000000000);
	cout << max_dist;

	return 0;
}
