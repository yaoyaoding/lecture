#include <cstdio>

int n, m, q;

struct Case1 {
	int bit[100010];
	void modify( int p, int d ) {
		for( int i = p; i <= m; i += i & -i )
			bit[i] += d;
	}
	int query( int r ) {
		int rt = 0;
		for( int i = r; i; i -= i & -i ) 
			rt += bit[i];
		return rt;
	}
	int query( int l, int r ) {
		return query(r) - query(l-1);
	}
	void solve() {
		while (q--) {
			char ss[100];
			scanf( "%s", ss );
			if( ss[0] == 'm' ) {
				int x, y, d;
				scanf( "%d%d%d", &x, &y, &d );
				modify( y, d );
			} else {
				int x1, y1, x2, y2;
				scanf( "%d%d%d%d", &x1, &y1, &x2, &y2 );
				printf( "%d\n", query(y1,y2) );
			}
		}
	}
}case1;
struct Case2 {
	int bit[1100][1100];
	void modify( int x, int y, int d ) {
		for( int i = x; i <= n; i += i & -i )
			for( int j = y; j <= m; j += j & -j )
				bit[i][j] += d;
	}
	int query( int x, int y ) {
		int rt = 0;
		for( int i = x; i; i -= i & -i )
			for( int j = y; j; j -= j & -j )
				rt += bit[i][j];
		return rt;
	}
	int query( int x1, int y1, int x2, int y2 ) {
		return query(x2,y2) - query(x1-1,y2) - query(x2,y1-1) + query(x1-1,y1-1);
	}
	void solve() {
		while(q--) {
			char ss[100];
			scanf( "%s", ss );
			if( ss[0] == 'm' ) {
				int x, y, d;
				scanf( "%d%d%d", &x, &y, &d );
				modify( x, y, d );
			} else {
				int x1, y1, x2, y2;
				scanf( "%d%d%d%d", &x1, &y1, &x2, &y2 );
				printf( "%d\n", query(x1,y1,x2,y2) );
			}
		}
	}
}case2;

int main() {
	scanf( "%d%d%d", &n, &m, &q );
	if( n == 1 )
		case1.solve();
	else
		case2.solve();
}

