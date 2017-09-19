#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 10;
const int NN = N * N;

struct Edge {
	int u, v;
	Edge(){}
	Edge(int u, int v):u(u),v(v){}
};

int n, m;
int id[N][N], id_clock;
char s[N][N];
vector<int> g[NN];
int dfn[NN], low[NN], bccno[NN], iscut[NN], bcc_cnt, dfs_clock;
vector<Edge> stk;

int dx[] = { 1, 0 };
int dy[] = { 0, 1 };

void init() {
	id_clock = 0;
	bcc_cnt = dfs_clock = 0;
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++) {
			id[i][j] = ++id_clock;
			dfn[id_clock] = low[id_clock] = iscut[id_clock] = 0;
			g[id_clock].clear();
		}
}
void dfs( int u, int fa ) {
    dfn[u] = low[u] = ++dfs_clock;;
    int child = 0;
	for(int t = 0; t < (int)g[u].size(); t++) {
		int v = g[u][t];
        if( v==fa ) continue;
        stk.push_back( Edge(u,v) );
        if( !dfn[v] ) {
            dfs(v,u);
            low[u] = min( low[u], low[v] );
            child++;
            if( low[v]>=dfn[u] ) {
                iscut[u] = true;
                bcc_cnt++;
                while(1) {
                    Edge e=stk.back();
                    stk.pop_back();
                    if( e.u==u && e.v==v ) break;
                }
            }
        } else if( dfn[v]<dfn[u] ) {
            low[u] = min( low[u], dfn[v] );
        }
    }
    if( u==fa && child<=1 ) iscut[u]=false;
}


int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		init();
		for(int i = 1; i <= n; i++) 
			scanf("%s", s[i] + 1);
		int tot = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) 
				tot += (s[i][j] == '#');
		if(tot <= 2) {
			printf("-1\n");
			continue;
		} 
		int sx, sy;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) {
				if(s[i][j] == '#') {
					sx = i;
					sy = j;
					for(int d = 0; d < 2; d++) {
						int ii = i + dx[d];
						int jj = j + dy[d];
						if(1 <= ii && ii <= n && 1 <= jj && jj <= m && s[ii][jj] == '#') {
							g[id[i][j]].push_back(id[ii][jj]);
							g[id[ii][jj]].push_back(id[i][j]);
						}
					}
				}
			}
		int src = id[sx][sy];
		dfs(src,src);
		if(bcc_cnt == 1) {
			printf("2\n");
		} else {
			printf("1\n");
		}
	}
}

