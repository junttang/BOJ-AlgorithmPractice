#include <iostream>
// BOJ - 1248 �����
#define MAX_NUM		10
using namespace std;

char S[MAX_NUM][MAX_NUM];
int A[MAX_NUM];
int flag = 0;		// �� ������ ��� �� ��� ��ü ���Ḧ ���� �÷���

/*
�� 0 1 2 3			// ���� ��Ȳ ����
0  - + 0 +
1    + + +
2      - -
3        +
*/

bool good(int N, int index) {
	int sum;

	for (int start = 0; start <= index; start++) {
		sum = 0;
		for (int i = start; i <= index; i++)
			sum += A[i];
		if (S[start][index] == '+' && sum <= 0) return false;
		if (S[start][index] == '-' && sum >= 0) return false;
		if (S[start][index] == '0' && sum != 0) return false;
	}
	
	return true;
}
/*
��͸� ��Ʈ��ŷ�Ͽ� �ð� ���⵵�� ������ ���̱� ���� good �Լ�
����Լ����� index�� ���� ������, �ش� ��Ȳ�� ���Ͽ�, A[index]�� i�� ��
0���� index����, 1���� index����, 2����.... �� �ؼ� S[][]�� �����ϴ� ������
��, A[index]�� �ĺ����� S[][]�� �������� �ʴ��� Ȯ�����ִ� �Լ��̴�.

good�� ��ȸ�� ���� ������, �� ģ���� ���ʿ��� ���ȣ���� ���δ�.
*/

void go(int N, int index) {		// ����Լ�
	if (flag) return;
	if (index == N) {
		for (int i = 0; i < N; i++)
			cout << A[i] << ' ';
		flag = 1;
		return;
	}

	if (S[index][index] == '0') {	// �� �κ� �Ǽ� ����!!!
		A[index] = 0;
		if (good(N, index))		// A[index] ���� �����ϴٸ�,
			go(N, index + 1);	// ��� ȣ��!
	}

	else if (S[index][index] == '+') {
		for (int i = 1; i <= 10; i++) {
			A[index] = i;
			if (good(N, index))
				go(N, index + 1);
		}
	}

	else {
		for (int i = 1; i <= 10; i++) {
			A[index] = -i;
			if (good(N, index))
				go(N, index + 1);
		}
	}
}

int main(void) {
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++)
			cin >> S[i][j];
	}
	go(N, 0);

	return 0;
}