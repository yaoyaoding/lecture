#include <bits/stdc++.h>
using namespace std;

const int N = 10 + 1;

int n, m, q;
vector<int> g[N];
vector<vector<int> > path[N]; 
vector<int> ph[N];
bool vis[N];

void dfs(int u, int dst, vector<int> &cur) {
	if(u == dst) {
		path[dst].push_back(cur);
		return;
	}
	vis[u] = true;
	for(int v : g[u]) {
		if(vis[v]) continue;
		cur.push_back(v);
		dfs(v, dst, cur);
		cur.pop_back();
	}
	vis[u] = false;
}

vector<int> intersection(vector<int> r, vector<int> s) {
	vector<int> rt;
	rt.resize(max(r.size(), s.size()));
	rt.resize(set_intersection(r.begin(),r.end(),s.begin(),s.end(),rt.begin()) - rt.begin());
	return rt;
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
	}
	int src = 1;
	vector<int> cur;
	for(int u = 1; u <= n; u++) {
		cur.push_back(src);
		dfs(src, u, cur);
		cur.pop_back();
		for(int t = 0; t < (int)path[u].size(); t++) {
			if(t == 0)
				ph[u] = path[u][t];
			else
				ph[u] = intersection(path[u][t], ph[u]);
		}
	}
	while(q--) {
		int k;
		scanf("%d", &k);
		vector<int> ans;
		for(int i = 1; i <= k; i++) {
			int u;
			scanf("%d", &u);
			if(i == 1)
				ans = ph[u];
			else
				ans = intersection(ph[u], ans);
		}
		printf("%d\n", (int)ans.size());
	}
}

