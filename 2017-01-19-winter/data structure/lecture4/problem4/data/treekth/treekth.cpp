#include <cstdio>
#include <vector>
using namespace std;

const int N = 100010;
const int M = N + N;
const int P = 16;

struct Node {
	int cnt;
	Node *ls, *rs;
	void update() {
		cnt = ls->cnt + rs->cnt;
	}
}pool[N * 30], *tail=pool, *roots[N], *null;

int n, q;
int aa[N];
int head[N], dest[M], last[M], etot;
int dep[N], anc[N][P+1];

void adde( int u, int v ) {
	etot++;
	dest[etot] = v;
	last[etot] = head[u];
	head[u] = etot;
}
void init() {
	null = ++tail;
	null->ls = null;
	null->rs = null;
	null->cnt = 0;
}
Node *newnode() {
	Node *nd = ++tail;
	nd->ls = null;
	nd->rs = null;
	nd->cnt = 0;
	return nd;
}
Node *modify( Node *nd, int lf, int rg, int pos, int delta ) {
	Node *nnd = newnode();
	if( lf == rg ) {
		nnd->cnt += delta;
		return nnd;
	}
	int mid = (lf + rg) >> 1;
	if( pos <= mid ) {
		nnd->ls = modify( nd->ls, lf, mid, pos, delta );
		nnd->rs = nd->rs;
		nnd->update();
	} else {
		nnd->ls = nd->ls;
		nnd->rs = modify( nd->rs, mid+1, rg, pos, delta );
		nnd->update();
	}
	return nnd;
}
int query( vector<Node*> &nds, int lf, int rg, int k ) {
	if( lf == rg )
		return lf;
	int mid = (lf + rg) >> 1;
	int lz = 0;
	for( int t = 0; t < 4; t++ )
		lz += nds[t]->ls->cnt * (t <= 1 ? 1 : -1);
	if( k <= lz ) {
		for( int t = 0; t < 4; t++ )
			nds[t] = nds[t]->ls;
		return query( nds, lf, mid, k );
	} else {
		for( int t = 0; t < 4; t++ )
			nds[t] = nds[t]->rs;
		k -= lz;
		return query( nds, mid+1, rg, k );
	}
}
void dfs( int u, int f ) {
	anc[u][0] = f;
	for( int p = 1; p <= P; p++ )
		anc[u][p] = anc[anc[u][p-1]][p-1];
	for( int t = head[u]; t; t = last[t] ) {
		int v = dest[t];
		if( v == f ) continue;
		roots[v] = modify( roots[u], 1, n, aa[v], +1 );
		dep[v] = dep[u] + 1;
		dfs( v, u );
	}
}
int lca( int u, int v ) {
	if( dep[u] < dep[v] ) swap(u,v);
	int t = dep[u] - dep[v];
	for( int p = 0; t; t >>= 1, p++ )
		if( t & 1 ) u = anc[u][p];
	if( u == v ) return u;
	for( int p = P; anc[u][0] != anc[v][0]; p-- )
		if( anc[u][p] != anc[v][p] ) u=anc[u][p],v= anc[v][p];
	return anc[u][0];
}
int query( int u, int v ) {
	int k, ca, len;
	ca = lca(u,v);
	len = dep[u] + dep[v] - dep[ca];
	if( ca != 1 ) len -= dep[anc[ca][0]];
	k = (1 + len) >> 1;
	vector<Node*> nds;
	nds.push_back( roots[u] );
	nds.push_back( roots[v] );
	nds.push_back( roots[ca] );
	nds.push_back( ca == 1 ? null : roots[anc[ca][0]] );
	return query( nds, 1, n, k );
}
int main() {
	scanf( "%d", &n );
	for( int i = 1; i <= n; i++ ) 
		scanf( "%d", aa + i );
	for( int i = 1; i < n; i++ ) {
		int u, v;
		scanf( "%d%d", &u, &v );
		adde( u, v );
		adde( v, u );
	}
	init();
	roots[1] = modify( null, 1, n, aa[1], +1 );
	dep[1] = 1;
	dfs(1,1);

	scanf( "%d", &q );
	while( q-- ) {
		int u, v;
		scanf( "%d%d", &u, &v );
		printf( "%d\n", query(u,v) );
	}
}

