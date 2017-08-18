#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int Mod = 1e9 + 7;

int n, m;
int aa[N][N];

int mpow(int a, int b) {
	int rt;
	for(rt = 1; b; b>>=1,a=(1LL*a*a)%Mod)
		if(b & 1) rt=(1LL*rt*a)%Mod;
	return rt;
}
int inverse(int a) {
	return mpow(a,Mod-2);
}
int det(int n) {
	int rt = 1;
	for(int i = 1, j, k; i <= n; i++) {
		j = -1;
		for(k = i; k <= n; k++)
			if(aa[k][i] != 0) {
				j = k;
				break;
			}
		if(j == -1) return 0;
		
		if(i != j) {
			for(k = i; k <= n; k++) {
				swap(aa[i][k], aa[j][k]);
				rt = (Mod - rt) % Mod;
			}
		}
		int inv = inverse(aa[i][i]);
		for(j = i + 1; j <= n; j++) {
			if(aa[j][i] == 0) continue;
			int r = 1LL * aa[j][i] * inv % Mod;
			for(k = i; k <= n; k++) {
				aa[j][k] -= 1LL * aa[i][k] * r % Mod;
				if(aa[j][k] < 0) aa[j][k] += Mod;
			}
		}
	}
	for(int i = 1; i <= n; i++)
		rt = 1LL * rt * aa[i][i] % Mod;
	return rt;
}

int main() {
	int T;
//	scanf("%d", &T);
	T = 1;
	while(T--) {
		scanf("%d%d", &n, &m);
		memset(aa, 0, sizeof(aa));
		for(int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			aa[u][u]++;
			aa[v][v]++;
			aa[u][v] = aa[v][u] = Mod-1;
		}
		printf("%d\n", det(n-1));
	}
}

