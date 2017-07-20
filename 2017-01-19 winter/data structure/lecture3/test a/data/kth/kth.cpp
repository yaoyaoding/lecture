#include <cstdio>

const int N = 100010;

struct Node {
	int cnt;
	Node *ls, *rs;
}pool[N*2+10], *tail=pool, *root;

int q;
int lbound, rbound;
int aa[N];

Node *build( int lf, int rg ) {
	Node *nd = ++tail;
	if( lf == rg ) {
		nd->cnt = aa[lf - lbound];
	} else {
		int mid = (lf + rg) >> 1;
		nd->ls = build( lf, mid );
		nd->rs = build( mid+1, rg );
		nd->cnt = nd->ls->cnt + nd->rs->cnt;
	}
	return nd;
}
void modify( Node *nd, int lf, int rg, int pos, int delta ) {
	if( lf == rg ) {
		nd->cnt += delta;
		if( nd->cnt < 0 ) nd->cnt = 0;
		return;
	}
	int mid = (lf + rg) >> 1;
	if( pos <= mid )
		modify( nd->ls, lf, mid, pos, delta );
	else
		modify( nd->rs, mid+1, rg, pos, delta );
	nd->cnt = nd->ls->cnt + nd->rs->cnt;
}
int query( Node *nd, int lf, int rg, int k ) {
	if( lf == rg ) return lf;
	int mid = (lf + rg) >> 1;
	int lz = nd->ls->cnt;
	if( k <= lz ) 
		return query( nd->ls, lf, mid, k );
	else
		return query( nd->rs, mid+1, rg, k - lz );
}
int main() {
	scanf( "%d%d", &lbound, &rbound );
	for( int i = 0; i < rbound - lbound + 1; i++ )
		scanf( "%d", &aa[i] );
	root = build( lbound, rbound );
	scanf( "%d", &q );
	while( q-- ) {
		char ss[100];
		int x, k;
		scanf( "%s", ss );
		if( ss[0] == 'a' ) {
			scanf( "%d", &x );
			modify( root, lbound, rbound, x, +1 );
		} else if( ss[0] == 'd' ) {
			scanf( "%d", &x );
			modify( root, lbound, rbound, x, -1 );
		} else {
			scanf( "%d", &k );
			printf( "%d\n", query( root, lbound, rbound, k ) );
		}
	}
}

