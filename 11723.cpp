#include <iostream>
#include <string>
// BOJ - 11723 Set
using namespace std;

int main(void) {
	int M, n, S = 0;
	string option;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M;
	while (M--) {
		cin >> option;
		if (option.compare("add") == 0) {
			cin >> n;
			S = S | (1 << n - 1);
		}
		else if (option.compare("remove") == 0) {
			cin >> n;
			S = S & ~(1 << n - 1);
		}
		else if (option.compare("check") == 0) {
			cin >> n;
			cout << ((S >> n - 1) & 1) << '\n';
		}
		else if (option.compare("toggle") == 0) {
			cin >> n;
			S = S ^ (1 << n - 1);
		}
		else if (option.compare("all") == 0) {
			S = 0; S = ~S;
		}
		else if (option.compare("empty") == 0)
			S = 0;
	}

	return 0;
}