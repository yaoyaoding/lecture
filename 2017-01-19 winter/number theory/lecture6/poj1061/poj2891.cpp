#include <iostream>
#include <vector>
using namespace std;

typedef long long dnt;

dnt gcd( dnt a, dnt b ) {	
	return b == 0 ? a : gcd( b, a % b );
}
dnt exgcd( dnt a, dnt b, dnt &x, dnt &y ) {
	if( b == 0 ) {
		x = 1;
		y = 0;
		return a;
	} else {
		dnt x0, y0;
		dnt cd = exgcd( b, a % b, x0, y0 );
		x = y0;
		y = x0 - (a/b) * y0;
		return cd;
	}
}

bool equation( dnt a, dnt b, dnt c, dnt &x, dnt &y ) {
	dnt x0, y0;
	dnt d = gcd( a, b );
	if( c % d ) return false;
	a /= d, b /= d, c /= d;
	d = exgcd( a, b, x0, y0 );
	x = x0 * (c / d);
	y = y0 * (c / d);
	dnt xinc;
	xinc = b / d;
	if( xinc < 0 ) xinc *= -1;
	x = (x % xinc + xinc) % xinc;
	y = (c - a * x) / b;
	return true;
}
bool merge( dnt a1, dnt m1, dnt a2, dnt m2, dnt &a3, dnt &m3 ) {
	dnt t1, t2;
	a1 %= m1;
	a2 %= m2;
	if( !equation(-m1,m2,a1-a2,t1,t2) ) return false;
	m3 = m1 / gcd( m1, m2 ) * m2;
	t1 = (t1 % m3 + m3) % m3;
	a3 = ((a1 + m1 * t1) % m3 + m3) % m3;
	return true;
}

int n;

int main() {
	while( cin >> n ) {
		pair<dnt,dnt> cur(0,1), nxt;
		bool ok = true;
		for( int i = 0; i < n; i++ ) {
			dnt a, m;
			cin >> m >> a;
			if( !merge( cur.first, cur.second, a, m, nxt.first, nxt.second ) ) {
				ok = false;
				for( i++; i < n; i++ )
					cin >> m >> a;
				break;
			} else {
				cur = nxt;
			}
//			printf( "[x = %lld mod %lld]\n", cur.first, cur.second );
		}
		cout << (ok ? cur.first : -1) << endl;
	}
}

