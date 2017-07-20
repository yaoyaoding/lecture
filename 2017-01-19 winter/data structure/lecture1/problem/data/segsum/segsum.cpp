#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100010;

struct Info {
	int vmin, vmax; 
	long long vsum;
	Info(){}
	Info( int vmin, int vmax, long long vsum ):vmin(vmin),vmax(vmax),vsum(vsum){}
};
Info merge( const Info &r, const Info &s ) {
	return Info( min(r.vmin,s.vmin), max(r.vmax,s.vmax), r.vsum + s.vsum );
}
struct Node {
	Info info;
	int delta;
	Node *ls, *rs;
	void pushdown( int lf, int rg ) {
		if( delta ) {
			int mid = (lf + rg) >> 1;
			ls->delta += delta;
			ls->info.vmin += delta;
			ls->info.vmax += delta;
			ls->info.vsum += 1LL * (mid - lf + 1) * delta;
			rs->delta += delta;
			rs->info.vmin += delta;
			rs->info.vmax += delta;
			rs->info.vsum += 1LL * (rg - mid) * delta;
			delta = 0;
		}
	}
	void update() {
		info = merge( ls->info, rs->info );
	}
}pool[N * 3], *tail=pool, *root;

int n, q;
int aa[N];

Node *build( int lf, int rg ) {
	Node *nd = ++tail;
	if( lf == rg ) {
		nd->info = Info(aa[lf],aa[lf],aa[lf]);
		nd->delta = 0;
	} else {
		int mid = (lf + rg) >> 1;
		nd->delta = 0;
		nd->ls = build( lf, mid );
		nd->rs = build( mid+1, rg );
		nd->update();
	}
	return nd;
}
void modify( Node *nd, int lf, int rg, int L, int R, int d ) {
	if( L <= lf && rg <= R ) {
		nd->delta += d;
		nd->info.vmax += d;
		nd->info.vmin += d;
		nd->info.vsum += d * (rg - lf + 1);
		return;
	}
	int mid = (lf + rg) >> 1;
	nd->pushdown(lf,rg);
	if( L <= mid )
		modify( nd->ls, lf, mid, L, R, d );
	if( R > mid )
		modify( nd->rs, mid+1, rg, L, R, d );
	nd->update();
}
Info query( Node *nd, int lf, int rg, int L, int R ) {
	if( L <= lf && rg <= R ) 
		return nd->info;
	int mid = (lf + rg) >> 1;
	nd->pushdown(lf,rg);
	if( R <= mid ) {
		return query( nd->ls, lf, mid, L, R );
	} else if( L > mid ) {
		return query( nd->rs, mid+1, rg, L, R );
	} else {
		return merge(
			query( nd->ls, lf, mid, L, R ),
			query( nd->rs, mid+1, rg, L, R ) );
	}
}
int main() {
	scanf( "%d%d", &n, &q );
	for( int i = 1; i <= n; i++ )
		scanf( "%d", aa + i );
	root = build( 1, n );
	while( q-- ) {
		char ss[100];
		int l, r, d;
		scanf( "%s", ss );
		if( ss[0] == 'q' ) {
			scanf( "%d%d", &l, &r );
			Info info = query( root, 1, n, l, r );
			printf( "%d %d %lld\n", info.vmin, info.vmax, info.vsum );
		} else {
			scanf( "%d%d%d", &l, &r, &d );
			modify( root, 1, n, l, r, d );
		}
	}
}

