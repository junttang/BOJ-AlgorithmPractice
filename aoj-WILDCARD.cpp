#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
// Algospot - WILDCARD
using namespace std;

int cache[101][101]; // ���ڿ��� �ִ� ���̰� 100�̹Ƿ� �ι��ڸ� �����Ͽ� 101

string wildcard, filename;

// Dynamic Programming
// -1 : ��� Ž���ؾ����� �ǹ�
// 1 : ���ϵ�ī�尡 �ùٸ��� ���Ǿ����� �ǹ� (��Ī)
// 0 : �� ���ڿ��� ��Ī���� ������ �ǹ�

int matchMemoized(int w, int f) { // memoization
	int &result = cache[w][f];	// w�� f���� �̹� üũ�Ǿ����� Ȯ���Ѵ�.

	if (result != -1)	// ĳ�ÿ� ����� ����� ����
		return result;	// -1�϶�, ��, ��� Ȯ���ؾ��� ���� �Ʒ��� ������.

	// wildcard�� filename�� ���������� �о����.
	if (w < wildcard.size() && f < filename.size() &&
		(wildcard[w] == '?' || wildcard[w] == filename[f]))
		return result = matchMemoized(w + 1, f + 1);
	// ���� ��Ȳ �� ?�� �ƹ� ���ڳ� �����Ǹ� �ǰ�, �� �ε����� ���ڰ� �������� ŵ����

	// �� �̻� ������ �� ������ while���� ����� ���̽��� Ȯ���Ѵ�.
	// ���ڿ��� ���� �����ؼ� ����� ��� : ���̸� ������ �ȴ�. ���� ���ǿ� ���� 
	if (w == wildcard.size() && f == filename.size())
		return result = 1;

	// *�� ������ ����� ���: *�� �� ���ڰ� �����ϴ��� ���ȣ��� Ȯ��
	if (wildcard[w] == '*') {	// ����* ���� ������ ���� Ȯ���ϴµ�,
		if (matchMemoized(w + 1, f) ||
			(f < filename.size() && matchMemoized(w, f + 1)))
			return result = 1;
		// *�� ���� ���� ���� ���, �Ǵ� �� ���� �� �����ϴ� ���(�� �ٸ� �����ִ°��)
	}

	// �� ���� ���� ��� ���� x
	return result = 0;
}

int main(void) {
	int c;

	cin >> c;
	while (c--) {
		vector<string> v;	// �ָ��Ҹ��� ���
		int n;

		cin >> wildcard;
		cin >> n;

		for (int j = 0; j < n; j++) {
			memset(cache, -1, sizeof(cache));	// ĳ�ø� ��� -1��

			cin >> filename;

			if (matchMemoized(0, 0) == 1) // ��Ī�� ��쿡�� ���Ϳ� ����(��������)
				v.push_back(filename);
		}

		sort(v.begin(), v.end()); // ��� ���� ����

		for (int j = 0; j < v.size(); j++)
			cout << v[j] << '\n';

		cout << '\n';
	}

	return 0;
}