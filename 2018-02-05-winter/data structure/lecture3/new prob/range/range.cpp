#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100000 + 10;

int n;
vector<int> g[N];
vector<int> vc[3];

void dfs(int u, int f) {
	sort(g[u].begin(),g[u].end());
	vc[0].push_back(u);
	vc[1].push_back(u);
	for(int t = 0; t < (int)g[u].size(); t++) {
		int v = g[u][t];
		if(v == f) continue;
		vc[2].push_back(v);
		dfs(v, u);
		vc[2].push_back(u);
	}
	vc[1].push_back(u);
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vc[2].push_back(1);
	dfs(1,1);
	for(int t = 0; t < (int)vc[0].size(); t++)
		printf("%d ", vc[0][t]);
	printf("\n");
	for(int t = 0; t < (int)vc[1].size(); t++)
		printf("%d ", vc[1][t]);
	printf("\n");
	for(int t = 0; t < (int)vc[2].size(); t++)
		printf("%d ", vc[2][t]);
	printf("\n");
	
}
