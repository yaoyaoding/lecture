#include <cstdio>

const int N = 100010;

typedef long long dnt;


int Mod;
dnt fac[N], vfac[N];

dnt mpow( dnt a, int b ) {
	dnt rt;
	for( rt = 1; b; b >>= 1, a = (a * a) % Mod )
		if( b & 1 ) rt = (rt * a) % Mod;
	return rt;
}
dnt inverse( dnt a ) {
	return mpow( a, Mod - 2 );
}
void init() {
	fac[0] = 1;
	for( int i = 1; i < Mod; i++ )
		fac[i] = (fac[i-1] * i) % Mod;
	vfac[Mod-1] = inverse( fac[Mod-1] );
	for( int i = Mod - 2; i >= 0; i-- )
		vfac[i] = (vfac[i+1] * (i+1)) % Mod;
}
dnt comb( dnt n, dnt m ) {
	if( m > n ) return 0;
	return fac[n] * vfac[m] % Mod * vfac[n-m] % Mod;
}
dnt lucas( dnt n, dnt m ) {
	if( m > n ) return 0;
	if( n < Mod ) return comb( n, m );
	return lucas( n / Mod, m / Mod ) * comb( n % Mod, m % Mod ) % Mod;
}

int main() {
	int T;
	scanf( "%d", &T );
	while( T-- ) {
		int n, m;
		scanf( "%d%d%d", &n, &m, &Mod );
		init();
		printf( "%d\n", (int)lucas(n+m,m) );
	}
}

