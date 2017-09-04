#include <cstdio>
#include <algorithm>
#define N 50010
#define oo 1000000001
#define fprintf(...)
using namespace std;
 
typedef long long dnt;
 
struct Point {
    int x, y, h;
    void read() { scanf( "%d%d%d", &x, &y, &h ); }
    Point(){}
    Point( int x, int y, int h ):x(x),y(y),h(h){}
    bool in( dnt a, dnt b, int c ) {
        return a*x+b*y<c;
    }
};
typedef bool (*Cmp)( const Point &a, const Point &b );
struct Box {
    int xmin, xmax;
    int ymin, ymax;
    dnt sum;
    Box():xmin(oo),xmax(-oo),ymin(oo),ymax(-oo){}
    void add( Point &p ) {
        xmin = min( xmin, p.x );
        xmax = max( xmax, p.x );
        ymin = min( ymin, p.y );
        ymax = max( ymax, p.y );
        sum += p.h;
    }
    void add( Box &b ) {
        xmin = min( xmin, b.xmin );
        xmax = max( xmax, b.xmax );
        ymin = min( ymin, b.ymin );
        ymax = max( ymax, b.ymax );
        sum += b.sum;
    }
    bool in( dnt a, dnt b, int c ) {
        return (a*xmin+b*ymin<c)
            && (a*xmax+b*ymin<c)
            && (a*xmin+b*ymax<c)
            && (a*xmax+b*ymax<c);
    }
    bool out( dnt a, dnt b, int c ) {
        return (a*xmin+b*ymin>=c)
            && (a*xmax+b*ymin>=c)
            && (a*xmin+b*ymax>=c)
            && (a*xmax+b*ymax>=c);
    }
};
struct Node {
    Point p;
    Box box;
    Cmp cmp;
    Node *ls, *rs;
}pool[N], *tail=pool, *root;
 
int n, m;
Point pts[N];
Cmp cmp[2];
 
bool cmpx( const Point &a, const Point &b ) {
    return a.x<b.x;
}
bool cmpy( const Point &a, const Point &b ) {
    return a.y<b.y;
}
Node *build( int lf, int rg, int c ) {
    if( lf>rg ) return 0;
    Node *nd = ++tail;
    int mid=(lf+rg)>>1;
    nth_element( pts+lf, pts+mid, pts+rg+1, cmp[c] );
    nd->cmp = cmp[c];
    nd->p = pts[mid];
    nd->ls = build( lf, mid-1, !c );
    nd->rs = build( mid+1, rg, !c );
    if( nd->ls ) nd->box.add( nd->ls->box );
    if( nd->rs ) nd->box.add( nd->rs->box );
    nd->box.add( pts[mid] );
    fprintf( stderr, "(%d,%d,%d) ", pts[mid].x, pts[mid].y, pts[mid].h );
    return nd;
}
dnt query( Node *nd, int a, int b, int c ) {
    if( nd->box.in(a,b,c) ) return nd->box.sum;
    if( nd->box.out(a,b,c) ) return 0;
    dnt rt = 0;
    if( nd->ls ) rt += query( nd->ls, a, b, c );
    if( nd->rs ) rt += query( nd->rs, a, b, c );
    if( nd->p.in(a,b,c) ) rt += nd->p.h;
    return rt;
}
int main() {
    scanf( "%d%d", &n, &m );
    for( int i=1; i<=n; i++ )
        pts[i].read();
    cmp[0] = cmpx;
    cmp[1] = cmpy;
    root = build( 1, n, 0 );
    fprintf( stderr, "\n" );
    for( int i=1,a,b,c; i<=m; i++ ) {
        scanf( "%d%d%d", &a, &b, &c );
        printf( "%lld\n", query(root,a,b,c) );
    }
}
