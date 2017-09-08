/*
 *	n <= 100000
 *	s < (1<<20)
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int Mod = 1e9 + 7;
const int P = 20;


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
void fix(int &a) {
	while(a >= Mod) a -= Mod;
	while(a < 0) a += Mod;
}
void sumup() {
	for(int i = 0; i < P; i++) {
		int s = ((1<<P) - 1) ^ (1<<i);
		for(int ss = s; ss > 0; ss=(ss-1)&s) {
			cnt[ss | (1<<i)] += cnt[ss];
			fix(cnt[ss | (1<<i)]);
		}
		cnt[1<<i] += cnt[0];
		fix(cnt[1<<i]);
	}
}
void sumdown() {
	for(int i = 0; i < P; i++) {
		int s = ((1<<P) - 1) ^ (1<<i);
		for(int ss = s; ss > 0; ss=(ss-1)&s) {
			cnt[ss | (1<<i)] -= cnt[ss];
			fix(cnt[ss | (1<<i)]);
		}
		cnt[1<<i] -= cnt[0];
		fix(cnt[1<<i]);
	}
}
int main() {
	int T;
	scanf("%d", &T);
	init(1e5);
	while(T--) {
		memset(cnt, 0, sizeof(cnt));
		scanf("%d%d%d", &n, &k, &s);
		for(int i = 1; i <= n; i++) {
			scanf("%d", aa + i);
			cnt[aa[i]]++;
		}
		sumup();
		for(int s = 0; s < (1<<P); s++) 
			cnt[s] = comb(cnt[s],k);
		sumdown();
		printf("%d\n", cnt[s]);
	}
}

