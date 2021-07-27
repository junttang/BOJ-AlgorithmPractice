#include <iostream>
#include <stack>
#include <string>
// BOJ - 10799 Steel Stick
/*
�ᱹ �� ������, "��ȣ ���ڿ�" ������ ������ ��ü������
������ ������ �䱸�Ѵٴ� ���� ����ϴ� ���� �ٽ��̴�.

���� ��ü�� ������ ��, ��ƽ�� �߽����� ���� �ʰ�, ������
�� �߽����� ����, ������ �ϳ��� ��������, ����� ������ ��
�� �����ؼ� ����, �̸� ��ȣ ���ڿ��� ������ �������� ������
�� ó���� �� ������ �ݻ� �߰��� �� �ִ�.
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