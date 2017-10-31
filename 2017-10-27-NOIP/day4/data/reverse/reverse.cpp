#include <bits/stdc++.h>
using namespace std;

const int N = 25;

long long A, B;
int abits[N], atot, bbits[N], btot;
int bits[N], tot;
unsigned long long dp[N][N][3][3];
bool done[N][N][3][3];

void split(unsigned long long val, int bits[N], int &tot) {
	tot = 0;
	while(val) {
		++tot;
		bits[tot] = int(val % 10);
		val /= 10;
	}
}
int trans(int a, int b, int s) {
	int delta = a - b;
	int ss;
	if(delta < 0) ss = 0;
	else if(delta == 0) ss = s;
	else ss = 2;
	return ss;
}
long long dfs(int i, int j, int s1, int s2, bool flag) {
	if(!flag && done[i][j][s1][s2]) return dp[i][j][s1][s2];
	unsigned long long dpv = 0;
	if(i == 1) {
		int ss1 = s1, ss2 = s2;
		if(j < atot) ss1 = 0;
		if(j < btot) ss2 = 0;
		if(ss1 != 0 && ss2 != 2) 
			dpv = 1;
		else
			dpv = 0;
	} else {
		int maxd = (flag ? bits[i - 1] : 9);
		for(int d = 0; d <= maxd; d++) {
			dpv += dfs(i - 1, j + 1, trans(d, abits[j + 1], s1), trans(d, bbits[j + 1], s2), flag && (d == maxd));
		}
	}
	if(!flag) {
		done[i][j][s1][s2] = true;
		return dp[i][j][s1][s2] = dpv;
	} else return dpv;
}
unsigned long long solve() {
	memset(done, 0, sizeof(done));
	unsigned long long ans = 0;
	for(int i = 1; i <= tot; i++) {
		int maxd = (i == tot ? bits[i] : 9);
		for(int d = 1; d <= maxd; d++) {
			unsigned long long sub = dfs(i, 1, trans(d,abits[1],1), trans(d,bbits[1],1), (i == tot && d == maxd));
			ans += sub;
//			printf("dfs(i = %d, j = %d, s1 = %d, s2 = %d, flag = %s) = %lld\n", i, 1,
//				trans(d,abits[1],1), trans(d,bbits[1],1), (i == tot && d == maxd) ? "True" : "False", sub );
		}
	}
	return ans;
}
int main() {
	int T, a, b;
//	scanf("%d", &T);
	cin >> T >> a >> b;
	for(int cas = 1; cas <= T; cas++) {
		memset(abits, 0, sizeof(abits));
		memset(bbits, 0, sizeof(bbits));
//		scanf("%llu%llu", &A, &B);
		cin >> A >> B;
		unsigned long long ans = 0;
		split(A, abits, atot);
		split(B, bbits, btot);

		split(B, bits, tot);
		ans += solve();
		if(A != 1) {
			split(A - 1, bits, tot);
			ans -= solve();
		}
//		printf("Case %d: %llu\n", cas, ans);
		cout << ans << endl;
	}
}
