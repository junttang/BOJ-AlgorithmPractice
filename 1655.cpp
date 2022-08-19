#include <iostream>
#include <vector>
#include <queue>
// BOJ - 1655 Say Middle
using namespace std;

priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;

int main(void) {
	int n, num;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;

		if (i == 0)
			maxheap.push(num);
		else if (i == 1) {
			if (num > maxheap.top())
				minheap.push(num);
			else {
				minheap.push(maxheap.top());
				maxheap.pop();
				maxheap.push(num);
			}
		}
		else {
			maxheap.push(num);

			if (maxheap.top() > minheap.top()) {
				maxheap.pop();
				minheap.push(num);
				if (minheap.size() > maxheap.size()) {
					maxheap.push(minheap.top());
					minheap.pop();
				}
			}
			if (maxheap.size() - minheap.size() > 1) {
				minheap.push(maxheap.top());
				maxheap.pop();
			}
		}

		cout << maxheap.top() << '\n';
	}

	return 0;
}

// 10000000
// 100000 * 10
// n^2logn ~> 즉, 매 입력마다 정렬하는 것은 미친 짓. 그렇다고 선형 대입하는 것도!
// 즉, heap을 사용해야함. 매 입력이 logn이고, 여기에 n 곱해봤자 nlogn이므로

/*
정렬 문제인데, 문제 입력 조건을 보면, 단순 정렬 알고리즘으로는 시간 초과가 자명
~> 결국 heap의 사용은 불가피한 것!
~~> 그런데, 이때, 중간값은 도통 어떻게 구해야할지 모르겠는데,
~~~> 먼가 중간지점과의 차이값으로 heap을 만들던가, 또는, heap에서 높이를 따지는
~~~> 식의 idea들이 떠오르지만, 결국 따지고 따져보면 답이 되지 않음을 알아챌 수 있음.
- 일단 후자는 자료구조 구축 자체를 물을리가 없고, 전후자 모두 논리적으로 답이 되지 못함.

==> 실제 해결 Idea : 최대/최소 힙을 모두 사용한다. 마치, 모래시계꼴로 구축하는 것.
===> 아래가 최대힙, 위에가 최소힙으로 두고, 두 힙의 사이즈를 같거나, 최대 1만 차이나도록
만들어주는 것. 대신, 아래가 더 육중해야할 것이고. 왜냐, 짝수 시 작은 수를 말하라했으므로.
*/

/*
1    v

5
1    v

 5
 2   v
1

  10
 5
 2   v
1

  10
 5
 2   v
1 -99

7 10
 5
 2   v
1 -99

7 10
 5
 5   v
2 1
   -99
*/
