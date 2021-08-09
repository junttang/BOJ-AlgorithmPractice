#include <iostream>
// BOJ - 11722 LDS
#define MAX_NUM		1000
using namespace std;
// D[i] : A[i]�� ���������� �ϰ�, ���� �� ���Һκм���
int A[MAX_NUM + 1];
int D[MAX_NUM + 1];
// D[i] = D[i-1] + 1
int makeDArray(int N) {
	int max = 0;
	
	for (int i = 1; i <= N; i++) {
		D[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[j] > A[i] && D[i] < D[j] + 1)
				D[i] = D[j] + 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (D[i] >= max)
			max = D[i];
	}	// D[i] �� �ִ��� Longest�̴�!!
	return max;
}


int main(void) {
	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	cout << makeDArray(N);

	return 0;
}