#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
const int M = N + N;

int n, q;
int head[N], dest[M], last[M], etot;
int siz[N], dep[N], son[N], fat[N];
int top[N], in[N], out[N], seq[N], idc;

void adde( int u, int v ) {
	etot++;
	dest[etot] = v;
	last[etot] = head[u];
	head[u] = etot;
}
void dfs1( int u ) {
	siz[u] = 1;
	for( int t = head[u]; t; t = last[t] ) {
		int v = dest[t];
		if( v == fat[u] ) continue;
		fat[v] = u;
		dep[v] = dep[u] + 1;
		dfs1( v );
		siz[u] += siz[v];
		if( siz[v] > siz[son[u]] ) son[u] = v;
	}
}
void dfs2( int u, int tp ) {
	in[u] = ++idc;
	seq[idc] = u;
	top[u] = tp;
	if( son[u] ) dfs2( son[u], tp );
	for( int t = head[u]; t; t = last[t] ) {
		int v = dest[t];
		if( v == son[u] || v == fat[u] ) continue;
		dfs2( v, v );
	}
	out[u] = idc;
}
int lca( int u, int v ) {
	while( top[u] != top[v] ) {
		if( dep[top[u]] < dep[top[v]] ) swap(u,v);
		u = fat[top[u]];
	} 
	return dep[u] < dep[v] ? u : v;
}
int main() {
	scanf( "%d", &n );
	for( int i = 1; i < n; i++ ) {
		int u, v;
		scanf( "%d%d", &u, &v );
		adde( u, v );
		adde( v, u );
	}
	fat[1] = 1;
	dep[1] = 1;
	dfs1(1);
	idc = 0;
	dfs2(1,1);
	scanf( "%d", &q );
	while( q-- ) {
		int u, v;
		scanf( "%d%d", &u, &v );
		printf( "%d\n", lca(u,v) );
	}
}

