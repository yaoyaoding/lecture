#include <cstdio>

const int N = 100010;

struct Node {
	int sum;
	int flag;
	Node *ls, *rs;
	void pushdown( int lf, int rg ) {
		if( flag ) {
			int mid = (lf + rg) >> 1;
			ls->flag = rs->flag = flag;
			ls->sum = flag * (mid - lf + 1);
			rs->sum = flag * (rg - mid);
			flag = 0;
		}
	}
	void update() {
		sum = ls->sum + rs->sum;
	}
}pool[N*3], *tail=pool, *root;

int n, q;
int aa[N];

Node *build( int lf, int rg ) {
	Node *nd = ++tail;
	if( lf == rg ) {
		nd->sum = aa[lf];
		nd->flag = 0;
	} else {
		int mid = (lf + rg) >> 1;
		nd->ls = build( lf, mid );
		nd->rs = build( mid+1, rg );
		nd->sum = nd->ls->sum + nd->rs->sum;
		nd->flag = 0;
	}
	return nd;
}
int query( Node *nd, int lf, int rg, int L, int R ) {
	if( L <= lf && rg <= R ) {
		return nd->sum;
	}
	int mid = (lf + rg) >> 1;
	nd->pushdown(lf,rg);
	int rt = 0;
	if( L <= mid )
		rt += query( nd->ls, lf, mid, L, R );
	if( R > mid )
		rt += query( nd->rs, mid+1, rg, L, R );
	nd->update();
	return rt;
}
void modify( Node *nd, int lf, int rg, int L, int R, int val ) {
	if( L <= lf && rg <= R ) {
		nd->sum = val * (rg - lf + 1);
		nd->flag = val;
		return;
	}
	int mid = (lf + rg) >> 1;
	nd->pushdown(lf,rg);
	if( L <= mid )
		modify( nd->ls, lf, mid, L, R, val );
	if( R > mid )
		modify( nd->rs, mid + 1, rg, L, R, val );
	nd->update();
}
int main() {
	scanf( "%d", &n );
	for( int i = 1; i <= n; i++ )
		scanf( "%d", aa + i );
	root = build( 1, n );
	scanf( "%d", &q );
	while( q-- ) {
		char ss[100];
		int l, r, d;
		scanf( "%s", ss );
		if( ss[0] == 'm' ) {
			scanf( "%d%d%d", &l, &r, &d );
			modify( root, 1, n, l, r, d );
		} else {
			scanf( "%d%d", &l, &r );
			printf( "%d\n", query(root,1,n,l,r) );
		}
	}
}


