#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1000000 + 10;

int n;
int aa[N + N];
int bit[N * 24];
long long ans, cur;

void modify( int pos, int delta ) {
	for( int i = pos; i <= n; i += i & -i )
		bit[i] += delta;
}
int query( int rg ) {
	int rt = 0;
	for( int i = rg; i; i -= i & -i )
		rt += bit[i];
	return rt;
}

int main() {
	scanf( "%d", &n );
	for( int i = 1; i <= n; i++ ) {
		scanf( "%d", aa + i );
		aa[n + i] = aa[i];
	}
	for( int i = 1; i <= n; i++ ) {
		cur += (i - 1) - query( aa[i] );
		modify( aa[i], +1 );
	}
	for( int i = n + 1; i <= n + n; i++ ) {
		modify( aa[i - n], -1 );
		cur += n - 1 - query( aa[i] );
		cur -= query( aa[i - n] - 1 );
		modify( aa[i], +1 );
		ans += cur;
	}
	cout << ans << endl;
}

