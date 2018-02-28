#include <cstdio>

const int N = 200000 + 10;
const int oo = 0x3f3f3f3f;

struct Splay {
	int pre[N], son[N][2], val[N], siz[N], ntot, root;

	void update( int nd ) {
		siz[nd] = siz[son[nd][0]]+siz[son[nd][1]]+1;
	}
	int build( int p, int *a, int lf, int rg ) {
		if( lf>rg ) return 0;
		int nd = ++ntot;
		int mid = (lf+rg)>>1;
		pre[nd] = p;
		son[nd][0] = build( nd, a, lf, mid-1 );
		son[nd][1] = build( nd, a, mid+1, rg );
		val[nd] = a[mid];
		update( nd );
		return nd;
	}
	void init( int n, int *a ) {
		siz[0] = 0;
		root = build( 0, a, 1, n );
	}
	void rotate( int nd, int d ) {
		int p = pre[nd];
		int s = son[nd][!d];
		int ss = son[s][d];

		son[nd][!d] = ss;
		son[s][d] = nd;
		if( p ) son[p][ nd==son[p][1] ] = s;
		else root = s;

		pre[nd] = s;
		pre[s] = p;
		if( ss ) pre[ss]=nd;

		update(nd);
		update(s);
	}
	void splay( int nd, int top=0 ) {
		while( pre[nd]!=top ) {
			int p = pre[nd];
			int nl = nd==son[p][0];
			if( pre[p]==top ) {
				rotate( p, nl );
			} else {
				int pp = pre[p];
				int pl = p==son[pp][0];
				if( nl==pl ) {
					rotate( pp, pl );
					rotate( p, nl );
				} else {
					rotate( p, nl );
					rotate( pp, pl );
				}
			}
		}
	}
	int find( int pos ) {
		int nd=root;
		while(1) {
			int ls = siz[son[nd][0]];
			if( pos<=ls ) nd=son[nd][0];
			else if( pos>=ls+2 ) {
				pos -= ls+1;
				nd=son[nd][1];
			} else return nd;
		}
	}
	void erase( int pos ) {
		int lnd = find(pos-1);
		int rnd = find(pos+1);
		splay( lnd );
		splay( rnd, lnd );
		son[rnd][0] = 0;
		update( rnd );
		update( lnd );
	}
	int query( int pos ) {
		return val[find(pos)];
	}
};

Splay T;
int n, m;
int w[N];

int main() {
	scanf( "%d%d", &n, &m );
	w[1] = oo;
	for( int i=2; i<=n+1; i++ ) 
		scanf( "%d", w+i );
	w[n+2] = oo;
	T.init( n+2, w );
	for( int i=1; i<=m; i++ ) {
		char opt[10];
		int pos;
		scanf( "%s%d", opt, &pos );
		if( opt[0]=='D' ) {
			T.erase( pos+1 );
		} else {
			printf( "%d\n", T.query(pos+1) );
		}
	}
}
