#include <iostream>
#include <cassert>
using namespace std;

typedef long long dnt;

long long Abs( long long a ) {
	return a < 0 ? -a : a;
}

void exgcd( dnt a, dnt b, dnt &d, dnt &x, dnt &y ) {
	if( b == 0 ) {
		x = 1, y = 0, d = a;
	} else {
		dnt x0, y0;
		exgcd( b, a % b, d, x0, y0 );
		x = y0;
		y = x0 - (a/b) * y0;
	}
}

int main() {
	int T;
	cin >> T;
	while( T-- ) {
		dnt a, b, c, d, x0, y0, x1, y1, dx, dy;
		cin >> a >> b >> c;
		exgcd( a, b, d, x0, y0 );
		if( c % d ) {
			cout << "No" << endl;
		} else {
			x1 = x0 * c / d;
			y1 = y0 * c / d;
			dx = b / d;
			dy = - a / d;
			assert( a * x1 + b * y1 == c );
			x1 = (x1 % Abs(dx) + Abs(dx)) % Abs(dx);
			y1 = (c - a * x1) / b;
			assert( a * x1 + b * y1 == c );
			cout << x1 << " " << y1 << " ";
			y1 = (y1 % Abs(dy) + Abs(dy)) % Abs(dy);
			x1 = (c - b * y1) / a;
			assert( a * x1 + b * y1 == c );
			cout << x1 << " " << y1 << endl;
		}
	}
}

