/*
 * n <= 100
 * s <= 1023
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int Mod = 1e9 + 7;

int n, k, s;
int aa[N];
int dp[N][N][1<<10];

void update(int &a, int b) {
	a += b;
	if(a >= Mod) a -= Mod;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		memset( dp, 0, sizeof(dp));
		scanf("%d%d%d", &n, &k, &s);
		for(int i = 1; i <= n; i++) 
			scanf("%d", aa + i);
		dp[0][0][0] = 1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j <= i; j++) {
				for(int s = 0; s < (1<<10); s++) {
					update(dp[i+1][j][s], dp[i][j][s]);
					update(dp[i+1][j+1][s | aa[i+1]], dp[i][j][s]);
				}
			}
		printf("%d\n", dp[n][k][s]);
	}
}

