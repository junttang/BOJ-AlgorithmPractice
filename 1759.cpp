#include <iostream>
#include <string>
#include <algorithm>
// BOJ - 1759 암호 만들기
#define MAX_NUM			15
using namespace std;

char A[MAX_NUM];

bool check(string password) {
	int ja = 0, mo = 0;

	for (int i = 0; i < password.size(); i++) {
		switch (password[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			mo++; break;
		default:
			ja++; break;
		}
	}

	if (ja >= 2 && mo >= 1)
		return true;
	return false;
}

void go(int L, int C, char *A, string password, int idx) {
	if (password.size() == L) {
		if (check(password))
			cout << password << '\n';
		return;
	}
	if (idx >= C)
		return;
	go(L, C, A, password + A[idx], idx + 1);
	go(L, C, A, password, idx + 1);
}

int main(void) {
	int L, C;
	string password = "";

	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> A[i];
	sort(A, A + C);

	go(L, C, A, password, 0);

	return 0;
}