#include <iostream>
#include <string>
#include <stdlib.h>
// BOJ - 2529 ∫ŒµÓ»£
#define MAX_NUM		9
#define INF	9999999999
using namespace std;

char A[MAX_NUM + 1];
int check[10];
string MAX = to_string(0);
string MIN = to_string(INF);

bool impossible(char a, char b, char relation) {
	if (relation == '<') {
		if (a > b)
			return true;
	}
	else if (relation == '>') {
		if (a < b)
			return true;
	}
	return false;
}

void go(int k, int index, string number) {
	if (index == k + 2) {
		if (number.compare(MAX) > 0) MAX = number;
		if (number.compare(MIN) < 0) MIN = number;
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (index != 1) {
			if (check[i] || impossible(number.back(), i + 48, A[index - 1]))
				continue;
		}
		
		check[i] = true;
		go(k, index + 1, number + to_string(i));
		check[i] = false;
	}
}

int main(void) {
	int k;
	string number = "";

	cin >> k;
	for (int i = 1; i <= k; i++)
		cin >> A[i];

	go(k, 1, number);
	cout << MAX << '\n' << MIN;

	return 0;
}