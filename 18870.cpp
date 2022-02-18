#include <iostream>
#include <algorithm>
// BOJ - 18870 Coordinates Compression
using namespace std;

typedef struct {
	int value;
	int x_index;
	int prime_index;
}Coord;

Coord x[1000000];

bool pred_value(Coord a, Coord b) {
	if (a.value < b.value) return true;
	return false;
}

bool pred_x_index(Coord a, Coord b) {
	if (a.x_index < b.x_index) return true;
	return false;
}

int main(void) {
	int n, cnt = 0;
	Coord newItem;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> newItem.value; newItem.x_index = i;
		x[i] = newItem;
	}

	sort(x, x + n, pred_value);

	for (int i = 0; i < n; ) {
		x[i].prime_index = cnt;
		int j = i + 1;
		for ( ; x[j].value == x[i].value; j++)
			x[j].prime_index = cnt;
		i = j;
		cnt++;
	}

	sort(x, x + n, pred_x_index);

	for (int i = 0; i < n; i++) 
		cout << x[i].prime_index << ' ';

	return 0;
}