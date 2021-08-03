#include <iostream>
// BOJ - 17087 Hide and Run

using namespace std;

int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

int main(void) {
	int N, S, bro;
	long long distance, D;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> bro;

		if (S > bro) distance = S - bro;
		else distance = bro - S;

		if (i == 0) {
			D = distance;
			continue;
		}

		D = GCD(distance, D);
	}
	cout << D;

	return 0;
}
