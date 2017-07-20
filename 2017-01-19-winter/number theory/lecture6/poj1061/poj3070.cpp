#include <cstdio>

const int Mod = 10000;

struct Matrix {
	int v[2][2];
	void unit() {
		for( int i = 0; i < 2; i++ )
			for( int j = 0; j < 2; j++ )
				v[i][j] = (i == j);
	}
	void zero() {
		for( int i = 0; i < 2; i++ )
			for( int j = 0; j < 2; j++ )
				v[i][j] = 0;
	}
	int * operator[]( int i ) { return v[i]; }
	const int * operator[]( int i ) const { return v[i]; }
};
Matrix operator*( const Matrix &r, const Matrix &s ) {
	Matrix rt;
	rt.zero();
	for( int i = 0; i < 2; i++ )
		for( int j = 0; j < 2; j++ )
			for( int k = 0; k < 2; k++ ) {
				rt[i][j] += r[i][k] * s[k][j] % Mod;
				if( rt[i][j] >= Mod ) rt[i][j] -= Mod;
			}
	return rt;
}

Matrix base;

Matrix matpow( Matrix a, int b ) {
	Matrix rt;
	for( rt.unit(); b; b>>=1,a=a*a )
		if( b & 1 ) rt = rt * a;
	return rt;
}

int main() {
	int n;
	while( scanf("%d",&n) == 1 && n != -1 ) {
		for( int i = 0; i < 2; i++ )
			for( int j = 0; j < 2; j++ )
				base[i][j] = (i == 0 || j == 0);
		Matrix ans = matpow( base, n );
		printf( "%d\n", ans[0][1] );
	}
}

