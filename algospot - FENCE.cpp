#include <iostream>
#include <vector>
#include <algorithm>
// Algospot - FENCE
using namespace std;

int solve(vector<int> &fence, int left, int right) {
	if (left == right) // Base : ���밡 �ϳ��ۿ� ���� ���
		return fence[left];

	int mid = (left + right) / 2; // [left, mid], [mid+1, right] �� �������� ����
	int result = max(solve(fence, left, mid), solve(fence, mid + 1, right));
	//�κ� ���� 3:�� �κп� ��� ��ġ�� �簢�� �� ���� ū ��
	int low = mid, high = mid + 1;
	int height = min(fence[low], fence[high]);

	result = max(result, height * 2); // [mid, mid+1]�� �ʺ� 2�� ���簢��

	while (left < low || high < right) { // ���簢���� ���� �������� Ȯ��
		if (high < right && (low == left || fence[low - 1] < fence[high + 1])) {
			high++;
			height = min(height, fence[high]);
		} // ���̰� �� ���������� Ȯ���Ѵ�. �׷��� ���� height�� �������� �ùٸ�
		else { // ����� ������ �� �����Ƿ�
			low--;
			height = min(height, fence[low]);
		}
		result = max(result, height*(high - low + 1)); // Ȯ�� ����� ������Ʈ
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