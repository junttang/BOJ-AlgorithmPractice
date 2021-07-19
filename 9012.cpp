#include <iostream>
#include <stdio.h>
#include <string.h>
// BOJ - 9012 Parenthesis String
#define MAX_LEN		51

using namespace std;

struct LogicStack {
	int size;

	LogicStack() {
		size = 0;
	}

	void push() {
		size++;
	}

	void pop() {
		size--;
	}
};

int main(void) {
	int T, flag = 0;
	char str[MAX_LEN];
	LogicStack s;
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;

	while (T--) {
		cin >> str;
		s.size = 0;

		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == ')') {
				s.pop();
				if (s.size < 0) {
					cout << "NO\n";
					i = strlen(str);
					flag = 1;
				}
			}
			else
				s.push();
		}

		if (!flag) {
			if (!s.size)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		
		flag = 0;
	}

	return 0;
}