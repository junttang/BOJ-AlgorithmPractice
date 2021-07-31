#include <iostream>
#include <stack>
#include <string>
// BOJ - 1918 Infix to Postfix

/*
중위 후위 변환의 핵심은,
- isp와 icp를 확인하고, 스택의 연산자가 우선순위가
더 높을 때는 postfix로 옮겨주어야한다는 점이다.

한편, 지속적인 오류로 인해 시간이 꽤나 오래걸렸는데,
결국 이유를 알고보니, string의 + 연산 시 ""로 묶지 않고
''로 묶은데에 이유가 있었다. 이를 반드시 주의하도록 하자.
*/

using namespace std;

namespace Op {
	enum op { eos, plus, minus, mult, div, left, right };
}

int isp[7] = { 0,1,1,2,2,0,4 };
int icp[7] = { 0,1,1,2,2,5,4 };

Op::op enumOfOp(char operate) {
	switch (operate) {
	case '+': return Op::plus;
	case '-': return Op::minus;
	case '*': return Op::mult;
	case '/': return Op::div;
	case '(': return Op::left;
	case ')': return Op::right;
	default: return Op::eos;
	}
}

string whatOp(Op::op operate) {
	switch (operate) {
	case Op::eos: return "\0";
	case Op::plus: return "+";
	case Op::minus: return "-";
	case Op::mult: return "*";
	case Op::div: return "/";
	default: return "\0";
	}
}

int main(void) {
	string infix;
	string postfix = "";
	stack<Op::op> s;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> infix;

	s.push(Op::eos);
	for (int i = 0; i < infix.size(); i++) {
		if (enumOfOp(infix[i]) != Op::eos) {
			if (infix[i] == ')') {
				while (s.top() != Op::left) {
					postfix += whatOp(s.top());
					s.pop();
				}
				s.pop();
			}
			else {
				while (isp[s.top()] >= icp[enumOfOp(infix[i])]) {
					postfix += whatOp(s.top());
					s.pop();
				}
				s.push(enumOfOp(infix[i]));
			}
		}
		else
			postfix += infix[i];
	}
	while (!s.empty()) {
		postfix += whatOp(s.top());
		s.pop();
	}
	cout << postfix;

	return 0;
}