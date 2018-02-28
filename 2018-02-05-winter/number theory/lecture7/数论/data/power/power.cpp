#include <cstdio>
#include <cstring>

const int N = 100010;
const int Mod = 1000000008;

typedef long long dnt;

int n;
char ss[N];

dnt mpow( dnt a, int b ) {
	dnt rt;
	for( rt = 1; b; b >>= 1, a = a * a % Mod )
		if( b & 1 ) rt = rt * a % Mod;
	return rt;
}
int main() {
	scanf( "%s", ss );
	n = (int)strlen(ss);
	dnt ans = 1;
	dnt base = 3;

	for( int i = n - 1; i >= 0; i-- ) {
		int digit = ss[i] - '0';
		ans = ans * mpow( base, digit ) % Mod;
		base = mpow( base, 10 );
	}
	printf( "%d\n", (int)ans );
	return 0;
}

