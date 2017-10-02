#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;

int n;
int siz[N];
long long dp[N];
vector<int> g[N];

void dfs1(int u, int fa) {
	siz[u] = 1;
	for(int t = 0; t < (int)g[u].size(); t++) {
		int v = g[u][t];
		if(v == fa) continue;
		dfs1(v, u);
		siz[u] += siz[v];
	}
}
void dfs2(int u, int fa) {
	if(u == fa) 
		dp[u] = 1;
	else 
		dp[u] = dp[fa] + ((n - siz[u])<<1) - 1;
	for(int t = 0; t < (int)g[u].size(); t++) {
		int v = g[u][t];
		if(v == fa) continue;
		dfs2(v, u);
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1,1);
	dfs2(1,1);
	for(int i = 1; i <= n; i++)
		printf("%lld.000\n", dp[i]);
}

