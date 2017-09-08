#include <bits/stdc++.h>
using namespace std;

const int N = 5000 + 10;

int comb[N][N];

void init(int n) {
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= i; j++) {
			if(j == 0 || j == i) {
				comb[i][j] = 1;
			} else {
				comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % 5;
			}
		}
}
int main() {
	init(5000);
	int T;
	scanf("%d", &T);
	while(T--) {
		int l, r, n;
		scanf("%d%d%d", &l, &r, &n);
		int ans = 0;
		for(int i = l; i <= r; i++)
			ans += (comb[n][i] == 0);
		printf("%d\n", ans);
	}
}

