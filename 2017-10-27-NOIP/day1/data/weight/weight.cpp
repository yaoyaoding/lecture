#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;
const int oo = 0x3f3f3f3f;

struct Node;
void modify( Node *nd, int lf, int rg, int L, int R, int v );
struct Node {
	int vmax;
	int vmin, flag;
	void pushdown(int lf, int rg) {
		if( flag != oo ) {
			int mid = (lf + rg) >> 1;
			modify(ls,lf,mid,lf,mid,flag);
			modify(rs,mid+1,rg,mid+1,rg,flag);
			flag = oo;
		}
	}
	void update() {
		vmax = max(ls->vmax, rs->vmax);
	}
	Node *ls, *rs;
}pool[N*2], *tail=pool, *root;

struct Edge {
	int i, u, v, w;
	Edge(){}
	Edge( int i, int u, int v, int w ):i(i),u(u),v(v),w(w){}
};
bool operator<( const Edge &r, const Edge &s ) {
	return r.w < s.w;
}
bool cmp_id( const Edge &r, const Edge &s ) {
	return r.i < s.i;
}

int n, m;
vector<int> g[N], ge[N];
Edge edges[N];
int fa[N];
int siz[N], dep[N], son[N], top[N], par[N], eid[N], in[N], seq[N], idc;
bool intree[N];
int ans[N];

void dfs1( int u ) {	//	siz son fa in seq
	siz[u] = 1;
	for(int t = 0; t < (int)g[u].size(); t++) {
		int v = g[u][t];
		if(v == par[u]) continue;
		par[v] = u;
		dep[v] = dep[u] + 1;
		eid[v] = ge[u][t];
		dfs1(v);
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]]) son[u] = v;
	}
}
void dfs2( int u, int tp ) {	//	top
	++idc;
	in[u] = idc;
	seq[idc] = u;
	top[u] = tp;
	if(son[u])
		dfs2(son[u], tp);
	for(int t = 0; t < (int)g[u].size(); t++) {
		int v = g[u][t];
		if(v == par[u]) continue;
		if(v == son[u]) continue;
		dfs2(v, v);
	}
}
int find( int u ) {
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}
Node *build( int lf, int rg ) {
	Node *nd = ++tail;
	if( lf == rg ) {
		nd->vmax = edges[eid[seq[lf]]].w;
		nd->vmin = oo;
		nd->flag = oo;
	} else {
		int mid = (lf + rg) >> 1;
		nd->ls = build(lf, mid);
		nd->rs = build(mid+1, rg);
		nd->flag = oo;
		nd->vmin = oo;
		nd->update();
	}
	return nd;
}
void modify( Node *nd, int lf, int rg, int L, int R, int v ) {
	if( L <= lf && rg <= R ) {
		nd->flag = min( nd->flag, v );
		nd->vmin = min( nd->vmin, v );
		return;
	}
	int mid = (lf + rg) >> 1;
	nd->pushdown(lf,rg);
	if( L <= mid )
		modify( nd->ls, lf, mid, L, R, v );
	if( R > mid )
		modify( nd->rs, mid+1, rg, L, R, v );
	nd->update();
}
int query( Node *nd, int lf, int rg, int L, int R ) {
	if( L <= lf && rg <= R ) {
		return nd->vmax;
	}
	int mid = (lf + rg) >> 1;
	nd->pushdown(lf,rg);
	int rt = 0;
	if( L <= mid )
		rt = max( rt, query(nd->ls,lf,mid,L,R) );
	if( R > mid )
		rt = max( rt, query(nd->rs,mid+1,rg,L,R) );
	return rt;
}
void dfs( Node *nd, int lf, int rg ) {
	if( lf == rg ) {
		ans[eid[seq[lf]]] = nd->vmin;
		return;
	}
	int mid = (lf + rg) >> 1;
	nd->pushdown(lf,rg);
	dfs(nd->ls,lf,mid);
	dfs(nd->rs,mid+1,rg);
}
int query( int u, int v ) {
	int ans = 0;
	while( top[u] != top[v] ) {
		if( dep[top[u]] < dep[top[v]] ) swap(u,v);
		ans = max( ans, query(root,1,n,in[top[u]], in[u] ) );
		u = par[top[u]];
	}
	if( dep[u] < dep[v] ) swap(u,v);
	if( in[u] != in[v] )
		ans = max( ans, query(root,1,n,in[v]+1, in[u] ) );
	return ans;
}
void modify( int u, int v, int val ) {
	while( top[u] != top[v] ) {
		if( dep[top[u]] < dep[top[v]] ) swap(u,v);
		modify( root, 1, n, in[top[u]], in[u], val );
		u = par[top[u]];
	}
	if( dep[u] < dep[v] ) swap(u,v);
	if( in[u] != in[v] )
		modify( root, 1, n, in[v]+1, in[u], val );
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edges[i] = Edge(i,u,v,w);
	}
	sort(edges + 1, edges + 1 + m);
	for(int u = 1; u <= n; u++)
		fa[u] = u;
	for(int i = 1; i <= m; i++) {
		Edge &e = edges[i];
		int fu = find(e.u);
		int fv = find(e.v);
		if(fu == fv) continue;
		fa[fu] = fv;
		intree[e.i] = true;
		g[e.u].push_back(e.v);
		g[e.v].push_back(e.u);
		ge[e.u].push_back(e.i);
		ge[e.v].push_back(e.i);
	}
	sort( edges + 1, edges + 1 + m, cmp_id );
	idc = 0;
	par[1] = 1;
	dep[1] = 1;
	eid[1] = 0;
	dfs1(1);
	dfs2(1,1);
	root = build( 1, n );
	for( int i = 1; i <= m; i++ ) {
		if( intree[i] ) continue;
		const Edge &e = edges[i];
		ans[e.i] = query( e.u, e.v ) - 1;
		modify( e.u, e.v, e.w - 1 );
	}
	dfs( root, 1, n );
	for( int i = 1; i <= m; i++ )
		if( ans[i] == oo )
			printf( "-1 " );
		else
			printf( "%d ", ans[i] );
	printf( "\n" );
}
