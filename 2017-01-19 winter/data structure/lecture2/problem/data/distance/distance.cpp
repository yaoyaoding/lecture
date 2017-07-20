#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100010;
const int P = 16;
const int M = N + N;

int n, q;
int head[N], dest[M], wght[M], last[M], etot;
int dep[N], dis[N], anc[N][P+1];

void adde( int u, int v, int w ) {
	etot++;
	dest[etot] = v;
	last[etot] = head[u];
	wght[etot] = w;
	head[u] = etot;
}
void dfs( int u, int f ) {
	anc[u][0] = f;
	for( int p = 1; p <= P; p++ )
		anc[u][p] = anc[anc[u][p-1]][p-1];
	for( int t = head[u]; t; t = last[t] ) {
		int v = dest[t];
		if( v == f ) continue;
		dep[v] = dep[u] + 1;
		dis[v] = dis[u] + wght[t];
		dfs( v, u );
	}
}
int lca( int u, int v ) {
	if( dep[u] < dep[v] ) swap(u,v);
	int t = dep[u] - dep[v];
	for( int p = 0; t; t>>=1, p++ )
		if( t & 1 ) u = anc[u][p];
	if( u == v ) return u;
	for( int p = P; anc[u][0] != anc[v][0]; p-- )
		if( anc[u][p] != anc[v][p] )
			u = anc[u][p], v = anc[v][p];
	return anc[u][0];
}
int main() {
	scanf( "%d", &n );
	for( int i = 1; i < n; i++ ) {
		int u, v, w;
		scanf( "%d%d%d", &u, &v, &w );
		adde( u, v, w );
		adde( v, u, w );
	}
	dep[1] = 1;
	dis[1] = 0;
	dfs( 1, 1 );
	scanf( "%d", &q );
	while( q-- ) {
		int u, v;
		scanf( "%d%d", &u, &v );
		int ca = lca(u,v);
		printf( "%d\n", dis[u] + dis[v] - dis[ca] - dis[ca] );
	}
}

