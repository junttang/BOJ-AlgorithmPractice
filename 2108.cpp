#include <iostream>
#include <stdio.h>
// BOJ - 2108 Statistics
using namespace std;

int number[8001];

int main(void) {
	int n, num, maximum, minimum, maxcnt = 0, maxcntnum, cntsum = 0, median; 
	double sum = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num; 
		sum += num;
		number[num + 4000]++;
	}

	printf("%.0f\n", sum / (double)n);	// »ê¼úÆò±Õ

	for (int i = 0; i < 8001; i++) {
		if (number[i] > 0)
			cntsum += number[i];
		if (cntsum >= n / 2 + 1) {
			median = i - 4000;
			break;
		}
	}
	cout << median << endl;	// Áß¾Ó°ª

	for (int i = 0; i < 8001; i++) {
		if (number[i] > maxcnt) {
			maxcnt = number[i];
			maxcntnum = i - 4000;
		}
	}
	for (int i = maxcntnum + 4001; i < 8001; i++) {
		if (number[i] == maxcnt) {
			maxcntnum = i - 4000;
			break;
		}
	}
	cout << maxcntnum << endl;	// ÃÖºó°ª

	for (int i = 8000; i >= 0; i--) {
		if (number[i] > 0) {
			maximum = i - 4000;
			break;
		}
	}
	for (int i = 0; i < 8001; i++) {
		if (number[i] > 0) {
			minimum = i - 4000;
			break;
		}
	}
	cout << maximum - minimum;	// ¹üÀ§

	return 0;
}