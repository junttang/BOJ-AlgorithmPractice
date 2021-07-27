#include <iostream>
#include <stack>
#include <string>
// BOJ - 10799 Steel Stick
/*
결국 이 문제는, "괄호 문자열" 형태의 문제는 대체적으로
스택의 본능을 요구한다는 점을 기억하는 것이 핵심이다.

문제 자체를 보았을 땐, 스틱을 중심으로 보지 않고, 레이저
를 중심으로 보면, 레이저 하나가 떨어질때, 생기는 조각의 수
를 집중해서 보면, 이를 괄호 문자열과 스택의 관점에서 간단하
게 처리할 수 있음을 금새 발견할 수 있다.
*/

using namespace std;

struct _node {
	char paren;
	int index;
};

int main(void) {
	string input;
	stack<struct _node> s;
	struct _node temp;
	int segments = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			temp.paren = input[i];
			temp.index = i;
			s.push(temp);
		}
		else if (input[i] == ')') {
			if (s.top().index == i - 1) {
				s.pop();
				segments += s.size();
			}
			else {
				s.pop();
				segments += 1;
			}
		}
	}
	cout << segments;

	return 0;
}