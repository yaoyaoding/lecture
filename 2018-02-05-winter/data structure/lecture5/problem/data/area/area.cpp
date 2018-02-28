#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 3100;

int n;
int xx[N][2], yy[N][2]; 
int xdisc[N], ydisc[N], xdtot, ydtot;
int flag[N][N];

int main() {
	scanf( "%d", &n );
	for( int i = 1; i <= n; i++ ) {
		scanf( "%d%d%d%d", &xx[i][0], &yy[i][0], &xx[i][1], &yy[i][1] );
		xx[i][1]++, yy[i][1]++;
		xdisc[++xdtot] = xx[i][0];
		xdisc[++xdtot] = xx[i][1];
		ydisc[++ydtot] = yy[i][0];
		ydisc[++ydtot] = yy[i][1];
	}
	sort( xdisc+1, xdisc+1+xdtot );
	sort( ydisc+1, ydisc+1+ydtot );
	xdtot = unique( xdisc+1, xdisc+1+xdtot ) - xdisc - 1;
	ydtot = unique( ydisc+1, ydisc+1+ydtot ) - ydisc - 1;
	for( int i = 1; i <= n; i++ ) {
		for( int t = 0; t <= 1; t++ )
			xx[i][t] = lower_bound( xdisc+1, xdisc+1+xdtot, xx[i][t] ) - xdisc;
		for( int t = 0; t <= 1; t++ )
			yy[i][t] = lower_bound( ydisc+1, ydisc+1+ydtot, yy[i][t] ) - ydisc;
	}
	for( int i = 1; i <= n; i++ ) {
		for( int x = xx[i][0]; x < xx[i][1]; x++ ) {
			flag[x][yy[i][0]]++;
			flag[x][yy[i][1]]--;
		}
	}
	long long ans = 0;
	for( int x = 1; x < xdtot; x++ ) {
		int sum = 0;
		for( int y = 1; y < ydtot; y++ ) {
			sum += flag[x][y];
			if( sum > 0 ) {
				ans += 1LL * (ydisc[y+1]-ydisc[y]) * (xdisc[x+1] - xdisc[x]);
				if(1LL * (ydisc[y+1]-ydisc[y]) * (xdisc[x+1] - xdisc[x]) < 0) {
					long long a =  1LL * (ydisc[y+1]-ydisc[y]) * (xdisc[x+1] - xdisc[x]);
					printf("NO\n");
				}
			}
		}
	}
	printf( "%lld\n", ans );
}

