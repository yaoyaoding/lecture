#include <cstdio>

const int N = 100010;
const int M = N + N;

int n, q;
int aa[N];
int head[N], dest[M], last[M], etot;
int in[N], out[N], seq[N], idc;
long long bit[N];

void adde( int u, int v ) {
	etot++;
	dest[etot] = v;
	last[etot] = head[u];
	head[u] = etot;
}
void dfs( int u, int f ) {
	idc++;
	in[u] = idc;
	seq[idc] = u;
	for( int t = head[u]; t; t = last[t] ) {
		int v = dest[t];
		if( v == f ) continue;
		dfs( v, u );
	}
	out[u] = idc;
}
void modify( int pos, int delta ) {
	for( int i = pos; i <= n; i += i & -i )
		bit[i] += delta;
}
long long query( int rg ) {
	long long rt = 0;
	for( int i = rg; i; i -= i & -i) {
		rt += bit[i];
	}
	return rt;
}
long long query( int lf, int rg ) {
	return query(rg) - query(lf-1);
}
int main() {
	scanf( "%d", &n );
	for( int i = 1; i <= n; i++ )
		scanf( "%d", aa + i );
	for( int i = 1; i < n; i++ ) {
		int u, v;
		scanf( "%d%d", &u, &v );
		adde( u, v );
		adde( v, u );
	}
	idc = 0;
	dfs(1,1);
	for( int u = 1; u <= n; u++ ) {
		modify( in[u], aa[u] );
	}
	scanf( "%d", &q );
	while( q-- ) {
		char ss[100];
		int u, d;
		scanf( "%s", ss );
		if( ss[0] == 'm' ) {
			scanf( "%d%d", &u, &d );
			modify( in[u], d );
		} else {
			scanf( "%d", &u );
			printf( "%lld\n", query( in[u], out[u] ) );
		}
	}
}

