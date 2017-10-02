#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;

struct Edge {
	int u, v;
	Edge(){}
	Edge(int u, int v):u(u),v(v){}
};

int n, m, q;
int ccno[N], ctot;
int etot;
Edge edges[N];
vector<int> ge[N];
vector<int> cc[N];
vector<long long> sum[N];
vector<int> mdist[N];
int diameter[N];
int vdis[N], edis[N];

bool cmp(int u, int v) { return vdis[u] < vdis[v]; }
void dfs(int u, int f) {
	cc[ctot].push_back(u);
	ccno[u] = ctot;
	for(int t = 0; t < (int)ge[u].size(); t++) {
//	for(int e : ge[u]) {
		int e = ge[u][t];
		int v = edges[e].v;
		if(v == f) continue;
		dfs(v, u);
	}
}
int dodp(int e) {
	if(edis[e] != -1) return edis[e];
	int s = edges[e].v;
	int &dpv = edis[e];
	dpv = 1;
	for(int t = 0; t < (int)ge[s].size(); t++) {
//	for(int ee : ge[s]) {
		int ee = ge[s][t];
		if((ee ^ 1) == e) continue;
		dpv = max(dpv, dodp(ee) + 1);
	}
	return dpv;
}
double query(int c1, int c2) {
	if(cc[c1].size() > cc[c2].size()) swap(c1,c2);
	int D = max(vdis[cc[c1].back()], vdis[cc[c2].back()]);
	long long tot = 0;
	long long s = 0;
	for(int t = 0; t < (int)cc[c1].size(); t++) {
		int u = cc[c1][t];
//	for(int u : cc[c1]) {
		int need = D - vdis[u] - 1;
		vdis[n+1] = need;
		int iv = (int)(lower_bound(cc[c2].begin(), cc[c2].end(), n + 1, cmp) - cc[c2].begin());
		if(iv != (int)cc[c2].size()) {
			s += sum[c2][iv] + (vdis[u] + 1) * 1LL * ((int)cc[c2].size() - iv);
			tot += ((int)cc[c2].size() - iv);
		}
	}
	long long all = (long long)cc[c1].size() * (long long)cc[c2].size();
	s += (all - tot) * D;
	return (double)((long double)s / all);
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[etot] = Edge(u,v);
		ge[u].push_back(etot++);
		edges[etot] = Edge(v,u);
		ge[v].push_back(etot++);
	}
	for(int i = 1; i <= n; i++) {
		if(ccno[i]) continue;
		ctot++;
		dfs(i, i);
	}
	memset(edis, -1, sizeof(edis));
	for(int i = 0; i < etot; i++)
		dodp(i);
	for(int u = 1; u <= n; u++) {
		vdis[u] = 0;
		for(int t = 0; t < (int)ge[u].size(); t++) {
			int e = ge[u][t];
//		for(int e : ge[u]) {
			vdis[u] = max(vdis[u], edis[e]);
		}
	}
	for(int c = 1; c <= ctot; c++) {
		sort(cc[c].begin(), cc[c].end(), cmp);
		sum[c].resize(cc[c].size());
		for(int t = (int)cc[c].size() - 1; t >= 0; t--) {
			sum[c][t] = 0;
			if(t + 1 < (int)cc[c].size())
				sum[c][t] += sum[c][t+1];
			sum[c][t] += vdis[cc[c][t]];
		}
	}
	map<pair<int,int>,double> mp;
	while(q--) {
		int u, v, c1, c2;
		scanf("%d%d", &u, &v);
		c1 = ccno[u];
		c2 = ccno[v];
		if(c1 == c2) {
			printf("-1.0\n");
		} else {
			if(c1 > c2) swap(c1,c2);
			map<pair<int,int>,double>::iterator it = mp.find(make_pair(c1,c2));
			if(it != mp.end()) {
				printf("%.10f\n", it->second);
			} else {
				double ans = query(c1,c2);
				mp[make_pair(c1,c2)] = ans;
				printf("%.10f\n", ans);
			}
		}
	}
}

