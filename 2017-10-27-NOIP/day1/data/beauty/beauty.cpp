#include <cstdio>
#include <cassert>
#include <iostream>
using namespace std;

#define next Hello_world

const int N = 200010;
const int M = N*2;

int n, m;
int head[N], dest[M], next[M], etot;
int size[N], mark[N], cnt[N], dp[N];
long long ans;

void adde( int u, int v ) {
	etot++;
	dest[etot] = v;
	next[etot] = head[u];
	head[u] = etot;
}
void dfs1( int u, int fa ) {
	size[u] = 1;
	cnt[u] = mark[u];
	for( int t=head[u]; t; t=next[t] ) {
		int v=dest[t];
		if( v==fa ) continue;
		dfs1(v,u);
		size[u] += size[v];
		cnt[u] += cnt[v];
	}
}
void dfs2( int u, int fa ) {
	for( int t=head[u]; t; t=next[t] ) {
		int v=dest[t];
		if( v==fa ) continue;
		dfs2(v,u);
	}
	ans += dp[u];
	dp[u] += mark[u];
	dp[fa] += std::min( dp[u], cnt[1]-cnt[u] );
}
int main() {
	int a;
	scanf( "%d%d%d", &n, &m, &a );
	m*=2;
	assert(m <= n);
	for( int i=1,u; i<=m; i++ ) {
		scanf( "%d", &u );
		assert(mark[u] == false);
		mark[u] = true;
	}
	for( int i=1,u,v; i<n; i++ ) {
		scanf( "%d%d", &u, &v );
		assert(1 <= u && u <= n);
		assert(1 <= v && v <= n);
		adde(u,v);
		adde(v,u);
	}
	dfs1(1,0);
	dfs2(1,0);
	std::cout<<ans<<std::endl;
}
