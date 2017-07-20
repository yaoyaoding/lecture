#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

long long exgcd( long long a, long long b, long long &x, long long &y ) {
	if( b == 0 ) {
		if( a < 0 ) {
			x = -1;
			y = 0;
			return -a;
		} else {
			x = 1;
			y = 0;
			return a;
		}
	} else {
		long long x0, y0;
		long long cd = exgcd( b, a % b, x0, y0 );
		x = y0;
		y = x0 - (a/b) * y0;
		return cd;
	}
}

long long inverse( long long a, long long mod ) {
	long long x, y;
	exgcd( a, mod, x, y );
	return (x % mod + mod) % mod;
}

long long crt( const vector<long long> &va, const vector<long long> &vm ) {
	int n = (int)va.size();
	long long summ = 1;
	for( int t = 0; t < n; t++ )
		summ *= vm[t];
	long long ans = 0;
	for( int t = 0; t < n; t++ ) {
		long long mi = summ / vm[t];
		long long invmi = inverse(mi,vm[t]);
		ans += mi * invmi %summ * va[t] % summ;
		if( ans >= summ ) ans -= summ;
	}
	return ans;
}

int main() {
	long long a, b, c, p;
	int tp = 0;
	while( (cin >> a >> b >> c >> p) && a != -1 ) {
		vector<long long> va, vm;
		vm.push_back( 23 );
		va.push_back( (a - p + 23000) % 23 );
		vm.push_back( 28 );
		va.push_back( (b - p + 28000) % 28 );
		vm.push_back( 33 );
		va.push_back( (c - p + 33000) % 33 );
		long long ans = crt( va, vm );
		if( ans == 0 ) ans += 23 * 28 * 33;
		printf( "Case %d: the next triple peak occurs in %d days.\n",
				++tp, (int)ans );
	}
}

