/*
 * n <= 100000
 * s < 1<<15
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int Mod = 1e9 + 7;
const int P = 15;

int n, k, s;
int aa[N];
int cnt[1<<P];
int fac[N], vfac[N];

int mpow(int a, int b) {
	int rt;
	for(rt = 1; b; b>>=1,a=(1LL*a*a)%Mod)
		if(b&1) rt=(1LL*rt*a)%Mod;
	return rt;
}
void init(int n) {
	fac[0] = 1;
	for(int i = 1; i <= n; i++)
		fac[i] = 1LL * fac[i-1] * i % Mod;
	vfac[n] = mpow(fac[n], Mod - 2);
	for(int i = n - 1; i >= 0; i--)
		vfac[i] = 1LL * vfac[i+1] * (i + 1) % Mod;
}
int comb(int n, int m) {
	if(m > n) return 0;
	return 1LL * fac[n] * vfac[m] % Mod * vfac[n-m] % Mod;
}
int main() {
	init(100000);
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(cnt, 0, sizeof(cnt));
		scanf("%d%d%d", &n, &k, &s);
		for(int i = 1; i <= n; i++) {
			scanf("%d", aa + i);
			cnt[aa[i]]++;
		}
		for(int s = (1<<P) - 1; s >= 0; s--) {
			int ss = ((1<<P) - 1) ^ s;
			for(int sss = ss; sss > 0; sss = (sss - 1) & ss) {
				cnt[s | sss] += cnt[s];
				if(cnt[s | sss] >= Mod) cnt[s | sss] -= Mod;
			}
		}
		for(int s = 0; s < (1<<P); s++) 
			cnt[s] = comb(cnt[s],k);
		for(int s = 0; s < (1<<P); s++) {
			for(int ss = (s - 1) & s; ss > 0; ss = (ss - 1) & s) {
				cnt[s] -= cnt[ss];
				if(cnt[s] < 0) cnt[s] += Mod;
			}
			if(s != 0) {
				cnt[s] -= cnt[0];
				if(cnt[s] < 0) cnt[s] += Mod;
			}
		}
		printf("%d\n", cnt[s]);
	}
}

