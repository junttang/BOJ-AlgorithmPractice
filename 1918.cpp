#include <iostream>
#include <stack>
#include <string>
// BOJ - 1918 Infix to Postfix

/*
���� ���� ��ȯ�� �ٽ���,
- isp�� icp�� Ȯ���ϰ�, ������ �����ڰ� �켱������
�� ���� ���� postfix�� �Ű��־���Ѵٴ� ���̴�.

����, �������� ������ ���� �ð��� �ϳ� �����ɷȴµ�,
�ᱹ ������ �˰���, string�� + ���� �� ""�� ���� �ʰ�
''�� �������� ������ �־���. �̸� �ݵ�� �����ϵ��� ����.
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