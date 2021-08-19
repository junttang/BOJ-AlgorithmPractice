#include <iostream>
// BOJ - 6064 ī�� �޷�
using namespace std;

int main(void) {
	int T;
	int M, N, x, y, temp, nofoundflag = 0, i;

	cin >> T;
	while (T--) {
		cin >> M >> N >> x >> y;

		nofoundflag = 1;
		for (i = x; i <= M * N; i += M) { // �� ���� ã�� ���� �������.
			temp = i % N;			// M*N�� ��Ȯ�� ���� �ƴ�����,
			if (temp == 0) temp = N;	// ��ȿ���� Ȯ���� �����ϹǷ� �������!

			if (temp == y) {
				nofoundflag = 0;
				break;
			}
		}

		if (nofoundflag) cout << -1 << '\n';
		else cout << i << '\n';
	}

	return 0;
}