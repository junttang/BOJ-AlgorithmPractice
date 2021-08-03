/*
156
19, 4
2, 3
0, 2
~> 234 ~> 128 + 24 + 4
*/
#include <iostream>
#include <string>
// BOJ - 11005 Notation Trasition

using namespace std;

int main(void) {
	long long N, remainder;
	int B;
	string output = "";
	char part[2];
	string partition;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> B;

	while (N != 0) {
		remainder = N % B;

		if (remainder < 10)
			remainder += 48;
		else
			remainder += 55;

		part[0] = ((char)remainder);
		part[1] = '\0';
		partition.assign(part);
		output = partition + output;

		N /= B;
	}
	cout << output;

	return 0;
}