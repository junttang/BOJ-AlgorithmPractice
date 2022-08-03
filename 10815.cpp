#include <iostream>
// BOJ 10815 - Number Cards
#define THR 10000000
#define for_0_to(N) for(int i=0;i<N;i++)
using namespace std;

bool cards[2*THR+1];
bool check[500000];

int main(void) {
	int n, m, k;

	cin >> n;
	for_0_to(n) {
		cin >> k;
		cards[k + THR] = true;
	}

	cin >> m;
	for_0_to(m) {
		cin >> k;
		if (cards[k + THR])
			check[i] = true;
	}

	for_0_to(m) cout << check[i] << ' ';

	return 0;
}
