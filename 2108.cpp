#include <iostream>
#include <stdio.h>
// BOJ - 2108 Statistics
using namespace std;

int number[8001];

int main(void) {
	int n, num, maximum, minimum, maxcnt = 0, maxcntnum, cntsum = 0, median;
	double sum = 0, avg;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		sum += num;
		number[num + 4000]++;
	}

	avg = sum / (double)n;
	if (avg > -0.5 && avg < 0) avg = -avg;
	printf("%.0f\n", avg);	// 산술평균

	for (int i = 0; i < 8001; i++) {
		if (number[i] > 0)
			cntsum += number[i];
		if (cntsum >= n / 2 + 1) {
			median = i - 4000;
			break;
		}
	}
	cout << median << endl;	// 중앙값

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
	cout << maxcntnum << endl;	// 최빈값

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
	cout << maximum - minimum;	// 범위

	return 0;
}
