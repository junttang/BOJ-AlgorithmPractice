#include <iostream>
// BOJ - 1629 Multiplication
using namespace std;
// a^b = a^(b/2) x a^(b/2)		2147483647
long long a, b, c, k;

long long power(long long b) {
	if (b == 0) return 1;
	if (b == 1) return a % c;
	
	k = power(b / 2) % c;
	if (b % 2 == 0) return k * k % c;
	return k * k % c * a % c;
}

int main(void) {
	cin >> a >> b >> c; 
	cout << power(b);

	return 0;
}