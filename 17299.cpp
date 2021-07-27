#include <iostream>
#include <stack>
// BOJ - 17299 NGF ����ū��
#define MAX_NUM		1000001

/*
��ū�� �������� �񱳸� ���� ũ�Ⱑ �ƴ� ���� ���� ��
(���⿡�� freq)�� ���ϵ��� �����ϸ� �Ǵ� ����.

������ �Ǽ��δ�, ���� freq�� dense array�� ǥ���ϰ���
�ߴµ�, �̶� ������ ũ�� N�� �� ����� ũ��� ��������
���̱� ������ dense�ϰ� freq �迭�� ������ ���, �Ʒ�ó��
freq�� 1000001 ũ�⸸ŭ �Ҵ����־�� �ߴ�. �׷��� ���� ����
�Ǽ��� N��ŭ�� �Ҵ��ߴ� ���̴�. ����!
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