#include <iostream>
#include <stack>
// BOJ - 17299 NGF 오등큰수
#define MAX_NUM		1000001

/*
오큰수 문제에서 비교를 수의 크기가 아닌 수의 등장 빈도
(여기에선 freq)를 비교하도록 수정하면 되는 문제.

유일한 실수로는, 나는 freq를 dense array로 표현하고자
했는데, 이때 수열의 크기 N과 각 요소의 크기는 개별적인
것이기 때문에 dense하게 freq 배열을 구성할 경우, 아래처럼
freq를 1000001 크기만큼 할당해주어야 했다. 그러나 나는 순간
실수로 N만큼만 할당했던 것이다. 주의!
*/

using namespace std;

int main(void) {
	int N, *arr, *freq, *ngf, n;
	stack<int> s;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	arr = new int[N];
	freq = new int[MAX_NUM]{};
	ngf = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> n;
		arr[i] = n;
		freq[n - 1] += 1;
	}

	s.push(0);
	for (int i = 1; i < N; i++) {
		if (freq[arr[s.top()] - 1] < freq[arr[i] - 1]) {
			while (!s.empty() && freq[arr[s.top()] - 1] < freq[arr[i] - 1]) {
				ngf[s.top()] = arr[i];
				s.pop();
			}
		}
		s.push(i);
	}
	while (!s.empty()) {
		ngf[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < N; i++)
		cout << ngf[i] << ' ';

	return 0;
}