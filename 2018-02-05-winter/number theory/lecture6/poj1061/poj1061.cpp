#include <iostream>
using namespace std;

long long abs( long long a ) {
	return a < 0 ? -a : a;
}

long long gcd( long long a, long long b ) {
	return b == 0 ? abs(a) : gcd( b, a%b );
}


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

bool linear_equation( long long a, long long b, long long c, long long &x, long long &y, long long &xinc, long long &yinc ) {
	long long d = gcd(a,b);
	if( c % d != 0 ) return false;
	a /= d, b /= d, c /= d;
	exgcd( a, b, x, y );
	x *= c;
	y *= c;
	xinc = b;
	yinc = -a;
	return true;
}

//	m > 0
bool mod_equation( long long a, long long b, long long m, long long &x ) {
	long long y, xinc, yinc;
	
	if( linear_equation( a, m, b, x, y, xinc, yinc ) ) {
		xinc = abs(xinc);
		x = (x % xinc + xinc) % xinc;
		return true;
	} else {
		return false;
	}
}

int main() {
	long long m, n, x, y, L;
	while(cin >> x >> y >> m >> n >> L) {
		long long a = m - n;
		long long b = y - x;
		long long mod = L;
		a = (a % mod + mod) % mod;
		b = (b % mod + mod) % mod;
		if( mod_equation( a, b, mod, x ) ) {
			cout << x << endl;
		} else {
			cout << "Impossible" << endl;
		}
	}
}

