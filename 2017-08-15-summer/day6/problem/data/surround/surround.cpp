#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define line(a,b) ((b)-(a))
#define eps 1e-8
#define oo 0x3f3f3f3f
#define N 550
using namespace std;

int sg( double x ) { return (x>-eps)-(x<eps); }
struct Vector {
	double x, y;
	Vector(){}
	Vector( double x, double y ):x(x),y(y){}
	Vector operator-( const Vector &b ) const { return Vector(x-b.x,y-b.y); }
	double operator^( const Vector &b ) const { return x*b.y-y*b.x; }
	double operator&( const Vector &b ) const { return x*b.x+y*b.y; }
	double len() { return sqrt(x*x+y*y); }
	bool operator<( const Vector &b ) const {
		return sg(x-b.x)<0 || (sg(x-b.x)==0 && sg(y-b.y)<0);
	}
	bool operator==( const Vector &b ) const {
		return sg(x-b.x)==0 && sg(y-b.y)==0;
	}
};
typedef Vector Point;

int n, m;
Point aa[N], bb[N];
int dis[N][N];

bool onleft( const Point &a, const Point &b, const Point &c ) {
	return sg(line(a,b)^line(a,c))>=0;
}
bool onseg( const Point &a, const Point &b, const Point &c ) {
	return sg(line(a,b)^line(a,c))==0 && sg(line(c,a)&line(c,b))<0;
}
bool case1() {
	if( m==1 ) {
		for( int i=1; i<=n; i++ )
			if( aa[i]==bb[1] ) 
				return true;
	}
	return false;
}
bool case2() {
	bool ok = true;
	for( int i=1; i<=m && ok; i++ )
		for( int j=i+1; j<=m && ok; j++ )
			for( int k=j+1; k<=m && ok; k++ )
				if( sg((bb[i]-bb[j])^(bb[k]-bb[j])) ) 
					ok =false;
	if( ok ) {
		int ii=1, jj=1;
		double ll = -1.0;
		for( int i=1; i<=m; i++ )
			for( int j=i+1; j<=m; j++ ) {
				double l = (bb[i]-bb[j]).len();
				if( l>ll ) {
					ii = i;
					jj = j;
					ll = l;
				}
			}
		for( int i=1; i<=n; i++ )
			for( int j=i+1; j<=n; j++ ) 
				if( onseg(aa[i],aa[j],bb[ii]) && onseg(aa[i],aa[j],bb[jj]) ) 
					return true;
	}
	return false;
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf( "%d%d", &n, &m );
		for( int i=1; i<=n; i++ ) {
			double x, y;
			scanf( "%lf%lf", &x, &y );
			aa[i] = Point(x,y);
		}
		for( int i=1; i<=m; i++ ) {
			double x, y;
			scanf( "%lf%lf", &x, &y );
			bb[i] = Point(x,y);
		}
		sort( bb+1, bb+1+m );
		m = unique( bb+1, bb+1+m ) - bb - 1;
		sort( aa+1, aa+1+n );
		n = unique( aa+1, aa+1+n ) - aa - 1;
		if( case1() ) {
			printf( "1\n" );
			continue;
		} else if( case2() ) {
			printf( "2\n" );
			continue;
		} 
		memset( dis, 0x3f, sizeof(dis) );
		for( int u=1; u<=n; u++ )
			for( int v=1; v<=n; v++ ) {
				if( u==v ) continue;
				bool ok = true;
				for( int k=1; k<=m; k++ ) 
					if( !onleft(aa[u],aa[v],bb[k]) ) {
						ok = false;
						break;
					}
				if( ok ) {
					dis[u][v] = 1;
				}
			}
		for( int k=1; k<=n; k++ )
			for( int i=1; i<=n; i++ )
				for( int j=1; j<=n; j++ )
					dis[i][j] = min( dis[i][j], dis[i][k]+dis[k][j] );
		int ans = oo;
		for( int i=1; i<=n; i++ ) {
			if( dis[i][i]==2 ) continue;
			ans = min( ans, dis[i][i] );
		}
		printf( "%d\n", ans==oo ? -1 : ans );
	}
}
