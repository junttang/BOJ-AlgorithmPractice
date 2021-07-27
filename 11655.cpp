#include <iostream>
#include <queue>
#include <string>
// BOJ - 11655 ROT13

using namespace std;

int main(void) {
	string input;
	char temp;
	queue<char> q, Q;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 26; i++) {
		q.push(i + 'a');
		Q.push(i + 'A');
	}

	getline(cin, input);

	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') {
			for (int j = 0; j < input[i] - 'A'; j++) {
				Q.push(Q.front());
				Q.pop();
			}
			for (int j = 0; j < 13; j++) {
				Q.push(Q.front());
				Q.pop();
			}
			cout << Q.front();
			for (int j = 0; j < 13; j++) {
				Q.push(Q.front());
				Q.pop();
			}
			for (int j = 0; j < 'Z' - input[i] + 1; j++) {
				Q.push(Q.front());
				Q.pop();
			}
		}
		else if (input[i] >= 'a' && input[i] <= 'z') {
			for (int j = 0; j < input[i] - 'a'; j++) {
				q.push(q.front());
				q.pop();
			}
			for (int j = 0; j < 13; j++) {
				q.push(q.front());
				q.pop();
			}
			cout << q.front();
			for (int j = 0; j < 13; j++) {
				q.push(q.front());
				q.pop();
			}
			for (int j = 0; j < 'z' - input[i] + 1; j++) {
				q.push(q.front());
				q.pop();
			}
		}
		else
			cout << input[i];
	}
	
	return 0;
}