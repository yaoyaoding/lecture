#include <bits/stdc++.h>
using namespace std;

const int N = 5000 + 10;

int n, m, p;
int aa[N], bb[N];

int main() {
	scanf("%d%d%d", &n, &m, &p );
	for( int i = 1; i <= n; i++ )
		scanf("%d", aa + i );
	for( int i = 1; i <= m; i++ )
		scanf("%d", bb + i );
	sort( aa + 1, aa + 1 + n );
	sort( bb + 1, bb + 1 + m );
	int ans = 2e9 + 10;
	for( int i = 1; i + n - 1 <= m; i++ ) {
		int sub = 0;
		for( int j = 0; j < n; j++ )
			sub = max( sub, abs(aa[1+j]-bb[i+j]) + abs(bb[i+j]-p) );
		ans = min( ans, sub );
	}
	printf( "%d\n", ans );
}
