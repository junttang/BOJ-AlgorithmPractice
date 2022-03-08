#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
// BOJ - 4949 Balanced World
using namespace std;

stack<char> s;

bool yesOrNo(char *str) {
	int i = 0;

	if (str[0] == ')' || str[0] == ']') return false;
	s.push(str[i++]);
	while (str[i]) {
		if (str[i] == ')') {
			while (!s.empty() && s.top() != '(') {
				if (s.top() == '[') return false;
				s.pop();
			}
			if (s.empty()) return false;
			if (!s.empty() && s.top() == '(') s.pop();
		}
		else if (str[i] == ']') {
			while (!s.empty() && s.top() != '[') {
				if (s.top() == '(') return false;
				s.pop();
			}
			if (s.empty()) return false;
			if (!s.empty() && s.top() == '[') s.pop();
		}
		else s.push(str[i]);
		i++;
	}

	while (!s.empty()) {
		if (s.top() == '(' || s.top() == '[') return false;
		s.pop();
	}

	return true;
}

int main(void) {
	char str[101];

	while (1) {
		scanf("%[^\n]s", str); getchar();
		if (str[0] == '.' && strlen(str) == 1) break;
		
		if (yesOrNo(str)) cout << "yes\n";
		else cout << "no\n";
		while (!s.empty()) s.pop();
	}

	return 0;
}