#include <cstdio>

#ifdef WIN32
#define Auto "%I64d"
#else
#define Auto "%lld"
#endif

typedef long long dnt;

const int N = 100000 + 10;

int n, m;
int aa[N];

void change( int l, int r, int delta ) {
	for( int i = l; i <= r; i++ )
		aa[i] += delta;
}
void modify( int l, int r, int value ) {
	for( int i = l; i <= r; i++ )
		aa[i] = value;
}
dnt query( int l, int r ) {
	dnt rt = 0;
	for( int i = l; i <= r; i++ )
		rt += aa[i];
	return rt;
}

int main() {
	scanf( "%d%d", &n, &m );
	for( int i = 1; i <= n; i++ ) 
		scanf( "%d", aa + i );
	while( m-- ) {
		char ss[10];
		int l, r, delta, value;
		scanf( "%s", ss );
		if( ss[0] == 'c' ) {
			scanf( "%d%d%d", &l, &r, &delta );
			change( l, r, delta );
		} else if( ss[0] == 'm' ) {
			scanf( "%d%d%d", &l, &r, &value );
			modify( l, r, value );
		} else {
			scanf( "%d%d", &l, &r );
			printf( Auto"\n", query( l, r ) );
		}
	}
}
