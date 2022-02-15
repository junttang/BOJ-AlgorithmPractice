#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
// Algospot - FANMEETING
using namespace std;

void normalize(vector<int>& num) {
	// �ڸ��� �ø��� ���� �����ϴ� �ڵ�. �� �������� ��� x. ������ 0, 1�θ� �̷�����Ƿ�
	num.push_back(0);	// �ڸ��� �ø��� ����, ���� �� �տ� 0�� �߰�

	for (int i = 0; i < num.size() - 1; i++) {
		if (num[i] < 0) {		// ī���߹� �˰��� �ʿ��� �κ� !!
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {		// �Ϲ����� ���� �� ��� ���� �˰��� �ʿ��� �κ�
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while (num.size() > 1 && num.back() == 0) // �� �տ� 0�� ������ Truncate����.
		num.pop_back();
}

vector<int> multiply(const vector<int> &A, const vector<int> &B) {	
	// Naive�� ���� �� ��� ���� ����
	vector<int> num(A.size() + B.size() + 1, 0);

	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
			num[i + j] += (A[i] * B[j]);
		}
	}

	//normalize(c);		// �� �������� ���� normalize ����ȭ �۾� �ʿ� x
	return num;
}

/* ī���߹� �˰���
=> ������ ���� �� ���� ó�� �˰��򿡼�, �� ��� �������� ���� ���꺸�� ����/���� ����
�� ���� �� �÷� ���� �� ���� ū ���� ������ �����ϰ��� �ϴ� ���̵��� ������.
a x b = a1b1*10^2k + (a1b0 + a0b1)*10^k + a0b0 = z2*10*2k + z1*10^k + z0
z2 = a1 * b1;
z0 = a0 * b0;
z1 = (a0 + a1) * (b0 + b1) - z0 - z2;
*/

// a += b*(10^k)�� ������ �κ�. �� �״�� �迭 ���� ���ϱ⸦ ǥ���� ����.
void addTo(vector<int>& A, const vector<int>& B, int k) {
	A.resize(max(A.size(), B.size() + k));

	for (int i = 0; i < B.size(); i++) {
		A[i + k] += B[i];
	} // ������ �迭 ǥ���̹Ƿ� �ε����� �� 10�� �ŵ������� degree�� ��

	//// ����ȭ normalize. A�� �� �ڸ����� ���ؼ� Naive�� Normalize ����
	//for (int i = 0; i < A.size(); i++) {
	//	if (A[i] > 10) {
	//		A[i + 1] += A[i] % 10;
	//		A[i] /= 10;
	//	}
	//}
}

// a -= b �� ������ �κ�. �� �״�� �迭 ���� ���⸦ ǥ���� ����. (a >= b ����)
void subFrom(vector<int>& A, const vector<int>& B) {
	A.resize(max(A.size(), B.size()) + 1);

	for (int i = 0; i < B.size(); i++) {
		A[i] -= B[i];
	}

	//// ����ȭ normalize. ���ó� Naive�ϰ� üũ���ָ� �ȴ�.
	//for (int i = 0; i < A.size(); i++) {
	//	if (A[i] < 0) {
	//		A[i] += 10;
	//		A[i + 1] -= 1;
	//	}
	//}
}

// ī���߹� �˰����� �⺻������ Divide & Conquer. a1 * 10^k + a0�� �÷� �����ϰ� �̸�
// ��������� ��� �����ִ� ����. ��, ū ���� �� ���� �� ���� ���ϴ� ���, ���� ũ��� ��
// �� ������ �� �� ���ϴ� ���̴�.
vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	// a�� ����� �� ������ �ٲ㼭 ���
	int an = a.size(), bn = b.size();
	if (an < bn) return karatsuba(b, a);

	// Base Step : a�� b�� ����ִ� ���
	if (an == 0 || bn == 0) return vector<int>(); // ���ϸ� �� ���Ͱ� ��ȯ�ȴ�.

	//system("pause");
	//Threshold : ����� 50���� ������ �׳� Naive�� ���� �� ��� ���� �˰��� ����
	if (an <= 50) return multiply(a, b);

	int half = an / 2; // �ݾ� ������.

	// a�� b�� ������ ������.
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(bn, half));//<int>�� �� �ٳ�
	vector<int> b1(b.begin() + min<int>(bn, half), b.end());

	// z ���ϱ�. �� �κ��� �ٷ� ����� ȣ���� ���� �κ�.
	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0);	// a = a1 * 10^k + a0
	addTo(b0, b1, 0);	// b = b1 * 10^k + b0

	// z1 = (a0 * b0) - z0 - z2
	vector<int> z1 = karatsuba(a0, b0);	// ���ó� �� ������ ���ȣ��� ó��
	subFrom(z1, z0);	// �迭 ǥ�� ������ ���� ������.
	subFrom(z1, z2);

	// ����� ��ģ��. 
	// a x b = a1b1*10^2k + (a1b0 + a0b1)*10^k + a0b0 = z2*10*2k + z1*10^k + z0
	vector<int> res;
	addTo(res, z0, 0);
	addTo(res, z1, half);
	addTo(res, z2, half * 2);

	return res;
}


void solve(const string& mems, const string& fans) {
	int n = mems.size(), m = fans.size(), cnt = 0;
	vector<int> A(n), B(m);

	for (int i = 0; i < n; i++) {
		A[i] = (mems[i] == 'M') ? 1 : 0;
	}
	for (int i = 0; i < m; i++) {
		B[m - i - 1] = (fans[i] == 'M') ? 1 : 0;
	}

	vector<int> C = karatsuba(A, B);	// �ӵ� ����� ���� ī���߹� �˰��� ����

	for (int i = n - 1; i < m; i++) {
		if (C[i] == 0)
			cnt++;
	}

	cout << cnt << "\n";
}

int main() {
	int C;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> C;
	while (C--) {
		string mems, fans;

		cin >> mems >> fans;

		solve(mems, fans);
	}
	return 0;
}