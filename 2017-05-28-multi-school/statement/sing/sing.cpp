#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;
const int M = 1000000 + 10;

int n, m;
vector<int> g[N], in[N], out[N];
vector<int> scc[N];
int low[N], dfn[N], idx[N], sccno[N], scc_cnt, idc;
int stk[N], top;
bool vis[N];
int dist[N];
int dp[N]; 
int ep[N][5][5];

void tarjan( int u ) {
	dfn[u] = low[u] = ++idc;
	stk[++top] = u;
	for( int t = 0; t < (int)g[u].size(); t++ ) {
		int v = g[u][t];
		if( !dfn[v] ) {
			tarjan(v);
			low[u] = min( low[u], low[v] );
		} else if( !sccno[v] ) {
			low[u] = min( low[u], dfn[v] );
		}
	}
	if( low[u] == dfn[u] ) {
		++scc_cnt;
		while(1) {
			int v;
			v = stk[top--];
			sccno[v] = scc_cnt;
			idx[v] = (int)scc[scc_cnt].size();
			scc[scc_cnt].push_back(v);
			if( v == u ) break;
		}
	}
}
void dfs( int s, int c, int u ) {
	int &epv = ep[s][idx[c]][idx[u]];
	epv = max( epv, dist[u] );
	for( int t = 0; t < (int)in[u].size(); t++ ) {
		int v = in[u][t];
		if( vis[v] ) continue;
		dist[v] = dist[u] + 1;
		vis[v] = true;
		dfs( s, c, v );
		vis[v] = false;
	}
}
void lbuild( int s ) {
	for( int t = 0; t < (int)scc[s].size(); t++ ) {
		int u = scc[s][t];
		dist[u] = 1;
		vis[u] = true;
		dfs( s, u, u );
		vis[u] = false;
	}
}
int main() {
	scanf( "%d%d", &n, &m );
	for( int i = 1; i <= m; i++ ) {
		int u, v;
		scanf( "%d%d", &u, &v );
		g[u].push_back(v);
	}
	for( int u = 1; u <= n; u++ ) {
		if( !dfn[u] ) tarjan(u);
	}
	for( int u = 1; u <= n; u++ ) {
		for( int t = 0; t < (int)g[u].size(); t++ ) {
			int v = g[u][t];
			if( sccno[u] == sccno[v] ) {
				in[u].push_back( v );
			} else {
				out[u].push_back( v );
			}
		}
	}
	for( int s = 1; s <= scc_cnt; s++ ) {
		lbuild(s);
		for( int t = 0; t < (int)scc[s].size(); t++ ) {
			int u = scc[s][t];
			for( int tt = 0; tt < (int)scc[s].size(); tt++ ) {
				int v = scc[s][tt];
				dp[u] = max( dp[u], ep[s][idx[u]][idx[v]] );
				for( int ttt = 0; ttt < (int)out[v].size(); ttt++ ) {
					int w = out[v][ttt];
					dp[u] = max( dp[u], ep[s][idx[u]][idx[v]] + dp[w] );
				}
			}
		}
	}
	int ans = 0;
	for( int u = 1; u <= n; u++ ) 
		ans = max( ans, dp[u] );
	printf( "%d\n", ans );
}

