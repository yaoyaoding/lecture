#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100010;
const int M = N + N;
const int P = 16;

struct Node {
	long long sum;
	Node *ls, *rs;
	void update() {
		sum = ls->sum + rs->sum;
	}
}pool[N*3], *tail=pool, *root;

int n, q;
int head[N], dest[M], last[M], etot;
int in[N], out[N], seq[N], dep[N], anc[N][P+1], idc;

void adde( int u, int v ) {
	etot++;
	dest[etot] = v;
	last[etot] = head[u];
	head[u] = etot;
}
void dfs( int u, int f ) {
	seq[++idc] = u;
	in[u] = idc;
	anc[u][0] = f;
	for( int p = 1; p <= P; p++ )
		anc[u][p] = anc[anc[u][p-1]][p-1];
	for( int t = head[u]; t; t = last[t] ) {
		int v = dest[t];
		dep[v] = dep[u] + 1;
		if( v == f ) continue;
		dfs( v, u );
	}
	out[u] = idc;
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
Node *build( int lf, int rg ) {
	Node *nd = ++tail;
	if( lf == rg ) {
		nd->sum = 0;
	} else {
		int mid = (lf + rg) >> 1;
		nd->ls = build( lf, mid );
		nd->rs = build( mid+1, rg );
		nd->sum = 0;
	}
	return nd;
}
long long query( Node *nd, int lf, int rg, int L, int R ) {
	if( L <= lf && rg <= R ) 
		return nd->sum;
	int mid = (lf + rg) >> 1;
	long long rt = 0;
	if( L <= mid )
		rt += query( nd->ls, lf, mid, L, R );
	if( R > mid )
		rt += query( nd->rs, mid + 1, rg, L, R );
	return rt;
}
void modify( Node *nd, int lf, int rg, int pos, int delta ) {
	if( lf == rg ) {
		nd->sum += delta;
		return;
	}
	int mid = (lf + rg)>>1;
	if( pos <= mid )
		modify( nd->ls, lf, mid, pos, delta );
	else
		modify( nd->rs, mid+1, rg, pos, delta );
	nd->update();
}
int main() {
	scanf( "%d", &n );
	for( int i = 1; i < n; i++ ) {
		int u, v;
		scanf( "%d%d", &u, &v );
		adde( u, v );
		adde( v, u );
	}
	idc = 0;
	dep[1] = 1;
	dfs( 1, 1 );
	root = build( 1, idc );
	scanf( "%d", &q );
	while( q-- ) {
		char ss[100];
		int u, v, w;
		scanf( "%s", ss );
		if( ss[0] == 'g' ) {
			scanf( "%d%d%d", &u, &v, &w );
			int ca = lca(u,v);
			modify( root, 1, idc, in[u], w );
			modify( root, 1, idc, in[v], w );
			modify( root, 1, idc, in[ca], -w );
			if( ca != 1 )
				modify( root, 1, idc, in[anc[ca][0]], -w );
		} else {
			scanf( "%d", &u );
			printf( "%lld\n", query(root,1,idc,in[u],out[u]) );
		}
	}
}

