#include <cstdio>
#include <bitset>
using namespace std;

const int N = 520;
const int P = 60;

int n, m;
bitset<N> row[P+1][2][N], col[P+1][2][N];
long long dp[N][P+1][2];

int main() {
	scanf( "%d%d", &n, &m );
	for( int i = 1; i <= m; i++ ) {
		int u, v, t;
		scanf( "%d%d%d", &u, &v, &t );
		row[0][t][u][v] = col[0][t][v][u] = 1;
	}
	for( int p = 1; p <= P; p++ ) {
		for( int t = 0; t <= 1; t++ ) {
			for( int u = 1; u <= n; u++ )
				for( int v = 1; v <= n; v++ ) {
					bool cur = (row[p-1][t][u] & col[p-1][t^1][v]).any();
					row[p][t][u][v] = col[p][t][v][u] = cur;
				}
		}
	}
	for( int p = 1; p <= P; p++ ) {
		for( int t = 0; t <= 1; t++ ) {
			for( int u = 1; u <= n; u++ ) {
				dp[u][p][t] = max( dp[u][p][t], dp[u][p-1][t] );
				for( int v = 1; v <= n; v++ ) {
					if( row[p-1][t][u][v] ) {
						dp[u][p][t] = max( dp[u][p][t], (1LL << (p-1)) + dp[v][p-1][t^1] );
					}
				}
			}
		}
	}
	long long ans = 0;
	for( int u = 1; u <= n; u++ )
		for( int p = 1; p <= 60; p++ )
			ans = max( ans, dp[u][p][0] );
	printf( "%lld\n", ans > 1000000000000000000LL ? -1 : ans );
}
