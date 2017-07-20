#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1000000 + 10;

int n;
int aa[N + N];


int main() {
	scanf( "%d", &n );
	for( int i = 1; i <= n; i++ ) {
		scanf( "%d", aa + i );
		aa[n + i] = aa[i];
	}
	long long ans = 0;
	for( int i = 1; i <= n; i++ ) {
		for( int l = 0; l < n; l++ )
			for( int r = l + 1; r < n; r++ )
				ans += (aa[i+l] > aa[i+r]);
	}
	cout << ans << endl;
}

