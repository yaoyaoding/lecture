#include <iostream>
using namespace std;

typedef unsigned long long udnt;

udnt a, b, c, k;

udnt gcd( udnt a, udnt b ) {
	return b == 0 ? a : gcd( b, a % b );
}
udnt mpow( udnt a, udnt b, udnt mod ) {
	udnt rt;
	for( rt = 1; b; b >>= 1, a = (a * a) % mod )
		if( b & 1 ) rt = (rt * a) % mod;
	return rt;
}
udnt inverse( udnt a, udnt mod ) {
	return mpow( a, mod-mod/2-1, mod );
}
void forever() {
	cout << "FOREVER" << endl;
}
void times( udnt v ) {
	cout << v << endl;
}
int main() {
	while( (cin >> a >> b >> c >> k) && k ) {
		udnt mod = 1LL << k;
		if( c == 0 ) {
			if( a == b ) {
				times( 0 );
			} else {
				forever();
			}
		} else {
			udnt d;
			if( b >= a )
				d = b - a;
			else
				d = mod - a + b;

			udnt cd = gcd( c, mod );
			if( d % cd != 0 ) {
				forever();
			} else {
				c /= cd;
				d /= cd;
				mod /= cd;
				d *= inverse( c, mod );
				d %= mod;
				times( d );
			}
		}
	}
}


