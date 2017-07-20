#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 200010;
struct Node{
	long long flag;
	long long sum;
	Node *ls, *rs;
	void pushdown( int lf, int rg ){
		if ( flag ) {
			int mid = (lf + rg) >>1;
			ls->flag += flag;
			ls->sum += (mid-lf+1) * flag;
			rs->flag += flag;
			rs->sum += (rg-mid) * flag;
			flag = 0;
		}
	}
	void update(){
		sum = ls->sum + rs->sum ; 
	}
}pool[2*N+5], *root, *tail=pool;
int n,m,a[200005];
Node *build( int lf, int rg ) {
	Node *nd = ++tail;
	if (lf == rg) {
		nd->sum = a[lf];
		nd->flag = 0;
	}else{
		int mid = (lf + rg) >> 1;
		nd->ls = build( lf, mid);
		nd->rs = build( mid+1, rg );
		nd->sum = nd->ls->sum + nd->rs->sum;
		nd->flag = 0;
	}
	return nd;
}
void modily( Node *nd, int lf, int rg,int L, int R, int delta) {
	if( L <= lf && rg <= R ) {
		nd->sum += (long long)( rg-lf+1 ) * delta;
		nd->flag = delta;
		return ;
	}
	int mid = (lf + rg) >> 1;
	nd->pushdown(lf,rg);
	if( L <= mid ) 
		modily( nd->ls ,lf ,mid ,L ,R ,delta );
	if( R > mid )
		modily( nd->rs ,mid+1 ,rg ,L ,R ,delta );
	nd->update();
}
long long query ( Node *nd, int lf, int rg , int L, int R ) {
	if( L<=lf && R>=rg ) {
		return nd->sum;
	}
	int mid = (lf + rg ) >> 1;
	nd->pushdown( lf, rg );
	long long rt = 0;                                                                                                                            
	if( L <= mid) 
		rt += query( nd->ls, lf, mid, L, R);
	if( R > mid)
		rt += query( nd->rs, mid+1, rg, L, R);
	return rt;
}
int main() {
	//freopen("segsum.in","r",stdin);
	//freopen("segsum.out","w",stdout);
	scanf("%d",&n);
	for( int i =1 ;i <= n ; i++)
		scanf("%d", &a[i]);
	root = build( 1, n );
	scanf("%d", &m);
	while( m-- ) {
		char b[105];
		scanf("%s", b);
		if(b[0] == 'm') {
			int j ,k ,l ;
			scanf("%d%d%d", &j, &k, &l);
			modily(root ,1 ,n ,j ,k ,l );
		}
		else {
			int j, k;
			scanf("%d%d", &j, &k);
			printf("%lld\n",query(root ,1 ,n ,j ,k ));
//			printf("%I64d\n",query(root ,1 ,n ,j ,k ));
		}
	}
	return 0;
}

