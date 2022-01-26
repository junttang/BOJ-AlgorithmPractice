#include <iostream>
#include <vector>
#include <algorithm>
// Algospot - PICNIC
using namespace std;

int wayCount;
vector<int> students;
bool gganbu[10][10];

void solve(int n) {
	bool noflag = false;

	for (int i = 0; i < n; i += 2) {
		if (!gganbu[students[i]][students[i + 1]]
			|| students[i] > students[i + 1])
			noflag = true;
	}
	if (!noflag) {
		for (int i = 2; i < n; i += 2) {
			if (students[i - 2] > students[i])
				noflag = true;
		}
	}

	if (!noflag)
		wayCount++;
}

int main(void) {
	int C, n, m, x, y, two = 1;
	long long cnt = 1;

	cin >> C;
	while (C--) {
		cin >> n >> m;

		for (int i = 0; i < n; i++)
			students.push_back(i);

		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			gganbu[x][y] = true;
			gganbu[y][x] = true;
		}

		for (int i = n; i >= 1; i--) 
			cnt *= i;
		for (int i = 0; i < cnt; i++) {
			solve(n);
			next_permutation(students.begin(), students.end());
		}

		cout << wayCount << "\n";
		
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				gganbu[i][j] = false;
			}
		}
		wayCount = 0; cnt = 1; two = 1; students.clear();
	}

	return 0;
}