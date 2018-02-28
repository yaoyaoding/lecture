#include <cstdio>

const int Mod = 107;
const int Phi = Mod - 1;

int comb[111][111];

void init( int n ) {
	for( int i = 0; i <= n; i++ )
		for( int j = 0; j <= i; j++ )
			if( j == 0 || j == i )
				comb[i][j] = 1;
			else
				comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % Phi;
}

int mpow( int a, int b ) {
	int rt;
	for( rt = 1; b; b >>= 1, a = (a * a) % Mod )
		if( b & 1 ) rt = rt * a % Mod;
	return rt;
}

int main() {
	int n;
	init(100);
	scanf( "%d", &n );
	int pw = (comb[n+n][n] - comb[n+n][n-1] + Phi) % Phi;
	printf( "%d\n", mpow( 2, pw ) );
}


