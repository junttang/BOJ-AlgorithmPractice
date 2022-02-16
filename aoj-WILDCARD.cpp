#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
// Algospot - WILDCARD
using namespace std;

int cache[101][101]; // 문자열의 최대 길이가 100이므로 널문자를 포함하여 101

string wildcard, filename;

// Dynamic Programming
// -1 : 계속 탐색해야함을 의미
// 1 : 와일드카드가 올바르게 사용되었음을 의미 (매칭)
// 0 : 두 문자열이 매칭되지 않음을 의미

int matchMemoized(int w, int f) { // memoization
	int &result = cache[w][f];	// w와 f까지 이미 체크되었는지 확인한다.

	if (result != -1)	// 캐시에 저장된 결과에 따라서
		return result;	// -1일때, 즉, 계속 확인해야할 때만 아래로 내려감.

	// wildcard와 filename을 선형적으로 읽어나간다.
	if (w < wildcard.size() && f < filename.size() &&
		(wildcard[w] == '?' || wildcard[w] == filename[f]))
		return result = matchMemoized(w + 1, f + 1);
	// 문제 상황 상 ?는 아무 문자나 대응되면 되고, 두 인덱스의 문자가 같을때도 킵고잉

	// 더 이상 대응할 수 없으면 while문이 종료된 케이스를 확인한다.
	// 문자열의 끝에 도달해서 종료된 경우 : 길이만 같으면 된다. 위의 조건에 의해 
	if (w == wildcard.size() && f == filename.size())
		return result = 1;

	// *를 만나서 종료된 경우: *에 몇 글자가 대응하는지 재귀호출로 확인
	if (wildcard[w] == '*') {	// ㅁㅁ* 조각 이후의 조각 확인하는데,
		if (matchMemoized(w + 1, f) ||
			(f < filename.size() && matchMemoized(w, f + 1)))
			return result = 1;
		// *에 대응 문자 없는 경우, 또는 한 글자 더 대응하는 경우(또 다른 조각있는경우)
	}

	// 이 외의 경우는 모두 대응 x
	return result = 0;
}

int main(void) {
	int c;

	cin >> c;
	while (c--) {
		vector<string> v;	// 주목할만한 기술
		int n;

		cin >> wildcard;
		cin >> n;

		for (int j = 0; j < n; j++) {
			memset(cache, -1, sizeof(cache));	// 캐시를 모두 -1로

			cin >> filename;

			if (matchMemoized(0, 0) == 1) // 매칭된 경우에만 벡터에 삽입(정렬위함)
				v.push_back(filename);
		}

		sort(v.begin(), v.end()); // 출력 조건 충족

		for (int j = 0; j < v.size(); j++)
			cout << v[j] << '\n';

		cout << '\n';
	}

	return 0;
}