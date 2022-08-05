#include <iostream>
#include <math.h>
// BOJ 1004 - Young Princess
#define DONT_BLANK 1
#define CAN_BLANK  0
using namespace std;

double planet[51][4];

double dist(double x1, double y1, double x2, double y2)
{ return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)); }

int main(void) {
	int t, n, blanked;
	double x1, y1, x2, y2, cx, cy, r;

	cin >> t;
	while (t--) {
		cin >> x1 >> y1 >> x2 >> y2 >> n;  blanked = 0;

		for (int i = 1; i <= n; i++) {
			cin >> cx >> cy >> r;
			planet[i][0] = cx;  planet[i][1] = cy;  planet[i][2] = r;

			if (dist(cx, cy, x1, y1) < r || dist(cx, cy, x2, y2) < r) {
				planet[i][3] = DONT_BLANK;
				if (dist(cx, cy, x1, y1) < r && dist(cx, cy, x2, y2) < r)
					planet[i][3] = CAN_BLANK;
			}
			else planet[i][3] = CAN_BLANK;
		}

		for (int i = 1; i <= n; i++) {
			if (planet[i][3] == DONT_BLANK) continue;
			
			if (dist(planet[i][0], planet[i][1], 0, 0) + planet[i][2] < 5000)
				blanked++;
		}

		cout << (n - blanked) << '\n';
	}

	return 0;
}
