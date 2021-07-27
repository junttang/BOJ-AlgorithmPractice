#include <iostream>
#include <stack>
#include <string>
// BOJ - 17413 Reversing Words 2
/*
결국, 문제는 <>에 대한 처리였다. 분기 부분에서 지속적으로 어려움을 느꼈다.
결국 알아낸 해결책은, 아래와 같은 분기였다.
문제가 있었던 이유는, 태그 부분을 플래그로 처리할 경우, 아래의 단어 뒤집기
상황에서 <를 만났을 때도 스택 팝을 진행해주어야 하는데, 그 부분에서 분기가
꼬여버린 것이다. 
따라서 꼬이지 않도록 문자열의 현재 탐색 문자와 태그 플래그를 부여하는 인덱
스를 1 차이나게 해주었다.

하지만, 사실 이는, < >를 현 탐색 인덱스를 기준으로 그냥 플래그 처리해주고,
여기서, <를 만날 때는 항상 스택 팝을 해주는, 즉, 
while (!s.empty()) {
	cout << s.top();
	s.pop();
}
를 플래그를 부여하는 초반부 부분에서도 똑같이 수행해주면 되는 것이다.

이러한 부분을 섬세하게 파악하도록 노력하자.
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