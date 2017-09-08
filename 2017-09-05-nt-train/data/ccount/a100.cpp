#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int P = 5;

int up[N], down[N], utot, dtot;
int comb[P][P];
long long _dp[N][5];

void init() {
	for(int i = 0; i < P; i++)
		for(int j = 0; j <= i; j++) {
			if(j == 0 || j == i)
				comb[i][j] = 1;
			else
				comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % P;
		}
}
void split(long long n, int *arr, int &tot) {
	if(n == 0) {
		tot = 1;
		arr[1] = 0;
	} else {
		tot = 0;
		while(n) {
			arr[++tot] = int(n % P);
			n /= P;
		}
	}
}
long long dp(int i, int r, bool flag) {
	if(_dp[i][r] != -1 && flag == false) return _dp[i][r];
	if(i == 0 ) return r == 0;
	long long dpv = 0;
	int top = flag ? up[i] : P - 1;
	for(int v = 0; v <= top; v++) 
		dpv += dp(i - 1, r * comb[down[i]][v] % P, flag && v == top);
	if(!flag) return _dp[i][r] = dpv;
	else return dpv;
}
long long solve(long long n) {
	split(n,up,utot);
	return dp(utot, 1, true);
}
int main() {
	int T;
	init();
	scanf("%d", &T);
	while(T--) {
		long long l, r, n;
		scanf("%lld%lld%lld", &l, &r, &n);
		split(n, down, dtot);
		memset(_dp, -1, sizeof(_dp));
		long long ans = solve(r);
		if(l != 0) 
			ans = ans - solve(l - 1);
		printf("%lld\n", ans);
	}
}

