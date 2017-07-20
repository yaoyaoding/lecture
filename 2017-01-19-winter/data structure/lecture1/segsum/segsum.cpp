#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100000 + 10;

struct Node {
	long long flag, sum;
	Node *ls, *rs;
	
	void pushdown( int lf, int rg ) {
		if( flag ) {
			int mid = (lf + rg) >> 1;
			ls->flag += flag;
			ls->sum += (mid - lf + 1) * flag;
			rs->flag += flag;
			rs->sum += (rg - mid) * flag;
			flag = 0;
		}
	}
	void update() {
		sum = ls->sum + rs->sum;
	}
}pool[N * 2 + 5], *tail=pool, *root;

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
void modify( Node *nd, int lf, int rg, int L, int R, int delta ) {
	if( L <= lf && rg <= R ) {
		nd->sum += (long long)(rg - lf + 1) * delta;
		nd->flag += delta;
		return;
	}
	int mid = (lf + rg) >> 1;
//	nd->pushdown(lf,rg);
	if( L <= mid )
		modify( nd->ls, lf, mid, L, R, delta );
	if( R > mid )
		modify( nd->rs, mid+1, rg, L, R, delta );
	nd->update();
	
}
long long query( Node *nd, int lf, int rg, int L, int R ) {
	if( L <= lf && rg <= R ) {
		return nd->sum;
	}
	int mid = (lf + rg) >> 1;
	nd->pushdown(lf,rg);
	long long rt = 0;
	if( L <= mid )
		rt += query( nd->ls, lf, mid, L, R );
	if( R > mid )
		rt += query( nd->rs, mid+1, rg, L, R );
	nd->update();
	return rt;
}

int main() {
	scanf( "%d", &n );
	for( int i = 1; i <= n; i++ )
		scanf( "%d", &aa[i] );
	root = build( 1, n );
	scanf( "%d", &q );
	while( q-- ) {
		char ss[100];
		scanf( "%s", ss );
		if( ss[0] == 'm' ) {
			int L, R, delta;
			scanf( "%d%d%d", &L, &R, &delta );
			modify( root, 1, n, L, R, delta );
		} else {
			int L, R;
			scanf( "%d%d", &L, &R );
			cout << query(root,1,n,L,R) << endl;
			//printf( "%lld\n", query(root,1,n,L,R) );
		}
	}
}

