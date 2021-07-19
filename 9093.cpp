#include <iostream>
#include <stdio.h>
#include <stack>
#include <string.h>
// BOJ - 9093 Reversing Words
#define MAX_WORD	21
#define MAX_SENT	1001
using namespace std;

struct Stack {
	char data[MAX_WORD];
	int size;

	Stack() {
		size = 0;
	}

	void push(char num) {
		data[size] = num;
		size += 1;
	}

	bool empty() {
		if (size == 0)
			return true;
		else
			return false;
	}

	char pop() {
		if (empty())
			return -1;
		else {
			size -= 1;
			return data[size];
		}
	}
};

int main(void) {
	int T;
	char sentence[MAX_SENT];
	Stack s;

	cin >> T;
	getchar();

	for (int i = T; i > 0; i--) {
		int k = 0;
		
		fgets(sentence, sizeof(sentence), stdin);
		sentence[strlen(sentence) - 1] = '\0';

		for (int j = 0; j <= strlen(sentence); j++) {
			if (sentence[j] == ' ' || sentence[j] == '\0') {
				int temp = k;
				for (; k < j; k++)
					s.push(sentence[k]);
				for (; temp < j; temp++)
					sentence[temp] = s.pop();
				k = j + 1;
			}
		}

		printf("%s\n", sentence);
	}
	return 0;
}
