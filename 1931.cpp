#include <iostream>
#include <algorithm>
// BOJ - 1931 Assign Conference Room 
using namespace std;

typedef struct { int start, end; } Conf;
Conf arr[100000];

bool pred(Conf a, Conf b) { 
	if (a.end < b.end) return true;
	else if (a.end == b.end && a.start < b.start) return true;
	return false; 
}

int solve(int n) {
	int cnt = 0, j;
	sort(arr, arr + n, pred);

	for (int i = 0; i < n; ) {
		for (j = i + 1; j < n; j++) {
			if (arr[j].start >= arr[i].end) break;
		}
		i = j;
		cnt++;
	}

	return cnt;
}

int main(void) {
	int n;
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) { cin >> arr[i].start >> arr[i].end; }
	cout << solve(n);

	return 0;
}
// 벨로그 포스팅 해야함. 인사이트를 잘 기억하자. 깃헙도 올려야함.
/*
11
1 4		3
3 5		2
0 6		6
5 7		2
3 8		5
5 9		4
6 10	4
8 11	3
8 12	4
2 13	11
12 14	2

12 14 v
2 13
8 12
8 11 v
6 10
5 9
3 8
5 7 v
0 6
3 5
1 4 v

10
0 2
1 1
1 1
1 1
1 3
3 5
2 4
2 3
5 8
6 10

6 10
5 8 v
3 5 v
2 4
2 3
1 3 v
0 2
1 1 v
1 1 v
1 1 v

4
1 4
4 4
4 4
1 4

4 4 v
4 4 v
1 4
1 4 v

3
1 10
9 12
11 20

11 20 v
9 12
1 10 v

1. 빨리 끝나는 애들부터 체킹한다.
*/