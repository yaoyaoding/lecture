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
	if(a >= Mod) a -= Mod;
	if(a < 0) a += Mod;
}
void sumup() {
	for(int i = 0; i < P; i++) {
		int s = ((1<<P) - 1) ^ (1<<i);
		for(int ss = s; ss > 0; ss=(ss-1)&s) {
			cnt[ss] += cnt[ss | (1<<i)];
			fix(cnt[ss]);
		}
		cnt[0] += cnt[1<<i];
		fix(cnt[0]);
	}
}
void sumdown() {
	for(int i = 0; i < P; i++) {
		int s = ((1<<P) - 1) ^ (1<<i);
		for(int ss = s; ss > 0; ss=(ss-1)&s) {
			cnt[ss] -= cnt[ss | (1<<i)];
			fix(cnt[ss]);
		}
		cnt[0] -= cnt[1<<i];
		fix(cnt[0]);
	}
}
int main() {
	scanf("%d%d%d", &n, &k, &s);
	init(1e5);
	for(int i = 1; i <= n; i++) {
		scanf("%d", aa + i);
		cnt[aa[i]]++;
	}
	/*
	for(int s = 0; s < (1<<P); s++)
		printf("cnt[%s] = %d\n", bitset<2>(s).to_string().c_str(),cnt[s]);
	*/
	sumup();
	/*
	for(int s = 0; s < (1<<P); s++)
		printf("cnt[%s] = %d\n", bitset<2>(s).to_string().c_str(),cnt[s]);
	*/
	for(int s = 0; s < (1<<P); s++) 
		cnt[s] = comb(cnt[s],k);
	/*
	for(int s = 0; s < (1<<P); s++)
		printf("cnt[%s] = %d\n", bitset<2>(s).to_string().c_str(),cnt[s]);
	*/
	sumdown();
	/*
	for(int s = 0; s < (1<<P); s++)
		printf("cnt[%s] = %d\n", bitset<2>(s).to_string().c_str(),cnt[s]);
	*/
	printf("%d\n", cnt[s]);
}

