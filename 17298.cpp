#include <iostream>
#include <stack>
// BOJ - 17298 NGE 오큰수

/*
이러한 유형의 핵심은 스택의 원리를 포착하는데에 있다.
결국 이 문제에서 스택이 필요했던 가장 큰 이유는,
"5 2 7의 수열이 있는 경우 NGE 수열은 7 7 -1인데,
5의 바로 다음에 오는 수가 5보다 작은 경우, 즉, 예시처럼
2가 온 경우, 5를 킵해두고, 2에 대해서 다시 같은 행위(바로
다음에 오는 수와 비교)를 해서 7이니까 더 크므로 2의 인덱스 1에
7을, 그리고 pop이 된 후, 스택에 남아있는 친구인 5에 대해서도 7이
5보다 더 크므로 5의 인덱스 0에 7을 넣어주는 행위"
바로 이 부분에서 "킵함"에서 스택의 원리가 보임을 포착해야한다.
*/

using namespace std;

int main(void) {
	int N, *arr, *nge, n;
	stack<int> s;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	arr = new int[N];
	nge = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> n;
		arr[i] = n;
	}

	s.push(0);
	for (int i = 1; i < N; i++) {
		if (arr[s.top()] < arr[i]) {
			while (!s.empty() && arr[s.top()] < arr[i]) {
				nge[s.top()] = arr[i];
				s.pop();
			}
		}
		s.push(i);
	}
	while (!s.empty()) {
		nge[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < N; i++)
		cout << nge[i] << ' ';

	return 0;
}