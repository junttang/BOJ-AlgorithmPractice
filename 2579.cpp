#include <iostream>
#include <algorithm>
// BOJ - 2579 Going up the stairs
using namespace std;

typedef struct _step {
	int key;
	int score;
}Step;

Step stairs[301];

int solve(int n) {
	stairs[0].key = stairs[0].score = 0; stairs[1].score = stairs[1].key;
	stairs[2].score = stairs[1].key + stairs[2].key;

	for (int i = 3; i <= n; i++) 
		stairs[i].score = max(stairs[i].key + stairs[i - 1].key + 
			stairs[i - 3].score, stairs[i].key + stairs[i - 2].score);

	return stairs[n].score;
}

int main(void) {
	int n;
	
	cin >> n;
	for (int i = 1; i <= n; i++)  cin >> stairs[i].key;
	cout << solve(n);

	return 0;
}