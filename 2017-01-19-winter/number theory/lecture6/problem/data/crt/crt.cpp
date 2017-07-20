#include <iostream>
#include <cassert>
using namespace std;

typedef long long dnt;

dnt Abs( dnt a ) {
	return a < 0 ? -a : a;
}
void exgcd( dnt a, dnt b, dnt &d, dnt &x, dnt &y ) {
	if( b == 0 ) {
		x = 1, y = 0, d = a;
	} else {
		dnt x0, y0;
		exgcd( b, a % b, d, x0, y0 );
		x = y0;
		y = x0 - (a / b) * y0;
	}
}

bool merge( dnt a1, dnt m1, dnt a2, dnt m2, dnt &a0, dnt &m0 ) {
	dnt d, t1, t2;
	exgcd( m1, -m2, d, t1, t2 );
	if( (a2 - a1) % d ) return false;
	m0 = m1 / Abs(d) * m2;
	a0 = (a1 % m0 + (m1 / d) % m0 * (t1 % m0) % m0 * ((a2 - a1) % m0) % m0) % m0;
	if( a0 < 0 ) a0 += m0;
	assert( a0 % m1 == a1 );
	assert( a0 % m2 == a2 );
	return true;
}

int main() {
	int T;
	cin >> T;
	while( T-- ) {
		int n;
		cin >> n;
		bool avi = true;
		dnt a = 0, m = 1;
		while( n-- ) {
			dnt aa, mm;
			cin >> aa >> mm;
			if( avi ) {
				if( merge(a,m,aa,mm,a,m) == false )
					avi = false;
			}
		}
		if( avi ) 
			cout << a << endl;
		else
			cout << "No" << endl;
	}
}


