#include <iostream>
#include <vector>
#include <algorithm>
// Algospot - CLOCKSYNC
using namespace std;

#define INF 9999		// INF�� ���������� int ���� ���� ���� �� �����鼭, ������ INF��
#define SWITCH 10
#define CLOCK 16

// linked[i][j] : ����ġ�� �ð��� ������踦 ǥ���� 2���� �׷���
// 1�̸� ����� ��. ���� ����ġ, ���� �ð�. ~> push ��Ȳ�� ó���� ȿ����!
int linked[SWITCH][CLOCK] = {
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};

// ��� �ð谡 12�ø� ����Ű�� �ִ��� Ȯ���ϴ� �ܼ��� ���ν���
bool areAligned(const vector<int> &clocks) {
	for (int i = 0; i < CLOCK; i++)
		if (clocks[i] != 12)
			return false;
	return true;
}

// swtch�� ����ġ�� ���� �ð��� �ð��� �����ϴ� �����ϸ鼭�� ȿ������ �Լ�
void push(vector<int> &clocks, int swtch) {
	for (int clock = 0; clock < CLOCK; clock++)
		if (linked[swtch][clock] == 1) { // swtch���� �� ��ȸ�ϸ鼭, ����� �ð���
			clocks[clock] += 3;			// �ð��� �ٲ��ش�.

			if (clocks[clock] == 15)
				clocks[clock] = 3;
		}
}

// clocks : ���� �ð���� ����
// swtch : �̹��� ���� ����ġ�� ��ȣ
//�� �־��� ��, ���� ����ġ���� ������ clocks�� 12�÷� ���� �� �ִ� �ּ� Ƚ���� ��ȯ
//���� �Ұ����ϴٸ� INF �̻��� ū ���� ��ȯ

int solve(vector<int> &clocks, int swtch) {
	if (swtch == SWITCH) // 10���� ����ġ�� ���� ��� ��������� ���� ���� Ȯ��(Ż������)
		return areAligned(clocks) ? 0 : INF;	// ���ĵ� ��� 0�� ��ȯ�ؼ� ��� ����
			// ���ĵ��� ���� ��쿣 INF�� ����� ����� ������ �˸���
	int result = INF;
	/*
	���� swtch ����ġ�� 0�� ������ ������ ���������� ��� �õ���.

	��, ��ǻ� (,,,,,,,,,)�̸�, �� ĭ�� 0~3�� ������, ��� ����(4^10)���� ������ ������
	�ּ��� Ƚ��(result)�� ã�� ��ȯ�ϴ� ������ ��!!

	�Ʒ� �Լ����� push(clocks, swtch)�� �׹� ȣ��Ǿ����� �ᱹ clocks�� ������ ���� ����
	*/
	for (int cnt = 0; cnt < 4; cnt++) {
		result = min(result, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}

	return result;
}

int main(void) {
	int C;

	vector<int> clocks(CLOCK);
	cin >> C;

	while (C--) {
		for (int i = 0; i < CLOCK; i++)
			cin >> clocks[i];

		int result = solve(clocks, 0);

		if (result == INF)
			cout << -1 << endl;
		else
			cout << result << endl;

	}

	return 0;
}