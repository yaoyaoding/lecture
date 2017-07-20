#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1010;

bool isnot[N];
int phi[N], prm[N], ptot;
long long sum[N];

void init( int n ) {
	isnot[1] = true;
	phi[1] = 1;
	for( int i = 2; i <= n; i++ ) {
		if( !isnot[i] ) {
			prm[ptot++] = i;
			phi[i] = i - 1;
		}
		for( int t = 0; t < ptot; t++ ) {
			int j = prm[t] * i;
			if( j > n ) break;
			isnot[j] = true;
			if( i % prm[t] ) {
				phi[j] = phi[prm[t]] * phi[i];
			} else {
				phi[j] = prm[t] * phi[i];
				break;
			}
		}
	}
	for( int i = 2; i <= n; i++ )
		sum[i] = sum[i-1] + phi[i];
}

int main() {
	init(1000);
	int n;
	int T;
	scanf( "%d", &T );
	int tp = 0;
	while( T-- ) {
		scanf( "%d", &n );
		printf( "%d %d %d\n", ++tp, n, int(sum[n] + sum[n] + 3) );
	}
}

