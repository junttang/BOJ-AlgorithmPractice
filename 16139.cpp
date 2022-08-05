#include <stdio.h>
// BOJ - 16139 Human-Computer Interaction
int p_alpha[200002][26];

int main(void) {
	char c, target;
	int q, l, r, idx = 1;

	while (1) {
		scanf("%c", &c);
		if (c == '\n') break;

		for (char cc = 'a'; cc <= 'z'; cc++) 
			p_alpha[idx][cc - 'a'] = p_alpha[idx - 1][cc - 'a'] + (c == cc);

		idx++;
	}

	scanf("%d", &q);
	while (q--) {
		getchar(); scanf("%c %d %d", &target, &l, &r);
		printf("%d\n", (p_alpha[r + 1][target - 'a'] - p_alpha[l][target - 'a']));
	}

	return 0;
}
