#include <bits/stdc++.h>
using namespace std;

#define fprintf(...)

const int N = 33;
const int NN = N * N;

int n, m, c, q, tp;
int id[N][N];
int idxx[NN], idyy[NN];
int board[N][N];
int bad[NN];
int match[NN], visit[NN], stamp;
vector<int> edge[NN];
int dx[] = { -1, -1, -2, -2, 1, 1, 2, 2 };
int dy[] = { -2,  2, -1, 1, -2, 2,-1, 1 };
int type[NN];

bool dfs( int u ) {
	for( int t = 0; t < (int)edge[u].size(); t++ ) {
		int v = edge[u][t];
		if( visit[v] == stamp ) continue;
		visit[v] = stamp;
		if( match[v] == 0 || dfs(match[v]) ) {
			match[v] = u;
			return true;
		}
	}
	return false;
}
int hungary() {
	int ans = 0;
	memset( visit, 0, sizeof(visit) );
	memset( match, 0, sizeof(match) );
	stamp = 0;
	for( int u = 1; u <= c; u++ ) {
		++stamp;
		if((idxx[u] + idyy[u]) & 1) continue;
		ans += dfs( u );
	}
	/*
	for(int u = 1; u <= c; u++) {
		if(match[u]) {
			fprintf(stderr, "(%d,%d) match (%d,%d)\n", idxx[u], idyy[u],
					idxx[match[u]], idyy[match[u]]);
		}
	}
	fprintf(stderr, "matched = %d\n", ans);
	*/
	for(int u = 1; u <= c; u++) 
		if(match[u]) 
			match[match[u]] = u;
	return ans;
}
vector<int> mis() {	//	maximum independent set
	vector<int> S;	//	independent set, 1
	vector<int> T;	//	dominate set, 2
	for(int u = 1; u <= c; u++) {
		if(bad[u]) continue;
		if(!match[u]) {
			S.push_back(u);
			type[u] = 1;
		}
	}
	while(!S.empty() || !T.empty()) {
		if(!S.empty()) {
			int u = S.back();
			S.pop_back();
			for(int t = 0; t < (int)edge[u].size(); t++) {
				int v = edge[u][t];
				if(bad[v]) continue;
				if(!type[v]) {
					type[v] = 2;
					T.push_back(v);
				}
			}
		}
		if(!T.empty()) {
			int u = T.back();
			T.pop_back();
			int v = match[u];
			if(bad[v]) continue;
			if(v && !type[v]) {
				type[v] = 1;
				S.push_back(v);
			}
		}
	}
	for(int u = 1; u <= c; u++) {
		if(bad[u]) continue;
		if(!type[u]) {
			int left, right;
			if((idxx[u] + idyy[u]) & 1) {
				left = u;
				right = match[u];
			} else {
				left = match[u];
				right = u;
			}
			type[left] = 1;
			type[right] = 2;
		}
	}
	vector<int> vc;
	for(int u = 1; u <= c; u++) {
		if(type[u] == 1)
			vc.push_back(u);
	}
	return vc;
}

/*
bool check(vector<int> ms) {
	set<int> st;
	for(int t = 0; t < (int)ms.size(); t++) 
		st.insert(ms[t]);
	for(int t = 0; t < (int)ms.size(); t++) {
		int u = ms[t];
		for(int tt = 0; tt < (int)edge[u].size(); tt++) {
			int v = edge[u][tt];
			if(st.count(v)) {
				fprintf(stderr, "%d %d fight %d %d\n",
						idxx[u], idyy[u], idxx[v], idyy[v]);
				return true;
			}
		}
	}
	return false;
}
*/
int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &q, &tp);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			++c;
			id[i][j] = c;
			idxx[c] = i;
			idyy[c] = j;
		}
	for(int i = 1; i <= q; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		board[x][y] = true;
		bad[id[x][y]] = true;
	}
	for(int x = 1; x <= n; x++)
		for(int y = 1; y <= m; y++) {
			if(board[x][y]) continue;
			for(int d = 0; d < 8; d++) {
				int xx = x + dx[d];
				int yy = y + dy[d];
				if(xx < 1 || xx > n || yy < 1 || yy > m || board[xx][yy]) continue;
				edge[id[x][y]].push_back(id[xx][yy]);
			}
		}
	int mched = hungary();
	vector<int> ms = mis();
	/*
	if(check(ms)) {
		fprintf(stderr, "*NO*\n");
	}
	*/
	printf("%d\n", (int)ms.size());
	if(tp == 1) {
		for(int t = 0; t < (int)ms.size(); t++)
			printf("%d %d\n", idxx[ms[t]], idyy[ms[t]]);
	}
		
}

