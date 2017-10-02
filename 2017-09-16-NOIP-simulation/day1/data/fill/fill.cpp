#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;
const int P = 16;

struct Path {
	int u, v, ca;
	Path(){}
	Path(int u, int v, int ca):u(u),v(v),ca(ca){}
};

int n, m;
vector<int> g[N];
int in[N], out[N], dep[N], anc[N][P + 1], idc;
vector<Path> paths;
int bit[N];

bool operator<(const Path &r, const Path &s) {
	return dep[r.ca] > dep[s.ca];
}
void init() {
	paths.clear();
	for(int u = 1; u <= n; u++) {
		g[u].clear();
		bit[u] = 0;
	}
	idc = 0;
}
void modify(int lf, int delta) {
	for(int i = lf; i <= n; i += i & -i)
		bit[i] += delta;
}
void modify(int lf, int rg, int delta) {
	modify(lf, delta);
	modify(rg + 1, -delta);
}
int query(int pos) {
	int rt = 0;
	for(int i = pos; i; i-=i&-i)
		rt += bit[i];
	return rt;
}
void dfs(int u, int fa) {
	in[u] = ++idc;
	for(int p = 1; p <= P; p++)
		anc[u][p] = anc[anc[u][p-1]][p-1];
	for(int t = 0; t < (int)g[u].size(); t++) { 
		int v = g[u][t];
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		anc[v][0] = u;
		dfs(v, u);
	}
	out[u] = idc;
}
int lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u,v);
	int t = dep[u] - dep[v];
	for(int p = 0; t; t>>=1,p++)
		if(t & 1) u = anc[u][p];
	if(u == v) return u;
	for(int p = P; anc[u][0] != anc[v][0]; p--)
		if(anc[u][p] != anc[v][p]) {
			u = anc[u][p];
			v = anc[v][p];
		}
	return anc[u][0];
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		init();
		for(int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		anc[1][0] = 1;
		dep[1] = 1;
		dfs(1,1);
		for(int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			paths.push_back(Path(u,v,lca(u,v)));
		}
		sort(paths.begin(), paths.end());
		int ans = 0;
		for(int t = 0; t < (int)paths.size(); t++) {
			Path &p = paths[t];
			if(query(in[p.u]) > 0 || query(in[p.v]) > 0) continue;
			ans ++;
			modify(in[p.ca], out[p.ca], +1);
		}
		printf("%d\n", ans);
	}
}

