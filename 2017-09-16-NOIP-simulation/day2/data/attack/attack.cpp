#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;
const int P = 16;

int n, m, q;
int indeg[N];
int anc[N][P + 1], dep[N];
vector<int> g[N], gg[N], vgg[N], stk, order;

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
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		indeg[v]++;
		gg[u].push_back(v);
		vgg[v].push_back(u);
	}
	stk.push_back(1);
	while(!stk.empty()) {
		int u = stk.back();
		stk.pop_back();
		order.push_back(u);
		for(int t = 0; t < (int)gg[u].size(); t++) {
			int v = gg[u][t];
			indeg[v]--;
			if(indeg[v] == 0)
				stk.push_back(v);
		}
	}

	dep[1] = 1;
	for(int p = 0; p <= P; p++)
		anc[1][p] = 1;

	for(int t = 1; t < (int)order.size(); t++) {
		int u = order[t];
		int ca = vgg[u][0];
		for(int tt = 1; tt < (int)vgg[u].size(); tt++) 
			ca = lca(ca,vgg[u][tt]);
		g[ca].push_back(u);
		anc[u][0] = ca;
		dep[u] = dep[ca] + 1;
//		fprintf(stderr, "add edge %d -> %d\n", ca, u);
		for(int p = 1; p <= P; p++)
			anc[u][p] = anc[anc[u][p-1]][p-1];
	}
	while(q--) {
		int k;
		scanf("%d", &k);
		int ca = -1;
		while(k--) {
			int u;
			scanf("%d", &u);
			if(ca == -1)
				ca = u;
			else
				ca = lca(ca,u);
		}
		printf("%d\n", dep[ca]);
	}
}

