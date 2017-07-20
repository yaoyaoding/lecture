#include <cstdio>

const int N = 100000 + 10;
const int M = N + N;
const int Mod = 31;

struct Info {
	int v, len;
	Info(){}
	Info( int v, int len ):v(v),len(len){}
};
struct Node {
	Info ab, ba;
	Node *ls, *rs;
}pool[N*4], *tail = pool, *root;

int n, m;
int head[N], wght[M], dest[M], last[M], etot;
int dep[N], siz[N], son[N], top[N], fat[N], val[N], in[N], rin[N], idc;
int tpow[N];

void init() {
	tpow[0] = 1;
	for( int i = 1; i < N; i++ )
		tpow[i] = tpow[i-1] * 10 % Mod;
}
Info merge( const Info &a, const Info &b ) {
	return Info( (a.v * tpow[b.len] + b.v) % Mod, a.len + b.len );
}
Node *build( int lf, int rg ) {
	Node *nd = ++tail;
	if( lf == rg ) {
		nd->ab = nd->ba = Info( val[rin[lf]], 1 );
	} else {
		int mid = (lf + rg) >> 1;
		nd->ls = build( lf, mid );
		nd->rs = build( mid + 1, rg );
		nd->ab = merge( nd->ls->ab, nd->rs->ab );
		nd->ba = merge( nd->rs->ba, nd->ls->ba );
	}
	return nd;
}
Info query_ab( Node *nd, int lf, int rg, int L, int R ) {
	if( L <= lf && rg <= R ) return nd->ab;
	int mid = (lf + rg) >> 1;
	if( R <= mid ) return query_ab( nd->ls, lf, mid, L, R );
	else if( L > mid ) return query_ab( nd->rs, mid+1, rg, L, R );
	else return merge( 
			query_ab( nd->ls, lf, mid, L, R ), 
			query_ab( nd->rs, mid+1, rg, L, R ) );
}
Info query_ba( Node *nd, int lf, int rg, int L, int R ) {
	if( L <= lf && rg <= R ) return nd->ba;
	int mid = (lf + rg) >> 1;
	if( R <= mid ) return query_ba( nd->ls, lf, mid, L, R );
	else if( L > mid ) return query_ba( nd->rs, mid+1, rg, L, R );
	else return merge(
			query_ba( nd->rs, mid+1, rg, L, R ),
			query_ba( nd->ls, lf, mid, L, R ) );
}
void adde( int u, int v, int d ) {
	etot++;
	dest[etot] = v;
	last[etot] = head[u];
	wght[etot] = d;
	head[u] = etot;
}
void dfs1( int u ) {
	siz[u] = 1;
	for( int t = head[u]; t; t = last[t] ) {
		int v = dest[t];
		if( v == fat[u] ) continue;
		fat[v] = u;
		dep[v] = dep[u] + 1;
		val[v] = wght[t];
		dfs1( v );
		siz[u] += siz[v];
		if( siz[v] > siz[son[u]] ) son[u] = v;
	}
}
void dfs2( int u ) {
	in[u] = ++idc;
	rin[idc] = u;
	if( son[u] ) {
		top[son[u]] = top[u];
		dfs2( son[u] );
	}
	for( int t = head[u]; t; t = last[t] ) {
		int v = dest[t];
		if( v == fat[u] || v == son[u] ) continue;
		top[v] = v;
		dfs2( v );
	}
}
int query( int u, int v ) {
	Info uca(0,0), cav(0,0);		//	u to lca, lca to v
	while( top[u] != top[v] ) {
		if( dep[top[u]] > dep[top[v]] ) {
			uca = merge( uca, query_ba( root, 1, idc, in[top[u]], in[u] ) );
			u = fat[top[u]];
		} else {
			cav = merge( query_ab( root, 1, idc, in[top[v]], in[v] ), cav );
			v = fat[top[v]];
		}
	}
	if( dep[u] > dep[v] ) {
		uca = merge( uca, query_ba( root, 1, idc, in[v]+1, in[u] ) );
	} else if( dep[v] > dep[u] ) {
		cav = merge( query_ab( root, 1, idc, in[u]+1, in[v] ), cav );
	}
	Info ans = merge( uca, cav );
	return ans.v;
}
int main() {
	scanf( "%d%d", &n, &m );
	for( int i = 1; i < n; i++ ) {
		int u, v, d;
		scanf( "%d%d%d", &u, &v, &d );
		adde( u, v, d );
		adde( v, u, d );
	}
	init();
	fat[1] = 1;
	dep[1] = 0;
	dfs1( 1 );
	top[1] = 1;
	dfs2( 1 );
	root = build( 1, idc );
	while( m-- ) {
		int u, v;
		scanf( "%d%d", &u, &v );
		printf( "%d\n", query(u,v) );
	}
}

