#include <cstdio>
#include <iostream>
using namespace std;

const int N = 500000 + 10;

struct Node {
	int lf, rg;
	int c1, c2, vmax;
	Node *ls, *rs;
	int query( int h ) {
		if( lf == rg ) {
			return h < vmax;
		} else {
			if( h < ls->vmax )
				return ls->query(h) + c2;
			else
				return rs->query(h);
		}
	}
	void update() {
		vmax = max( ls->vmax, rs->vmax );
		c2 = rs->query( ls->vmax );
		c1 = ls->c1 + c2;
	}
}pool[N*2], *tail = pool, *root;

int n, m;
int hh[N];
Node *qu[N]; 
int bg, ed;

Node *build( int lf, int rg ) {
	Node *nd = ++tail;
	nd->lf = lf;
	nd->rg = rg;
	if( lf == rg ) {
		nd->c1 = 1;
		nd->c2 = 0;	//	no sense
		nd->vmax = hh[lf];
	} else {
		int mid = (lf + rg) >> 1;
		nd->ls = build( lf, mid );
		nd->rs = build( mid+1, rg );
		nd->update();
	}
	return nd;
}
void fetch( Node *nd, int L, int R ) {
	if( L <= nd->lf && nd->rg <= R ) {
		qu[++ed] = nd;
		return;
	}
	int mid = (nd->lf + nd->rg) >> 1;
	if( L <= mid )
		fetch( nd->ls, L, R );
	if( R > mid )
		fetch( nd->rs, L, R );
}
int query( int L, int R ) {
	bg = 1, ed = 0;
	fetch( root, L, R );
	int curh = 0;
	int ans = 0;
	for( int i = bg; i <= ed; i++ ) {
		ans += qu[i]->query( curh );
		curh = max( curh, qu[i]->vmax );
	}
	return ans;
}
int main() {
	scanf( "%d%d", &n, &m );
	for( int i = 1; i <= n; i++ )
		scanf( "%d", hh + i );
	root = build( 1, n );
	while( m-- ) {
		int L, R;
		scanf( "%d%d", &L, &R );
		printf( "%d\n", query(L,R) );
	}
}

