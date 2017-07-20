#include <cstdio>

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
int head[N], dest[M], last[M], etot;
int in[N], out[N], seq[N], idc;

void adde( int u, int v ) {
	etot++;
	dest[etot] = v;
	last[etot] = head[u];
	head[u] = etot;
}
void dfs( int u, int f ) {
	seq[++idc] = u;
	in[u] = idc;
	for( int t = head[u]; t; t = last[t] ) {
		int v = dest[t];
		if( v == f ) continue;
		dfs( v, u );
	}
	out[u] = idc;
}
Node *build( int lf, int rg ) {
	Node *nd = ++tail;
	if( lf == rg ) {
		nd->sum = nd->flag = 0;
	} else {
		int mid = (lf + rg) >> 1;
		nd->ls = build( lf, mid );
		nd->rs = build( mid+1, rg );
		nd->sum = nd->flag = 0;
	}
	return nd;
}
long long query( Node *nd, int lf, int rg, int L, int R ) {
	if( L <= lf && rg <= R ) 
		return nd->sum;
	int mid = (lf + rg) >> 1;
	nd->pushdown(lf,rg);
	long long rt = 0;
	if( L <= mid )
		rt += query( nd->ls, lf, mid, L, R );
	if( R > mid )
		rt += query( nd->rs, mid + 1, rg, L, R );
	return rt;
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
int main() {
	scanf( "%d", &n );
	for( int i = 1; i < n; i++ ) {
		int u, v;
		scanf( "%d%d", &u, &v );
		adde( u, v );
		adde( v, u );
	}
	idc = 0;
	dfs( 1, 1 );
	root = build( 1, idc );
	scanf( "%d", &q );
	while( q-- ) {
		char ss[100];
		int u, w;
		scanf( "%s", ss );
		if( ss[0] == 'g' ) {
			scanf( "%d%d", &u, &w );
			modify( root, 1, idc, in[u], out[u], w );
		} else if( ss[0] == 's' ) {
			scanf( "%d", &u );
			printf( "%lld\n", query( root, 1, idc, in[u], in[u] ) );
		} else {
			scanf( "%d", &u );
			printf( "%lld\n", query( root, 1, idc, in[u], out[u] ) );
		}
	}
}

