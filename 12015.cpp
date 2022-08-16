#include <iostream>
#include <vector>
// BOJ - 12015 LIS 2
using namespace std;

vector<int> a, ans;

int idx_bsearch(int k) {
	int lo = 0, hi = ans.size() - 1, mid;

	while (lo < hi) {
		mid = lo + (hi - lo) / 2;

		if (ans[mid] >= k) 
			hi = mid;
		else lo = mid + 1;
	}

	return hi;
}

int main(void) {
	int n, t, idx;

	cin >> n;
	for (int i = 0; i < n; i++) 
	{ cin >> t;  a.push_back(t); }
	ans.push_back(a.front());

	for (int i = 1; i < n; i++) {
		if (a[i] > ans.back())
			ans.push_back(a[i]);
		else {
			idx = idx_bsearch(a[i]);
			ans[idx] = a[i];
		}
	}
	cout << ans.size();

	return 0;
}

/*
10 20 10 30 20 50

10
10 20
10 20
10 20 30
10 20 30 50

맨 첫 원소부터 선형적으로 확인해가며, 증가 부분 수열인지를 확인하며 추가한다.
이때, 만약, 수열에 포함된 원소보다 작은 원소가 발견되면, 이는 수열 내에서
가장 값이 가까운 원소와 대체한다.
*/
