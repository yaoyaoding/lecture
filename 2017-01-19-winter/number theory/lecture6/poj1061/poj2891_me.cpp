#include <cstdio>

typedef long long lng;

void exgcd( lng a, lng b, lng &d, lng &x, lng &y ) {
	if(!b) { d=a,x=1,y=0; }
	else {
		exgcd(b,a%b,d,y,x);
		y-=a/b*x;
	}
}
lng mod( lng a, lng m ) {
	return (a%m+m)%m;
}
lng gcd( lng a, lng b ) {
	if(!b) return a;
	return gcd(b,a%b);
}
lng lcm( lng a, lng b ) {
	return a/gcd(a,b)*b;
}
lng modeq( lng a, lng b, lng n ) {
	lng d, x, y, e;
	a = mod(a,n);
	b = mod(b,n);
	exgcd(a,n,d,x,y);
	if( b%d ) return -1;
	e = x*b/d;
	return mod(e,n/d);
}
int merge( lng a, lng n, lng b, lng m, lng &c, lng &nm ) {
	//	x=a(n)	x=a+u*n
	//	x=b(m)	x=b+v*m
	lng u;
	u = modeq(n,b-a,m);
	if( u==-1 ) return -1;
	nm = lcm(n,m);
	c = mod(a+u*n,nm);
	return 1;
}
int main() {
	int st;
	while( scanf("%d",&st)==1 ) {
		lng a, n, b, m, c, nm;
		scanf( "%lld%lld", &n, &a );
		int i;
		for( i=1; i<st; i++ ) {
			scanf( "%lld%lld", &m, &b );
			if( merge(a,n,b,m,c,nm)==-1 ) {
				a = -1;
				i++;
				break;
			}
			a = c;
			n = nm;
			printf( "x = %lld (%lld)\n", a, n );
		}
		for( ; i<st; i++ ) scanf( "%lld%lld", &m, &b );
		printf( "%lld\n", a );
	}
}
