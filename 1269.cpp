#include <iostream>
// BOJ 1269 Symmetric difference of sets
#define MAX_VAL 100000001
using namespace std;

char elem[MAX_VAL];

int main(void) {
	int a, b, k, cnt = 0;
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> a >> b;

	for (int i = 0; i < a + b; i++) {
		cin >> k;
		if (i >= a) {
			if (elem[k] == 0) cnt++;
			if (elem[k] == 1) cnt--;
		}
		else {
			elem[k]++;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}
