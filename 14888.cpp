#include <iostream>
#include <algorithm>
#include <climits>
// BOJ - 14888 Operator Insertion
using namespace std;

int num[11];
int opnum[4];
int op[11]; // + - x %
int MAX = -INT_MAX, MIN = INT_MAX;
int permutationCnt(int n) { if (n == 0) return 1; return n * permutationCnt(n - 1);}

int cal(int opNum) {
	int res = num[0];

	for (int i = 0; i < opNum; i++) {
		switch (op[i]) {
		case 1: res = (res + num[i + 1]); break;
		case 2: res = (res - num[i + 1]); break;
		case 3: res = (res * num[i + 1]); break;
		case 4: res = (res / num[i + 1]); break;
		}
	}

	return res;
}

void solve(int n, int opNum) {
	int res, permuCnt = permutationCnt(n - 1);

	for (int i = 0; i < permuCnt; i++) {
		res = cal(opNum);
		if (res > MAX) MAX = res;
		if (res < MIN) MIN = res;
		next_permutation(op, op + opNum);
	}
}

int main(void) {
	int n, opIdx = 0;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	cin >> opnum[0]; for (int i = 0; i < opnum[0]; i++) op[opIdx++] = 1;
	cin >> opnum[1]; for (int i = 0; i < opnum[1]; i++) op[opIdx++] = 2;
	cin >> opnum[2]; for (int i = 0; i < opnum[2]; i++) op[opIdx++] = 3;
	cin >> opnum[3]; for (int i = 0; i < opnum[3]; i++) op[opIdx++] = 4;

	solve(n, opIdx);
	cout << MAX << endl << MIN;
		
	return 0;
}