#include <cstdio>
#include <algorithm>

#ifdef WIN32 
#define Auto "%I64d"
#else
#define Auto "%lld"
#endif

const int N = 100000 + 10;
const int Ins = 1;
const int Del = 2;

typedef long long dnt;

struct Event {
	int type;	//	1 ins 2 del
	int time;	//	x
	int lf, rg;	//	y1 y2
	Event(){}
	Event( int type, int time, int lf, int rg )
		:type(type),time(time),lf(lf),rg(rg){}
};
bool operator<( const Event &r, const Event &s ) {
	return r.time < s.time;
}
struct Node {
	int cnt,	//	将这个节点完全覆盖的次数
		sum;	//	只考虑覆盖这个节点的子节点的那些操作导致的非零的位置的个数
	Node *ls, *rs;
	int query( int lf, int rg ) {
		return cnt ? rg - lf + 1 : sum;
	}
	void update( int lf, int rg ) {
		int mid = (lf + rg) >> 1;
		sum = ls->query(lf,mid) + rs->query(mid+1,rg);
	}
}pool[N*2], *tail = pool, *root;

int n;
int total;
Event events[N*2]; 

Node *build( int lf, int rg ) {
	Node *nd = ++tail;
	if( lf == rg ) {
		nd->cnt = nd->sum = 0;
	} else {
		int mid = (lf + rg) >> 1;
		nd->ls = build( lf, mid );
		nd->rs = build( mid+1, rg );
		nd->cnt = nd->sum = 0;
	}
	return nd;
}
void modify( Node *nd, int lf, int rg, int L, int R, int delta ) {
	if( L <= lf && rg <= R ) {
		nd->cnt += delta;
		return;
	}
	int mid = (lf + rg) >> 1;
	if( L <= mid ) modify( nd->ls, lf, mid, L, R, delta );
	if( R > mid ) modify( nd->rs, mid+1, rg, L, R, delta );
	nd->update(lf,rg);
}

int main() {
	scanf( "%d", &n );
	for( int i = 1; i <= n; i++ ) {
		int x1, y1, x2, y2;
		scanf( "%d%d%d%d", &x1, &y1, &x2, &y2 );
		events[total++] = Event( Ins, x1, y1, y2 );
		events[total++] = Event( Del, x2+1, y1, y2 );
	}
	std::sort( events, events + total );
	root = build( 1, n );
	dnt area = 0;
	for( int i = 0,j; i < total; i = j + 1 ) {
		for( j = i; j + 1 < total && events[j+1].time == events[i].time; j++ );
		for( int k = i; k <= j; k++ ) {
			modify( root, 1, n, events[k].lf, events[k].rg, events[k].type == Ins ? +1 : -1 );
		}
		if( j != total-1 ) {
			area += (dnt)root->query(1,n) * (events[j+1].time - events[i].time);
		}
	}
	printf( Auto"\n", area );
}


