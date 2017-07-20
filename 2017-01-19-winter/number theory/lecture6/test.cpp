#include <cstdio>

int main() {
	long long a = 100;
	long long b = 33;
	for( int sa = -1; sa <= 1; sa++ )
		for( int sb = -1; sb <= 1; sb++ ) {
			if( sa == 0 || sb == 0 ) continue;
			a *= sa;
			b *= sb;
			printf( "a = %lld b = %lld a/b = %lld a%%b = %lld [%s]\n", 
					a, b, a/b, a%b, a == b * (a/b) + a%b ? "YES" : "NO" );
			a *= sa;
			b *= sb;
		}
}

