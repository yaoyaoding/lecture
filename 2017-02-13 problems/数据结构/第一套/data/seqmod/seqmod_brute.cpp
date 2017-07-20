#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100000 + 10;
const int M = N + N;
const int Mod = 31;

int n, m;
int head[N], wght[M], dest[M], last[M], etot;
int dep[N], val[N], fat[N];

void adde( int u, int v, int d ) {
	etot++;
	dest[etot] = v;
	last[etot] = head[u];
	wght[etot] = d;
	head[u] = etot;
}
void dfs( int u ) {
	for( int t = head[u]; t; t = last[t] ) {
		int v = dest[t];
		if( v == fat[u] ) continue;
		fat[v] = u;
		dep[v] = dep[u] + 1;
		val[v] = wght[t];
		dfs( v );
	}
}
int query( int u, int v ) {
	vector<int> va, vb;
	while( u != v ) {
		if( dep[u] > dep[v] ) {
			va.push_back( val[u] );
			u = fat[u];
		} else {
			vb.push_back( val[v] );
			v = fat[v];
		}
	}
	reverse( vb.begin(), vb.end() );
	int ans = 0;
	for( int i = 0; i < (int)va.size(); i++ ) 
		ans = (ans * 10 + va[i]) % Mod;
	for( int i = 0; i < (int)vb.size(); i++ ) 
		ans = (ans * 10 + vb[i]) % Mod;
	return ans;
}
int main() {
	scanf( "%d%d", &n, &m );
	for( int i = 1; i < n; i++ ) {
		int u, v, d;
		scanf( "%d%d%d", &u, &v, &d );
		adde( u, v, d );
		adde( v, u, d );
	}
	fat[1] = 0;
	dep[1] = 0;
	dfs(1);
	while( m-- ) {
		int u, v;
		scanf( "%d%d", &u, &v );
		printf( "%d\n", query(u,v) );
	}
}
