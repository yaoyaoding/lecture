#include <cstdio>

const int N = 510;
const int P = 9;

int n, m, q;
int st[N][N][P+1][P+1];
int logb[N];

int gcd( int a, int b ) {
	return b == 0 ? a : gcd(b,a%b);
}
void init() {
	for( int pi = 0; pi <= P; pi++ )
		for( int pj = 0; pj <= P; pj++ ) {
			if( pi == 0 && pj == 0 ) continue;
			for( int i = 1; i + (1<<pi) - 1 <= n; i++ )
				for( int j = 1; j + (1<<pj) - 1 <= m; j++ ) {
					if( pi == 0 ) {
						st[i][j][pi][pj] = gcd( st[i][j][pi][pj-1], st[i][j + (1<<(pj-1))][pi][pj-1] );
					} else {
						st[i][j][pi][pj] = gcd( st[i][j][pi-1][pj], st[i + (1<<(pi-1))][j][pi-1][pj] );
					}
				}
		}
}
int query( int x1, int y1, int x2, int y2 ) {
	int dx = x2 - x1 + 1;
	int dy = y2 - y1 + 1;
	int px = logb[dx], py = logb[dy];
	int ans = 0;
	ans = gcd( ans, st[x1][y1][px][py] );
	ans = gcd( ans, st[x2 - (1<<px) + 1][y1][px][py] );
	ans = gcd( ans, st[x1][y2 - (1<<py) + 1][px][py] );
	ans = gcd( ans, st[x2 - (1<<px) + 1][y2 - (1<<py) + 1][px][py] );
	return ans;
}
int main() {
	logb[0] = -1;
	for( int i = 1; i < N; i++ )
		logb[i] = logb[i/2] + 1;
	scanf( "%d%d%d", &n, &m, &q );
	for( int i = 1; i <= n; i++ )
		for( int j = 1; j <= m; j++ ) 
			scanf( "%d", &st[i][j][0][0] );
	init();
	while( q-- ) {
		int x1, y1, x2, y2;
		char ss[100];
		scanf( "%s%d%d%d%d", ss, &x1, &y1, &x2, &y2 );
		printf( "%d\n", query(x1,y1,x2,y2) );
	}
}



