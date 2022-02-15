#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
// Algospot - FANMEETING
using namespace std;

void normalize(vector<int>& num) {
	// 자리수 올림을 위해 존재하는 코드. 본 문제에선 사용 x. 정수가 0, 1로만 이루어지므로
	num.push_back(0);	// 자리수 올림을 위해, 수의 맨 앞에 0을 추가

	for (int i = 0; i < num.size() - 1; i++) {
		if (num[i] < 0) {		// 카라추바 알고리즘에 필요한 부분 !!
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {		// 일반적인 곱의 합 방식 곱셈 알고리즘에 필요한 부분
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while (num.size() > 1 && num.back() == 0) // 맨 앞에 0이 있으면 Truncate하자.
		num.pop_back();
}

vector<int> multiply(const vector<int> &A, const vector<int> &B) {	
	// Naive한 곱의 합 방식 곱셈 과정
	vector<int> num(A.size() + B.size() + 1, 0);

	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
			num[i + j] += (A[i] * B[j]);
		}
	}

	//normalize(c);		// 본 문제에선 굳이 normalize 정규화 작업 필요 x
	return num;
}

/* 카라추바 알고리즘
=> 기존의 곱의 합 곱셈 처리 알고리즘에서, 그 계산 과정에서 곱셈 연산보다 덧셈/뺄셈 연산
의 수를 더 늘려 보다 더 빠른 큰 수의 곱셈을 수행하고자 하는 아이디어에서 시작함.
a x b = a1b1*10^2k + (a1b0 + a0b1)*10^k + a0b0 = z2*10*2k + z1*10^k + z0
z2 = a1 * b1;
z0 = a0 * b0;
z1 = (a0 + a1) * (b0 + b1) - z0 - z2;
*/

// a += b*(10^k)를 구현한 부분. 말 그대로 배열 간의 더하기를 표현한 것임.
void addTo(vector<int>& A, const vector<int>& B, int k) {
	A.resize(max(A.size(), B.size() + k));

	for (int i = 0; i < B.size(); i++) {
		A[i + k] += B[i];
	} // 정수의 배열 표현이므로 인덱스가 곧 10의 거듭제곱의 degree인 것

	//// 정규화 normalize. A의 각 자릿수에 대해서 Naive한 Normalize 수행
	//for (int i = 0; i < A.size(); i++) {
	//	if (A[i] > 10) {
	//		A[i + 1] += A[i] % 10;
	//		A[i] /= 10;
	//	}
	//}
}

// a -= b 를 구현한 부분. 말 그대로 배열 간의 빼기를 표현한 것임. (a >= b 가정)
void subFrom(vector<int>& A, const vector<int>& B) {
	A.resize(max(A.size(), B.size()) + 1);

	for (int i = 0; i < B.size(); i++) {
		A[i] -= B[i];
	}

	//// 정규화 normalize. 역시나 Naive하게 체크해주면 된다.
	//for (int i = 0; i < A.size(); i++) {
	//	if (A[i] < 0) {
	//		A[i] += 10;
	//		A[i + 1] -= 1;
	//	}
	//}
}

// 카라추바 알고리즘은 기본적으로 Divide & Conquer. a1 * 10^k + a0의 꼴로 분해하고 이를
// 재귀적으로 계속 나눠주는 것임. 즉, 큰 정수 두 개를 한 번에 곱하는 대신, 절반 크기로 나
// 눈 조각을 네 번 곱하는 것이다.
vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	// a가 사이즈가 더 작으면 바꿔서 계산
	int an = a.size(), bn = b.size();
	if (an < bn) return karatsuba(b, a);

	// Base Step : a나 b가 비어있는 경우
	if (an == 0 || bn == 0) return vector<int>(); // 곱하면 빈 벡터가 반환된다.

	//system("pause");
	//Threshold : 사이즈가 50보다 작으면 그냥 Naive한 곱의 합 방식 곱셈 알고리즘 수행
	if (an <= 50) return multiply(a, b);

	int half = an / 2; // 반씩 나눈다.

	// a와 b를 반으로 나눈다.
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(bn, half));//<int>가 왜 붙냐
	vector<int> b1(b.begin() + min<int>(bn, half), b.end());

	// z 구하기. 이 부분이 바로 재귀적 호출이 들어가는 부분.
	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0);	// a = a1 * 10^k + a0
	addTo(b0, b1, 0);	// b = b1 * 10^k + b0

	// z1 = (a0 * b0) - z0 - z2
	vector<int> z1 = karatsuba(a0, b0);	// 역시나 이 곱셈은 재귀호출로 처리
	subFrom(z1, z0);	// 배열 표현 정수의 뺄셈 과정임.
	subFrom(z1, z2);

	// 결과를 합친다. 
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

	vector<int> C = karatsuba(A, B);	// 속도 향상을 위해 카라추바 알고리즘 도입

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