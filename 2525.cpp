#include <iostream>
// BOJ - 2525 Oven Clock

using namespace std;

int main(void) {
	int A, B, C;

	cin >> A >> B >> C;

	A += C / 60;
	B += C % 60;
	if (B >= 60) {
		B -= 60; A += 1;
	}
	A %= 24;

	cout << A << " " << B << endl;

	return 0;
}