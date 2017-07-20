#include <cstdio>

int n;
int head[N], dest[M], last[M], etot;
int siz[N], son[N], dep[N], fat[N];
int top[N], in[N], out[N], idc;


void dfs1( int u ) {
	siz[u] = 1;
	for( int t = head[u]; t; t = last[t] ) {
		int v = dest[t];
		if( v == fat[u] ) continue;
		fat[v] = u;
		dep[v] = dep[u]+1;
		dfs(v);
		siz[u] += siz[v];
		if( siz[v] > siz[son[u]] ) son[u] = v;
	}
}
void dfs2( int u, int tp ) {
	in[u] = ++idc;
	top[u] = tp;
	if( son[u] ) dfs2( son[u], tp );
	for( int t = head[u]; t; t = last[t] ) {
		int v = dest[t];
		if( v == fat[u] || v == son[u] ) continue;
		dfs2( v, v );
	}
}
int lca( int u, int v ) {
	while( top[u] != top[v] ) {
		if( dep[top[u]] < dep[top[v]] ) swap(u,v);
		u = fat[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}
operate_path( int u, int v ) {
	while( top[u] != top[v] ) {
		if( dep[top[u]] < dep[top[v]] ) swap(u,v);
		operate_seg( in[top[u]], in[u] );
		u = fat[top[u]];
	}
	if( dep[u] < dep[v] ) swap( u, v );
	operate_seg( in[v], in[u] );
}
void build() {
	dep[1] = 1;
	fat[1] = 1;
	dfs1(1);
	idc = 0;
	dfs2(1,1);
}

