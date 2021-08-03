#include <iostream>
#include <string>
// BOJ - 2745 Notation Transition

using namespace std;

int main(void) {
	string N;
	int B, tmp, cnt = 0;
	long long num = 0, mult = 1;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> B;

	for (int i = N.size() - 1; i >= 0; i--) {
		mult = 1;

		if (N[i] >= 'A' && N[i] <= 'Z')
			tmp = N[i] - 'A' + 10;
		else
			tmp = N[i] - '0';
		
		for (int i = 0; i < cnt; i++)
			mult *= B;

		tmp *= mult;
		num += tmp;
		cnt++;
	}
	cout << num;

	return 0;
}