#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
const int M = N + N;

struct Node {
	long long sum, flag;
	Node *ls, *rs;
	void pushdown( int lf, int rg ) {
		if( flag ) {
			int mid = (lf + rg) >> 1;
			ls->flag += flag;
			ls->sum += flag * (mid - lf + 1);
			rs->flag += flag;
			rs->sum += flag * (rg - mid);
			flag = 0;
		}
	}
	void update() {
		sum = ls->sum + rs->sum;
	}
}pool[N*3], *tail=pool, *root;

int n, q;
int aa[N];
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

Node *build( int lf, int rg ) {
	Node *nd = ++tail;
	if( lf == rg ) {
		nd->sum = aa[seq[lf]];
		nd->flag = 0;
	} else {
		int mid = (lf + rg) >> 1;
		nd->ls = build( lf, mid );
		nd->rs = build( mid+1, rg );
		nd->flag = 0;
		nd->sum = nd->ls->sum + nd->rs->sum;
	}
	return nd;
}

void modify( Node *nd, int lf, int rg, int L, int R, int delta ) {
	if( L <= lf && rg <= R ) {
		nd->sum += 1LL * delta * (rg - lf + 1);
		nd->flag += delta;
		return;
	}
	int mid = (lf + rg) >> 1;
	nd->pushdown(lf,rg);
	if( L <= mid )
		modify( nd->ls, lf, mid, L, R, delta );
	if( R > mid )
		modify( nd->rs, mid+1, rg, L, R, delta );
	nd->update();
}

long long query( Node *nd, int lf, int rg, int L, int R ) {
	if( L <= lf && rg <= R ) 
		return nd->sum;
	int mid = (lf + rg)>>1;
	nd->pushdown(lf,rg);
	long long rt = 0;
	if( L <= mid )
		rt += query( nd->ls, lf, mid, L, R );
	if( R > mid )
		rt += query( nd->rs, mid+1, rg, L, R );
	return rt;
}

void mpth( int u, int v, int x ) {
	while( top[u] != top[v] ) {
		if( dep[top[u]] < dep[top[v]] ) swap(u,v);
		modify( root, 1, idc, in[top[u]], in[u], x );
		u = fat[top[u]];
	}
	if( dep[u] < dep[v] ) swap(u,v);
	modify( root, 1, idc, in[v], in[u], x );
}

long long qpth( int u, int v ) {
	long long rt = 0;
	while( top[u] != top[v] ) {
		if( dep[top[u]] < dep[top[v]] ) swap(u,v);
		rt += query( root, 1, idc, in[top[u]], in[u] );
		u = fat[top[u]];
	}
	if( dep[u] < dep[v] ) swap(u,v);
	rt += query( root, 1, idc, in[v], in[u] );
	return rt;
}

void msub( int u, int x ) {
	modify( root, 1, idc, in[u], out[u], x );
}

long long qsub( int u ) {
	return query( root, 1, idc, in[u], out[u] );
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
	fat[1] = 1;
	dep[1] = 1;
	dfs1(1);
	idc = 0;
	dfs2(1,1);
	root = build( 1, n );
	scanf( "%d", &q );
	while( q-- ) {
		char ss[100];
		int u, v, x;
		scanf( "%s", ss );
		if( ss[0] == 'm' && ss[1] == 's' ) {
			scanf( "%d%d", &u, &x );
			msub(u,x);
		} else if( ss[0] == 'm' && ss[1] == 'p' ) {
			scanf( "%d%d%d", &u, &v, &x );
			mpth(u,v,x);
		} else if( ss[0] == 'q' && ss[1] == 's' ) {
			scanf( "%d", &u );
			printf( "%lld\n", qsub(u) );
		} else {
			scanf( "%d%d", &u, &v );
			printf( "%lld\n", qpth(u,v) );
		}
	}
}

