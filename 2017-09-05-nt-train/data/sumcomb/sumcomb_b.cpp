#include <bits/stdc++.h>
using namespace std;

const int N = 5000 + 10;
const int Mod = 1e9 + 7;

long long comb[N][N];

void init(int n) {
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= i; j++) {
			if(j == 0 || j == i)
				comb[i][j] = 1;
			else
				comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % Mod;
		}
}

int main() {
	init(5000);
	int T;
	scanf("%d", &T);
	while(T--) {
		int dir, n, m;
		scanf("%d%d%d", &dir, &n, &m);
		if(dir == 1) {
			long long ans = 0;
			for(int i = 0; i <= n; i++)
				ans = (ans + comb[i][m]) % Mod;
			printf("%lld\n",ans);
		} else if(dir == 2) {
			long long ans = 0;
			for(int i = 0; i <= n && i <= m; i++) {
				ans = (ans + comb[n-i][m-i]) % Mod;
			}
			printf("%lld\n", ans);
		}
	}
}
