#include <iostream>
#include <vector>
#include <algorithm>
// Algospot - FENCE
using namespace std;

int solve(vector<int> &fence, int left, int right) {
	if (left == right) // Base : 막대가 하나밖에 없는 경우
		return fence[left];

	int mid = (left + right) / 2; // [left, mid], [mid+1, right] 두 구간으로 분할
	int result = max(solve(fence, left, mid), solve(fence, mid + 1, right));
	//부분 문제 3:두 부분에 모두 걸치는 사각형 중 가장 큰 것
	int low = mid, high = mid + 1;
	int height = min(fence[low], fence[high]);

	result = max(result, height * 2); // [mid, mid+1]의 너비 2인 직사각형

	while (left < low || high < right) { // 직사각형을 양쪽 방향으로 확장
		if (high < right && (low == left || fence[low - 1] < fence[high + 1])) {
			high++;
			height = min(height, fence[high]);
		} // 높이가 더 높은쪽으로 확장한다. 그래야 기존 height와 비교했을때 올바른
		else { // 결과를 도출할 수 있으므로
			low--;
			height = min(height, fence[low]);
		}
		result = max(result, height*(high - low + 1)); // 확장 결과를 업데이트
	}

	return result;
}

int main(void) {
	int C, num;

	cin >> C;
	while (C--) {
		cin >> num;

		vector<int> fence(num, 0);

		for (int i = 0; i < num; i++)
			cin >> fence[i];

		cout << solve(fence, 0, fence.size() - 1) << "\n";
	}

	return 0;
}