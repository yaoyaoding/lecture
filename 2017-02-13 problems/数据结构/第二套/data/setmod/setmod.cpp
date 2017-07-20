#include <cstdio>

#ifdef WIN32
#define Auto "%I64d"
#else
#define Auto "%lld"
#endif

typedef long long dnt;

const int N = 100000 + 10;

struct Node;
void modify( Node *nd, int lf, int rg, int L, int R, dnt value );
void change( Node *nd, int lf, int rg, int L, int R, dnt delta );

struct Node {
	dnt sum;
	int type;			//	标记类型：0 无， 1 change， 2 modify
	dnt delta, value;
	Node *ls, *rs;
	void update() {
		sum = ls->sum + rs->sum;
	}
	void pushdown( int lf, int rg ) {
		if( type == 0 ) return;

		int mid = (lf + rg) >> 1;
		if( type == 1 ) {
			change( ls, lf, mid, lf, mid, delta );
			change( rs, mid+1, rg, mid+1, rg, delta );
			type = 0;
		} else {
			modify( ls, lf, mid, lf, mid, value );
			modify( rs, mid+1, rg, mid+1, rg, value );
			type = 0;
		}
	}
}pool[N*2], *tail = pool, *root;

int n, m;
int aa[N];

Node *build( int lf, int rg ) {
	Node *nd = ++tail;
	if( lf == rg ) {
		nd->sum = aa[lf];
		nd->type = 0;
	} else {
		int mid = (lf + rg) >> 1;
		nd->ls = build( lf, mid );
		nd->rs = build( mid+1, rg );
		nd->type = 0;
		nd->update();
	}
	return nd;
}
void modify( Node *nd, int lf, int rg, int L, int R, dnt value ) {
	if( L <= lf && rg <= R ) {
		nd->sum = (dnt)(rg - lf + 1) * value;
		nd->type = 2;
		nd->value = value;
		return;
	}
	int mid = (lf + rg) >> 1;
	nd->pushdown(lf,rg);
	if( L <= mid ) modify( nd->ls, lf, mid, L, R, value );
	if( R > mid ) modify( nd->rs, mid+1, rg, L, R, value );
	nd->update();
}
void change( Node *nd, int lf, int rg, int L, int R, dnt delta ) {
	if( L <= lf && rg <= R ) {
		nd->sum += (dnt)(rg - lf + 1) * delta;
		if( nd->type == 0 ) {
			nd->type = 1;
			nd->delta = delta;
		} else if( nd->type == 1 ) {
			nd->delta += delta;
		} else if( nd->type == 2 ) {
			nd->value += delta;
		}
		return;
	}
	int mid = (lf + rg) >> 1;
	nd->pushdown(lf,rg);
	if( L <= mid ) change( nd->ls, lf, mid, L, R, delta );
	if( R > mid ) change( nd->rs, mid+1, rg, L, R, delta );
	nd->update();
}
dnt query( Node *nd, int lf, int rg, int L, int R ) {
	if( L <= lf && rg <= R ) 
		return nd->sum;
	int mid = (lf + rg) >> 1;
	nd->pushdown(lf,rg);
	dnt rt = 0;
	if( L <= mid ) rt += query( nd->ls, lf, mid, L, R );
	if( R > mid ) rt += query( nd->rs, mid+1, rg, L, R );
	return rt;
}

int main() {
	scanf( "%d%d", &n, &m );
	for( int i = 1; i <= n; i++ ) 
		scanf( "%d", aa + i );
	root = build( 1, n );
	while( m-- ) {
		char ss[10];
		int l, r, delta, value;
		scanf( "%s", ss );
		if( ss[0] == 'c' ) {
			scanf( "%d%d%d", &l, &r, &delta );
			change( root, 1, n, l, r, delta );
		} else if( ss[0] == 'm' ) {
			scanf( "%d%d%d", &l, &r, &value );
			modify( root, 1, n, l, r, value );
		} else {
			scanf( "%d%d", &l, &r );
			printf( Auto"\n", query( root, 1, n, l, r ) );
		}
	}
}


