#include <cstdio>
#include <vector>
using namespace std;

const int N = 100010;

struct Node {
	int cnt;
	Node *ls, *rs;
}pool[N * 200], *tail = pool, *roots[N], *null;

int n, q;
int aa[N];

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
void modify( vector<Node*> &va, int lf, int rg, int pos, int delta ) {
	for( int t = 0; t < (int)va.size(); t++ )
		va[t]->cnt += delta;
	if( lf == rg ) 
		return;
	int mid = (lf + rg)>>1;
	if( pos <= mid ) {
		for( int t = 0; t < (int)va.size(); t++ ) {
			if( va[t]->ls == null ) 
				va[t]->ls = newnode();
			va[t] = va[t]->ls;
		}
		modify( va, lf, mid, pos, delta );
	} else {
		for( int t = 0; t < (int)va.size(); t++ ) {
			if( va[t]->rs == null )
				va[t]->rs = newnode();
			va[t] = va[t]->rs;
		}
		modify( va, mid+1, rg, pos, delta );
	}
}
int query( vector<Node*> &va, vector<Node*> &vb, int lf, int rg, int k ) {
	if( lf == rg ) return lf;
	int mid = (lf + rg) >> 1;
	int lz = 0;
	for( int t = 0; t < (int)va.size(); t++ ) lz += va[t]->ls->cnt;
	for( int t = 0; t < (int)vb.size(); t++ ) lz -= vb[t]->ls->cnt;
	if( k <= lz ) {
		for( int t = 0; t < (int)va.size(); t++ ) va[t] = va[t]->ls;
		for( int t = 0; t < (int)vb.size(); t++ ) vb[t] = vb[t]->ls;
		return query( va, vb, lf, mid, k );
	} else {
		for( int t = 0; t < (int)va.size(); t++ ) va[t] = va[t]->rs;
		for( int t = 0; t < (int)vb.size(); t++ ) vb[t] = vb[t]->rs;
		k -= lz;
		return query( va, vb, mid+1, rg, k );
	}
}
void modify( int u, int x, int delta ) {
	vector<Node*> va;
	for( int i = u; i <= n; i += i & -i ) {
		va.push_back( roots[i] );
	}
	modify( va, 1, n, x, delta );
}
void modify( int u, int x ) {
	modify( u, aa[u], -1 );
	modify( u, x, +1 );
	aa[u] = x;
}
int query( int l, int r, int k ) {
	vector<Node*> va, vb;
	for( int i = r; i; i -= i & -i )
		va.push_back( roots[i] );
	for( int i = l - 1; i; i -= i & -i )
		vb.push_back( roots[i] );
	return query(va,vb,1,n,k);
}

int main() {
	scanf( "%d", &n );
	for( int i = 1; i <= n; i++ )
		scanf( "%d", aa + i );
	init();
	for( int i = 1; i <= n; i++ )
		roots[i] = newnode();
	for( int i = 1; i <= n; i++ )
		modify( i, aa[i], +1 );
	scanf( "%d", &q );
	while( q-- ) {
		char ss[100];
		scanf( "%s", ss );
		if( ss[0] == 'q' ) {
			int l, r, k;
			scanf( "%d%d%d", &l, &r, &k );
			printf( "%d\n", query(l,r,k) );
		} else {
			int pos, val;
			scanf( "%d%d", &pos, &val );
			modify( pos, val );
		}
	}
	//fprintf( stderr, "mem used %d%%\n", int(tail - pool) * 100 / int(sizeof(pool)/sizeof(pool[0])) );
}


