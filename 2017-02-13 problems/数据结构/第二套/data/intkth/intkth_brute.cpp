#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int n, q;
int aa[N], bb[N];

void modify( int pos, int val ) {
	aa[pos] = val;
}
int query( int l, int r, int k ) {
	for( int i = 0; i < r - l + 1; i++ )
		bb[i] = aa[l + i];
	std::sort( bb, bb + r - l + 1 );
	return bb[k-1];
}
int main() {
	scanf( "%d%d", &n, &q );
	for( int i = 1; i <= n; i++ )
		scanf( "%d", aa + i );
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
}

