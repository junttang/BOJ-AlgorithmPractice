#include <iostream>
// BOJ - 14501 ���
#define MAX_DAY		15
using namespace std;

/*
max��� �̸��� ���������� std�� ���Ե� Ű����� �̸��� ���ļ�
������ ������ �ҷ�����ų �� �ִ�.
*/

int T[MAX_DAY + 1];
int P[MAX_DAY + 1];
int MAX = 0;

void go(int N, int day, int sum) {
	if (day == N + 1) {
		if (sum > MAX) 
			MAX = sum;
		return;
	}
	if (day > N + 1)
		return;
	go(N, day + T[day], sum + P[day]);
	go(N, day + 1, sum);
}

int main(void) {
	int N;

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> T[i] >> P[i];
	
	go(N, 1, 0);
	cout << MAX;
	
	return 0;
}