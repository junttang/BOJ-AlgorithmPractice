#include <iostream>
#include <stack>
#include <string>
// BOJ - 17413 Reversing Words 2
/*
�ᱹ, ������ <>�� ���� ó������. �б� �κп��� ���������� ������� ������.
�ᱹ �˾Ƴ� �ذ�å��, �Ʒ��� ���� �б⿴��.
������ �־��� ������, �±� �κ��� �÷��׷� ó���� ���, �Ʒ��� �ܾ� ������
��Ȳ���� <�� ������ ���� ���� ���� �������־�� �ϴµ�, �� �κп��� �бⰡ
�������� ���̴�. 
���� ������ �ʵ��� ���ڿ��� ���� Ž�� ���ڿ� �±� �÷��׸� �ο��ϴ� �ε�
���� 1 ���̳��� ���־���.

������, ��� �̴�, < >�� �� Ž�� �ε����� �������� �׳� �÷��� ó�����ְ�,
���⼭, <�� ���� ���� �׻� ���� ���� ���ִ�, ��, 
while (!s.empty()) {
	cout << s.top();
	s.pop();
}
�� �÷��׸� �ο��ϴ� �ʹݺ� �κп����� �Ȱ��� �������ָ� �Ǵ� ���̴�.

�̷��� �κ��� �����ϰ� �ľ��ϵ��� �������.
*/

#define MAX_LEN		100001

using namespace std;

int main(void) {
	string input;
	stack<char> s;
	int tagflag = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	getline(cin, input);

	for (int i = 0; i <= input.size(); i++) {
		if (i >= 1 && input[i - 1] == '<')
			tagflag = 1;
		if (i >= 1 && input[i - 1] == '>')
			tagflag = 0;
		if (tagflag)
			cout << input[i];
		else {
			if (input[i] == ' ' || input[i] == '<' || input[i] == '\0') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				if (input[i] == ' ' || input[i] == '<')
					cout << input[i];
			}
			else
				s.push(input[i]);
		}
		
	}

	return 0;
}