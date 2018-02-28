#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef long long dnt;

const dnt Mod = 1000000000000000000LL;

inline dnt add( dnt a, dnt b ) {
	dnt c = a + b;
	if( c >= Mod ) c -= Mod;
	return c;
}
dnt mul( dnt a, dnt b ) {
	dnt rt;
	for( rt = 0; b; b >>= 1, a=add(a,a) )
		if( b & 1 ) rt = add(rt,a);
	return rt;
}

struct Matrix {
	dnt v[4][4];
	void unit() {
		for( int i = 0; i < 4; i++ )
			for( int j = 0; j < 4; j++ )
				v[i][j] = (i == j);
	}
	void zero() {
		for( int i = 0; i < 4; i++ )
			for( int j = 0; j < 4; j++ )
				v[i][j] = 0;
	}
	dnt * operator[]( int i ) { return v[i]; }
	const dnt *operator[]( int i ) const { return v[i]; }
};

Matrix operator*( Matrix a, Matrix b ) {
	Matrix c;
	for( int i = 0; i < 4; i++ )
		for( int j = 0; j < 4; j++ ) {
			c[i][j] = 0;
			for( int k = 0; k < 4; k++ ) 
				c[i][j] = add( c[i][j], mul(a[i][k],b[k][j]) );
		}
	return c;
}

Matrix mpow( Matrix a, dnt b ) {
	Matrix rt;
	for( rt.unit(); b; b>>=1,a=a*a )
		if( b & 1 ) rt = rt * a;
	return rt;
}

dnt b, c, d, e, n, col[4];

int main() {
	Matrix base, dest;
	for( int i = 0; i < 3; i++ )
		cin >> col[2-i];
	col[3] = 1;
	cin >> b >> c >> d >> e >> n;
	base.zero();
	base[0][0] = b;
	base[0][1] = c;
	base[0][2] = d;
	base[0][3] = e;
	base[1][0] = 1;
	base[2][1] = 1;
	base[3][3] = 1;
	dest = mpow( base, n );
	dnt ans = 0;
	for( int k = 0; k < 4; k++ )
		ans = add( ans, mul( dest[2][k], col[k] ) );
	stringstream ss;
	string sans;
	ss << ans;
	ss >> sans;
	for( int i = 0; i < 18 - (int)sans.size(); i++ )
		cout << "0";
	cout << sans << endl;
}





