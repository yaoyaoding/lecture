#include <cstdio>

int a[100001];

int main() {
	a[1] = 1;
	for( int i = 2; i <= 100000; i++ ) {
		a[i] = a[i/2] + a[i - i/2] + 1;
		if( a[i] != 2 * i - 1 )
			printf( "a[%d] = %d\n", i, a[i] );
	}
}
