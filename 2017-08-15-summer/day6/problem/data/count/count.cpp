#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#define abs(a) ((a)<0?-(a):(a))
#define M 31011
#define maxn 110
using namespace std;

struct Edge {
    int u, v, w;
    Edge( int u, int v, int w ) : u(u), v(v), w(w) {}
    bool operator<( const Edge & b ) const {
        return w<b.w;
    }
};

typedef int Matrix[maxn][maxn];

int n, m;
vector<Edge> edge;

int fa[maxn];

void init() {
    for( int i=1; i<=n; i++ ) fa[i]=i;
}
int find( int a ) {
    return fa[a]==a ? a : fa[a]=find(fa[a]);
}
void unon( int a, int b ) {
    a = find(a);
    b = find(b);
    fa[a] = b;
}

int det( Matrix a, int n ) {
    for( int i=0; i<n; i++ ) {
        int r = i;
        for( int j=i+1; j<n; j++ )
            if( abs(a[j][i])>abs(a[r][i]) ) r=j;
        if( r!=i )
            for( int k=i; k<n; k++ )
                swap( a[i][k], a[r][k] );
        if( a[i][i]==0 ) return 0;
        for( int j=i+1; j<n; j++ ) {
            while( a[j][i] ) {
                int d = a[i][i] / a[j][i];
                for( int k=i; k<n; k++ ) {
                    a[i][k] = (a[i][k]-a[j][k]*d%M)%M;
                    swap( a[i][k], a[j][k] );
                }
            }
        }
    }
    int rt = 1;
    for( int i=0; i<n; i++ )
        rt = (rt*a[i][i])%M;
    return abs(rt);
}

int subfa[30], cnt;
Matrix a;
int sfind( int a ) {
    return a==subfa[a] ? a : subfa[a]=sfind(subfa[a]);
}
void sunon( int a, int b ) {
    a = sfind(a);
    b = sfind(b);
    if( b<a ) subfa[a] = b;
    else subfa[b] = a;
}
int pm( map<int,int> &mp, int i ) { return mp[i]; }
int calc( const vector<Edge> & e ) {
    vector<int> cc[30];
    map<int,int> mp;
    cnt = 0;
    for( int i=0; i<e.size(); i++ ) {
        int u = e[i].u, v = e[i].v;
        if( !mp.count(find(u)) ) mp[find(u)]=cnt++;
        if( !mp.count(find(v)) ) mp[find(v)]=cnt++;
    }
    for( int i=0; i<mp.size(); i++ ) subfa[i] = i;
    for( int i=0; i<e.size(); i++ ) {
        int u = e[i].u, v = e[i].v;
        sunon( mp[find(u)], mp[find(v)] );
    }
    int rt = 1;
    for( int i=0; i<cnt; i++ ) 
        cc[sfind(i)].push_back(i);
    for( int c=0; cc[c].size(); c++ ) {
        if( cc[c].size()==1 ) continue;
        map<int,int> np;
        for( int t=0; t<cc[c].size(); t++ ) 
            np[cc[c][t]] = t;
        memset( a, 0, sizeof(a) );
        for( int i=0; i<e.size(); i++ ) {
            int u = np[mp[find(e[i].u)]];
            int v = np[mp[find(e[i].v)]];
            a[u][u]++;
            a[v][v]++;
            a[u][v]--;
            a[v][u]--;
        }
        rt = (rt*det(a,cc[c].size()-1))%M;
    }
    return rt;
}
void work() {
    sort( edge.begin(), edge.end() );
    init();
    vector<Edge> e;
    int ans = 1;
    for( int i=0; i<edge.size(); ) {
        do 
            e.push_back( edge[i++] );
        while( i<edge.size() && edge[i].w==edge[i-1].w );
        ans = (ans*calc(e))%M;
        while( !e.empty() ) {
            unon( e.back().u, e.back().v );
            e.pop_back();
        }
    }
    for( int i=2; i<=n; i++ )
        if( find(i)!=find(i-1) ) {
            ans=0;
            break;
        }
    printf( "%d\n", ans );
}

int main() {
    scanf( "%d%d", &n, &m );
    for( int i=0,u,v,w; i<m; i++ ) {
        scanf( "%d%d%d", &u, &v, &w );
        edge.push_back( Edge(u,v,w) );
    }
    work();
}
