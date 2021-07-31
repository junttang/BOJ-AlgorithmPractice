#include <iostream>
#include <stack>
#include <string>
// BOJ - 1935 Calculating Postfix

using namespace std;

namespace Op {
	enum op { eos, plus, minus, mult, div };
}

Op::op enumOfOp(char operate) {
	switch (operate) {
	case '+': return Op::plus;
	case '-': return Op::minus;
	case '*': return Op::mult;
	case '/': return Op::div;
	default: return Op::eos;
	}
}

double calcOp(Op::op operate, double a, double b) {
	switch (operate) {
	case Op::plus: return a + b;
	case Op::minus: return a - b;
	case Op::mult: return a * b;
	case Op::div: return a / b;
	default: return -1;
	}
}

int main(void) {
	string postfix;
	stack<double> s;
	int N;
	double a, b;
	double * alphabet;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	alphabet = new double[N];
	cin >> postfix;
	for (int i = 0; i < N; i++)		// 각 A, B, C, .. 이 친구들을
		cin >> alphabet[i];	// 배열을 이용하여 매칭 변수화하였다. 이 센스 중요

	for (int i = 0; i < postfix.size(); i++) {
		if (enumOfOp(postfix[i]) != Op::eos) {
			b = s.top(); s.pop(); a = s.top(); s.pop();
			s.push(calcOp(enumOfOp(postfix[i]), a, b));
		}
		else 
			s.push(alphabet[postfix[i] - 65]);
	}
	printf("%.2lf", s.top());

	return 0;
}