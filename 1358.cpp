#include <iostream>
#include <math.h>
// BOJ 1358 - Hockey
using namespace std;

double dist(double x1, double y1, double x2, double y2) 
{ return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)); }

int main(void) {
	int w, h, x, y, p, px, py, cnt = 0;
	cin >> w >> h >> x >> y >> p;

	for (int i = 0; i < p; i++) {
		cin >> px >> py;

		if (px >= x && px <= (x + w) && py >= y && py <= (y + h)) 
			cnt++;
		else if ((dist(x, y + h / 2, px, py) <= (double)(h / 2) && px <= x) ||
			(dist(x + w, y + h / 2, px, py) <= (double)(h / 2) && px >= (x + w)))
			cnt++; 
	}
	cout << cnt;

	return 0;
}
