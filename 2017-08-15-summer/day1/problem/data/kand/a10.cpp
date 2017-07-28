/*
 * n <= 20
 * s <= 1023
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 11;
const int Mod = 1e9 + 7;

int n, k, s;
int aa[N];
int ans = 0;

void dfs(int i, int cnt, int cur) {
	if(i == n) {
		ans += (cur == s) && (cnt == k);
		if(ans >= Mod) ans -= Mod;
		return;
	}
	dfs(i + 1, cnt, cur);
	dfs(i + 1, cnt + 1, cur & aa[i]);
}

int main() {
	scanf("%d%d%d", &n, &k, &s);
	for(int i = 0; i < n; i++)
		scanf("%d", aa + i);
	dfs(0, 0, (1<<20) - 1);
	printf("%d\n", ans);
}

