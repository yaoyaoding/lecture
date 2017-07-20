#include <cstdio>

const int N = 100000 + 10;

int n;
int xx[N][2], yy[N][2];

int main() {
	scanf( "%d", &n );
	for( int i = 1; i <= n; i++ )
		scanf( "%d%d%d%d", xx[i], yy[i], xx[i]+1, yy[i] + 1 );
	int ans = 0;
	for( int x = 1; x <= n; x++ )
		for( int y = 1; y <= n; y++ ) {
			bool in = false;
			for( int i = 1; i <= n && !in; i++ )
				in = in || (xx[i][0] <= x && x <= xx[i][1] && yy[i][0] <= y && y <= yy[i][1]);
			ans += in;
		}
	printf( "%d\n", ans );
}
