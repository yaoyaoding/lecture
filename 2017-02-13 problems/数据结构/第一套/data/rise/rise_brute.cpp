#include <cstdio>
#include <iostream>
using namespace std;

const int N = 500000 + 10;

int n, m;
int hh[N];

int query( int L, int R ) {
	int curh = 0;
	int rt = 0;
	for( int i = L; i <= R; i++ ) {
		rt += hh[i] > curh;
		curh = max( curh, hh[i] );
	}
	return rt;
}

int main() {
	scanf( "%d%d", &n, &m );
	for( int i = 1; i <= n; i++ )
		scanf( "%d", hh + i );
	while( m-- ) {
		int L, R;
		scanf( "%d%d", &L, &R );
		printf( "%d\n", query(L,R) );
	}
}

