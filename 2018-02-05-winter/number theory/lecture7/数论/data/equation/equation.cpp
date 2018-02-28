#include <cstdio>
#include <iostream>
using namespace std;

typedef long long dnt;

bool isprime( int a ) {
	for( int i = 2; i * i <= a; i++ )
		if( a % i == 0 ) return false;
	return true;
}
void exgcd( dnt a, dnt b, dnt &d, dnt &x, dnt &y ) {
	if( b == 0 ) {
		x = 1, y = 0, d = a;
	} else {
		dnt x1, y1;
		exgcd( b, a % b, d, x1, y1 );
		x = y1;
		y = x1 - (a/b) * y1;
	}
}
dnt inverse( dnt a, dnt mod ) {
	dnt d, x, y;
	exgcd( a, mod, d, x, y );
	if( d < 0 ) d = -d, x = -x, y = -y;
	return (x % mod + mod) % mod;
}
//	assert( n < p )
dnt comb( int n, int m, int p ) {
	dnt rt = 1;
	for( int i = 1; i <= m; i++ ) {
		rt = rt * (n + 1 - i) % p;
		rt = rt * inverse( i, p ) % p;
	}
	return rt;
}
//	assert( m1, m2 are primes )
//	a1 + t1 * m1 = a2 + t2 * m2 = x
//	m1 * t1 - m2 * t2 = a2 - a1
void merge( dnt a1, dnt m1, dnt a2, dnt m2, dnt &a, dnt &m ) {
	dnt t1, t2, d;
	exgcd( m1, -m2, d, t1, t2 );
	t1 = (t1 % m2 + m2) % m2;
	t1 = t1 * (a2 - a1) / d;
	m = m1 * m2;
	a = a1 + (m1 * t1) % m;
	a = (a % m + m) % m;
}
int main() {
	int T;
	scanf( "%d", &T );
	while( T-- ) {
		int n, m, mod;
		scanf( "%d%d%d", &n, &m, &mod );
		if( isprime(mod) ) {
			cout << comb(n+m-1,m,mod) << endl;
		} else {
			int p, q;
			for( int i = 2; i * i <= mod; i++ ) {
				if( mod % i == 0 ) {
					p = i;
					q = mod / i;
					break;
				}
			}
			dnt a1 = comb( n + m - 1, m, p ), m1 = p;
			dnt a2 = comb( n + m - 1, m, q ), m2 = q;
			dnt a, m;
			merge( a1, m1, a2, m2, a, m );
			cout << a << endl;
		}
	}
}

