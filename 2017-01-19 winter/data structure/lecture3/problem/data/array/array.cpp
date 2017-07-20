#include <cstdio>

const int N = 100010;

struct Node {
	int v;
	Node *ls, *rs;
}pool[N * 2 + N * 20], *tail = pool, *roots[N];

int n, q;
int aa[N];

Node *build( int lf, int rg ) {
	Node *nd = ++tail;
	if( lf == rg ) {
		nd->v = aa[lf];
	} else {
		int mid = (lf + rg)>>1;
		nd->ls = build( lf, mid );
		nd->rs = build( mid+1, rg );
	}
	return nd;
}
int query( Node *nd, int lf, int rg, int pos ) {
	if( lf == rg ) 
		return nd->v;
	int mid = (lf + rg)>>1;
	if( pos <= mid ) 
		return query( nd->ls, lf, mid, pos );
	else
		return query( nd->rs, mid+1, rg, pos );
}
Node *modify( Node *nd, int lf, int rg, int pos, int val ) {
	Node *nnd = ++tail;
	if( lf == rg ) {
		nnd->v = val;
		return nnd;
	}
	int mid = (lf + rg) >> 1;
	if( pos <= mid ) {
		nnd->ls = modify( nd->ls, lf, mid, pos, val );
		nnd->rs = nd->rs;
	} else {
		nnd->ls = nd->ls;
		nnd->rs = modify( nd->rs, mid+1, rg, pos, val );
	}
	return nnd;
}

int main() {
	scanf( "%d", &n );
	for( int i = 1; i <= n; i++ )
		scanf( "%d", aa + i );
	roots[0] = build( 1, n );
	scanf( "%d", &q );
	for( int t = 1; t <= q; t++ ) {
		char ss[100];
		int pos, val;
		scanf( "%s", ss );
		if( ss[0] == 'q' ) {
			scanf( "%d", &pos );
			roots[t] = roots[t-1];
			printf( "%d\n", query(roots[t],1,n,pos) );
		} else if( ss[0] == 'm' ) {
			scanf( "%d%d", &pos, &val );
			roots[t] = modify( roots[t-1], 1, n, pos, val );
		} else {
			int tt;
			scanf( "%d", &tt );
			roots[t] = roots[tt];
		}
	}
}

